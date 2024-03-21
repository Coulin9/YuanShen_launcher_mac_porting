//
//  NSColor+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 31/08/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NSColor* _Nullable RGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);
NSColor* _Nullable RGB(CGFloat r, CGFloat g, CGFloat b);

@interface NSColor (VMMColor)

+(nullable NSColor*)colorWithHexColorString:(nonnull NSString*)inColorString;
-(nullable NSString*)hexColorString;

@end
