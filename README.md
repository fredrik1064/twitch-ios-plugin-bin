###TwitchKit v2.0 Integration Notes

###Integration
TwitchKit enables you to embed a list of live streams for your iOS game with minimal effort. To display UI, TwitchKit must be running on a device with iOS 7.0 or later.
To add TwitchKit to your project, simply drop TwitchKit.framework and TwitchKit.bundle to the Frameworks section of your project in Xcode. Then, include the TwitchKit header file and invoke the presentStreamListForGameTitle:mode: with the name of your game:

`#import <TwitchKit/TwitchKit.h>`   
  
`...`  
  
`- (IBAction)presentStreams:(id)sender`  
`{`  
 <space><space>`[[TwitchKit sharedPlugin] presentStreamListForGameTitle:@"Minecraft" mode:TKStreamPresentationModeRemainInApp];`  
`}`  

###What it does

When presentStreamListForGameTitle:mode: is invoked, TwitchKit will present a modal view controller from your app’s window’s root view controller. An infinite-scrolling grid or list (depending on device and orientation) of stream previews will be displayed. When the user selects a stream, the Twitch app will be launched to play it if it is installed and TKStreamPresentationModeUseTwitchAppIfInstalled is specified. If you instead specify TKStreamPresentationModeRemainInApp, video playback will occur in another modal view controller.

You may also invoke presentStreamForChannelNamed:mode: to immediately begin playback of a specific live channel.

If you are integrating with our iOS broadcasting SDK, you may invoke presentLoginViewForClientID:redirectURI: to present a localized login view modal and obtain an authentication token.

###Notifications
TwitchKit posts the following notifications to the default NSNotificationCenter:

**TKChannelListingWasPresentedNotification** <— Sent after the channel listing has animated in

**TKChannelListingWasDismissedNotification** <- Sent after the channel listing has animated out

**TKUserSelectedChannelNotification** <- Sent when a user taps on a channel (channel name is in the ‘channel’ member of the userInfo dictionary)

**TKWillLaunchTwitchAppNotification** <- Sent before the Twitch app is launched to play a stream

**TKLoginViewWasPresentedNotification** <— Sent after the login modal has animated in

**TKLoginViewWasDismissedNotification** <- Sent after the login view has animated out. If authentication was successful, the userInfo dictionary will contain the auth token as an NSString associated with TKAuthTokenUserInfoKey. If an error occured, an NSString describing it will be associated with TKErrorUserInfoKey. If neither key is present in the dictionary, the login view was dismissed by the user tapping the cancel button.

###Requirements

TwitchKit v2.0 should be deployed in applications that link against 7.0 and later versions of the iOS SDK. The Release and Debug binaries are compiled for armv7, armv7s and i386 architectures.

You project should also link against the following standard libraries:
ImageIO.framework
libc++.dylib
libz.dylib
UIKit.framework
Foundation.framework
CoreGraphics.framework
