//
//  MethodChannelHandle.swift
//  flutter_dmcb_alibc
//
//  Created by dmcb on 2022/4/1.
//

import Foundation
import WindmillWeaver

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

    // MARK: - - 百川电商SDK初始化

    /// 百川电商SDK初始化
    func initAlibc(call: FlutterMethodCall, result: @escaping FlutterResult) {
        AlibcTradeUltimateSDK.sharedInstance()
            .asyncInit {
                WMLHandlerFactory.registerHandler(ALITradeDemoZipArchiver(), with: TRVZipArchiveProtocol.self)

                let dict = MyResult.success(message: "百川电商SDK初始化成功")
                printLog("--Alibc--initAlibc", dict) {
                    AlibcTradeUltimateSDK.sharedInstance().enableLocalDebug(true)
                    AlibcTradeUltimateSDK.sharedInstance().setDebugLogOpen(true)
                }
                result(dict)

            } failure: { error in

                let code = (error as NSError).code
                let msg = error.localizedDescription
                let dict = MyResult.error(code: "\(code)", message: "百川电商SDK初始化失败: \(msg)")
                printLog("--Alibc--initAlibc", dict)

                result(dict)
            }
    }

    // MARK: - - 获取用户信息

    /// 获取用户信息
    func getUserInfo(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let isLogin = loginService.isLogin()
        if isLogin {
            let userInfo = loginService.getUser()
            let dict = MyResult.success(message: "获取成功",
                                        payload: [
                                            "nick": userInfo?.nick ?? "",
                                            "avatarUrl": userInfo?.avatarUrl ?? "",
                                            "openId": userInfo?.openId ?? "",
                                            "openSid": userInfo?.openSid ?? "",
                                            "topAccessToken": userInfo?.topAccessToken ?? "",
                                            "topAuthCode": userInfo?.topAuthCode ?? "",
                                        ])

            printLog("--Alibc--getUserInfo", dict)
            result(dict)

        } else {
            let dict = MyResult.error(message: "用户未登录")
            printLog("--Alibc--getUserInfo", dict)
            result(dict)
        }
    }

    // MARK: - - 淘宝授权登录

    /// 淘宝授权登录
    func authLogin(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        loginService.setH5Only(false)
        loginService.auth(rootViewController) { userInfo in

            let dict = MyResult.success(message: "用户授权登录成功",
                                        payload: [
                                            "nick": userInfo?.nick ?? "",
                                            "avatarUrl": userInfo?.avatarUrl ?? "",
                                            "openId": userInfo?.openId ?? "",
                                            "openSid": userInfo?.openSid ?? "",
                                            "topAccessToken": userInfo?.topAccessToken ?? "",
                                            "topAuthCode": userInfo?.topAuthCode ?? ""])

            printLog("--Alibc--authLogin", dict)
            result(dict)

        } failure: { error in

            let errorCode = (error as NSError?)?.code ?? -1
            let errorMsg = error?.localizedDescription ?? "淘宝授权登录失败"
            let dict = MyResult.error(code: "\(errorCode)", message: errorMsg)
            printLog("--Alibc--authLogin", dict)
            result(dict)
        }
    }

    // MARK: - - 是否已登录

    /// 是否已登录
    func isLogin(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let state = loginService.isLogin()
        printLog("--Alibc--isLogin", state)
        result(state)
    }

    // MARK: - - 获取Utdid

    /// 获取Utdid
    func getUtdid(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let utdid = UTDevice.utdid()
        printLog("--Alibc--getUtdid", utdid)
        result(utdid)
    }

    // MARK: - - 退出登录

    /// 退出登录
    func logout(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        loginService.logout()
        printLog("--Alibc--logout")
    }

    // MARK: - - 打开商品详情通过code

    /// 打开商品详情通过code
    func openByCode(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        // 商品id
        let id = call.getString(key: "id") ?? ""
        // 淘客ID
        let pid = call.getString(key: "pid") ?? ""
        // 渠道id
        let relationId = call.getString(key: "relationId") ?? ""

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

        AlibcTradeUltimateSDK.sharedInstance()
            .tradeService()
            .openTradePage(
                byCode: code,
                parentController: rootViewController,
                urlParams: urlP,
                showParams: showP,
                taoKeParams: taokeP,
                trackParam: [:]) { error, data in

                printLog("--Alibc--openByCode", error ?? "success", data ?? [:])

                if let err = error {
                    let code = (err as NSError).code
                    let dict = MyResult.error(code: "\(code)", message: err.localizedDescription)
                    result(dict)

                } else {
                    let dict = MyResult.success(message: "打开成功")
                    result(dict)
                }
            }
    }

    // MARK: - - 打开商品详情通过url

    /// 打开商品详情通过url
    func openByUrl(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        let url = call.getString(key: "url") ?? ""
        // 商品id
        let id = call.getString(key: "id") ?? ""
        // 淘客ID
        let pid = call.getString(key: "pid") ?? ""
        // 渠道id
        let relationId = call.getString(key: "relationId") ?? ""

        let urlP = AlibcTradeUrlParams()
        urlP.id = id

        let showP = AlibcTradeShowParams()
        showP.linkKey = "taobao"
        showP.isPushBCWebView = false

        let taokeP = AlibcTradeTaokeParams()
        taokeP.pid = pid
        taokeP.relationId = relationId

        AlibcTradeUltimateSDK
            .sharedInstance()
            .tradeService()
            .openTradeUrl(
                url,
                parentController: rootViewController,
                showParams: showP,
                taoKeParams: taokeP,
                trackParam: [:]) { error, data in

                printLog("--Alibc--openByUrl", error ?? "success", data ?? [:])

                if let err = error {
                    let code = (err as NSError).code
                    let dict = MyResult.error(code: "\(code)", message: err.localizedDescription)
                    result(dict)
                } else {
                    let dict = MyResult.success(message: "打开成功")
                    result(dict)
                }
            }
    }
}
