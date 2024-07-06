//
//  VMMVideoCard.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 18/03/18.
//  Copyright © 2018 VitorMM. All rights reserved.
//
//  References:
//  https://lists.denx.de/pipermail/u-boot/2015-May/215147.html
//

#import <Foundation/Foundation.h>
#import "VMMComputerInformation.h"

static NSString * _Nonnull const VMMVideoCardModelNameKey =                  @"sppci_model";
static NSString * _Nonnull const VMMVideoCardChipsetNameKey =                @"_name";
static NSString * _Nonnull const VMMVideoCardDeviceTypeKey =                 @"sppci_device_type";      // eg. 'GPU'
static NSString * _Nonnull const VMMVideoCardBusKey =                        @"sppci_bus";              // eg. VMMVideoCardBusPCIe
static NSString * _Nonnull const VMMVideoCardMemorySizeBuiltInAlternateKey = @"_spdisplays_vram";       // eg. '1536 MB'
static NSString * _Nonnull const VMMVideoCardMemorySizeBuiltInKey =          @"spdisplays_vram_shared"; // eg. '1536 MB'
static NSString * _Nonnull const VMMVideoCardMemorySizePciOrPcieKey =        @"spdisplays_vram";        // eg. '1536 MB'
static NSString * _Nonnull const VMMVideoCardVendorIDKey =                   @"spdisplays_vendor-id";   // eg. '0x8086'
static NSString * _Nonnull const VMMVideoCardVendorKey =                     @"spdisplays_vendor";
static NSString * _Nonnull const VMMVideoCardDeviceIDKey =                   @"spdisplays_device-id";   // eg. '0x0046'
static NSString * _Nonnull const VMMVideoCardMetalSupportKey =               @"spdisplays_metal";
static NSString * _Nonnull const VMMVideoCardKextInfoKey =                   @"sppci_kextinfo"; // eg. 'sppci_kextnotloaded'

static NSString * _Nonnull const VMMVideoCardKextInfoNotLoaded =  @"sppci_kextnotloaded";

static NSString * _Nonnull const VMMVideoCardTypeApple =           @"Apple Silicon";
static NSString * _Nonnull const VMMVideoCardTypeIntelHD =         @"Intel HD";
static NSString * _Nonnull const VMMVideoCardTypeIntelUHD =        @"Intel UHD";
static NSString * _Nonnull const VMMVideoCardTypeIntelIris =       @"Intel Iris";
static NSString * _Nonnull const VMMVideoCardTypeIntelIrisPro =    @"Intel Iris Pro";
static NSString * _Nonnull const VMMVideoCardTypeIntelIrisPlus =   @"Intel Iris Plus";
static NSString * _Nonnull const VMMVideoCardTypeIntelGMA =        @"Intel GMA";
static NSString * _Nonnull const VMMVideoCardTypeIntelCoffeeLake = @"Intel Coffee Lake";
static NSString * _Nonnull const VMMVideoCardTypeATIAMD =          @"ATI/AMD";
static NSString * _Nonnull const VMMVideoCardTypeNVIDIA =          @"NVIDIA";

static NSString * _Nonnull const VMMVideoCardDeviceTypeGPU  = @"spdisplays_gpu";
static NSString * _Nonnull const VMMVideoCardDeviceTypeeGPU = @"spdisplays_egpu";

static NSString * _Nonnull const VMMVideoCardBusPCIe =        @"spdisplays_pcie_device";
static NSString * _Nonnull const VMMVideoCardBusPCI =         @"sppci_pci_device";
static NSString * _Nonnull const VMMVideoCardBusBuiltIn =     @"spdisplays_builtin";

static NSString * _Nonnull const VMMVideoCardVendorIDApple =  @"0x05ac";
static NSString * _Nonnull const VMMVideoCardVendorIDIntel =  @"0x8086";
static NSString * _Nonnull const VMMVideoCardVendorIDNVIDIA = @"0x10de";
static NSString * _Nonnull const VMMVideoCardVendorIDATIAMD = @"0x1002";

static NSString * _Nonnull const VMMVideoCardVendorApple =    @"Apple";
static NSString * _Nonnull const VMMVideoCardVendorIntel =    @"Intel";
static NSString * _Nonnull const VMMVideoCardVendorNVIDIA =   @"NVIDIA";
static NSString * _Nonnull const VMMVideoCardVendorATIAMD =   @"ATI/AMD";

static NSString * _Nonnull const VMMVideoCardNameVirtualBox =                 @"VirtualBox VM";
static NSString * _Nonnull const VMMVideoCardTypeVirtualBox =                 @"VirtualBox";
static NSString * _Nonnull const VMMVideoCardVendorVirtualBox =               @"VirtualBox";
static NSString * _Nonnull const VMMVideoCardVendorIDVirtualBox =             @"0x80ee";
static NSString * _Nonnull const VMMVideoCardDeviceIDVirtualBox =             @"0xbeef";

