//
//  NSAttributedString+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 12/03/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSAttributedString_Extension_Class
#define NSAttributedString_Extension_Class

#import <Cocoa/Cocoa.h>

@interface NSAttributedString (VMMAttributedString)

-(nullable instancetype)initWithHTMLData:(nonnull NSData*)data;
-(nullable instancetype)initWithHTMLString:(nonnull NSString*)string;

-(nonnull NSString*)htmlString;

@end

#endif
