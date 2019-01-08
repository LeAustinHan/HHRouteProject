//
//  HHRouteMatcher.h
//  HHRouterTestDemo
//  URL与Handle的匹配关系，规则,该对象会根据url匹配表达式生成一个HHRouteRequest路由请求对象，如果为nil则说明不匹配，如果不为nil则说明该url可以匹配.
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HHRouteRequest.h"

//@class HHRouteRequest;

@interface HHRouteMatcher : NSObject

@property (nonatomic,copy) NSString *routeExpressionPattern;

@property (nonatomic,copy) NSString *originalRouteExpression;


+(instancetype)matchRouteExpression:(NSString *)expression;

//通过传入url和参数，检查是否返回request请求
- (HHRouteRequest *)createRequestWithURL:(NSURL *)url primitiveParameters:(NSDictionary *)primitiveParameters targetCallback:(HHRouteCompletionHandler )targetCallback;

@end

