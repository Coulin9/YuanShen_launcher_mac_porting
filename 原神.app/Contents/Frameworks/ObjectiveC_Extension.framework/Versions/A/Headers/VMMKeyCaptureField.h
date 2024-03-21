//
//  VMMKeyCaptureField.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 18/08/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "VMMDeviceObserver.h"
#import "VMMUsageKeycode.h"

@protocol VMMKeyCaptureFieldDelegate <NSObject>
-(void)keyCaptureField:(nonnull NSTextField*)field didChangedKeyUsageKeycode:(uint32_t)keyUsage;
@end

@interface VMMKeyCaptureField : NSTextField<VMMDeviceObserverDelegate>

@property (nonatomic, strong, nullable) IBOutlet NSObject<VMMKeyCaptureFieldDelegate>* keyCaptureDelegate;
@property (nonatomic, nullable) IOHIDManagerRef hidManager;
@property (nonatomic) uint32_t keyUsageKeycode;

@end