static NSString * _Nonnull const VMMVideoCardNameVMware =                     @"VMware VM";
static NSString * _Nonnull const VMMVideoCardTypeVMware =                     @"VMware";
static NSString * _Nonnull const VMMVideoCardVendorVMware =                   @"VMware";
static NSString * _Nonnull const VMMVideoCardVendorIDVMware =                 @"0x15ad";

static NSString * _Nonnull const VMMVideoCardNameParallelsDesktop =           @"Parallels Desktop VM";
static NSString * _Nonnull const VMMVideoCardTypeParallelsDesktop =           @"Parallels Desktop";
static NSString * _Nonnull const VMMVideoCardVendorParallelsDesktop =         @"Parallels Desktop";
static NSString * _Nonnull const VMMVideoCardVendorIDParallelsDesktop =       @"0x1ab8";

static NSString * _Nonnull const VMMVideoCardNameMicrosoftRemoteDesktop =     @"Microsoft Remote Desktop";
static NSString * _Nonnull const VMMVideoCardTypeMicrosoftRemoteDesktop =     @"Microsoft Remote Desktop";
static NSString * _Nonnull const VMMVideoCardVendorMicrosoftRemoteDesktop =   @"Microsoft Remote Desktop";
static NSString * _Nonnull const VMMVideoCardVendorIDMicrosoftRemoteDesktop = @"0xbaad";

static NSString * _Nonnull const VMMVideoCardNameQemu =                       @"QEMU Emulated Graphic Card";
static NSString * _Nonnull const VMMVideoCardTypeQemu =                       @"QEMU";
static NSString * _Nonnull const VMMVideoCardVendorQemu =                     @"QEMU";
static NSString * _Nonnull const VMMVideoCardVendorIDQemu =                   @"0x1234";
static NSString * _Nonnull const VMMVideoCardDeviceIDQemu =                   @"0x1111";


static NSString * _Nonnull const VMMVideoCardDeviceIDIntelHDGraphics =     @"0x0046";
static NSString * _Nonnull const VMMVideoCardDeviceIDIntelHDGraphics3000 = @"0x0116";
static NSString * _Nonnull const VMMVideoCardDeviceIDIntelHDGraphics4000 = @"0x0166";
static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce9400M =  @"0x0863";

static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce320M_1 = @"0x08a0";
static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce320M_2 = @"0x08a2";
static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce320M_3 = @"0x08a3";
static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce320M_4 = @"0x08a4";
static NSString * _Nonnull const VMMVideoCardDeviceIDNVIDIAGeForce320M_5 = @"0x08a5";

static NSInteger const VMMVideoCardMemoryMinimumSize = 64;

static NSString * _Nonnull const VMMVideoCardTemporaryKeyIOServiceValues      = @"RawRegIOServiceValues";
static NSString * _Nonnull const VMMVideoCardTemporaryKeyOpenGlApiMemorySizes = @"temp_memory_size_opengl_api_values";

@interface VMMVideoCard : NSObject
{
    NSLock* _Nullable nameLock;
    NSLock* _Nullable typeLock;
    NSLock* _Nullable busLock;
    NSLock* _Nullable deviceIDLock;
    NSLock* _Nullable vendorIDLock;
    NSLock* _Nullable vendorLock;
    NSLock* _Nullable memorySizeInMegabytesLock;
}

-(instancetype _Nullable )initVideoCardWithDictionary:(NSDictionary* _Nonnull)dict;

@property (nonatomic, strong, readonly) NSDictionary* _Nonnull dictionary;

@property (nonatomic, strong, readonly) NSString* _Nullable modelName;
@property (nonatomic, strong, readonly) NSString* _Nullable chipsetName;
@property (nonatomic, strong, readonly) NSString* _Nullable type;
@property (nonatomic, strong, readonly) NSString* _Nullable bus;
@property (nonatomic, strong, readonly) NSString* _Nullable deviceID;
@property (nonatomic, strong, readonly) NSString* _Nullable vendorID;
@property (nonatomic, strong, readonly) NSString* _Nullable vendor;
@property (nonatomic, strong, readonly) NSNumber* _Nullable memorySizeInMegabytes;

-(BOOL)kextLoaded;

-(BOOL)isExternalGpu;

-(BOOL)supportsMetal;
-(VMMMetalFeatureSet)metalFeatureSet;

-(NSString* _Nonnull)descriptiveName;
-(NSString* _Nonnull)veryDescriptiveName;

-(BOOL)hasRealVendorID;
-(BOOL)isComplete;
-(BOOL)isVirtualMachineVideoCard;

-(BOOL)isSameVideoCard:(nonnull VMMVideoCard*)vc;
-(void)mergeWithIOPCIVideoCard:(nonnull VMMVideoCard*)vc;

@end
