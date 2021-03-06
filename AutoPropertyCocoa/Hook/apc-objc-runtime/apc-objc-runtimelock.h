//
//  APCOBJC2Runtimelock.h
//  AutoPropertyCocoa
//
//  Created by Meterwhite on 2019/5/9.
//  Copyright (c) 2019 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APCScope.h"

#ifndef APC_OBJC_RUNTIMELOCK
#define APC_OBJC_RUNTIMELOCK

/**
 @lockruntime({
    ...
 });
 */
#define lockruntime(...)\
\
submacro_apc_keywordify \
\
apc_objcruntimelock_lock(^()__VA_ARGS__)

#if DEBUG
#define APCTestCloseOBJCRuntimelock() apc_objcruntimelock_testing_delete()
#define APCTestOpenOBJCRuntimelock() apc_objcruntimelock_testing_create()
#else
#define APCTestCloseOBJCRuntimelock()
#define APCTestOpenOBJCRuntimelock()
#endif


/**
 This is a necessary step to get runtimelock,which allows APC to actually delete a method at runtime.
 
 If you always operate on an instance object, you can ignore the method.
 
 If you operate on a Class type and will unbind it, calling this method will make the process safer.
 When you operate on a Class type without calling this method,a fake non-method(like apc_null_getter) is generated to undo the behavior of the deleted method when the hooked method is unbound.
 So if you want to swizzle a method for superclass, you should clearly use your target class.If you know this, then you can not call this method.It is no problem.
 */
FOUNDATION_EXPORT void
apc_main_classHookFullSupport(void);

FOUNDATION_EXPORT _Bool
apc_contains_objcruntimelock(void);

FOUNDATION_EXPORT void
apc_objcruntimelock_lock(void(NS_NOESCAPE^userblock)(void));

#if DEBUG

FOUNDATION_EXPORT void
apc_debug_objcruntimelock_delete(void);

FOUNDATION_EXPORT void
apc_debug_objcruntimelock_create(void);

FOUNDATION_EXPORT void
apc_debug_test_objcruntimelock(void);

#endif


#endif
