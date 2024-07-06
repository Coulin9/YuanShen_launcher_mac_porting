//
//  NSMutableDictionary+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/07/16.
//  Copyright © 2016 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSMutableDictionary_Extension_Class
#define NSMutableDictionary_Extension_Class

#import <Foundation/Foundation.h>

@interface NSMutableDictionary (VMMMutableDictionary)

+(nullable instancetype)mutableDictionaryWithContentsOfFile:(nonnull NSString*)filePath;

@end

#endif
