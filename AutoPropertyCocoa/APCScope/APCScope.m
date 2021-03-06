#ifndef __APCScope__H__
#define __APCScope__H__

#import <Foundation/Foundation.h>

NSString *const  APCProgramingType_ptr               =   @"void*";
NSString *const  APCProgramingType_charptr           =   @"char*";
NSString *const  APCProgramingType_id                =   @"id";
NSString *const  APCProgramingType_NSBlock           =   @"NSBlock";
NSString *const  APCProgramingType_SEL               =   @"SEL";
NSString *const  APCProgramingType_char              =   @"char";
NSString *const  APCProgramingType_unsignedchar      =   @"unsigned char";
NSString *const  APCProgramingType_int               =   @"int";
NSString *const  APCProgramingType_unsignedint       =   @"unsigned int";
NSString *const  APCProgramingType_short             =   @"short";
NSString *const  APCProgramingType_unsignedshort     =   @"unsigned short";
NSString *const  APCProgramingType_long              =   @"long";
NSString *const  APCProgramingType_unsignedlong      =   @"unsigned long";
NSString *const  APCProgramingType_longlong          =   @"long long";
NSString *const  APCProgramingType_unsignedlonglong  =   @"unsigned long long";
NSString *const  APCProgramingType_float             =   @"float";
NSString *const  APCProgramingType_double            =   @"double";
NSString *const  APCProgramingType_Bool              =   @"_Bool";

#if __LP64__
char *const  APCDeallocMethodEncoding                =   "v16@0:8";
char *const  APCGetterMethodEncoding                 =   "@16@0:8";
char *const  APCSetterMethodEncoding                 =   "v24@0:8@16";
#else
char *const  APCDeallocMethodEncoding                =   "v8@0:4";
char *const  APCGetterMethodEncoding                 =   "@8@0:4";
char *const  APCSetterMethodEncoding                 =   "v12@0:4@8";
#endif

#endif
