#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint flutter_dmcb_alibc.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'flutter_dmcb_alibc'
  s.version          = '0.0.1'
  s.summary          = 'Flutter 百川电商SDK插件'
  s.description      = <<-DESC
A new Flutter project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '10.0'

  s.dependency 'SSZipArchive','2.4.3'
  s.dependency 'SDWebImage','5.12.5'
  s.dependency 'Masonry','1.1.0'
  s.dependency 'FMDB','2.7.5'
  s.dependency 'Reachability','3.2'
  s.dependency 'SocketRocket','0.6.0'

  s.vendored_frameworks = "framework/AliAuthSDK/AlibabaAuthEntrance.framework","framework/AliAuthSDK/AlibabaAuthExt.framework","framework/AliAuthSDK/AlibabaAuthSDK.framework","framework/AlibcTradeUltimateSDK/AlibcTradeBaseContainer.framework","framework/AlibcTradeUltimateSDK/AlibcTradeCommonSDK.framework","framework/AlibcTradeUltimateSDK/AlibcTradeContainer.framework","framework/AlibcTradeUltimateSDK/AlibcTrademiniAppContainer.framework","framework/AlibcTradeUltimateSDK/AlibcTradeUltimateBizSDK.framework","framework/AlibcTradeUltimateSDK/AlibcTradeUltimateSDK.framework","framework/AlibcTradeUltimateSDK/AlibcTradeWebViewContainer.framework","framework/AlibcTradeUltimateSDK/MunionBcAdSDK.framework","framework/applink/AlibcLinkPartnerSDK.framework","framework/Ariver/AriverApi.framework","framework/Ariver/AriverApp.framework","framework/Ariver/AriverAuth.framework","framework/Ariver/AriverConfig.framework","framework/Ariver/AriverDevice.framework","framework/Ariver/AriverDeviceCore.framework","framework/Ariver/AriverFileManager.framework","framework/Ariver/AriverKernel.framework","framework/Ariver/AriverLogger.framework","framework/Ariver/AriverResource.framework","framework/Ariver/AriverRuntime.framework","framework/Ariver/AriverSecurity.framework","framework/Ariver/AriverWebSocket.framework","framework/BCUserTrack/UT.framework","framework/BCUserTrack/UT_AppMonitor.framework","framework/BCUserTrack/UT_Common.framework","framework/BCUserTrack/UT_Core.framework","framework/DWInteractiveSDK/AliHADeviceEvaluation.framework","framework/DWInteractiveSDK/AliReachability.framework","framework/DWInteractiveSDK/DWInteractiveSDK.framework","framework/miniAppMediaSDK/AliWindmillImage.framework","framework/mtopSDK/mtopcoreopen.framework","framework/mtopSDK/mtopext.framework","framework/mtopSDK/MtopSDK.framework","framework/securityGuard/SecurityGuardSDK.framework","framework/securityGuard/SGIndieKit.framework","framework/securityGuard/SGMain.framework","framework/securityGuard/SGMiddleTier.framework","framework/securityGuard/SGNoCaptcha.framework","framework/securityGuard/SGSecurityBody.framework","framework/TBMediaPlayer/TBMediaPlayer.framework","framework/TBMediaPlayer/TBMediaPlayerBundle.framework","framework/TBMediaPlayer/TBModuleHub.framework","framework/Triver/TriverAPI.framework","framework/Triver/TriverAppContainer.framework","framework/Triver/TriverCapability.framework","framework/Triver/TriverDebugTool.framework","framework/Triver/TriverLivePlayer.framework","framework/Triver/TriverLocalDebug.framework","framework/Triver/TriverRuntime.framework","framework/Triver/TriverVideo.framework","framework/Triver/TriverVideoEnhance.framework","framework/UTDID/UTDID.framework","framework/Windmill/WindmillTRiverKit.framework","framework/Windmill/WindmillWeaver.framework","framework/WindMix/AliRemoteDebugInterface.framework","framework/WindMix/RiverLogger.framework","framework/WindMix/WindMix.framework","framework/WindVane/WindVane.framework","framework/WindVane/WindVaneBasic.framework","framework/WindVane/WindVaneCore.framework"
  s.frameworks = 'AssetsLibrary', 'CoreMotion', 'Contacts','ContactsUI','AddressBook','AddressBookUI','JavaScriptCore'
  s.libraries = 'resolv','c++','icucore'
  s.resources = ['bundle/*.bundle']

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end
