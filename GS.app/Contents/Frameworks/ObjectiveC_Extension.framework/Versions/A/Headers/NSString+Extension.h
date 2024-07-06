//
//  NSString+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSString_Extension_Class
#define NSString_Extension_Class

#import <Foundation/Foundation.h>

@interface NSString (VMMString)

+(nonnull  NSString*)stringWithCFTypeIDDescription:(CFTypeRef _Nonnull)cf_type;
+(nullable NSString*)stringWithCFString:(CFStringRef _Nonnull)cf_string;
+(nonnull  NSString*)stringWithCFNumber:(CFNumberRef _Nonnull)cf_number ofType:(CFNumberType)number_type;
+(nullable NSString*)stringWithCFType:(CFTypeRef _Nonnull)cf_type;

-(NSRange)rangeOfUnescapedChar:(char)character;
-(NSRange)rangeOfUnescapedChar:(char)character range:(NSRange)rangeOfReceiverToSearch;

-(BOOL)contains:(nonnull NSString*)string;
-(BOOL)matchesWithSearchTerms:(nonnull NSArray*)searchTerms;
-(nonnull NSArray<NSString*>*)searchTermsWithString;

-(BOOL)matchesWithRegex:(nonnull NSString*)regexString;
-(nonnull NSArray<NSString*>*)componentsMatchingWithRegex:(nonnull NSString*)regexString;

+(nonnull NSString*)humanReadableSizeForBytes:(long long int)bytes withDecimalMeasureSystem:(BOOL)measure;

-(nonnull NSString*)hexadecimalUTF8String;
+(nullable NSString*)stringWithHexadecimalUTF8String:(nonnull NSString*)string;

+(nonnull NSString*)stringByRemovingEvenCharsFromString:(nonnull NSString*)text;
-(nonnull NSString*)stringToWebStructure;

-(NSRange)rangeAfterString:(nullable NSString*)before andBeforeString:(nullable NSString*)after;
-(nullable NSString*)getFragmentAfter:(nullable NSString*)before andBefore:(nullable NSString*)after;

-(nullable NSNumber*)initialIntegerValue;

+(nullable NSString*)stringWithContentsOfFile:(nonnull NSString*)file;
+(nullable NSString*)stringWithContentsOfFile:(nonnull NSString*)file encoding:(NSStringEncoding)enc;
+(void)stringWithContentsOfURL:(nonnull NSURL *)url encoding:(NSStringEncoding)enc timeoutInterval:(long long int)timeoutInterval withCompletionHandler:(void (^_Nullable)(NSUInteger statusCode, NSString* _Nullable string, NSError* _Nullable error))completion;

-(BOOL)writeToFile:(nonnull NSString*)path atomically:(BOOL)useAuxiliaryFile encoding:(NSStringEncoding)enc;

-(nonnull NSData*)dataWithBase64Encoding;

-(BOOL)isAValidURL;

-(NSString*)stringByReplacingCharactersInSet:(NSCharacterSet *)characterset withString:(NSString *)string;
-(NSString*)stringByRemovingCharactersInSet:(NSCharacterSet *)characterset;

@end

#endif
