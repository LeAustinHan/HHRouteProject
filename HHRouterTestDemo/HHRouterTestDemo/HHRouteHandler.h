////根据request，找到目标VCL
//  HHRouteHandler.h
//  HHRouterTestDemo
//  处理HHRouteRequest，回调给调用者
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class HHRouteRequest;//前置引用类

@interface HHRouteHandler : NSObject

//是否要处理请求,检查工作
- (BOOL)shouldHandleWithRequest:(HHRouteRequest *)routeRequest;
//处理请求，核心方法
- (BOOL)handleRequest:(HHRouteRequest *)routeRequest error:(NSError *__autoreleasing *)error;
//用请求获取目标VCL
- (UIViewController *)targetViewControllerWithRequest:(HHRouteRequest *)routeRequest;
//用请求获取专场中源VCL
- (UIViewController *)sourceViewControllerFormTransitionWithRequest:(HHRouteRequest *)routeRequest;
//完成专场逻辑，用请求，源VCL，目标VCL，...
- (BOOL)transitionWithRequest:(HHRouteRequest *)routeRequest
         sourceViewController:(UIViewController *)sourceViewController
         targetViewController:(UIViewController *)targetViewController
                isPreferModal:(BOOL)isPreferModel
                        error:(NSError *__autoreleasing*)error;
//根据request返回是否模态跳转
- (BOOL)preferModalPresentationWithRequest:(HHRouteRequest *)routeRequest;


@end
