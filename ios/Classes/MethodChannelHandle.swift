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
            let dic: [String: Any] = [codeKey: "00000", messageKey: "百川电商SDK初始化成功", dataKey: ["utdid": UTDevice.utdid()]]
            result(dic)

        } failure: { error in
            let code = (error as NSError).code
            let msg = error.localizedDescription
            let dic: [String: Any] = [codeKey: "\(code)", messageKey: "百川电商SDK初始化失败: \(msg)", dataKey: ["utdid": UTDevice.utdid()]]
            result(dic)
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
