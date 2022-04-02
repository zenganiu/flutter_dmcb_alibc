import 'dart:async';
import 'package:flutter/services.dart';

class FlutterDmcbAlibc {
  static const MethodChannel _channel = MethodChannel('flutter_dmcb_alibc');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  /// 初始化百川电商SDK
  static Future<dynamic?> initAlibc() async {
    var version = await _channel.invokeMethod('initAlibc');
    return version;
  }

  /// 授权登录
  static Future<Map?> authLogin() async {
    final Map? result = await _channel.invokeMethod('authLogin');
    return result;
  }

  /// 获取Utdid
  static Future<String> getUtdid() async {
    String result = await _channel.invokeMethod("getUtdid");
    return result;
  }

  /// 退出登录
  static void loignOut() {
    _channel.invokeMethod('loginOut');
  }

  /// 是否已登录
  static Future<bool> isLogin() async {
    final bool? result = await _channel.invokeMethod('isLogin');
    return result == true;
  }

  /// 打开商品
  ///
  /// [id] 商品id
  /// [pid] 淘客ID
  /// [relationId] 渠道id
  static Future openByCode({
    required String id,
    required String pid,
    required String relationId,
  }) async {
    _channel.invokeMethod('openByCode', {"id": id, 'pid': pid, 'relationId': relationId});
  }

  static void openByUrl({
    required String url,
    required String id,
    required String pid,
    required String relationId,
  }) {
    _channel.invokeMethod('openByUrl', {"url": url, "id": id, 'pid': pid, 'relationId': relationId});
  }
}
