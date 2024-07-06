//
//  VMMView.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 07/11/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface VMMView : NSView

typedef NS_ENUM(NSUInteger, VMMViewBorderSide)
{
    VMMViewBorderSideLeft   = 1,
    VMMViewBorderSideRight  = 2,
    VMMViewBorderSideTop    = 4,
    VMMViewBorderSideBottom = 8
};

@property (nonatomic, strong) NSColor* borderColor;
@property (nonatomic, strong) NSNumber* borderThickness;
@property (nonatomic, strong) NSNumber* borderSides;

@property (nonatomic, strong) NSColor* backgroundColor;
@property (nonatomic, strong) NSImage* backgroundImage;

@end
