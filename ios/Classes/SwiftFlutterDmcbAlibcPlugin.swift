import Flutter
import UIKit

public class SwiftFlutterDmcbAlibcPlugin: NSObject, FlutterPlugin {
    var handle: MethodChannelHandle?

    public static func register(with registrar: FlutterPluginRegistrar) {
        let channel = FlutterMethodChannel(name: "flutter_dmcb_alibc", binaryMessenger: registrar.messenger())
        let instance = SwiftFlutterDmcbAlibcPlugin()
        instance.handle = MethodChannelHandle(channel: channel)
        registrar.addMethodCallDelegate(instance, channel: channel)
    }

    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        if call.method == "getPlatformVersion" {
            result("iOS " + UIDevice.current.systemVersion)
        } else if call.method == "initAlibc" {
            handle?.initAlibc(call: call, result: result)
        } else if call.method == "login"{
            
        }
    }
}
