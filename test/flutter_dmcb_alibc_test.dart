import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flutter_dmcb_alibc/flutter_dmcb_alibc.dart';

void main() {
  const MethodChannel channel = MethodChannel('flutter_dmcb_alibc');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await FlutterDmcbAlibc.platformVersion, '42');
  });
}
