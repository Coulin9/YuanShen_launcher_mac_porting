//
//  NSData+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSData_Extension_Class
#define NSData_Extension_Class

#import <Foundation/Foundation.h>

@interface NSData (VMMData)

+(void)dataWithContentsOfURL:(nonnull NSURL *)url timeoutInterval:(long long int)timeoutInterval withCompletionHandler:(void (^_Nullable)(NSUInteger statusCode, NSData* _Nullable data, NSError* _Nullable error))completion;
+(nullable NSData*)safeDataWithContentsOfFile:(nonnull NSString*)filePath;

+(nullable NSString*)jsonStringWithObject:(nonnull id)object;
+(nullable NSData*)jsonDataWithObject:(nonnull id)object;
-(nullable id)objectWithJsonData;

-(nonnull NSString*)base64EncodedString;

@end

#endif
