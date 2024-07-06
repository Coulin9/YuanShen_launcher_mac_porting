//
//  VMMWebView.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 30/10/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

#import "VMMView.h"
#import "VMMComputerInformation.h"

#define VMMWebViewSupportsHTML5     IS_SYSTEM_MAC_OS_10_9_OR_SUPERIOR

@interface VMMWebViewNavigationBar : VMMView
@property (nonatomic, strong, nullable) NSTextField* addressBarField;
@property (nonatomic, strong, nullable) NSButton* refreshButton;
@end

@interface VMMWebView : VMMView

@property (nonatomic) BOOL hideNavigationBar;
@property (nonatomic) BOOL urlLoaded;
@property (nonatomic) BOOL usingWkWebView;
@property (nonatomic, strong, nullable) NSView* webView;
@property (nonatomic, strong, nullable) VMMWebViewNavigationBar* navigationBar;
@property (nonatomic, strong, nullable) NSTextField* webViewErrorLabel;

@property (nonatomic, strong, nullable) NSURL* lastAccessedUrl;

-(void)showErrorMessage:(nonnull NSString*)errorMessage;

-(BOOL)loadURL:(nonnull NSURL*)url;
-(BOOL)loadURLWithString:(nonnull NSString*)website;
-(void)loadHTMLString:(nonnull NSString*)htmlPage;
-(void)loadEmptyPage;

@end

