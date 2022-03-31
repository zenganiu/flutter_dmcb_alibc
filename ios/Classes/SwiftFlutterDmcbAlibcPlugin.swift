import Flutter
import UIKit

public class SwiftFlutterDmcbAlibcPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "flutter_dmcb_alibc", binaryMessenger: registrar.messenger())
    let instance = SwiftFlutterDmcbAlibcPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    result("iOS " + UIDevice.current.systemVersion)
  }
}
