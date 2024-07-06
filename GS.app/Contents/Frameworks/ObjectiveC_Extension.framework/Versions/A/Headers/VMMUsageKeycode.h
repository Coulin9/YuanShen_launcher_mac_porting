//
//  VMMUsageKeycode.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 09/08/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//
//  Source:
//  http://www.usb.org/developers/hidpage/Hut1_12v2.pdf (page 53)
//
//  Reference:
//  /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/IOKit.framework/Versions/A/Headers/hid/IOHIDUsageTables.h
//

#import <Foundation/Foundation.h>

@interface VMMUsageKeycode : NSObject

+(nonnull NSDictionary*)usageNamesByKeycode;

+(nullable NSString*)nameOfUsageKeycode:(uint32_t)key;

@end

enum {
    // 00 Reserved
    kKU_ErrorRollOver             = 0x01,
    kKU_PostFail                  = 0x02,
    kKU_ErrorUndefined            = 0x03,
    
    kKU_ANSI_A                    = 0x04,
    kKU_ANSI_B                    = 0x05,
    kKU_ANSI_C                    = 0x06,
    kKU_ANSI_D                    = 0x07,
    kKU_ANSI_E                    = 0x08,
    kKU_ANSI_F                    = 0x09,
    kKU_ANSI_G                    = 0x0A,
    kKU_ANSI_H                    = 0x0B,
    kKU_ANSI_I                    = 0x0C,
    kKU_ANSI_J                    = 0x0D,
    kKU_ANSI_K                    = 0x0E,
    kKU_ANSI_L                    = 0x0F,
    kKU_ANSI_M                    = 0x10,
    kKU_ANSI_N                    = 0x11,
    kKU_ANSI_O                    = 0x12,
    kKU_ANSI_P                    = 0x13,
    kKU_ANSI_Q                    = 0x14,
    kKU_ANSI_R                    = 0x15,
    kKU_ANSI_S                    = 0x16,
    kKU_ANSI_T                    = 0x17,
    kKU_ANSI_U                    = 0x18,
    kKU_ANSI_V                    = 0x19,
    kKU_ANSI_W                    = 0x1A,
    kKU_ANSI_X                    = 0x1B,
    kKU_ANSI_Y                    = 0x1C,
    kKU_ANSI_Z                    = 0x1D,
    
    kKU_ANSI_1                    = 0x1E,
    kKU_ANSI_2                    = 0x1F,
    kKU_ANSI_3                    = 0x20,
    kKU_ANSI_4                    = 0x21,
    kKU_ANSI_5                    = 0x22,
    kKU_ANSI_6                    = 0x23,
    kKU_ANSI_7                    = 0x24,
    kKU_ANSI_8                    = 0x25,
    kKU_ANSI_9                    = 0x26,
    kKU_ANSI_0                    = 0x27,
    
    kKU_Enter                     = 0x28, /* Mac calls it Return */
    kKU_Escape                    = 0x29,
    kKU_Delete                    = 0x2A, /* Backspace in Windows keyboards */
    kKU_Tab                       = 0x2B,
    kKU_Space                     = 0x2C,
    kKU_ANSI_Minus                = 0x2D,
    kKU_ANSI_Equal                = 0x2E,
    kKU_ANSI_LeftBracket          = 0x2F,
    kKU_ANSI_RightBracket         = 0x30,
    kKU_ANSI_Backslash            = 0x31,
    kKU_NonUSPound                = 0x32, /* Non-US # or _ */
    kKU_ANSI_Semicolon            = 0x33,
    kKU_ANSI_Quote                = 0x34,
    kKU_ANSI_Grave                = 0x35,
    kKU_ANSI_Comma                = 0x36,
    kKU_ANSI_Period               = 0x37,
    kKU_ANSI_Slash                = 0x38,
    kKU_CapsLock                  = 0x39,
    
