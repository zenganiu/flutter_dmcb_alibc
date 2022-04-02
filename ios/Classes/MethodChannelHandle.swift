//
//  MethodChannelHandle.swift
//  flutter_dmcb_alibc
//
//  Created by dmcb on 2022/4/1.
//

import Foundation
import WindmillWeaver

private let codeKey = "code"
private let messageKey = "message"
private let dataKey = "payload"
private let code_success = "00000"

class MethodChannelHandle: NSObject {
    private var channel: FlutterMethodChannel?
    init(channel: FlutterMethodChannel) {
        super.init()
        self.channel = channel
    }

    var loginService: AlibcTradeUltimateLoginService {
        return AlibcTradeUltimateSDK.sharedInstance().loginService()
    }

    var rootViewController: UIViewController {
        if let rootVC = UIApplication.shared.windows.first?.rootViewController {
            return rootVC
        }
        if let rootVC = UIApplication.shared.keyWindow?.rootViewController {
            return rootVC
        }
        return UIViewController()
    }

    /// 百川电商SDK初始化
    func initAlibc(call: FlutterMethodCall, result: @escaping FlutterResult) {
        AlibcTradeUltimateSDK.sharedInstance().asyncInit {
            WMLHandlerFactory.registerHandler(ALITradeDemoZipArchiver(), with: TRVZipArchiveProtocol.self)
            let dict: [String: Any] = [codeKey: code_success, messageKey: "百川电商SDK初始化成功"]
            #if DEBUG
                AlibcTradeUltimateSDK.sharedInstance().enableLocalDebug(true)
                AlibcTradeUltimateSDK.sharedInstance().setDebugLogOpen(true)
                print("--Alibc--initAlibc", dict)
            #endif

            result(dict)

        } failure: { error in
            let code = (error as NSError).code
            let msg = error.localizedDescription
            let dict: [String: Any] = [codeKey: "\(code)", messageKey: "百川电商SDK初始化失败: \(msg)"]
            #if DEBUG
                print("--Alibc--initAlibc", dict)
            #endif
            result(dict)
        }
    }

    /// 获取用户信息
    func getUserInfo(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let isLogin = loginService.isLogin()
        if isLogin {
            let userInfo = loginService.getUser()
            let dict: Dictionary<String, Any> = [
                codeKey: code_success,
                messageKey: "获取成功",
                dataKey: [
                    "nick": userInfo?.nick ?? "",
                    "avatarUrl": userInfo?.avatarUrl ?? "",
                    "openId": userInfo?.openId ?? "",
                    "openSid": userInfo?.openSid ?? "",
                    "topAccessToken": userInfo?.topAccessToken ?? "",
                    "topAuthCode": userInfo?.topAuthCode ?? ""],
            ]

            #if DEBUG
                print("--Alibc--getUserInfo", dict)
            #endif
            result(dict)
        } else {
            let dict: Dictionary<String, Any> = [
                codeKey: "-1",
                messageKey: "用户未登录",
            ]
            #if DEBUG
                print("--Alibc--getUserInfo", dict)
            #endif
            result(dict)
        }
    }

    /// 淘宝授权登录
    func authLogin(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        loginService.setH5Only(false)
        loginService.auth(rootViewController) { userInfo in

            let dict: Dictionary<String, Any> = [
                codeKey: code_success,
                messageKey: "用户授权登录",
                dataKey: [
                    "nick": userInfo?.nick ?? "",
                    "avatarUrl": userInfo?.avatarUrl ?? "",
                    "openId": userInfo?.openId ?? "",
                    "openSid": userInfo?.openSid ?? "",
                    "topAccessToken": userInfo?.topAccessToken ?? "",
                    "topAuthCode": userInfo?.topAuthCode ?? ""],
            ]
            #if DEBUG
                print("--Alibc--authLogin", dict)
            #endif

            result(dict)

        } failure: { error in

            let errorCode = (error as NSError?)?.code ?? -1
            let errorMsg = error?.localizedDescription ?? "淘宝授权登录失败"
            let dict = [codeKey: "\(errorCode)", messageKey: errorMsg]
            #if DEBUG
                print("--Alibc--authLogin", dict)
            #endif
            result(dict)
        }
    }

