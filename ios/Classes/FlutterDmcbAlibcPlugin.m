#import "FlutterDmcbAlibcPlugin.h"
#if __has_include(<flutter_dmcb_alibc/flutter_dmcb_alibc-Swift.h>)
#import <flutter_dmcb_alibc/flutter_dmcb_alibc-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "flutter_dmcb_alibc-Swift.h"
#endif

@implementation FlutterDmcbAlibcPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftFlutterDmcbAlibcPlugin registerWithRegistrar:registrar];
}
@end
