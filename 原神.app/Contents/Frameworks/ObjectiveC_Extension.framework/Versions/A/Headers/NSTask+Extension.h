//
//  NSTask+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSTask_Extension_Class
#define NSTask_Extension_Class

#import <Foundation/Foundation.h>

@interface NSTask (VMMTask)

+(NSArray*)componentsFromFlagsString:(NSString*)initialFlags;

+(NSString*)runCommand:(NSArray<NSString*>*)programAndFlags;
+(NSString*)runCommand:(NSArray<NSString*>*)programAndFlags atRunPath:(NSString*)path;
+(NSString*)runCommand:(NSArray<NSString*>*)programAndFlags atRunPath:(NSString*)path andWait:(BOOL)shouldWait;

+(void)runAsynchronousCommand:(NSArray<NSString*>*)programAndFlags;

+(NSString*)runProgram:(NSString*)program;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags outputEncoding:(NSStringEncoding)encoding;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags atRunPath:(NSString*)path andWaiting:(BOOL)wait;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags withEnvironment:(NSDictionary*)env;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags atRunPath:(NSString*)path withEnvironment:(NSDictionary*)env;
+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags waitingForTimeInterval:(unsigned int)timeout;

+(void)runAsynchronousProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags withEnvironment:(NSDictionary*)env;
+(void)runAsynchronousProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags atRunPath:(NSString*)path withEnvironment:(NSDictionary*)env;

+(NSString*)runProgram:(NSString*)program withFlags:(NSArray<NSString*>*)flags atRunPath:(NSString*)path withEnvironment:(NSDictionary*)env andWaiting:(BOOL)wait forTimeInterval:(unsigned int)timeout outputEncoding:(NSStringEncoding)encoding;

@end

#endif
