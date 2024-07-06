//
//  VMMPropertyList.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 08/03/2018.
//  Copyright © 2018 VitorMM. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VMMPropertyList : NSObject

+(nullable id)propertyListWithUnarchivedString:(nonnull NSString*)string;
+(nullable id)propertyListWithUnarchivedData:(nonnull NSData*)data;

+(nullable id)propertyListWithArchivedString:(nonnull NSString *)string;
+(nullable id)propertyListWithArchivedData:(nonnull NSData *)data;

@end