    kKU_F1                        = 0x3A,
    kKU_F2                        = 0x3B,
    kKU_F3                        = 0x3C,
    kKU_F4                        = 0x3D,
    kKU_F5                        = 0x3E,
    kKU_F6                        = 0x3F,
    kKU_F7                        = 0x40,
    kKU_F8                        = 0x41,
    kKU_F9                        = 0x42,
    kKU_F10                       = 0x43,
    kKU_F11                       = 0x44,
    kKU_F12                       = 0x45,
    
    kKU_PrintScreen               = 0x46, // Not present in Mac virtual keycodes?
    kKU_ScrollLock                = 0x47, // Not present in Mac virtual keycodes?
    kKU_Pause                     = 0x48, // Not present in Mac virtual keycodes?
    kKU_Insert                    = 0x49,
    kKU_Home                      = 0x4A,
    kKU_PageUp                    = 0x4B,
    kKU_ForwardDelete             = 0x4C,
    kKU_End                       = 0x4D,
    kKU_PageDown                  = 0x4E,
    kKU_RightArrow                = 0x4F,
    kKU_LeftArrow                 = 0x50,
    kKU_DownArrow                 = 0x51,
    kKU_UpArrow                   = 0x52,
    
    kKU_ANSI_KeypadClear          = 0x53, /* This is also Num Lock */
    kKU_ANSI_KeypadDivide         = 0x54,
    kKU_ANSI_KeypadMultiply       = 0x55,
    kKU_ANSI_KeypadMinus          = 0x56,
    kKU_ANSI_KeypadPlus           = 0x57,
    kKU_ANSI_KeypadEnter          = 0x58,
    kKU_ANSI_Keypad1              = 0x59,
    kKU_ANSI_Keypad2              = 0x5A,
    kKU_ANSI_Keypad3              = 0x5B,
    kKU_ANSI_Keypad4              = 0x5C,
    kKU_ANSI_Keypad5              = 0x5D,
    kKU_ANSI_Keypad6              = 0x5E,
    kKU_ANSI_Keypad7              = 0x5F,
    kKU_ANSI_Keypad8              = 0x60,
    kKU_ANSI_Keypad9              = 0x61,
    kKU_ANSI_Keypad0              = 0x62,
    kKU_ANSI_KeypadDecimal        = 0x63,
    kKU_NonUSBackslash            = 0x64,
    kKU_Application               = 0x65, // Not present in Mac virtual keycodes?
    kKU_Power                     = 0x66, // Maybe Menu in different keyboard? Wtf is menu? Have to check
    kKU_ANSI_KeypadEquals         = 0x67,
    
    kKU_F13                       = 0x68,
    kKU_F14                       = 0x69,
    kKU_F15                       = 0x6A,
    kKU_F16                       = 0x6B,
    kKU_F17                       = 0x6C,
    kKU_F18                       = 0x6D,
    kKU_F19                       = 0x6E,
    kKU_F20                       = 0x6F,
    kKU_F21                       = 0x70,
    kKU_F22                       = 0x71,
    kKU_F23                       = 0x72,
    kKU_F24                       = 0x73,
    
    kKU_Execute                   = 0x74, // Not present in Mac virtual keycodes?
    kKU_Help                      = 0x75,
    kKU_ContextMenu               = 0x76, /* That strange key next to Alt Gr in Windows keyboards */
    kKU_Select                    = 0x77, // Not present in Mac virtual keycodes?
    kKU_Stop                      = 0x78, // Not present in Mac virtual keycodes?
    kKU_Again                     = 0x79, // Not present in Mac virtual keycodes?
    kKU_Undo                      = 0x7A, // Not present in Mac virtual keycodes?
    kKU_Cut                       = 0x7B, // Not present in Mac virtual keycodes?
    kKU_Copy                      = 0x7C, // Not present in Mac virtual keycodes?
    kKU_Paste                     = 0x7D, // Not present in Mac virtual keycodes?
    kKU_Find                      = 0x7E, // Not present in Mac virtual keycodes?
    kKU_Mute                      = 0x7F,
    kKU_VolumeUp                  = 0x80,
    kKU_VolumeDown                = 0x81,
    kKU_Locking_CapsLock          = 0x82, // Not present in Mac virtual keycodes?
    kKU_Locking_NumLock           = 0x83, // Not present in Mac virtual keycodes?
    kKU_Locking_ScrollLock        = 0x84, // Not present in Mac virtual keycodes?
    kKU_JIS_KeypadComma           = 0x85,
    kKU_ANSI_KeypadEqual          = 0x86, // Not present in Mac virtual keycodes?
    
