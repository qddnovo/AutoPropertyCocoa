//
//  APCClassMapper.h
//  AutoPropertyCocoa
//
//  Created by Meterwhite on 2019/4/20.
//  Copyright (c) 2019 GitHub, Inc. All rights reserved.
//

#import "APCScope.h"


/**
 Thread safe
 */
@interface APCClassMapper : NSObject<NSFastEnumeration>

- (BOOL)containsClass:(nonnull Class)cls;

/**
 Must first check if the Class exists.
 */
- (void)addClass:(nonnull Class)cls;

/**
 Must first check if the Class exists.
 */
- (void)removeClass:(nonnull Class)cls;

/**
 Subclasses included.
 */
- (void)removeKindOfClass:(nonnull Class)cls;

- (void)removeAllClasses;

- (nullable Class)superclassOfClass:(nonnull Class)cls;

@end
