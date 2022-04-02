//
//  AlibcRSA.h
//  AlibcTradeCommonSDK
//
//  Created by zhongweitao on 2020/8/3.
//

#import <Foundation/Foundation.h>

@interface AlibcRSA : NSObject

#pragma mark - Encryption with RSA Public Key

/**
 * Encryption with RSA Public Key
 * @param str utf8 str
 * @param pubKey public key
 * @return base64 encoded string
 */
+ (NSString *)encryptString:(NSString *)str publicKey:(NSString *)pubKey;

/**
 * Encryption with RSA Public Key
 * @param data raw data
 * @param pubKey public key
 * @return raw data
 */
+ (NSData *)encryptData:(NSData *)data publicKey:(NSString *)pubKey;

/**
 * Encryption with RSA Private Key
 * @param str utf8 str
 * @param privKey private key
 * @return base64 encoded string
 */
+ (NSString *)encryptString:(NSString *)str privateKey:(NSString *)privKey;

/**
 * Encryption with RSA Private Key
 * @param data raw data
 * @param privKey private key
 * @return raw data
 */
+ (NSData *)encryptData:(NSData *)data privateKey:(NSString *)privKey;

#pragma mark - Decryption with RSA Public Key
// decrypt base64 encoded string, convert result to string(not base64 encoded)

/**
 * Decryption with RSA Public Key
 * @param str base64 encoded string
 * @param pubKey public key
 * @return string(not base64 encoded)
 */
+ (NSString *)decryptString:(NSString *)str publicKey:(NSString *)pubKey;

/**
 * Decryption with RSA Public Key
 * @param data raw data
 * @param pubKey public key
 * @return raw data
 */
+ (NSData *)decryptData:(NSData *)data publicKey:(NSString *)pubKey;

/**
 * Decryption with RSA Private Key
 * @param str base64 encoded string
 * @param privKey private key
 * @return string(not base64 encoded)
 */
+ (NSString *)decryptString:(NSString *)str privateKey:(NSString *)privKey;

/**
 * Decryption with RSA Private Key
 * @param data raw data
 * @param privKey private key
 * @return raw data
 */
+ (NSData *)decryptData:(NSData *)data privateKey:(NSString *)privKey;

@end
