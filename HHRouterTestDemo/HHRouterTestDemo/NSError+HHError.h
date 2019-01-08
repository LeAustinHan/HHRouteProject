//
//  NSError+HHError.h
//  HHRouterTestDemo
//
//  Created by HanHan on 2019/1/8.
//  Copyright © 2019 HanHan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, HHError) {
    
    /** The passed URL does not match a registered route. */
    HHErrorNotFound = 45150,
    
    /** The matched route handler does not specify a target view controller. */
    HHErrorHandlerTargetOrSourceViewControllerNotSpecified = 45151,
    HHErrorBlockHandleNoReturnRequest = 45152,
    HHErrorMiddlewareRaiseError = 45153,
    HHErrorHandleRequestError = 45154
};
@interface NSError (HHError)
+(NSError *)HHNotFoundError;
+(NSError *)HHTransitionError;
+(NSError *)HHHandleBlockNoTeturnRequest;
+(NSError *)HHMiddlewareRaiseErrorWithMsg:(NSString *)error;
+(NSError *)HHHandleRequestErrorWithMessage:(NSString *)errorMsg;
@end
