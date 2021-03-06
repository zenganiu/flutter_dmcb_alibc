import 'dart:convert' as convert;

class DmcbAlibcModel<T> {
  /// 状态码，成功为：'00000'
  String code;
  String message;
  T? payload;

  bool get isSuccess => code == '00000';

  DmcbAlibcModel({required this.code, this.message = '', this.payload});

  DmcbAlibcModel.formJson(Map? js)
      : code = _getValueByJson<String>(js?['code']) ?? '-99999',
        message = _getValueByJson<String>(js?['message']) ?? '未知数据',
        payload = _getPayloadModel<T>(js?['payload']);

  @override
  String toString() {
    final list = {'code': code, 'message': message, 'payload': payload.toString()};
    return convert.jsonEncode(list);
  }
}

/// 用户信息
class DmcbAlibcUser {
  /// 昵称
  final String? nick;

  /// 头像
  final String? avatarUrl;

  /// openId
  final String? openId;

  /// openSid
  final String? openSid;

  /// topAccessToken
  final String? topAccessToken;

  /// topAuthCode
  final String? topAuthCode;

  /// 构造函数
  DmcbAlibcUser({
    this.nick,
    this.avatarUrl,
    this.openId,
    this.openSid,
    this.topAccessToken,
    this.topAuthCode,
  });

  /// 从json数据中构建
  DmcbAlibcUser.fromJson(Map? js)
      : nick = _getValueByJson<String>(js?['nick']),
        avatarUrl = _getValueByJson<String>(js?['avatarUrl']),
        openId = _getValueByJson<String>(js?['openId']),
        openSid = _getValueByJson<String>(js?['openSid']),
        topAccessToken = _getValueByJson<String>(js?['topAccessToken']),
        topAuthCode = _getValueByJson<String>(js?['topAuthCode']);

  @override
  String toString() {
    final list = {
      'nick': nick,
      'avatarUrl': avatarUrl,
      'openId': openId,
      'openSid': openSid,
      'topAccessToken': topAccessToken,
      'topAuthCode': topAuthCode,
    };
    return convert.jsonEncode(list);
  }
}

/// 用户授权token信息
class DmcbAlibcAccessToken {
  /// token
  final String? accessToken;

  /// 失效时间： 单位秒
  final String? expire;

  DmcbAlibcAccessToken({this.accessToken, this.expire});

  /// 从json数据中构建
  DmcbAlibcAccessToken.fromJson(Map? js)
      : accessToken = _getValueByJson<String>(js?['accessToken']),
        expire = _getValueByJson<String>(js?['expire']);

  @override
  String toString() {
    final list = {
      'accessToken': accessToken,
      'expire': expire,
    };
    return convert.jsonEncode(list);
  }
}

T? _getPayloadModel<T>(dynamic value) {
  T? result;
  if (value is Map) {
    if (T == DmcbAlibcUser) {
      result = DmcbAlibcUser.fromJson(value) as T?;
    } else if (T == DmcbAlibcAccessToken) {
      result = DmcbAlibcAccessToken.fromJson(value) as T?;
    }
  }
  return result;
}

T? _getValueByJson<T>(dynamic value) {
  if (value is T) {
    return value;
  } else {
    return null;
  }
}
