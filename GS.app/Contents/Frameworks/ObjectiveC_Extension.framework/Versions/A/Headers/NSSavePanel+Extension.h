//
//  NSSavePanel+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSSavePanel_Extension_Class
#define NSSavePanel_Extension_Class

#import <Cocoa/Cocoa.h>

@interface NSOpenPanel (VMMOpenPanel)

+(void)runThreadSafeModalWithOpenPanel:(void (^)(NSOpenPanel* openPanel))optionsForPanel completionHandler:(void (^) (NSArray<NSURL*>* selectedUrls))completionHandler;
+(void)runMainThreadModalWithOpenPanel:(void (^)(NSOpenPanel* openPanel))optionsForPanel completionHandler:(void (^) (NSArray<NSURL*>* selectedUrls))completionHandler;
+(NSArray<NSURL*>*)runBackgroundThreadModalWithOpenPanel:(void (^)(NSOpenPanel* openPanel))optionsForPanel;

@end

@interface NSSavePanel (VMMSavePanel)

-(NSUInteger)runBackgroundThreadModalWithWindow;

+(void)runThreadSafeModalWithSavePanel:(void (^)(NSSavePanel* savePanel))optionsForPanel completionHandler:(void (^) (NSURL* selectedUrl))completionHandler;
+(void)runMainThreadModalWithSavePanel:(void (^)(NSSavePanel* savePanel))optionsForPanel completionHandler:(void (^) (NSURL* selectedUrl))completionHandler;
+(NSURL*)runBackgroundThreadModalWithSavePanel:(void (^)(NSSavePanel* savePanel))optionsForPanel;

-(void)setInitialDirectory:(NSString*)path;

-(void)setWindowTitle:(NSString*)string;

@end

#endif