    kKU_InternationalKey1         = 0x87, // Not present in Mac virtual keycodes?
    kKU_InternationalKey2         = 0x88, // Not present in Mac virtual keycodes?
    kKU_JIS_Yen                   = 0x89,
    kKU_InternationalKey4         = 0x8A, // Not present in Mac virtual keycodes?
    kKU_InternationalKey5         = 0x8B, // Not present in Mac virtual keycodes?
    kKU_InternationalKey6         = 0x8C, // Not present in Mac virtual keycodes?
    kKU_InternationalKey7         = 0x8D, // Not present in Mac virtual keycodes?
    kKU_InternationalKey8         = 0x8E, // Not present in Mac virtual keycodes?
    kKU_InternationalKey9         = 0x8F, // Not present in Mac virtual keycodes?
    
    kKU_Toggle_HangulEnglish      = 0x90, // Not present in Mac virtual keycodes?
    kKU_Conversion_Hanja          = 0x91, // Not present in Mac virtual keycodes?
    kKU_Katakana                  = 0x92, // Not present in Mac virtual keycodes?
    kKU_Hiragana                  = 0x93, // Not present in Mac virtual keycodes?
    kKU_Zenkaku_Or_Hankaku        = 0x94, // Not present in Mac virtual keycodes?
    kKU_LanguageSpecific1         = 0x95, // Not present in Mac virtual keycodes?
    kKU_LanguageSpecific2         = 0x96, // Not present in Mac virtual keycodes?
    kKU_LanguageSpecific3         = 0x97, // Not present in Mac virtual keycodes?
    kKU_LanguageSpecific4         = 0x98, // Not present in Mac virtual keycodes?
    
    kKU_AltenateErase             = 0x99, // Not present in Mac virtual keycodes?
    kKU_SysReq_Or_Attention       = 0x9A, // Not present in Mac virtual keycodes?
    kKU_Cancel                    = 0x9B, // Not present in Mac virtual keycodes?
    kKU_Clear                     = 0x9C, // Not present in Mac virtual keycodes?
    kKU_Prior                     = 0x9D, // Not present in Mac virtual keycodes?
    kKU_Return                    = 0x9E, // Not present in Mac virtual keycodes?
    kKU_Separator                 = 0x9F, // Not present in Mac virtual keycodes?
    kKU_Out                       = 0xA0, // Not present in Mac virtual keycodes?
    kKU_Oper                      = 0xA1, // Not present in Mac virtual keycodes?
    kKU_Clear_Or_Again            = 0xA2, // Not present in Mac virtual keycodes?
    kKU_CrSel_Or_Props            = 0xA3, // Not present in Mac virtual keycodes?
    kKU_ExSel                     = 0xA4, // Not present in Mac virtual keycodes?
    
    // A5 Reserved
    // A6 Reserved
    // A7 Reserved
    // A8 Reserved
    // A9 Reserved
    // AA Reserved
    // AB Reserved
    // AC Reserved
    // AD Reserved
    // AE Reserved
    // AF Reserved
    
