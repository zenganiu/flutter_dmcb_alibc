//
//  ALiTradeDemoURLHandler.swift
//  flutter_baichuan
//
//  Created by dmcb on 2021/8/26.
//

import Foundation
import AlibcTradeContainer

class ALiTradeDemoURLHandler: NSObject,AlibcTradeMiniAppURLRouterProtocol {
    func openURL(_ urlStr: String, on vc: UIViewController, withParam param: [AnyHashable : Any], animated: Bool) -> Bool {
        return false
    }
}
