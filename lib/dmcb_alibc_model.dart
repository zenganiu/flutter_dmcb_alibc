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

class DmcbAlibcUser {
  final String? nick;
  final String? avatarUrl;
  final String? openId;
  final String? openSid;
  final String? topAccessToken;
  final String? topAuthCode;
  DmcbAlibcUser({
    this.nick,
    this.avatarUrl,
    this.openId,
    this.openSid,
    this.topAccessToken,
    this.topAuthCode,
  });

  DmcbAlibcUser.fromJson(Map? js)
      : nick = _getValueByJson<String>(js?['nick']),
        avatarUrl = _getValueByJson<String>(js?['avatarUrl']),
        openId = _getValueByJson<String>(js?['openId']),
        openSid = _getValueByJson<String>(js?['openSid']),
        topAccessToken = _getValueByJson<String>(js?['topAccessToken']),
        topAuthCode = _getValueByJson<String>(js?['topAuthCode']);
}

T? _getPayloadModel<T>(dynamic value) {
  T? result;
  if (value is Map) {
    if (T == DmcbAlibcUser) {
      result = DmcbAlibcUser.fromJson(value) as T?;
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
