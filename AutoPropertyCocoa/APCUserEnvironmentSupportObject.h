//
//  APCUserEnvironmentSupportObject.h
//  AutoPropertyCocoa
//
//  Created by Novo on 2019/4/30.
//  Copyright © 2019 Novo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+APCExtension.h"
#import <objc/message.h>
#import "APCScope.h"

@class APCUserEnvironmentSupportObject;

@protocol APCUserEnvironmentMessage <NSObject>
- (nullable id<APCUserEnvironmentMessage>)superObject;
@end

typedef id id_apc_t;

#ifndef DEBUG

OBJC_EXPORT void
apc_debug_super_method_void1(id_apc_t _Nonnull instance);

OBJC_EXPORT void
apc_debug_super_method_void2(id_apc_t _Nonnull instance, id _Nullable object);

OBJC_EXPORT BOOL
apc_debug_super_method_BOOL2(id_apc_t _Nonnull instance, id _Nullable object);

OBJC_EXPORT id _Nullable
apc_debug_super_method_id1(id_apc_t _Nonnull instance);


#define APCSuperMethod_void(...) \
submacro_apc_concat(apc_debug_super_method_void, submacro_apc_argcount(__VA_ARGS__))(__VA_ARGS__)

#define APCSuperMethod_BOOL(...) \
submacro_apc_concat(apc_debug_super_method_BOOL, submacro_apc_argcount(__VA_ARGS__))(__VA_ARGS__)

#define APCSuperMethod_id(...) \
submacro_apc_concat(apc_debug_super_method_id, submacro_apc_argcount(__VA_ARGS__))(__VA_ARGS__)

#define apc_debug_super_method_void0 apc_debug_super_method_void1
#define apc_debug_super_method_void3 apc_debug_super_method_void2
#define apc_debug_super_method_void4 apc_debug_super_method_void2
#define apc_debug_super_method_void5 apc_debug_super_method_void2
#define apc_debug_super_method_void6 apc_debug_super_method_void2

#define apc_debug_super_method_BOOL0 apc_debug_super_method_BOOL2
#define apc_debug_super_method_BOOL1 apc_debug_super_method_BOOL2
#define apc_debug_super_method_BOOL3 apc_debug_super_method_BOOL2
#define apc_debug_super_method_BOOL4 apc_debug_super_method_BOOL2
#define apc_debug_super_method_BOOL5 apc_debug_super_method_BOOL2
#define apc_debug_super_method_BOOL6 apc_debug_super_method_BOOL2

#define apc_debug_super_method_id0 apc_debug_super_method_id1
#define apc_debug_super_method_id2 apc_debug_super_method_id1
#define apc_debug_super_method_id3 apc_debug_super_method_id1
#define apc_debug_super_method_id4 apc_debug_super_method_id1
#define apc_debug_super_method_id5 apc_debug_super_method_id1
#define apc_debug_super_method_id6 apc_debug_super_method_id1

#else

#define APCSuperMethod APCSuperMethod_void

#define APCSuperMethod_void(instance, ...) \
\
if(YES == [(id)instance isProxy]){         \
\
((void(*)(submacro_apc_msgSend_t_list(__VA_ARGS__)))objc_msgSend)\
    (                                                   \
        [(APCUserEnvironmentSupportObject*)instance superMessage]             \
        , [(APCUserEnvironmentSupportObject*)instance action]                 \
        , [(APCUserEnvironmentSupportObject*)instance self]                   \
        , ##__VA_ARGS__                                 \
    );\
}

#define APCSuperMethod_BOOL(instance, ...) \
\
((YES == [(id)instance isProxy])\
?                               \
((BOOL(*)(submacro_apc_msgSend_t_list(__VA_ARGS__)))objc_msgSend)\
(                                                       \
    [(APCUserEnvironmentSupportObject*)instance superMessage]                 \
    , [(APCUserEnvironmentSupportObject*)instance action]                     \
    , [(APCUserEnvironmentSupportObject*)instance self]                       \
    , ##__VA_ARGS__                                     \
) : NO)

#define APCSuperMethod_id(instance, ...) \
\
((YES == [(APCUserEnvironmentSupportObject*)instance isProxy])  \
?                                                   \
((id(*)(submacro_apc_msgSend_t_list(__VA_ARGS__)))objc_msgSend)  \
(                                                       \
    [(APCUserEnvironmentSupportObject*)instance superMessage]                 \
    , [(APCUserEnvironmentSupportObject*)instance action]                     \
    , [(APCUserEnvironmentSupportObject*)instance self]                       \
    , ##__VA_ARGS__                                     \
) : nil)

#define submacro_apc_msgSend_t_list(...)\
\
submacro_apc_concat(submacro_apc_t_list_ , submacro_apc_argcount(__VA_ARGS__))

#define submacro_apc_t_list_6 id,SEL,id,id,id,id
#define submacro_apc_t_list_5 id,SEL,id,id,id
#define submacro_apc_t_list_4 id,SEL,id,id,id
#define submacro_apc_t_list_3 id,SEL,id,id,id
#define submacro_apc_t_list_2 id,SEL,id,id
#define submacro_apc_t_list_1 id,SEL,id
#define submacro_apc_t_list_0 apc_t_list_1

#endif


#define APCUserEnvironmentObject(object, msg) \
\
([[APCUserEnvironmentSupportObject alloc] initWithObject:object message:msg action:_cmd])

/**
 The behavior of the proxy object is the same as that of the normal object.
 */
@interface APCUserEnvironmentSupportObject<MessageType> : NSProxy
- (nonnull id_apc_t)initWithObject:(nonnull NSObject*)object
                               message:(nonnull MessageType<APCUserEnvironmentMessage>)message
                                action:(nonnull SEL)action;
- (nullable MessageType)superMessage;

- (nonnull SEL)action;

/**
 Overwrite <NSObject>.
 Returns the object that actually responds to the message
 */
- (nonnull id)self;

- (void)apc_performUserSuperVoidWithObject:(nullable id)object ;
- (void)apc_performUserSuperVoid;
- (BOOL)apc_performUserSuperBOOLWithObject:(nullable id)object;
- (nullable id)apc_performUserSuperID;
@end
