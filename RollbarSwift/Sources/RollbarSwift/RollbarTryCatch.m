//
//  RollbarTryCatch.m
//  
//
//  Created by Andrey Kornich on 2021-03-04.
//

//
//  SwiftTryCatch.h
//
//  Created by William Falcon on 10/10/14.
//  Copyright (c) 2014 William Falcon. All rights reserved.
//
/*
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#import "RollbarTryCatch.h"

@implementation RollbarTryCatch

+ (void)try:(__attribute__((noescape)) void(^ _Nullable)(void))tryBlock
      catch:(__attribute__((noescape)) void(^ _Nullable)(NSException* exception))catchBlock
    finally:(__attribute__((noescape)) void(^ _Nullable)(void))finallyBlock {
    
    @try {
        
        if (NULL != tryBlock) {
            
            tryBlock();
        }
    }
    @catch (NSException *exception) {
        
        if (NULL != catchBlock) {
            
            catchBlock(exception);
        }
    }
    @finally {
        
        if (NULL != finallyBlock) {
            
            finallyBlock();
        }
    }
}

+ (void)throwString:(NSString*)string {
    
    NSException *exception = [NSException exceptionWithName:string
                                                     reason:string
                                                   userInfo:nil];
    [RollbarTryCatch throwException:exception];
}

+ (void)throwException:(NSException*)exception {
    
    @throw exception;
}

@end