    /// 是否已登录
    func isLogin(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let state = loginService.isLogin()
        #if DEBUG
            print("--Alibc--isLogin", state)
        #endif
        result(state)
    }

    /// 获取Utdid
    func getUtdid(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let utdid = UTDevice.utdid()
        #if DEBUG
            print("--Alibc--getUtdid", utdid)
        #endif
        result(utdid)
    }

    /// 退出登录
    func logout(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        loginService.logout()
        #if DEBUG
            print("--Alibc--logout")
        #endif
    }

    /// 打开商品详情通过code
    func openByCode(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        // 商品id
        let id = call.getString(key: "id")
        // 淘客ID
        let pid = call.getString(key: "pid")
        // 渠道id
        let relationId = call.getString(key: "relationId")

        let urlP = AlibcTradeUrlParams()
        urlP.id = id

        let showP = AlibcTradeShowParams()
        showP.linkKey = "taobao"
        showP.isPushBCWebView = false

        let taokeP = AlibcTradeTaokeParams()
        taokeP.pid = pid
        taokeP.relationId = relationId
        taokeP.materialSourceUrl = ""

        let code = "suite://bc.suite.basic/bc.template.detail"

        AlibcTradeUltimateSDK.sharedInstance().tradeService().openTradePage(byCode: code, parentController: rootViewController, urlParams: urlP, showParams: showP, taoKeParams: taokeP, trackParam: [:]) { error, data in

            #if DEBUG
                print("--Alibc--openByCode", error ?? "success", data ?? [:])
            #endif

            if let err = error {
                let code = (err as NSError).code
                let dict: [String: Any] = [codeKey: "\(code)", messageKey: err.localizedDescription]
                result(dict)

            } else {
                let dict: [String: Any] = [codeKey: code_success, messageKey: "打开成功"]
                result(dict)
            }
        }
    }

    /// 打开商品详情通过url
    func openByUrl(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let url = call.getString(key: "url")
        // 商品id
        let id = call.getString(key: "id")
        // 淘客ID
        let pid = call.getString(key: "pid")
        // 渠道id
        let relationId = call.getString(key: "relationId")

        let urlP = AlibcTradeUrlParams()
        urlP.id = id

        let showP = AlibcTradeShowParams()
        showP.linkKey = "taobao"
        showP.isPushBCWebView = false

        let taokeP = AlibcTradeTaokeParams()
        taokeP.pid = pid
        taokeP.relationId = relationId

        AlibcTradeUltimateSDK.sharedInstance().tradeService().openTradeUrl(url, parentController: rootViewController, showParams: showP, taoKeParams: taokeP, trackParam: [:]) { error, data in

            #if DEBUG
                print("--Alibc--openByUrl", error ?? "success", data ?? [:])
            #endif

            if let err = error {
                let code = (err as NSError).code
                let dict: [String: Any] = [codeKey: "\(code)", messageKey: err.localizedDescription]
                result(dict)
            } else {
                let dict: [String: Any] = [codeKey: code_success, messageKey: "打开成功"]
                result(dict)
            }
        }
    }
}

// 随便定义一个数组，如果等于他就是空
private let EmptyNum: NSNumber = NSNumber(integerLiteral: 5285)
extension FlutterMethodCall {
    func getString(key: String) -> String {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? String else {
            return ""
        }
        return result
    }

    func getNumber(key: String) -> NSNumber {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? NSNumber else {
            return EmptyNum
        }
        return result
    }

    func getBool(key: String) -> Bool {
        guard let result = (arguments as? Dictionary<String, Any>)?[key] as? Bool else {
            return false
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