    kKU_Keypad_ZeroZero           = 0xB0, // Not present in Mac virtual keycodes?
    kKU_Keypad_ZeroZeroZero       = 0xB1, // Not present in Mac virtual keycodes?
    kKU_Keypad_ThousandsSeparator = 0xB2, // Not present in Mac virtual keycodes? In US: ','
    kKU_Keypad_DecimalSeparator   = 0xB3, // Not present in Mac virtual keycodes? In US: '.'
    kKU_Keypad_CurrencyUnit       = 0xB4, // Not present in Mac virtual keycodes? In US: '$'
    kKU_Keypad_CurrencySubunit    = 0xB5, // Not present in Mac virtual keycodes? In US: '¢'
    kKU_Keypad_LeftParentheses    = 0xB6, // Not present in Mac virtual keycodes?
    kKU_Keypad_RightParentheses   = 0xB7, // Not present in Mac virtual keycodes?
    kKU_Keypad_LeftBraces         = 0xB8, // Not present in Mac virtual keycodes?
    kKU_Keypad_RightBraces        = 0xB9, // Not present in Mac virtual keycodes?
    kKU_Keypad_Tab                = 0xBA, // Not present in Mac virtual keycodes?
    kKU_Keypad_Backspace          = 0xBB, // Not present in Mac virtual keycodes?
    kKU_Keypad_A                  = 0xBC, // Not present in Mac virtual keycodes?
    kKU_Keypad_B                  = 0xBD, // Not present in Mac virtual keycodes?
    kKU_Keypad_C                  = 0xBE, // Not present in Mac virtual keycodes?
    kKU_Keypad_D                  = 0xBF, // Not present in Mac virtual keycodes?
    kKU_Keypad_E                  = 0xC0, // Not present in Mac virtual keycodes?
    kKU_Keypad_F                  = 0xC1, // Not present in Mac virtual keycodes?
    kKU_Keypad_XOR                = 0xC2, // Not present in Mac virtual keycodes?
    kKU_Keypad_Circumflex         = 0xC3, // Not present in Mac virtual keycodes?
    kKU_Keypad_Percent            = 0xC4, // Not present in Mac virtual keycodes?
    kKU_Keypad_Less_Than          = 0xC5, // Not present in Mac virtual keycodes?
    kKU_Keypad_More_Than          = 0xC6, // Not present in Mac virtual keycodes?
    kKU_Keypad_Ampersand          = 0xC7, // Not present in Mac virtual keycodes?
    kKU_Keypad_AmpersandAmpersand = 0xC8, // Not present in Mac virtual keycodes?
    kKU_Keypad_VerticalLine       = 0xC9, // Not present in Mac virtual keycodes?
    kKU_Keypad_TwoVerticalLines   = 0xCA, // Not present in Mac virtual keycodes?
    kKU_Keypad_Colon              = 0xCB, // Not present in Mac virtual keycodes?
    kKU_Keypad_NumberSign         = 0xCC, // Not present in Mac virtual keycodes?
    kKU_Keypad_Space              = 0xCD, // Not present in Mac virtual keycodes?
    kKU_Keypad_CommercialAt       = 0xCE, // Not present in Mac virtual keycodes?
    kKU_Keypad_Exclamation        = 0xCF, // Not present in Mac virtual keycodes?
    
    kKU_Keypad_MemoryStore        = 0xD0, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemoryRecall       = 0xD1, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemoryClear        = 0xD2, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemoryAdd          = 0xD3, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemorySubstract    = 0xD4, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemoryMultiply     = 0xD5, // Not present in Mac virtual keycodes?
    kKU_Keypad_MemoryDivide       = 0xD6, // Not present in Mac virtual keycodes?
    kKU_Keypad_PlusMinus          = 0xD7, // Not present in Mac virtual keycodes?
    kKU_Keypad_Clear              = 0xD8, // Not present in Mac virtual keycodes?
    kKU_Keypad_ClearEntry         = 0xD9, // Not present in Mac virtual keycodes?
    kKU_Keypad_Binary             = 0xDA, // Not present in Mac virtual keycodes?
    kKU_Keypad_Octal              = 0xDB, // Not present in Mac virtual keycodes?
    kKU_Keypad_Decimal            = 0xDC, // Not present in Mac virtual keycodes?
    kKU_Keypad_Hexadecimal        = 0xDD, // Not present in Mac virtual keycodes?
    
    // DE Reserved
    // DF Reserved
    
    kKU_LeftControl               = 0xE0,
    kKU_LeftShift                 = 0xE1,
    kKU_LeftOption                = 0xE2,
    kKU_LeftCommand               = 0xE3,
    kKU_RightControl              = 0xE4,
    kKU_RightShift                = 0xE5,
    kKU_RightOption               = 0xE6,
    kKU_RightCommand              = 0xE7,
    
    // E8 ~ FFFF Reserved
};
