//
//  VMMDeviceSimulator.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 01/10/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface VMMDeviceSimulator : NSObject

+(void)simulateCursorClickAtScreenPoint:(CGPoint)clickPoint;

+(void)simulateVirtualKeycode:(CGKeyCode)keyCode withKeyDown:(BOOL)keyPressed;

@end
