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
                  OutlinedButton(onPressed: login, child: const Text('登录')),
                  const SizedBox(height: 16),
                  OutlinedButton(onPressed: openByCode, child: const Text('open by code')),
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
    final res = await FlutterDmcbAlibc.openByCode(
      id: '668413008263',
      pid: 'mm_1460680056_2101550125_110951050292',
      relationId: '2763056884',
    );

    print(res);
  }
}
