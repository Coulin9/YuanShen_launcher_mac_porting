//
//  VMMUUID.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 03/11/2017.
//  Copyright © 2017 VitorMM. All rights reserved.
//

#import <Foundation/Foundation.h>

NSString* _Nonnull VMMUUIDCreate(void);

@interface VMMUUID : NSObject

+(nonnull NSString*)newUUIDString;

@end
