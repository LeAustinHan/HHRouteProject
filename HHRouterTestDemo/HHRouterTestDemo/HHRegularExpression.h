//
//  HHRegularExpression.h
//  HHRouterTestDemo
//  提供匹配和转换标准正则表达式的功能
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HHMatchResult;

@interface HHRegularExpression : NSRegularExpression

/**
 This method can return a WLRMatchResult object to check a url string is matched.
 
 @param string a url string
 @return matching result
 */
-(HHMatchResult *)matchResultForString:(NSString *)string;

+(HHRegularExpression *)expressionWithPattern:(NSString *)pattern;

@end

