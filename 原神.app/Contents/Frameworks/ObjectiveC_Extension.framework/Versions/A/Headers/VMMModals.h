//
//  VMMModals.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 11/10/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface VMMModals : NSObject

+(NSWindow*)modalsWindow;

+(void)nextModalShouldRunOnWindow:(NSWindow*)window;
+(void)modalsShouldRunOnWindow:(NSWindow*)window whenCalledDuringBlock:(void (^) (void))block;

@end
