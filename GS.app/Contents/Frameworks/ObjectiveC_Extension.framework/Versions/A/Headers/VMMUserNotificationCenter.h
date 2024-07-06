//
//  VMMUserNotificationCenter.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    VMMUserNotificationNormal                = 0,
    VMMUserNotificationOnlyWithAction        = 1 << 0,
    VMMUserNotificationPreferGrowl           = 1 << 1,
    VMMUserNotificationNoAlert               = 1 << 2
    
} VMMUserNotificationCenterOptions;

@protocol VMMUserNotificationCenterDelegate
-(void)actionButtonPressedForNotificationWithUserInfo:(nullable NSObject*)userInfo;
@end

@interface VMMUserNotificationCenter : NSObject

@property (nonatomic, nullable) id<VMMUserNotificationCenterDelegate> delegate;

+(nonnull instancetype)defaultUserNotificationCenter;

+(BOOL)isGrowlAvailable;
+(BOOL)isNSUserNotificationCenterAvailable;

-(BOOL)deliverNotificationWithTitle:(nullable NSString*)title message:(nullable NSString*)message userInfo:(nullable NSObject*)info icon:(nullable NSImage*)icon actionButtonText:(nullable NSString*)actionButton options:(VMMUserNotificationCenterOptions)options;

-(BOOL)deliverNotificationWithTitle:(nullable NSString*)title message:(nullable NSString*)message icon:(nullable NSImage*)icon options:(VMMUserNotificationCenterOptions)options;

@end
