//
//  NSRunningApplication+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 23/09/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSRunningApplication (VMMRunningApplication)

-(nonnull NSArray<NSDictionary*>*)visibleWindows;

-(BOOL)isVisible;

-(nonnull NSArray<NSDictionary*>*)visibleWindowsSizes;
-(nullable NSDictionary*)windowWithSize:(NSSize)size;
-(BOOL)hasWindowWithSize:(NSSize)size;

-(void)bringWindowsToFront;

@end
