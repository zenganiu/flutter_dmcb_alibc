//
//  ExFlutterMethodCall.swift
//  flutter_dmcb_alibc
//
//  Created by dmcb on 2022/5/23.
//

import Flutter
import Foundation

private let codeKey = "code"
private let messageKey = "message"
private let dataKey = "payload"
private let code_success = "00000"

internal struct MyResult {
    var code: String
    var message: String
    var payload: Dictionary<String, Any>?

    func toDictionary() -> Dictionary<String, Any> {
        var dict: Dictionary<String, Any> = [:]
        dict[codeKey] = code
        dict[messageKey] = message
        dict[dataKey] = payload ?? [:]
        return dict
    }

    static func success(message: String, payload: Dictionary<String, Any>? = nil) -> Dictionary<String, Any> {
        return MyResult(code: code_success, message: message, payload: payload).toDictionary()
    }

    static func error(code: String = "-1", message: String, payload: Dictionary<String, Any>? = nil) -> Dictionary<String, Any> {
        assert(code != code_success, "状态码不能为\(code_success)")
        return MyResult(code: code, message: message, payload: payload).toDictionary()
    }
}

internal func printLog(_ items: Any..., callback: (() -> Void)? = nil) {
    #if DEBUG
        callback?()
        print(items)
    #endif
}

internal extension FlutterMethodCall {
    func getValue<T>(key: String) -> T? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? T else {
            return nil
        }
        return result
    }

    func getNumber(key: String) -> NSNumber? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? NSNumber else {
            return nil
        }
        return result
    }

    func getString(key: String) -> String? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? String else {
            return nil
        }
        return result
    }

    func getBool(key: String) -> Bool? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? Bool else {
            return nil
        }
        return result
    }

    func getInt(key: String) -> Int? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? Int else {
            return nil
        }
        return result
    }

    func getDouble(key: String) -> Double? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? Double else {
            return nil
        }
        return result
    }

    func getDict(key: String) -> Dictionary<String, Any>? {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? Dictionary<String, Any> else {
            return nil
        }
        return result
    }
}
