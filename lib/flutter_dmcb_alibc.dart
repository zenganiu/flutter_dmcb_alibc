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
  ///
  /// 若已授权将不会调起淘宝授权，直接返回用户信息
  static Future<DmcbAlibcModel<DmcbAlibcUser>> authLogin() async {
    final json = await _channel.invokeMethod<Map>('authLogin');
    final model = DmcbAlibcModel<DmcbAlibcUser>.formJson(json);
    return model;
  }

  /// TOP授权获取token
  ///
  /// [appKey] appkey
  /// [appName] 应用名称
  /// [appLogo] app图标
  static Future<DmcbAlibcModel<DmcbAlibcAccessToken>> getAccessToken({
    required String appKey,
    required String appName,
    required String appLogo,
  }) async {
    final json = await _channel.invokeMethod('getAccessToken', {
      'appKey': appKey,
      'appName': appName,
      'appLogo': appLogo,
    });
    final data = DmcbAlibcModel<DmcbAlibcAccessToken>.formJson(json);
    return data;
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

  /// 已登录时获取授权登录用户信息
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
  ///
  /// 关于直接打开s.click链接分佣说明
  /// 百川SDK不支持s.click（或uland）链接的二次转链逻辑，如果采用openByUrl方式打开该类链接，请勿传入pid等分佣参数；
  /// 若需要使用其他渠道获取的s.click链接进行分佣，可自行去淘客联盟后台生成自己的s.click链接或调用联盟服务接口生成。
  /// [url] url
  /// [id] 商品id
  /// [pid] 淘客ID
  /// [relationId] 渠道id
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
