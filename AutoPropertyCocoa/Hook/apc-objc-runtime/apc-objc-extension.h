//
//  apc-objc-private.hpp
//  Test123123
//
//  Created by MDLK on 2019/5/5.
//  Copyright © 2019 MDLK. All rights reserved.
//

#ifndef APC_OBJC_PRIVATE
#define APC_OBJC_PRIVATE

#import <objc/runtime.h>

#if defined __cplusplus
extern "C"
{
#endif
    
    /**
     Does not affect the super class
     The runtimelock is not locked when the function is called.
     So avoid the write behavior of other threads to the method_list of that Class when the function is called.
     */
    void class_removeMethod_APC_OBJC2(Class _Nonnull cls, SEL _Nonnull name);
    
    IMP _Nullable class_itMethodImplementation_APC(Class _Nonnull cls, SEL _Nonnull name);
    
#if defined __cplusplus
};
#endif

#endif /* APC_OBJC_PRIVATE */

