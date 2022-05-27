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

        } else if call.method == "authLogin" {
            handle?.authLogin(call, result: result)

        } else if call.method == "getUtdid" {
            handle?.getUtdid(call, result: result)

        } else if call.method == "getUserInfo" {
            handle?.getUserInfo(call, result: result)

        } else if call.method == "logout" {
            handle?.logout(call, result: result)

        } else if call.method == "isLogin" {
            handle?.isLogin(call, result: result)

        } else if call.method == "openByCode" {
            handle?.openByCode(call, result: result)

        } else if call.method == "openByUrl" {
            
            handle?.openByUrl(call, result: result)
            
        } else if call.method == "getAccessToken" {
            
            handle?.getAccessToken(call, result: result)
            
        }
    }
}
