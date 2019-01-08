//
//  NSError+HHError.m
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import "NSError+HHError.h"

NSString * const HHErrorDomain = @"com.HHroute.error";

@implementation NSError (HHError)
+(NSError *)HHNotFoundError{
    return [self HHErrorWithCode:HHErrorNotFound msg:@"The passed URL does not match a registered route."];
}
+(NSError *)HHTransitionError{
    
    return [self HHErrorWithCode:HHErrorHandlerTargetOrSourceViewControllerNotSpecified msg:@"TargetViewController or SourceViewController not correct"];
}
+(NSError *)HHHandleBlockNoTeturnRequest
{
    return [self HHErrorWithCode:HHErrorBlockHandleNoReturnRequest msg:@"Block handle no turn HHRouteRequest object"];
}

+(NSError *)HHMiddlewareRaiseErrorWithMsg:(NSString *)error{
    return [self HHErrorWithCode:HHErrorMiddlewareRaiseError msg:[NSString stringWithFormat:@"HHRouteMiddle raise a error:%@",error]];
}
+(NSError *)HHHandleRequestErrorWithMessage:(NSString *)errorMsg;
{
    return [self HHErrorWithCode:HHErrorHandleRequestError msg:[NSString stringWithFormat:@"HHHandler raise a error:%@",errorMsg]];
}
+(NSError *)HHErrorWithCode:(NSInteger)code msg:(NSString *)msg{
    NSDictionary *userInfo = @{ NSLocalizedDescriptionKey: NSLocalizedString(msg, nil) };
    return [NSError errorWithDomain:HHErrorDomain code:code userInfo:userInfo];
}
@end

