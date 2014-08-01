//
//  TwitchKit.h
//  Twitch Plugin
//
//  Created by Auston Stewart on 1/21/14.
//  Copyright (c) 2014 Twitch Interactive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const TKChannelListingWasPresentedNotification;
extern NSString *const TKChannelListingWasDismissedNotification;
extern NSString *const TKLoginViewWasPresentedNotification;
extern NSString *const TKLoginViewWasDismissedNotification;
extern NSString *const TKWillLaunchTwitchAppNotification;
extern NSString *const TKUserSelectedChannelNotification;

extern NSString *const TKAuthTokenUserInfoKey;
extern NSString *const TKErrorUserInfoKey;

typedef enum {
	TKStreamPresentationModeUseTwitchAppIfInstalled,
	TKStreamPresentationModeRemainInApp
} TKStreamPresentationMode;

@interface TwitchKit : NSObject

// Obtain the shared plugin instance
+ (TwitchKit *) sharedPlugin;

// Display a list of live streams for the specified game
- (void)presentStreamListForGameTitle:(NSString *)gameTitle mode:(TKStreamPresentationMode)mode;

// Present a live channel in the Twitch app
- (void)presentStreamForChannelNamed:(NSString *)channel mode:(TKStreamPresentationMode)mode;

// Log the user in to obtain an auth token for broadcasting
- (void)presentLoginViewForClientID:(NSString *)clientID redirectURI:(NSString *)redirectURI;

@end
