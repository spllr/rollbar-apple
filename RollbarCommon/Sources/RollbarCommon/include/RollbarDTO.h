//
//  RollbarDTO.h
//  Rollbar
//
//  Created by Andrey Kornich on 2019-10-08.
//  Copyright © 2019 Rollbar. All rights reserved.
//

#ifndef RollbarDTO_h
#define RollbarDTO_h

#import "RollbarJSONSupport.h"

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/// The foundation for defining Rollbar Data Transfer Objects (DTOs)
@interface RollbarDTO : NSObject <RollbarJSONSupport> {
    @private
    id _data;
        //...
    
    //@protected
        //...

    @private
    NSMutableDictionary<NSString *, id> *_dataDictionary;
    NSMutableArray *_dataArray;
}

/// Checks if the provided object is transferrable (ie could be converted to/from JSON)
/// @param obj the object in question
+ (BOOL)isTransferableObject:(id)obj;

/// Checks if the provided object could be used as a DTO property/data value
/// @param obj the object in question
+ (BOOL)isTransferableDataValue:(id)obj;

/// Returns list of the property names of this DTO
- (NSArray *)getDefinedProperties;

/// Checks if the provided DTO has same defined properties as this instance
/// @param otherDTO the other DTO to compare with
- (BOOL)hasSameDefinedPropertiesAs:(RollbarDTO *)otherDTO;

/// Signifies that this DTO doesn't carry any useful data and is just an empty transport "shell"
@property (nonatomic, readonly) BOOL isEmpty;

#pragma mark - Initializers

/// Initialize this DTO instance with valid JSON data string seed
/// @param jsonString valid JSON data string seed
- (instancetype)initWithJSONString:(NSString *)jsonString;

/// Initialize this DTO instance with valid JSON  NSData seed
/// @param data valid JSON NSData seed
- (instancetype)initWithJSONData:(NSData *)data;

/// Initialize this DTO instance with valid JSON NSDictionary seed
/// @param data valid JSON NSDictionary seed
- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)data
NS_DESIGNATED_INITIALIZER;

/// Initialize this DTO instance with valid JSON NSArray seed
/// @param data valid JSON NSArray seed
- (instancetype)initWithArray:(NSArray *)data
NS_DESIGNATED_INITIALIZER;

/// Initialize empty DTO
- (instancetype)init
NS_DESIGNATED_INITIALIZER;


/// @abstract use any of initWith... initializers instead of this one
//- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

#endif //RollbarDTO_h
