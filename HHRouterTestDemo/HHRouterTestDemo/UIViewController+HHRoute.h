//
//  UIViewController+HHRoute.h
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HHRouteRequest;

@interface UIViewController (HHRoute)

@property(nonatomic,strong)HHRouteRequest * hh_request;

@end
