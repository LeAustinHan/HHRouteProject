//
//  HHRouter.h
//  HHRouterTestDemo
//  路由器，核心部分,供其他模块调用,完成对URL的拦截和处理并返回结果,
// 保存了需要匹配拦截的URL表达式
// 对于匹配上的Url需要有对应的Handler处理
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HHRouteRequest;
@class HHRouteHandler;


@interface HHRouter : NSObject
/**
 注册[Url表达式]对应到Handler的功能

 @param routeHandler block用以处理匹配route表达式的url的请求
 @param route url的路由表达式，支持正则表达式的分组，例如app://login/:phone({0,9+})是一个表达式，:phone代表该路径值对应的key,可以在WLRRouteRequest对象中的routeParameters中获取
 */
- (void)registerHandler:(HHRouteHandler *)routeHandler forRoute:(NSString *)route;
/**
 根据URL是否能够匹配handle

 @param url 调用的url
 @return能否handle处理
 */
- (BOOL)canHandleWithURL:(NSURL *)url;

/**
 处理url请求，传入Url和参数就能匹配到Handler的功能

 @param url 调用的url
 @param primitiveParameters 原始参数
 @param targetCallback 传给目标对象的回调block
 @param completionCallBack 完成路由中转的block
 @return 能否handle处理
 */
- (BOOL)routeObjectHandleURL:(NSURL *)url
         primitiveParameters:(NSDictionary *)primitiveParameters
              targetCallback:(void(^)(NSError *error,NSDictionary *responseObject))targetCallback
      withComplitionCallBack:(void(^)(BOOL handled, NSError *error))completionCallBack;


/**
 注册block

 @param routeHandlerBlock block用以处理匹配route表达式的url的请求
 @param route url的路由表达式，支持正则表达式的分组，例如app://login/:phone({0,9+})是一个表达式，:phone代表该路径值对应的key,可以在WLRRouteRequest对象中的routeParameters中获取
 */
-(void)registerBlock:(HHRouteRequest *(^)(HHRouteRequest * request))routeHandlerBlock forRoute:(NSString *)route;

@end

