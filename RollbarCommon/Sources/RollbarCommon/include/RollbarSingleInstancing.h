//
//  RollbarSingleInstancing.h
//  
//
//  Created by Andrey Kornich on 2021-04-23.
//

#ifndef Header_h
#define Header_h

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Defines a protocol of a Singleton
@protocol RollbarSingleInstancing

@required

+ (instancetype)sharedInstance;

+ (instancetype)alloc NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)allocWithZone:(NSZone *)zone NS_UNAVAILABLE;

- (instancetype)copy NS_UNAVAILABLE;

- (instancetype)copyWithZone:(NSZone *)zone NS_UNAVAILABLE;

- (instancetype)mutableCopy NS_UNAVAILABLE;

- (instancetype)mutableCopyWithZone:(NSZone *)zone NS_UNAVAILABLE;

@optional

+ (void)attemptDealloc;

+ (BOOL)sharedInstanceExists;

@end



NS_ASSUME_NONNULL_END

#endif /* Header_h */
