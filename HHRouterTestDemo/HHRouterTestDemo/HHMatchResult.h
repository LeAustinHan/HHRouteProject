//
//  HHMatchResult.h
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface HHMatchResult : NSObject
/**
 If matched,value is YES.
 */
@property (nonatomic, assign, getter=isMatch) BOOL match;
/**
 If matched,the paramProperties dictionary  will store url's path keyword paramaters away.
 如果匹配成功，url路径中的关键字对应的值将存储在该字典中.
 */
@property (nonatomic, strong) NSDictionary *paramProperties;
@end
