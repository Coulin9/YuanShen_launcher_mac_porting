//
//  VMMUserAuthorization.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 05/02/2018.
//  Copyright © 2018 VitorMM. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum VMMParentalControlsItunesGamesAgeRestriction
{
    VMMParentalControlsItunesGamesAgeRestrictionNone = 1000,
    VMMParentalControlsItunesGamesAgeRestriction4    = 100,
    VMMParentalControlsItunesGamesAgeRestriction9    = 200,
    VMMParentalControlsItunesGamesAgeRestriction12   = 300,
    VMMParentalControlsItunesGamesAgeRestriction17   = 600,
} VMMParentalControlsItunesGamesAgeRestriction;


@interface VMMParentalControls : NSObject

+(BOOL)isEnabled;

+(id)parentalControlsValueForAppWithDomain:(NSString*)appDomain keyName:(NSString*)keyName;

+(BOOL)iTunesMatureGamesAllowed;
+(VMMParentalControlsItunesGamesAgeRestriction)iTunesAgeRestrictionForGames;

+(BOOL)isAppRestrictionEnabled;
+(BOOL)isAppUseRestricted:(NSString*)appPath;

+(BOOL)isInternetUseRestricted;
+(BOOL)isWebsiteAllowed:(NSString*)websiteAddress;

@end
