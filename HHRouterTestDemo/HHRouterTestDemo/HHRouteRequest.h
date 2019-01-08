//
//  HHRouteRequest.h
//  HHRouterTestDemo
//  路由请求，以URL为基础，是对URL进行的封装，把URL携带的字符串，按照一定规则分解成路由
//  需要的页面，参数等数据
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^HHRouteCompletionHandler)(NSError *error,NSDictionary *responseObject);

typedef void(^HHRouteNormalCallBack)(NSError *error,id responseObject);

@interface HHRouteRequest : NSObject<NSCopying>

@property (nonatomic, copy,readonly) NSURL *url;

@property (nonatomic, strong) NSString *routeExpression;
//查询参数，对应url的键值对
@property (nonatomic, copy, readonly) NSDictionary *queryParameters;
//路径参数，找到App内部相应的页面用
@property (nonatomic, copy, readonly) NSDictionary *routeParameters;
//原生参数，App某一页面使用的具体参数
@property (nonatomic, copy, readonly) NSDictionary *primitiveParameters;

@property (nonatomic, copy) HHRouteNormalCallBack targetCallback;
//？？？是否消费掉，一个request只能处理一次，该字段反应request是否被处理过【防止重复解析？？？】
@property (nonatomic, assign)BOOL isConsumed;


/**
 下标发去参数？？？

 @param key 参数
 */
- (void)objectForKeySubscript:(NSString *)key;

/**
 核心方法

 @param url url
 @param routeExpression url路由表达式
 @param routeParameters 路由参数，路径
 @param primitiveParameters 页面原始参数
 @param targetCallback 目标回调
 @return 返回request
 */
- (instancetype)initWithURL:(NSURL *)url
            routeExpression:(NSString *)routeExpression
            routeParameters:(NSDictionary *)routeParameters
        primitiveParameters:(NSDictionary *)primitiveParameters targetCallback:(HHRouteCompletionHandler )targetCallback;

- (instancetype)initWithURL:(NSURL *)url;

- (void)defaultFinishTargetCallback;

@end

