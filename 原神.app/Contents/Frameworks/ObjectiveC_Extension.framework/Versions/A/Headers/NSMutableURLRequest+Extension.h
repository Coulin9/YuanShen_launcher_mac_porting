//
//  NSMutableURLRequest+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSMutableURLRequest_Extension_Class
#define NSMutableURLRequest_Extension_Class

#import <Foundation/Foundation.h>

@interface NSMutableURLRequest (VMMMutableURLRequest)

-(void)ifModifiedSince:(nonnull NSDate*)modificationDate;

@end

#endif
