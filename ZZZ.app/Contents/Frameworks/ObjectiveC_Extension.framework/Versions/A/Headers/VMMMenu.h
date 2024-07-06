//
//  VMMMenu.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 03/02/19.
//  Copyright © 2019 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface VMMMenu : NSMenu

+ (void)forceLightMenu;
+ (void)forceDarkMenu;
+ (void)forceSystemMenu;

@end

NS_ASSUME_NONNULL_END
