//
//  NSThread+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSThread_Extension_Class
#define NSThread_Extension_Class

#import <Foundation/Foundation.h>

#define threadSafeUiValue(__value)   [NSThread returnThreadSafeBlock:^id{ return (__value); }]

dispatch_queue_t queueWithNameAndPriority(const char* name, long priority, BOOL concurrent);

@interface NSThread (VMMThread)

+(void)dispatchQueueWithName:(const char*)name priority:(long)priority concurrent:(BOOL)concurrent withBlock:(void (^)(void))thread;
+(void)dispatchBlockInMainQueue:(void (^)(void))thread;

+(void)runThreadSafeBlock:(void (^)(void))block;

+(id)returnThreadSafeBlock:(id (^)(void))block;

@end

#endif
