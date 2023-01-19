import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:flutter_dmcb_alibc/flutter_dmcb_alibc.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _platformVersion = 'Unknown';

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    final result = await FlutterDmcbAlibc.initAlibc();
    print(result);
    String platformVersion;
    try {
      platformVersion = await FlutterDmcbAlibc.platformVersion ?? 'Unknown platform version';
    } on PlatformException {
      platformVersion = 'Failed to get platform version.';
    }
    if (!mounted) return;

    setState(() {
      _platformVersion = platformVersion;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: SafeArea(
          child: SingleChildScrollView(
            child: Center(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: initAlibc, child: const Text('初始化')),
                  Text('Running on: $_platformVersion\n'),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: hasLogin, child: const Text('是否登录')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: getUTdid, child: const Text('getUTdid')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: getUserInfo, child: const Text('getUserInfo')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: getAccessToken, child: const Text('getAccessToken')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: login, child: const Text('登录')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: openByCode, child: const Text('open by code')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: openByUrl, child: const Text('open by url')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: logout, child: const Text('退出登录')),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }

  void initAlibc() async {
    final result = await FlutterDmcbAlibc.initAlibc();
    print(result);
  }

  void getUTdid() async {
    final utdid = await FlutterDmcbAlibc.getUtdid();
    print(utdid);
  }

  void getUserInfo() async {
    final userInfo = await FlutterDmcbAlibc.getUserInfo();
    print([
      userInfo.payload?.nick,
      userInfo.payload?.openId,
    ]);
  }

  void getAccessToken() async {
    final tokenInfo = await FlutterDmcbAlibc.getAccessToken(appKey: "31528286", appName: "魔方黑卡", appLogo: "appLogo");
    print(tokenInfo.payload);
  }

  void hasLogin() async {
    final hasLogin = await FlutterDmcbAlibc.isLogin();
    print(hasLogin);
  }

  void login() async {
    final userInfo = await FlutterDmcbAlibc.authLogin();
    print(userInfo);
  }

  void logout() async {
    FlutterDmcbAlibc.logout();
  }

  void openByCode() async {
    const id = 'm726WXnfktZQJVohzj6tQC3-zD03ZyKIWQzMy92nTJ';
    // final id = '668413008263';
    final res = await FlutterDmcbAlibc.openByCode(
      id: id,
      pid: 'mm_1460680056_2101550125_110951050292',
      relationId: '2763056884',
    );

    print(res);
  }

  void openByUrl() async {
    final res = await FlutterDmcbAlibc.openByUrl(
      //url: "https://uland.taobao.com/quan/detail?sellerId=2184341780&activityId=c20c73d1f7c04e3488512f5e45b1a00c",
      url:
          "https://uland.taobao.com/coupon/edetail?e=qDn6JUq1qJMNfLV8niU3R5TgU2jJNKOfNNtsjZw%2F%2FoJms6L95Arne3H3vPDGqf3toOju9iDH1ffzHoMJvGBOZ5rFNBQuQgInNg4Gqf8CT4C52QHp1NazSDAtmMXHLxkRmMHpNfYdHdA79XCbiE%2BEvbMIJ15N9xbNbaCdIF6c6YN%2B%2F62v0DkmDgKlNMeVV1112i%2FUsVUylfJlBRYM90QVRw%3D%3D&&app_pvid=59590_33.61.98.174_848_1653376051062&ptl=floorId:6706;app_pvid:59590_33.61.98.174_848_1653376051062;tpp_pvid:100_11.14.196.31_43509_1801653376051067520&union_lens=lensId%3AMAPI%401653376051%40213d62ae_0919_180f4e46818_30c1%4001",
      id: "585903443033",
      pid: "mm_1460680056_2101550125_110951050292",
      relationId: "2763056884",
    );
  }
}
