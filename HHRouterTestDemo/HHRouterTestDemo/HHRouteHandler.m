//
//  HHRouteHandler.m
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import "HHRouteHandler.h"

#import "NSError+HHError.h"
#import "UIViewController+HHRoute.h"

@implementation HHRouteHandler

- (BOOL)shouldHandleWithRequest:(HHRouteRequest *)routeRequest{
    return YES;
}

//准备好转场所需要的一切，包括是否模态跳转，目标控制器，源控制器，
- (BOOL)handleRequest:(HHRouteRequest *)routeRequest error:(NSError *__autoreleasing *)error{
    UIViewController *sourceVCL = [self sourceViewControllerFormTransitionWithRequest:routeRequest];
    UIViewController *targetVCL = [self targetViewControllerWithRequest:routeRequest];
    if ((![sourceVCL isKindOfClass:[UIViewController class]])||(![targetVCL isKindOfClass:[UIViewController class]])) {
        *error = [NSError HHTransitionError];
        return NO;
    }
    
    if (targetVCL != nil) {
        targetVCL.hh_request = routeRequest;
    }
    
    BOOL isPreferModal = [self preferModalPresentationWithRequest:routeRequest];
    
    return [self transitionWithRequest:routeRequest sourceViewController:sourceVCL targetViewController:targetVCL isPreferModal:isPreferModal error:error];
}

- (UIViewController *)targetViewControllerWithRequest:(HHRouteRequest *)routeRequest{
    return [[NSClassFromString(@"HBTestViewController") alloc]init];
}

- (UIViewController *)sourceViewControllerFormTransitionWithRequest:(HHRouteRequest *)routeRequest{
    return [UIApplication sharedApplication].windows[0].rootViewController;
}

- (BOOL)transitionWithRequest:(HHRouteRequest *)routeRequest
         sourceViewController:(UIViewController *)sourceViewController
         targetViewController:(UIViewController *)targetViewController
                isPreferModal:(BOOL)isPreferModel
                        error:(NSError *__autoreleasing*)error{
    return YES;
}

- (BOOL)preferModalPresentationWithRequest:(HHRouteRequest *)routeRequest{
    return NO;
}
@end
