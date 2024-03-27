//
//  NSFileManager+Extension.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef NSFileManager_Extension_Class
#define NSFileManager_Extension_Class

#import <Foundation/Foundation.h>

typedef enum NSChecksumType
{
    NSChecksumTypeGOSTMac,
    NSChecksumTypeStreebog512,
    NSChecksumTypeStreebog256,
    NSChecksumTypeGOST94,
    NSChecksumTypeMD4,
    NSChecksumTypeMD5,
    NSChecksumTypeRIPEMD160,
    NSChecksumTypeSHA,
    NSChecksumTypeSHA1,
    NSChecksumTypeSHA224,
    NSChecksumTypeSHA256,
    NSChecksumTypeSHA384,
    NSChecksumTypeSHA512,
    NSChecksumTypeWrirlpool
} NSChecksumType;

@interface NSFileManager (VMMFileManager)

-(BOOL)createSymbolicLinkAtPath:(nonnull NSString *)path withDestinationPath:(nonnull NSString *)destPath;
-(BOOL)createDirectoryAtPath:(nonnull NSString*)path withIntermediateDirectories:(BOOL)interDirs;
-(BOOL)createEmptyFileAtPath:(nonnull NSString*)path;

-(BOOL)moveItemAtPath:(nonnull NSString*)path toPath:(nonnull NSString*)destination;
-(BOOL)copyItemAtPath:(nonnull NSString*)path toPath:(nonnull NSString*)destination;
-(BOOL)removeItemAtPath:(nonnull NSString*)path;
-(BOOL)directoryExistsAtPath:(nonnull NSString*)path;
-(BOOL)regularFileExistsAtPath:(nonnull NSString*)path;
-(nullable NSArray<NSString*>*)contentsOfDirectoryAtPath:(nonnull NSString*)path;
-(nullable NSArray<NSString*>*)subpathsAtPath:(nonnull NSString *)path ofFilesNamed:(nonnull NSString*)fileName;
-(nullable NSString*)destinationOfSymbolicLinkAtPath:(nonnull NSString *)path;

-(nullable NSString*)userReadablePathForItemAtPath:(nonnull NSString*)path joinedByString:(nullable NSString*)join;

-(unsigned long long int)sizeOfRegularFileAtPath:(nonnull NSString*)path;
-(unsigned long long int)sizeOfDirectoryAtPath:(nonnull NSString*)path;

-(nullable NSString*)checksum:(NSChecksumType)checksum ofFileAtPath:(nonnull NSString*)file;

-(nullable NSString*)base64OfFileAtPath:(nonnull NSString*)path;

@end

#endif
