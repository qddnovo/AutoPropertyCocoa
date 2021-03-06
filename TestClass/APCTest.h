//
//  APCTest.h
//  AutoPropertyCocoa
//
//  Created by Meterwhite on 2019/4/8.
//  Copyright (c) 2019 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define APC_TEST_DEMO(domo,id) + (void)domo##__##id

@interface APCTest : NSObject

+ (void)openClearTest;
+ (void)closeClearTest;

+ (void)testDemo:(NSUInteger)index;
+ (void)testDemoFrom:(NSUInteger)from to:(NSUInteger)to;

APC_TEST_DEMO(removeMethod,0);

#pragma mark - unhook
APC_TEST_DEMO(ClassUnhook           , 100);
APC_TEST_DEMO(InstanceUnhook        , 101);
APC_TEST_DEMO(ClassLazyload         , 102);
APC_TEST_DEMO(InstanceLazyload      , 103);
APC_TEST_DEMO(ClassTrigger          , 104);
APC_TEST_DEMO(InstanceTrigger       , 105);
APC_TEST_DEMO(ClassMix              , 106);
APC_TEST_DEMO(InstanceMix           , 107);
APC_TEST_DEMO(ClassInstanceMix      , 108);
APC_TEST_DEMO(UserEnviroment        , 109);
APC_TEST_DEMO(BasicValue            , 110);
APC_TEST_DEMO(InstanceMultiThread   , 111);
APC_TEST_DEMO(ClassMultiThread      , 112);

@end

NS_ASSUME_NONNULL_END
