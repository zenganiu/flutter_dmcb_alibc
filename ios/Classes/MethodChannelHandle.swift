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

            #if DEBUG
                AlibcTradeUltimateSDK.sharedInstance().enableLocalDebug(true)
                AlibcTradeUltimateSDK.sharedInstance().setDebugLogOpen(true)
            #endif
            let dic: [String: Any] = [codeKey: code_success, messageKey: "百川电商SDK初始化成功", dataKey: ["utdid": UTDevice.utdid()]]
            result(dic)

        } failure: { error in
            let code = (error as NSError).code
            let msg = error.localizedDescription
            let dic: [String: Any] = [codeKey: "\(code)", messageKey: "百川电商SDK初始化失败: \(msg)", dataKey: ["utdid": UTDevice.utdid()]]
            result(dic)
        }
    }
    
    /// 淘宝授权登录
    func authLogin(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let isLogin = loginService.isLogin()
        if isLogin {
            let userInfo = loginService.getUser()
            let dict: Dictionary<String, Any> = [
                codeKey: code_success,
                messageKey: "success",
                dataKey: [
                    "nick": userInfo?.nick ?? "",
                    "avatarUrl": userInfo?.avatarUrl ?? "",
                    "openId": userInfo?.openId ?? "",
                    "openSid": userInfo?.openSid ?? "",
                    "topAccessToken": userInfo?.topAccessToken ?? "",
                    "topAuthCode": userInfo?.topAuthCode ?? ""],
            ]

            #if DEBUG
                print("loginTaoBao-userInfo", dict)
            #endif
            result(dict)

        } else {
            loginService.setH5Only(false)
            loginService.auth(rootViewController) { userInfo in

                let dict: Dictionary<String, Any> = [
                    codeKey: code_success,
                    messageKey: "success",
                    dataKey: [
                        "nick": userInfo?.nick ?? "",
                        "avatarUrl": userInfo?.avatarUrl ?? "",
                        "openId": userInfo?.openId ?? "",
                        "openSid": userInfo?.openSid ?? "",
                        "topAccessToken": userInfo?.topAccessToken ?? "",
                        "topAuthCode": userInfo?.topAuthCode ?? ""],
                ]
                #if DEBUG
                    print("loginTaoBao-userInfo", dict)
                #endif

                result(dict)

            } failure: { error in

                let errorCode = (error as NSError?)?.code ?? -1
                let errorMsg = error?.localizedDescription ?? "淘宝授权登录失败"
                let dic = [codeKey: "\(errorCode)", messageKey: errorMsg]
                result(dic)
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
