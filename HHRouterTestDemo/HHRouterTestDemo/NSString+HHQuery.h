//
//  NSString+HHQuery.h
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (HHQuery)

+ (NSString *)HHQueryStringWithParameters:(NSDictionary *)parameters ;
- (NSDictionary *)HHParametersFromQueryString ;
- (NSString *)HHStringByAddingPercentEscapesUsingEncoding:(NSStringEncoding)encoding ;
- (NSString *)HHStringByReplacingPercentEscapesUsingEncoding:(NSStringEncoding)encoding;

@end

