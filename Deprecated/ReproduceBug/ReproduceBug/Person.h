//
//  Person.h
//  ReproduceBug
//
//  Created by NOVO on 2019/5/16.
//  Copyright © 2019 NOVO. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
{
@public
    
    Class _proxyClass;
}
@property (nonatomic,strong) id obj;

@end

NS_ASSUME_NONNULL_END
