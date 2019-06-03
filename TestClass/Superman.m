//
//  Superman.m
//  AutoPropertyCocoa
//
//  Created by Meterwhite on 2019/4/10.
//  Copyright (c) 2019 GitHub, Inc. All rights reserved.
//

#import "Superman.h"

@implementation Superman
{
    id _apc_supermanRealizeToPerson;
}

- (id)supermanRealizeToPerson
{
    
    NSLog(@"APCTest << %s << _apc_supermanRealizeToPerson = %@", __func__, _apc_supermanRealizeToPerson);
    return _apc_supermanRealizeToPerson;
}

- (void)setSupermanRealizeToPerson:(id)supermanRealizeToPerson
{
    NSLog(@"APCTest << %s << _apc_supermanRealizeToPerson = %@", __func__, supermanRealizeToPerson);
    _apc_supermanRealizeToPerson = supermanRealizeToPerson;
}

- (void)fly
{
    NSLog(@"Shoo~~~");
}

@end
