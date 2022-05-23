import 'dart:async';
import 'package:flutter/services.dart';

import 'dmcb_alibc_model.dart';

/// 淘宝客插件
class FlutterDmcbAlibc {
  static const MethodChannel _channel = MethodChannel('flutter_dmcb_alibc');

  /// 获取系统版本
  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  /// 初始化百川电商SDK
  static Future<DmcbAlibcModel> initAlibc() async {
    final json = await _channel.invokeMethod<Map>('initAlibc');
    final model = DmcbAlibcModel.formJson(json);
    return model;
  }

  /// 授权登录
  static Future<DmcbAlibcModel<DmcbAlibcUser>> authLogin() async {
    final json = await _channel.invokeMethod<Map>('authLogin');
    final model = DmcbAlibcModel<DmcbAlibcUser>.formJson(json);
    return model;
  }

  /// 获取Utdid
  static Future<String> getUtdid() async {
    String result = await _channel.invokeMethod("getUtdid");
    return result;
  }

  /// 退出登录
  static void logout() {
    _channel.invokeMethod('logout');
  }

  /// 是否已登录
  static Future<bool> isLogin() async {
    final bool? result = await _channel.invokeMethod('isLogin');
    return result == true;
  }

  static Future<DmcbAlibcModel<DmcbAlibcUser>> getUserInfo() async {
    final json = await _channel.invokeMethod<Map>('getUserInfo');
    final model = DmcbAlibcModel<DmcbAlibcUser>.formJson(json);
    return model;
  }

  /// 通过code打开商品
  ///
  /// [id] 商品id
  /// [pid] 淘客ID
  /// [relationId] 渠道id
  static Future<DmcbAlibcModel> openByCode({
    required String id,
    required String pid,
    required String relationId,
  }) async {
    final json = await _channel.invokeMethod<Map>('openByCode', {
      "id": id,
      'pid': pid,
      'relationId': relationId,
    });
    final model = DmcbAlibcModel.formJson(json);
    return model;
  }

  /// 通过URL打开商品
  static Future<DmcbAlibcModel> openByUrl({
    required String url,
    required String id,
    required String pid,
    required String relationId,
  }) async {
    final json = await _channel.invokeMethod<Map>('openByUrl', {
      "url": url,
      "id": id,
      'pid': pid,
      'relationId': relationId,
    });
    final model = DmcbAlibcModel.formJson(json);
    return model;
  }
}
