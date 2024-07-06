//
//  NSUserDefaults+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 31/08/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (VMMUserDefaults)

-(nonnull id)objectForKey:(nonnull NSString *)key withDefaultValue:(nonnull id)value;

-(BOOL)preferExternalGPU;
-(void)setPreferExternalGPU:(BOOL)prefer;

@end
