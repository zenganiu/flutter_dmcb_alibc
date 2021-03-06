package com.example.flutter_dmcb_alibc;

import android.app.Activity;
import android.app.Application;
import android.content.Intent;
import android.text.TextUtils;
import android.util.Log;

import androidx.annotation.NonNull;

import com.alibaba.alibclogin.AlibcLogin;
import com.alibaba.alibcprotocol.callback.AlibcLoginCallback;
import com.alibaba.alibcprotocol.callback.AlibcTradeCallback;
import com.alibaba.alibcprotocol.param.AlibcBizParams;
import com.alibaba.alibcprotocol.param.AlibcDegradeType;
import com.alibaba.alibcprotocol.param.AlibcShowParams;
import com.alibaba.alibcprotocol.param.AlibcTaokeParams;
import com.alibaba.alibcprotocol.param.OpenType;
import com.alibaba.ariver.kernel.common.utils.JSONUtils;
import com.alibaba.baichuan.trade.common.AlibcTradeCommon;
import com.alibaba.baichuan.trade.common.utils.AlibcCommonUtils;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.baichuan.nb_trade.AlibcTrade;
import com.baichuan.nb_trade.callback.AlibcTradeInitCallback;
import com.baichuan.nb_trade.core.AlibcTradeBiz;
import com.baichuan.nb_trade.core.AlibcTradeSDK;

import java.util.HashMap;
import java.util.Map;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.embedding.engine.plugins.activity.ActivityAware;
import io.flutter.embedding.engine.plugins.activity.ActivityPluginBinding;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/**
 * FlutterDmcbAlibcPlugin
 */
public class FlutterDmcbAlibcPlugin implements FlutterPlugin, MethodCallHandler, ActivityAware {
    /// The MethodChannel that will the communication between Flutter and native Android
    ///
    /// This local reference serves to register the plugin with the Flutter Engine and unregister it
    /// when the Flutter Engine is detached from the Activity
    private MethodChannel channel;

    private Application mAppContext;

    private Activity mActivity;

