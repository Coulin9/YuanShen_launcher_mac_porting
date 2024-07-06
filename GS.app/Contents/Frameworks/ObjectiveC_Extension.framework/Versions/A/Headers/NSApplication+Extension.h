//
//  NSApplication+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 23/12/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#ifndef NSApplication_Extension_Class
#define NSApplication_Extension_Class

#import <Cocoa/Cocoa.h>
#import "VMMComputerInformation.h"

#define VMMAppearanceDarkPreMojaveCompatible IS_SYSTEM_MAC_OS_10_10_OR_SUPERIOR
#define VMMAppearanceDarkCompatible          IS_SYSTEM_MAC_OS_10_14_OR_SUPERIOR

typedef NSString* VMMAppearanceName;

static VMMAppearanceName _Nonnull const VMMAppearanceNameLight         = @"NSAppearanceNameAqua";
static VMMAppearanceName _Nonnull const VMMAppearanceNameDarkPreMojave = @"NSAppearanceNameVibrantDark";
static VMMAppearanceName _Nonnull const VMMAppearanceNameDark          = @"NSAppearanceNameDarkAqua";

@interface NSApplication (VMMApplication)

+(void)restart;
+(void)restartInLanguage:(nonnull NSString*)language;

+(nullable VMMAppearanceName)appearance;
+(BOOL)setAppearance:(nullable VMMAppearanceName)appearance;

@end

#endif

