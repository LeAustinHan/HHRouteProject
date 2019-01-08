//
//  HHRouter.m
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import "HHRouter.h"

#import <objc/runtime.h>
#import "HHRouteHandler.h"
#import "HHRouteMatcher.h"
#import "HHRouteRequest.h"
#import "NSError+HHError.h"

@interface HHRouter()

@property(nonatomic,strong)NSMutableDictionary * routeMatchers;
@property(nonatomic,strong)NSMutableDictionary * routeHandles;
@property(nonatomic,strong)NSMutableDictionary * routeblocks;
@property(nonatomic,strong)NSHashTable * middlewares;

@end

@implementation HHRouter

- (void)registerHandler:(HHRouteHandler *)routeHandler forRoute:(NSString *)route{
    
}

- (BOOL)canHandleWithURL:(NSURL *)url{
    return NO;
}

- (BOOL)routeObjectHandleURL:(NSURL *)url
         primitiveParameters:(NSDictionary *)primitiveParameters
              targetCallback:(void(^)(NSError *error,NSDictionary *responseObject))targetCallback
      withComplitionCallBack:(void(^)(BOOL handled, NSError *error))completionCallBack{
    
    
    return NO;
}

- (void)registerBlock:(HHRouteRequest *(^)(HHRouteRequest * request))routeHandlerBlock forRoute:(NSString *)route{
    //首先添加一个HHRouteMatcher实例
    if (routeHandlerBlock&&[route length]) {
        [self.routeMatchers setObject:[HHRouteMatcher matchRouteExpression:route] forKey:route];
        //删除route对应的handler对象
        [self.routeHandles removeObjectForKey:route];
        //将routeHandlerBlock和route存入对应关系的字典中
        self.routeblocks[route] = routeHandlerBlock;
    }
}


@end