    @Override
    public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
        channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "flutter_dmcb_alibc");
        channel.setMethodCallHandler(this);
        mAppContext = (Application) flutterPluginBinding.getApplicationContext();
    }

    @Override
    public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
        if (call.method.equals("getPlatformVersion")) {
            result.success("Android " + android.os.Build.VERSION.RELEASE);
        } else if (call.method.equals("initAlibc")) {
            initialSDK(result);
        } else if (call.method.equals("getUtdid")) {
            getUtdId(result);
        } else if (call.method.equals("authLogin")) {
            authLogin(call, result);
        } else if (call.method.equals("getUserInfo")) {
            getUserInfo(result);
        } else if (call.method.equals("logout")) {
            logout();
        } else if (call.method.equals("isLogin")) {
            isLogin(result);
        } else if (call.method.equals("openByCode")) {
            openDetail(call, result);
        } else if (call.method.equals("openByUrl")) {
            openDetail(call, result);
        } else if (call.method.equals("getAccessToken")) {
            getAccessToken(call, result);
        } else {
            result.notImplemented();
        }
    }

    /**
     * ??????????????????
     *
     * @param call
     * @param result
     */
    public void getAccessToken(final MethodCall call, final Result result) {
        CustomActivity.setCallBack(call, result);
        Intent intent = new Intent(mActivity, CustomActivity.class);
        intent.putExtra("method", "authLogin");
        mActivity.startActivity(intent);
    }

    /**
     * ????????????????????????
     *
     * @param call
     * @param result
     */
    public void authLogin(final MethodCall call, final Result result) {
        AlibcLoginCallback loginCallback = new AlibcLoginCallback() {
            @Override
            public void onSuccess(String uid, String nick) {
                Map<String, Object> map = AlibcLogin.getInstance().getUserInfo();
                Log.d("substring", " getUserInfo " + JSON.toJSONString(map));
                JSONObject mJSONObject = new JSONObject();
                mJSONObject.put("nick", map.get("nick"));
                mJSONObject.put("openId", map.get("userId"));
                JSONObject main = new JSONObject();
                main.put("code", "00000");
                main.put("message", "????????????");
                main.put("payload", mJSONObject);
                result.success(main);
            }

            @Override
            public void onFailure(int i, String s) {
                Log.d("substring", "onFailure " + s);
            }
        };
        if (AlibcLogin.getInstance().isLogin()) {
            AlibcLogin.getInstance().init(loginCallback);
        } else {
            AlibcLogin.getInstance().showLogin(loginCallback);
        }
    }

    /**
     * ??????????????????
     *
     * @param result
     */
    public void initialSDK(final Result result) {
        if (BuildConfig.DEBUG) {
            AlibcCommonUtils.setOpenAnalysisTool(true);
            //?????????????????????????????????????????????????????????
            AlibcTradeCommon.turnOnDebug();
            AlibcTradeCommon.openErrorLog();
            AlibcTradeBiz.turnOnDebug();
        } else {
            // ?????????????????????????????????????????????
            AlibcTradeCommon.turnOffDebug();
            AlibcTradeCommon.closeErrorLog();
            AlibcTradeBiz.turnOffDebug();
        }
        Map<String, Object> params = new HashMap<>();
        params.put("open4GDownload", true);
        params.put("open5GDownload", true);
        AlibcTradeSDK.asyncInit(mAppContext, params, new AlibcTradeInitCallback() {
            @Override
            public void onSuccess() {
                Log.d("substring", "????????????????????????");
                JSONObject mJSONObject = new JSONObject();
                mJSONObject.put("code", "00000");
                mJSONObject.put("message", "????????????????????????");
                mJSONObject.put("payload", "");
                result.success(mJSONObject);
            }

            @Override
            public void onFailure(int code, String msg) {
                Log.d("substring", "????????????????????????" + code + msg);
                JSONObject mJSONObject = new JSONObject();
                mJSONObject.put("code", code);
                mJSONObject.put("message", msg);
                mJSONObject.put("payload", "");
                result.success(mJSONObject);
            }
        });
    }

    /**
     * ???????????????????????????????????????????????????????????????????????????
     *
     * @param result
     */
    private void getUtdId(@NonNull Result result) {
        String utdId = AlibcTradeCommon.getUtdid();
        Log.d("substring", "getUtdId" + utdId);
        result.success(utdId);
    }

    private void getUserInfo(@NonNull Result result) {
        Map<String, Object> map = AlibcLogin.getInstance().getUserInfo();
        Log.d("substring", " getUserInfo " + JSON.toJSONString(map));
        JSONObject mJSONObject = new JSONObject();
        mJSONObject.put("nick", map.get("nick"));
        mJSONObject.put("openId", map.get("userId"));
        JSONObject main = new JSONObject();
        main.put("code", "00000");
        main.put("message", "????????????");
        main.put("payload", mJSONObject);
        result.success(main);
    }

    private void logout() {
        AlibcLogin.getInstance().logout(new AlibcLoginCallback() {
            @Override
            public void onSuccess(String s, String s1) {
                Log.d("substring", "????????????");
            }

            @Override
            public void onFailure(int i, String s) {
                Log.d("substring", "????????????");
            }
        });
    }

    private void isLogin(@NonNull Result result) {
        boolean isLogin = AlibcLogin.getInstance().isLogin();
        Log.d("substring", "isLogin" + isLogin);
        result.success(isLogin);
    }

    /**
     * ???????????????????????????
     *
     * @param call
     * @param result
     */
    public synchronized void openDetail(MethodCall call, MethodChannel.Result result) {
        String id = call.argument("id");
        String pid = call.argument("pid");
        String relationId = call.argument("relationId");
        String url = call.argument("url");
        Log.d("substring", "openDetail" + id);
        Log.d("substring", "openDetail" + pid);
        Log.d("substring", "openDetail" + relationId);
        Log.d("substring", "openDetail" + url);
        AlibcBizParams alibcBizParams = new AlibcBizParams();
        // ??????????????????
        HashMap<String, String> extMap = new HashMap<>();
        // ???????????????id???????????????????????????id???
//        extMap.put("id", id);
        alibcBizParams.setId(id);
        alibcBizParams.setExtParams(extMap);
        AlibcShowParams showParams = new AlibcShowParams();
        showParams.setOpenType(OpenType.Auto);
        showParams.setClientType("taobao");
        showParams.setBackUrl("szmf://");
        showParams.setNewWindow(true);
        AlibcTaokeParams alibcTaokeParams = new AlibcTaokeParams(pid);
        alibcTaokeParams.pid = pid;
        alibcTaokeParams.materialSourceUrl = url;
        if (!TextUtils.isEmpty(relationId)) {
            alibcTaokeParams.relationId = relationId;
        }
        Map<String, String> trackParams = new HashMap<>(16);
        if (!TextUtils.isEmpty(url)) {
            if (!url.contains("http")) {
                url = url.replace("//uland", "http://uland");
            }
            showParams.setDegradeType(AlibcDegradeType.Download);
            showParams.setDegradeUrl(url);
            AlibcTrade.openByUrl(mActivity, url, showParams, alibcTaokeParams, trackParams, new AlibcTradeCallback() {
                @Override
                public void onSuccess(int i, Object o) {
                    Log.d("substring", "openByUrl success: code = " + i);
                    JSONObject mJSONObject = new JSONObject();
                    mJSONObject.put("code", "00000");
                    mJSONObject.put("message", o + "");
                    mJSONObject.put("payload", "");
                    result.success(mJSONObject);
                }

                @Override
                public void onFailure(int i, String s) {
                    Log.d("substring", "openByUrl fail: code = " + i + ", msg = " + s);
                    JSONObject mJSONObject = new JSONObject();
                    mJSONObject.put("code", i);
                    mJSONObject.put("message", s);
                    mJSONObject.put("payload", "");
                    result.success(mJSONObject);
                }
            });
        } else {
            String codeDetail = "suite://bc.suite.basic/bc.template.detail";
            AlibcTrade.openByCode(mActivity, codeDetail, alibcBizParams, showParams,
                    alibcTaokeParams, trackParams, new AlibcTradeCallback() {
                        @Override
                        public void onSuccess(int i, Object o) {
                            Log.d("substring", "openByCode success: code = " + i);
                            JSONObject mJSONObject = new JSONObject();
                            mJSONObject.put("code", "00000");
                            mJSONObject.put("message", o + "");
                            mJSONObject.put("payload", "");
                            result.success(mJSONObject);
                        }

                        @Override
                        public void onFailure(int i, String s) {
                            Log.d("substring", "openByCode fail: code = " + i + ", msg = " + s);
                            JSONObject mJSONObject = new JSONObject();
                            mJSONObject.put("code", i);
                            mJSONObject.put("message", s);
                            mJSONObject.put("payload", "");
                            result.success(mJSONObject);
                        }
                    });
        }
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        channel.setMethodCallHandler(null);
    }

    @Override
    public void onAttachedToActivity(@NonNull ActivityPluginBinding binding) {
        mActivity = binding.getActivity();
    }

    @Override
    public void onDetachedFromActivityForConfigChanges() {
    }

    @Override
    public void onReattachedToActivityForConfigChanges(@NonNull ActivityPluginBinding binding) {
    }

    @Override
    public void onDetachedFromActivity() {
    }
}
