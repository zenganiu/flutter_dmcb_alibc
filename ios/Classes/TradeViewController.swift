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
        view.backgroundColor = .white
        if #available(iOS 13.0, *) {
            self.navigationController?.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .close, target: self, action: #selector(back))
        } else {
            navigationController?.navigationItem.leftBarButtonItem = UIBarButtonItem(title: "返回", style: .done, target: self, action: #selector(back))
            // Fallback on earlier versions
        }

        openUrl()
    }

    @objc func back() {
        navigationController?.dismiss(animated: true, completion: nil)
    }

    func openUrl() {
        let urlP = AlibcTradeUrlParams()
        // 商品id
        urlP.id = call.getString(key: "id") ?? ""

        let showP = AlibcTradeShowParams()
        showP.linkKey = "taobao"
        showP.isPushBCWebView = false

        let taokeP = AlibcTradeTaokeParams()
        // 淘客ID
        taokeP.pid = call.getString(key: "pid") ?? ""
        // 渠道id
        taokeP.relationId = call.getString(key: "relationId") ?? ""

        AlibcTradeUltimateSDK.sharedInstance()
            .tradeService()
            .openTradePage(byCode: "suite://bc.suite.live/bc.template.live.list",
                           parentController: navigationController,
                           urlParams: urlP,
                           showParams: showP,
                           taoKeParams: taokeP,
                           trackParam: [:]) { error, data in

                printLog("--openByCode--", error ?? "--", data ?? [:])
            }
    }
}

// final list = <String>[
//   ///AliAuthSDK
//   'framework/AliAuthSDK/AlibabaAuthEntrance.framework',
//   'framework/AliAuthSDK/AlibabaAuthExt.framework',
//   'framework/AliAuthSDK/AlibabaAuthSDK.framework',
//
//   /// AlibcTradeUltimateSDK
//   'framework/AlibcTradeUltimateSDK/AlibcTradeBaseContainer.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTradeCommonSDK.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTradeContainer.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTrademiniAppContainer.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTradeUltimateBizSDK.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTradeUltimateSDK.framework',
//   'framework/AlibcTradeUltimateSDK/AlibcTradeWebViewContainer.framework',
//   'framework/AlibcTradeUltimateSDK/MunionBcAdSDK.framework',
//
//   /// applink
//   'framework/applink/AlibcLinkPartnerSDK.framework',
//
//   /// Ariver
//   'framework/Ariver/AriverApi.framework',
//   'framework/Ariver/AriverApp.framework',
//   'framework/Ariver/AriverAuth.framework',
//   'framework/Ariver/AriverConfig.framework',
//   'framework/Ariver/AriverDevice.framework',
//   'framework/Ariver/AriverDeviceCore.framework',
//   'framework/Ariver/AriverFileManager.framework',
//   'framework/Ariver/AriverKernel.framework',
//   'framework/Ariver/AriverLogger.framework',
//   'framework/Ariver/AriverResource.framework',
//   'framework/Ariver/AriverRuntime.framework',
//   'framework/Ariver/AriverSecurity.framework',
//   'framework/Ariver/AriverWebSocket.framework',
//
//   /// BCUserTrack
//   'framework/BCUserTrack/UT.framework',
//   'framework/BCUserTrack/UT_AppMonitor.framework',
//   'framework/BCUserTrack/UT_Common.framework',
//   'framework/BCUserTrack/UT_Core.framework',
//
//   /// DWInteractiveSDK
//   'framework/DWInteractiveSDK/AliHADeviceEvaluation.framework',
//   'framework/DWInteractiveSDK/AliReachability.framework',
//   'framework/DWInteractiveSDK/DWInteractiveSDK.framework',
//
//   /// miniAppMediaSDK
//   'framework/miniAppMediaSDK/AliWindmillImage.framework',
//
//   /// mtopSDK
//   'framework/mtopSDK/mtopcoreopen.framework',
//   'framework/mtopSDK/mtopext.framework',
//   'framework/mtopSDK/MtopSDK.framework',
//
//   /// MunionBcAdSDK
//   'framework/MunionBcAdSDK/MunionBcAdSDK.framework',
//
//   /// securityGuard
//   'framework/securityGuard/SecurityGuardSDK.framework',
//   'framework/securityGuard/SGIndieKit.framework',
//   'framework/securityGuard/SGMain.framework',
//   'framework/securityGuard/SGMiddleTier.framework',
//   'framework/securityGuard/SGNoCaptcha.framework',
//   'framework/securityGuard/SGSecurityBody.framework',
//
//   /// TBMediaPlayer
//   'framework/TBMediaPlayer/TBMediaPlayer.framework',
//   'framework/TBMediaPlayer/TBMediaPlayerBundle.framework',
//   'framework/TBMediaPlayer/TBModuleHub.framework',
//
//   /// Triver
//   'framework/Triver/TriverAPI.framework',
//   'framework/Triver/TriverAppContainer.framework',
//   'framework/Triver/TriverCapability.framework',
//   'framework/Triver/TriverDebugTool.framework',
//   'framework/Triver/TriverLivePlayer.framework',
//   'framework/Triver/TriverLocalDebug.framework',
//   'framework/Triver/TriverRuntime.framework',
//   'framework/Triver/TriverVideo.framework',
//   'framework/Triver/TriverVideoEnhance.framework',
//
//   ///UTDID
//   'framework/UTDID/UTDID.framework',
//
//   /// Windmill
//   'framework/Windmill/WindmillTRiverKit.framework',
//   'framework/Windmill/WindmillWeaver.framework',
//
//   ///WindMix
//   'framework/WindMix/AliRemoteDebugInterface.framework',
//   'framework/WindMix/RiverLogger.framework',
//   'framework/WindMix/WindMix.framework',
//
//   /// WindVane
//   'framework/WindVane/WindVane.framework',
//   'framework/WindVane/WindVaneBasic.framework',
//   'framework/WindVane/WindVaneCore.framework',
// ];
