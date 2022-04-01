/**
 * Created by xinnian on 2016/12/21.
 */
var setTimeout, setInterval, clearTimeout, clearInterval, AlipayTimersExecution;
if(!this.console){
  this.console = {
    log: function () {},
    error: function () {},
    warn: function () {},
    info: function () {}
  }
};
(function () {
  AlipayTimersExecution = {
    GUID: 1,
    Type: {
      setTimeout: "setTimeout",
      setInterval: "setInterval",
      requestAnimationFrame: "requestAnimationFrame",
      setImmediate: "setImmediate"
    },

    callbacks: [],
    types: [],
    timerIDs: [],
    immediates: [],

    callTimer: function (timerID) {

      var timerIndex = AlipayTimersExecution.timerIDs.indexOf(timerID);
      // timerIndex of -1 means that no timer with that ID exists. There are
      // two situations when this happens, when a garbage timer ID was given
      // and when a previously existing timer was deleted before this callback
      // fired. In both cases we want to ignore the timer id, but in the former
      // case we warn as well.
      if (timerIndex === -1) {
        return;
      }
      var type = AlipayTimersExecution.types[timerIndex];
      var callback = AlipayTimersExecution.callbacks[timerIndex];

      // Clear the metadata
      if (type === AlipayTimersExecution.Type.setTimeout || type === AlipayTimersExecution.Type.setImmediate || type === AlipayTimersExecution.Type.requestAnimationFrame) {
        AlipayTimersExecution._clearIndex(timerIndex);
      }

      try {
        if (type === AlipayTimersExecution.Type.setTimeout || type === AlipayTimersExecution.Type.setInterval || type === AlipayTimersExecution.Type.setImmediate) {
          callback();
        } else if (type === AlipayTimersExecution.Type.requestAnimationFrame) {
          var currentTime = performanceNow();
          callback(currentTime);
        } else {
          console.error('Tried to call a callback with invalid type: ' + type);
          return;
        }
      } catch (e) {
        // Don't rethrow so that we can run every other timer.
        AlipayTimersExecution.errors = AlipayTimersExecution.errors || [];
        AlipayTimersExecution.errors.push(e);
      }
    },

    /**
     * This is called from the native side. We are passed an array of timerIDs,
     * and
     */
    callTimers: function (timerIDs) {
      //invariant(timerIDs.length !== 0, 'Probably shouldn\'t call "callTimers" with no timerIDs');
      AlipayTimersExecution.errors = null;
      timerIDs.forEach(AlipayTimersExecution.callTimer);

      var errors = AlipayTimersExecution.errors;
      if (errors) {
        var errorCount = errors.length;
        if (errorCount > 1) {
          // Throw all the other errors in a setTimeout, which will throw each
          // error one at a time
          for (var ii = 1; ii < errorCount; ii++) {
            var error = errors[ii];
            AlipayTimers.setTimeout(function () {
                throw error;
              },
              0);
          }
        }
        throw errors[0];
      }
    },

    /**
     * This is called after we execute any command we receive from native but
     * before we hand control back to native.
     */
    callImmediates: function () {
      AlipayTimersExecution.errors = null;
      while (AlipayTimersExecution.immediates.length !== 0) {
        AlipayTimersExecution.callTimer(AlipayTimersExecution.immediates.shift());
      }
      if (AlipayTimersExecution.errors) {
        AlipayTimersExecution.errors.forEach(function () {
          var args = Array.prototype.slice.call(undefined, arguments);
          var error = args[0];
          AlipayTimers.setTimeout(function () {
              throw error;
            },
            0);
        });
      }
    },

    _clearIndex: function (i) {
      AlipayTimersExecution.timerIDs[i] = null;
      AlipayTimersExecution.callbacks[i] = null;
      AlipayTimersExecution.types[i] = null;
    }
  };

  function _getFreeIndex() {
    var freeIndex = AlipayTimersExecution.timerIDs.indexOf(null);
    if (freeIndex === -1) {
      freeIndex = AlipayTimersExecution.timerIDs.length;
    }
    return freeIndex;
  }

  function _allocateCallback(func, type) {
    const id = AlipayTimersExecution.GUID++;
    const freeIndex = _getFreeIndex();
    AlipayTimersExecution.timerIDs[freeIndex] = id;
    AlipayTimersExecution.callbacks[freeIndex] = func;
    AlipayTimersExecution.types[freeIndex] = type;
    return id;
  }

  function _freeCallback(timerID) {
    // AlipayTimersExecution.timerIDs contains nulls after timers have been removed;
    // ignore nulls upfront so indexOf doesn't find them
    if (timerID == null) {
      return;
    }

    var index = AlipayTimersExecution.timerIDs.indexOf(timerID);
    // See corresponding comment in `callTimers` for reasoning behind this
    if (index !== -1) {
      AlipayTimersExecution._clearIndex(index);
      const type = AlipayTimersExecution.types[index];
      if (type !== 'setImmediate' && type !== 'requestIdleCallback') {
        //call native method
        deleteTimer(timerID);
      }
    }
  }

  var AlipayTimers = {

    setTimeout: function () {
      var args = Array.prototype.slice.call(arguments);
      var func = arguments[0];
      var duration = arguments[1];

      var id = _allocateCallback((function (fn) {
        return function () {
          fn.apply(undefined, args.slice(2));
        }
      })(func), 'setTimeout');
      //call native method
      createTimer(id, duration || 0, Date.now(), false);
      return id;
    },

    setInterval: function () {
      var args = Array.prototype.slice.call(arguments);
      var func = arguments[0];
      var duration = arguments[1];

      var id = _allocateCallback((function (fn) {
        return function () {
          fn.apply(undefined, args.slice(2));
        }
      })(func), 'setInterval');
      //call native method
      createTimer(id, duration || 0, Date.now(), true);
      return id;
    },

    clearTimeout: function (timerID) {
      _freeCallback(timerID);
    },

    clearInterval: function (timerID) {
      _freeCallback(timerID);
    }
  };

  setTimeout = setTimeout || AlipayTimers.setTimeout;
  setInterval = setInterval || AlipayTimers.setInterval;
  clearTimeout = clearTimeout || AlipayTimers.clearTimeout;
  clearInterval = clearInterval || AlipayTimers.clearInterval;
})();