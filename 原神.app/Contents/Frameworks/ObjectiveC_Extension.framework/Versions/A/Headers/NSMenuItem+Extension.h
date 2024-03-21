//
//  NSMenuItem+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 30/05/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSMenuItem (VMMMenuItem)

+(nonnull NSMenuItem*)menuItemWithTitle:(nonnull NSString*)title andAction:(nullable SEL)action forTarget:(nullable id)target;

@end
