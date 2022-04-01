//
//  TradeViewController.swift
//  flutter_baichuan
//
//  Created by dmcb on 2021/8/26.
//

import UIKit

class TradeViewController: UIViewController {
    
    var call: FlutterMethodCall
    
    init(call: FlutterMethodCall) {
        self.call = call
        super.init(nibName: nil, bundle: nil)
    }
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = .white;
        if #available(iOS 13.0, *) {
            self.navigationController?.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .close, target: self, action: #selector(back))
        } else {
            self.navigationController?.navigationItem.leftBarButtonItem = UIBarButtonItem(title: "返回", style: .done, target: self, action: #selector(back))
            // Fallback on earlier versions
        }
        
        openUrl()
    }
    
    @objc func back(){
        self.navigationController?.dismiss(animated: true, completion: nil)
    }
    
    func openUrl(){
        
        let urlP = AlibcTradeUrlParams()
        // 商品id
        urlP.id = call.getString(key: "id")

        let showP = AlibcTradeShowParams()
        showP.linkKey = "taobao"
        showP.isPushBCWebView = false

        let taokeP = AlibcTradeTaokeParams()
        // 淘客ID
        taokeP.pid = call.getString(key: "pid")
        // 渠道id
        taokeP.relationId = call.getString(key: "relationId")
        
        AlibcTradeUltimateSDK.sharedInstance().tradeService().openTradePage(byCode: "suite://bc.suite.live/bc.template.live.list", parentController: self.navigationController, urlParams: urlP, showParams: showP, taoKeParams: taokeP, trackParam: [:]) { error, data in

            print("--openByCode--",error ?? "--", data ?? [:])
        }
    }
    
}
