//
//  VMMVersion.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 18/09/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum VMMVersionCompare
{
    VMMVersionCompareFirstIsNewest,
    VMMVersionCompareSecondIsNewest,
    VMMVersionCompareSame
} VMMVersionCompare;

@interface VMMVersion : NSObject

@property (nonatomic, strong) NSArray<NSString*>* _Nonnull components;

-(nonnull instancetype)initWithString:(nonnull NSString*)string;
-(VMMVersionCompare)compareWithVersion:(nonnull VMMVersion*)version;

+(VMMVersionCompare)compareVersionString:(nonnull NSString*)PK1 withVersionString:(nonnull NSString*)PK2;

@end
