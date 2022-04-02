import 'dart:async';

import 'package:flutter/services.dart';

class FlutterDmcbAlibc {
  static const MethodChannel _channel = MethodChannel('flutter_dmcb_alibc');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }


  /// 初始化百川电商SDK
  static Future<String?> initAlibc() async {
    final String? version = await _channel.invokeMethod('initAlibc');
    return version;
  }

  /// 初始化百川电商SDK
  static Future<String?> login() async {
    final String? version = await _channel.invokeMethod('loginTaoBao');
    return version;
  }


}
