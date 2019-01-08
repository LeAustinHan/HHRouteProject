//
//  HHRouteRequest.m
//  HHRouterTestDemo
//  请求是消费型的？？要防止重复处理？？？isConsumed
//  Created by HanHan on 2019/1/7.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import "HHRouteRequest.h"

#import "NSString+HHQuery.h"

@implementation HHRouteRequest

- (void)objectForKeySubscript:(NSString *)key{
    
}

//初始化方法，把url的键值对取出来，初始化其他属性
- (instancetype)initWithURL:(NSURL *)url
            routeExpression:(NSString *)routeExpression
            routeParameters:(NSDictionary *)routeParameters
        primitiveParameters:(NSDictionary *)primitiveParameters targetCallback:(HHRouteCompletionHandler )targetCallback{
    if (!url) {
        return nil;
    }
    self = [super init];
    if (self) {
        _url = url;
        _queryParameters = [[_url query] HHParametersFromQueryString];
        _routeExpression = routeExpression;
        _routeParameters = routeParameters;
        _primitiveParameters = primitiveParameters;
        self.targetCallback = targetCallback;
    }
    return self;
}

- (instancetype)initWithURL:(NSURL *)url{
    if(!url){
        return nil;
    }
    self = [super init];
    if (self) {
        _url = url;
        //获取url的键值对,本身url类中就有quary键值对属性
        _queryParameters = [[_url query] HHParametersFromQueryString];
    }
    return self;
}


-(void)setRouteParameters:(NSDictionary *)routeParameters{
    _routeParameters = routeParameters;
    
}
-(void)setPrimitiveParameters:(NSDictionary *)primitiveParameters{
    _primitiveParameters = primitiveParameters;
}

//- (nonnull id)copyWithZone:(nullable NSZone *)zone {
//}

-(id)copyWithZone:(NSZone *)zone{
    HHRouteRequest * copyRequest = [[HHRouteRequest alloc]initWithURL:self.url];
    //本身是readonly，因为重写了set方法，所以可以点引用
    copyRequest.routeParameters = self.routeParameters;
    copyRequest.routeExpression = self.routeExpression;
    copyRequest.primitiveParameters = self.primitiveParameters;
    copyRequest.targetCallback = self.targetCallback;
    copyRequest.isConsumed = self.isConsumed;
    self.isConsumed = YES;
    return copyRequest;
}

//HHRouteCompletionHandler targetCallback;
- (void)setTargetCallback:(HHRouteNormalCallBack)targetCallback{
    __weak HHRouteRequest *weakSelf = self;
    if (targetCallback == nil) {
        return;
    }
    self.isConsumed = NO;
    _targetCallback = ^(NSError *error,id responseObject){
        weakSelf.isConsumed = YES;
        targetCallback(error,responseObject);
    };
}

- (void)defaultFinishTargetCallback{
    if (self.targetCallback && self.isConsumed == NO) {
        self.targetCallback(nil, @"正常回调");
    }
}

@end
