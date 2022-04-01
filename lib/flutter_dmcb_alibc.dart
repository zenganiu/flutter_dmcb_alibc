import 'dart:async';

import 'package:flutter/services.dart';

class FlutterDmcbAlibc {
  static const MethodChannel _channel = MethodChannel('flutter_dmcb_alibc');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
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
