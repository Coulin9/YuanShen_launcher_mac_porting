//
//  ObjectiveC_Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 29/09/17.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//! Project version number for ObjectiveC_Extension.
FOUNDATION_EXPORT double ObjectiveC_ExtensionVersionNumber;

//! Project version string for ObjectiveC_Extension.
FOUNDATION_EXPORT const unsigned char ObjectiveC_ExtensionVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ObjectiveC_Extension/PublicHeader.h>

#import <ObjectiveC_Extension/ObjCExtensionConfig.h>

// Devices
#if KEEP_DEVICE_CLASSES == true
#import <ObjectiveC_Extension/VMMVirtualKeycode.h>
#import <ObjectiveC_Extension/VMMDeviceObserver.h>
#import <ObjectiveC_Extension/VMMDeviceSimulator.h>
#import <ObjectiveC_Extension/VMMUsageKeycode.h>
#endif

// Extensions
#import <ObjectiveC_Extension/NSApplication+Extension.h>
#import <ObjectiveC_Extension/NSArray+Extension.h>
#import <ObjectiveC_Extension/NSAttributedString+Extension.h>
#import <ObjectiveC_Extension/NSBundle+Extension.h>
#import <ObjectiveC_Extension/NSColor+Extension.h>
#import <ObjectiveC_Extension/NSData+Extension.h>
#import <ObjectiveC_Extension/NSDateFormatter+Extension.h>
#import <ObjectiveC_Extension/NSException+Extension.h>
#import <ObjectiveC_Extension/NSFileManager+Extension.h>
#import <ObjectiveC_Extension/NSImage+Extension.h>
#import <ObjectiveC_Extension/NSMenuItem+Extension.h>
#import <ObjectiveC_Extension/NSMutableArray+Extension.h>
#import <ObjectiveC_Extension/NSMutableAttributedString+Extension.h>
#import <ObjectiveC_Extension/NSMutableDictionary+Extension.h>
#import <ObjectiveC_Extension/NSMutableString+Extension.h>
#import <ObjectiveC_Extension/NSMutableURLRequest+Extension.h>
#import <ObjectiveC_Extension/NSRunningApplication+Extension.h>
#import <ObjectiveC_Extension/NSSavePanel+Extension.h>
#import <ObjectiveC_Extension/NSScreen+Extension.h>
#import <ObjectiveC_Extension/NSString+Extension.h>
#import <ObjectiveC_Extension/NSTask+Extension.h>
#import <ObjectiveC_Extension/NSText+Extension.h>
#import <ObjectiveC_Extension/NSThread+Extension.h>
#import <ObjectiveC_Extension/NSTimer+Extension.h>
#import <ObjectiveC_Extension/NSUnarchiver+Extension.h>
#import <ObjectiveC_Extension/NSUserDefaults+Extension.h>
#import <ObjectiveC_Extension/NSView+Extension.h>
#import <ObjectiveC_Extension/NSWorkspace+Extension.h>

// Utilities
#import <ObjectiveC_Extension/NKFTPManager.h>
#import <ObjectiveC_Extension/VMMComputerInformation.h>
#import <ObjectiveC_Extension/VMMVideoCard.h>
#import <ObjectiveC_Extension/VMMVideoCardManager.h>
#import <ObjectiveC_Extension/VMMDockProgressIndicator.h>
#import <ObjectiveC_Extension/VMMLocalizationUtility.h>
#import <ObjectiveC_Extension/VMMLogUtility.h>
#import <ObjectiveC_Extension/VMMModals.h>
#import <ObjectiveC_Extension/VMMParentalControls.h>
#import <ObjectiveC_Extension/VMMPropertyList.h>
#import <ObjectiveC_Extension/VMMUserNotificationCenter.h>
#import <ObjectiveC_Extension/VMMVersion.h>
#import <ObjectiveC_Extension/VMMUUID.h>

// Views
#import <ObjectiveC_Extension/VMMKeyCaptureField.h>
#import <ObjectiveC_Extension/VMMAlert.h>
#import <ObjectiveC_Extension/VMMMenu.h>
#import <ObjectiveC_Extension/VMMView.h>
#import <ObjectiveC_Extension/VMMWebView.h>
#import <ObjectiveC_Extension/VMMTextFileView.h>

