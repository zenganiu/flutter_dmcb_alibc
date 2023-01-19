#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint flutter_dmcb_alibc.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'flutter_dmcb_alibc'
  s.version          = '0.0.1'
  s.summary          = 'Flutter 百川电商SDK插件'
  s.description      = <<-DESC
A new Flutter project.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.dependency 'Flutter'
  s.platform = :ios, '10.0'

  s.dependency 'SSZipArchive','2.4.3'
  s.dependency 'SDWebImage','5.12.5'
  s.dependency 'Masonry','1.1.0'
  s.dependency 'FMDB','2.7.5'
  s.dependency 'Reachability','3.2'
  s.dependency 'SocketRocket','0.6.0'

  s.vendored_frameworks = "framework/**/*.framework"
  s.frameworks = 'AssetsLibrary', 'CoreMotion', 'Contacts','ContactsUI','AddressBook','AddressBookUI','JavaScriptCore'
  s.libraries = 'resolv','c++','icucore'
  s.resources = ['bundle/*.bundle']

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end
