/*
 * libbambuser - Bambuser iOS library
 * Copyright 2013 Bambuser AB
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import <BambuserBroadcaster/BambuserViewDelegate.h>

/**
 * @mainpage Bambuser SDK for iOS 9.0+
 *
 * @section libbambuser Bambuser broadcasting library, BambuserBroadcaster.xcframework
 * The Bambuser broadcasting library has the following dependencies:
 *
 * libz.tbd
 *
 * AudioToolbox, AVFoundation, CoreGraphics, CoreLocation, CoreMedia,
 * CoreVideo, Foundation, QuartzCore, SystemConfiguration, UIKit, VideoToolbox, CoreTelephony
 *
 * The Bambuser library also requires the C++ runtime library. If your
 * application already uses C++ directly, a C++ runtime library will
 * already be linked in, and you don't need to do anything extra. If
 * your application doesn't use C++, you need to add it manually. Add
 * libc++.tbd to the list of linked frameworks and libraries.
 *
 * @section libbambuserplayer Bambuser player library, BambuserPlayer.xcframework
 *
 * The Bambuser player library has the following dependencies:
 *
 * AudioToolbox, AVFoundation, CoreMedia, Foundation, UIKit, AVKit
 *
 * The Bambuser player library also requires the C++ runtime library. If your
 * application already uses C++ directly, a C++ runtime library will
 * already be linked in, and you don't need to do anything extra. If
 * your application doesn't use C++, you need to add it manually. Add
 * libc++.tbd to the list of linked frameworks and libraries.
 *
 */

/**
 * \anchor BambuserCameraController
 * Class for exposure, focus and white balance settings
 */
@interface BambuserCameraController : NSObject {
}
/**
 * \anchor focusMode
 * Returns focus mode for the current camera. Focus mode is set with #setFocusAt:focusMode:
 * Default focus mode is AVCaptureFocusModeContinuousAutoFocus if supported by camera, if not AVCaptureFocusModeLocked is default. At camera swap focus mode is set to default.
 *
 * @return a AVCaptureFocusMode constant
 * @see #setFocusAt:focusMode:
*/
@property (nonatomic, readonly) AVCaptureFocusMode focusMode;
/**
 * \anchor focusPointOfInterest
 * Returns current focus point of interest for the current camera. Focus point of interest is set with #setFocusAt:focusMode:
 * Default focus point of interest is in the center of the view. At camera swap focus point of interest is set to default.
 *
 * @return A CGPoint in BambuserView coordinate space
 * @see #setFocusAt:focusMode:
*/
@property (nonatomic, readonly) CGPoint focusPointOfInterestInView;
/**
 * \anchor exposureMode
 * Returns exposure mode for the current camera. Exposure mode is set with #setExposureAt:exposureMode:
 * Default exposure mode is AVCaptureExposureModeContinuousAutoExposure if supported by camera. At camera swap exposure mode is set to default.
 * Note! AVCaptureExposureModeCustom is not supported.
 *
 * @return a AVCaptureExposureMode constant
 * @see #setExposureAt:exposureMode:
*/
@property (nonatomic, readonly) AVCaptureExposureMode exposureMode;
/**
 * \anchor exposurePointOfInterest
 * Returns current exposure point of interest for the current camera. Exposure point of interest is set with #setExposureAt:exposureMode:
 * Default exposure point of interest is in the center of the view. At camera swap exposure point of interest is set to default.
 *
 * @return A CGPoint in BambuserView coordinate space
 * @see #setExposureAt:exposureMode:
*/
@property (nonatomic, readonly) CGPoint exposurePointOfInterestInView;
/**
 * \anchor exposureTargetBias
 * Bias applied to the target exposure value, in EV units, for the current camera.
 * Default value is 0. At camera swap exposureTargetBias is set to default value.
 */
@property (nonatomic) float exposureTargetBias;
/**
 * \anchor minExposureTargetBias
 * The minimum supported exposure bias, in EV units, by the current camera.
 */
@property (nonatomic, readonly) float minExposureTargetBias;
/**
 * \anchor maxExposureTargetBias
 * The maximum supported exposure bias, in EV units, by the current camera.
 */
@property (nonatomic, readonly) float maxExposureTargetBias;
/**
 * \anchor isLockingWhiteBalanceWithCustomGainsSupported
 * Returns YES if current #BambuserView::cameraPosition supports locking with custom white balance gains.
 * Custom whitebalance gains can be set with #lockWhiteBalanceGains: or #lockWhiteBalanceGainsWithTemperatureAndTintValues:
 */
@property (nonatomic, readonly) BOOL isLockingWhiteBalanceWithCustomGainsSupported;
/**
 * \anchor deviceWhiteBalanceGains
 * Returns a AVCaptureWhiteBalanceGains struct with current red, green, and blue gain values used for white balance.
 * For each channel, only values between 1.0 and #maxWhiteBalanceGain are supported.
 * Set with #lockWhiteBalanceGains:.
 */
@property (nonatomic, readonly) AVCaptureWhiteBalanceGains deviceWhiteBalanceGains;
/**
 * \anchor grayWorldDeviceWhiteBalanceGains
 * Returns a AVCaptureWhiteBalanceGains struct with current red, green, and blue gain values derived from the current scene to deliver a neutral (or gray world) white point for white balance.
 * Gray world values assume a neutral subject (for example, a gray card) has been placed in the middle of the subject area and fills the center 50% of the frame.
 * Clients can read these values and apply them to the device using #lockWhiteBalanceGains:.
 * For each channel, only values between 1.0 and #maxWhiteBalanceGain are supported.
 */
@property (nonatomic, readonly) AVCaptureWhiteBalanceGains grayWorldDeviceWhiteBalanceGains;
/**
 * \anchor whiteBalanceTemperatureAndTintValues
 * Returns a AVCaptureWhiteBalanceTemperatureAndTintValues struct with the current temperature and tint values used for white balance.
 * Set with #lockWhiteBalanceGainsWithTemperatureAndTintValues:
 */
@property (nonatomic, readonly) AVCaptureWhiteBalanceTemperatureAndTintValues whiteBalanceTemperatureAndTintValues;
/**
 * \anchor maxWhiteBalanceGain
 * The maximum supported gain value for red, green and blue components, by the current camera. Minimum value is always 1.0.
 */
@property (nonatomic, readonly) float maxWhiteBalanceGain;
/**
 * \anchor isWhiteBalanceLocked
 * Returns YES if white balance is locked and not auto adjusting. Default behaviour is auto adjusted white balance.
 */
@property (nonatomic, readonly) BOOL isWhiteBalanceLocked;
/**
 * \anchor init
 * Can't be instantiated. Get a BambuserCameraController reference using #BambuserView::cameraController
*/
- (instancetype) init NS_UNAVAILABLE;
/**
 * \anchor new
 * Can't be instantiated. Get a BambuserCameraController reference using #BambuserView::cameraController
*/
- (instancetype) new NS_UNAVAILABLE;
/**
 * \anchor isExposureModeSupported
 *
 * Returns a Boolean value that indicates whether the given exposure mode is supported.
 * Note! BambuserBroadcaster doesn't provide any interface for custom exposure settings (ISO, exposure duration),
 * therefore AVCaptureExposureModeCustom is not supported and hence always returns false.
 *
 * @param mode a AVCaptureExposureMode constant
 * @return YES if mode is supported, otherwise NO.
 */
- (BOOL) isExposureModeSupported: (AVCaptureExposureMode) mode;
/**
 * \anchor setExposureAt
 * Set exposure point of interest and exposure mode.
 * Note! AVCaptureExposureModeCustom is not supported.
 *
 * @param point a CGPoint in the BambuserView coordinate space. BambuserView will handle convertion to device coordinates
 * @param mode a AVCaptureExposureMode constant
 */
- (void) setExposureAt: (CGPoint) point exposureMode: (AVCaptureExposureMode) mode;
/**
 * \anchor isFocusModeSupported
 *
 * Returns a Boolean value that indicates whether the given focus mode is supported.
 *
 * @param mode a AVCaptureFocusMode constant
 * @return YES if mode is supported, otherwise NO.
 */
- (BOOL) isFocusModeSupported: (AVCaptureFocusMode) mode;
/**
 * \anchor setFocusAt
 * Set focus point and mode
 *
 * @param point a CGPoint in the BambuserView coordinate space. BambuserView will handle convertion to device coordinates
 * @param mode a AVCaptureFocusMode constant
 */
- (void) setFocusAt: (CGPoint) point focusMode: (AVCaptureFocusMode) mode;
/**
 * \anchor setPointOfInterestAt
 * Combines #setExposureAt:exposureMode: and #setFocusAt:focusMode: in one atomic call.
 *
 * @param point a CGPoint in the BambuserView coordinate space. BambuserView will handle convertion to device coordinates
 * @param exposureMode a AVCaptureExposureMode constant
 * @param focusMode a AVCaptureFocusMode constant
 */
- (void)setPointOfInterestAt: (CGPoint) point exposureMode: (AVCaptureExposureMode) exposureMode focusMode: (AVCaptureFocusMode) focusMode;
/**
 * \anchor lockWhiteBalanceGains
 *  Lock white balance to given gain.
 *  If gain values are outside the allowed range (1.0 - #maxWhiteBalanceGain) the gain will be capped at the outer boundaries. At camera swap white balance is set back to unlocked.
 *  Not supported if #isLockingWhiteBalanceWithCustomGainsSupported returns NO. Locking to custom white balance gains is currently not supported for virtual camera.
 *  Virtual camera is enabled if #BambuserView::hasVirtualCamera returns YES. To enable custom white balance gains disable virtual camera support by setting #BambuserView::virtualCameraEnabled to NO.
 *
 *  @param gains a AVCaptureWhiteBalanceGains struct containing red, green and blue gain values in the range 1.0 - #maxWhiteBalanceGain
 */
- (void) lockWhiteBalanceGains: (AVCaptureWhiteBalanceGains) gains;
/**
 * \anchor lockWhiteBalanceGainsWithTemperatureAndTintValues
 *  Lock white balance to given temperature and tint values. BambuserView internally converts to AVCaptureWhiteBalanceGains.
 *  Supported tint values are with the range -150.0 - 150.0.
 *  Takes any temperature values, but will internally cap it to corresponding AVCaptureWhiteBalanceGains range 1.0 - #maxWhiteBalanceGain. Typical temperature range is 2000 - 10000 K. At camera swap white balance is set back to unlocked.
 *  Not supported if #isLockingWhiteBalanceWithCustomGainsSupported returns NO. Locking to custom white balance gains is currently not supported for virtual camera.
 *  Virtual camera is enabled if #BambuserView::hasVirtualCamera returns YES. To enable custom white balance gains disable virtual camera support by setting #BambuserView::virtualCameraEnabled to NO.
 *
 *  @param tempAndTintValues a AVCaptureWhiteBalanceTemperatureAndTintValues struct with temperature and tint values
 */
- (void) lockWhiteBalanceGainsWithTemperatureAndTintValues: (AVCaptureWhiteBalanceTemperatureAndTintValues) tempAndTintValues;
/**
 * \anchor lockCurrentWhiteBalanceGains
 * Lock white balance to the cameras current red, green and blue gain values. At camera swap white balance is set back to unlocked.
 */
- (void) lockCurrentWhiteBalanceGains;
/**
 * \anchor unlockWhiteBalanceGains
 *  Unlocks white balance gains and let the device continuously adjust white balance. This is the default behaviour.
 */
- (void) unlockWhiteBalanceGains;
/**
 * \anchor lockCurrentLensPosition
 * Lock focus to current lens position. To unlock call #setFocusAt:focusMode: with constant AVCaptureFocusModeContinuousAutoFocus
 */
- (void) lockCurrentLensPosition;
@end

/**
 * \anchor BambuserView
 * This is the main class for using the broadcasting library.
 */
@interface BambuserView : UIViewController {
}

/**
 * Property for setting delegate to receive BambuserViewDelegate callbacks
 */
@property (weak) id delegate;
/**
 * \anchor applicationId
 * This property should hold your application ID. Depending on serverside setup this ID can redirect you to a suitable
 * ingest server, and automatically set your broadcasting credentials.
 *
 * This property shall be set before calling #startBroadcasting and can not be altered during a broadcast.
 */
@property (nonatomic, retain, setter = setApplicationId:, getter = applicationId) NSString* applicationId;
/**
 * \anchor chatView
 * This property presents a scrollable view for displaying chat messages.
 * See documentation for UIView for styling the view with background
 * color, alpha and frame.
 */
@property (nonatomic, retain) UIView *chatView;
/**
 * \anchor canStart
 * This property is YES if the startBroadcasting method can be called.
 * If the library is connecting or already is connected this method will
 * return NO.
 */
@property (nonatomic, readonly, getter = canStart) BOOL canStart;
/**
 * \anchor audioQualityPreset
 * This property sets the audio quality preset for the upcoming bambuser broadcast. This setting is locked while local recording is in progress.
 * Constants are defined in BambuserConstants.h for the possible values of this property.
 * The default value is #kAudioHigh.
 */
@property (nonatomic, setter = setAudioQualityPreset:, getter = audioQualityPreset) enum AudioQuality audioQualityPreset;
/**
 * \anchor saveOnServer
 * When this property is YES, the next broadcast will signal the Bambuser video server that the broadcast
 * should be available on demand when the live broadcast is over.
 * This property can not be altered during an ongoing broadcast.
 */
@property (nonatomic, setter = setSaveOnServer:, getter = saveOnServer) BOOL saveOnServer;
/**
 * \anchor saveLocally
 * When this property is YES, the next broadcast will also be saved to a local file. If a path is set in #localFilename, the file gets written in that path,
 * otherwise the file gets a unique filename assigned and is stored within the sandbox's NSTemporaryDirectory().
 * This property can not be altered during an ongoing broadcast.
 *
 * @see #localFilename
 * @see #BambuserViewDelegate::recordingComplete:
 */
@property (nonatomic, setter = setSaveLocally:, getter = saveLocally) BOOL saveLocally;
/**
 * \anchor setTalkback
 * When this property is YES, the next broadcast will signal the Bambuser video server that the client is willing to accept requests for talkback.
 * This property can not be altered during an ongoing broadcast.
 */
@property (nonatomic, setter = setTalkback:, getter = talkback) BOOL talkback;
/**
 * \anchor setTalkbackMix
 * This property indicates whether the talkback audio should be mixed into the signal that gets recorded into the local copy and broadcasted.
 * This property can not be altered during an ongoing broadcast.
 */
@property (nonatomic, setter = setTalkbackMix:, getter = talkbackMix) BOOL talkbackMix;
/**
 * \anchor setLocalFilename
 * This property can be set if you want to set a specific file path when saving a local copy of your broadcast.
 * If this value is nil the local copy will be saved with a unique filename in the sandbox's NSTemporaryDirectory().
 * This property can not be altered during an ongoing broadcast.
 *
 * @see #saveLocally
 * @see #BambuserViewDelegate::recordingComplete:
 */
@property (nonatomic, retain, setter = setLocalFilename:, getter = localFilename) NSString *localFilename;
/**
 * \anchor sendPosition
 * When this property is YES, the location of the device will be sent continuously during the next broadcast.
 * This property can not be altered during an ongoing broadcast.
 */
@property (nonatomic, setter = setSendPosition:, getter = sendPosition) BOOL sendPosition;
/**
 * \anchor author
 * Contains the author field which will be associated with the broadcast.
 *
 * This can be any arbitrary string that should be associated with the
 * broadcast.
 * This property should be set before calling #startBroadcasting.
 */
@property (nonatomic, retain, setter = setAuthor:, getter = author) NSString *author;
/**
 * \anchor broadcastTitle
 * Sets the title for an upcoming broadcast, or updates the title for
 * an ongoing broadcast. This property can be altered at any time.
 */
@property (nonatomic, retain, setter = setBroadcastTitle:, getter = broadcastTitle) NSString *broadcastTitle;
/**
 * \anchor customData
 * Can be set to an arbitrary string that will be associated with the broadcast.
 *
 * This property can be set before broadcasting and updated during the broadcast.
 *
 * Note: This field is currently limited to 10000 bytes serverside.
 */
@property (nonatomic, retain, setter = setCustomData:, getter = customData) NSString *customData;
/**
 * \anchor orientation
 * This property determines the orientation the video will be recorded in.
 *
 * This property can be set to the UIInterfaceOrientation* constants from UIKit/UIApplication.h.
 * The default value is UIInterfaceOrientationLandscapeRight.
 *
 * During a broadcast, it can only be set to flipped versions of the same orientation (i.e. switching from
 * UIInterfaceOrientationLandscapeRight to UIInterfaceOrientationLandscapeLeft).
 */
@property (nonatomic, setter = setOrientation:, getter = orientation) UIInterfaceOrientation orientation;
/**
 * \anchor previewOrientation
 * This property determines the orientation of the application UI, making sure that the camera picture on the screen is rotated correctly.
 *
 * This property is read-only - setting the orientation property sets this to the same value.
 * See #setOrientation:previewOrientation: in order to change it.
 */
@property (nonatomic, readonly, getter = previewOrientation) UIInterfaceOrientation previewOrientation;
/**
 * \anchor torch
 * This property turns the LED torch on and off, if the device has one. This property can be altered at any time.
 */
@property (nonatomic, setter = setTorch:, getter = torch) BOOL torch;
/**
 * \anchor hasLedTorch
 * This readonly property will be YES if the device has an LED torch.
 */
@property (nonatomic, readonly, getter = hasLedTorch) BOOL hasLedTorch;
/**
 * \anchor hasCurrentCameraLedTorch
 * This readonly property will be YES if the current camera has an LED torch.
 */
@property (nonatomic, readonly, getter = hasCurrentCameraLedTorch) BOOL hasCurrentCameraLedTorch;
/**
 * \anchor hasFrontCamera
 * This readonly property will be YES if the device has a front-facing camera.
 */
@property (nonatomic, readonly, getter = hasFrontCamera) BOOL hasFrontCamera;
/**
 * \anchor health
 * This readonly property returns a value between 0 and 100, indicating the current stream health.
 *
 * A value of 0 indicates that the connection is unable to keep up with transferring all data currently being generated.
 * A value of 100 indicates that the connection is able to send all the data currently being generated.
 *
 * This method will return 0 when not broadcasting.
 */
@property (nonatomic, readonly, getter = health) int health;
/**
 * \anchor talkbackState
 * This readonly property contains the current state of talkback.
 *
 * See BambuserConstants.h for possible values.
 */
@property (nonatomic, readonly, getter = talkbackState) enum TalkbackState talkbackState;
/**
 * \anchor zoom
 * This property controls the current zoom level. Accepted values are in the range [1.0, #maxZoom].
 */
@property (nonatomic, setter = setZoom:, getter = zoom) float zoom;
/**
 * \anchor maxZoom
 * This readonly property returns the highest value accepted for the zoom property.
 *
 * A negative value indicates that the device does not support zooming.
 */
@property (nonatomic, readonly, getter = maxZoom) float maxZoom;
/**
 * \anchor framerate
 * This property allows setting the maximum capture framerate, within a range from 24 to 30 fps.
 * Default framerate is 30.
 *
 * @see #setFramerate:minFramerate: for setting a minimum capture framerate.
 */
@property (nonatomic, setter = setFramerate:, getter = framerate) float framerate;
/**
 * \anchor minFramerate
 * This property indicates the minimum framerate.
 *
 * This property is read-only, it can be set via #setFramerate:minFramerate:.
 */
@property (nonatomic, readonly, getter = minFramerate) float minFramerate;
/**
 * \anchor uplinkSpeed
 * This property returns the current speed in bytes per second of an ongoing or previously
 * performed uplink test.
 *
 * If an uplink test has not yet been started, 0 will be returned.
 */
@property (nonatomic, readonly, getter = uplinkSpeed) float uplinkSpeed;
/**
 * \anchor uplinkRecommendation
 * This property returns the current recommendation whether to broadcast or not, during an
 * ongoing or previously performed uplink test.
 *
 * If an uplink test has not yet been started, NO will be returned.
 */
@property (nonatomic, readonly, getter = uplinkRecommendation) BOOL uplinkRecommendation;
/**
 * \anchor maxBroadcastDimension
 * Sets the max size for any dimension (width, height) when using the auto quality preset (#kSessionPresetAuto).
 *
 * This can be used to conserve bandwidth while using a higher camera video resolution, for example when a
 * high resolution local copy is desired.
 *
 * Accepted values range from 200 to 1280. Default value is 0, which will give the maximum camera resolution.
 * Currently it is 1280x720 in landscape mode and 720x1280 in portrait mode.
 *
 * The live broadcast resolution will not be higher than the set limit, not higher
 * than the actual camera video resolution and will still be automatically adjusted depending
 * on current network conditions. This method only sets an upper bound.
 *
 * For instance, if maxBroadcastDimension is set to 640, the broadcast is limited to 640x360
 * in landscape mode, and to 360x640 in portrait mode at the default aspect ratio.
 *
 * This property can not be altered during a broadcast.
 */
@property (nonatomic, setter=setMaxBroadcastDimension:, getter=maxBroadcastDimension) int maxBroadcastDimension;
/**
 * \anchor previewFrame
 * Property to set a custom rectangle with the desired location and dimensions for the preview view.
 */
@property (nonatomic, setter=setPreviewFrame:, getter=previewFrame) CGRect previewFrame;
/**
 * \anchor cameraPosition
 * Property to set camera used, AVCaptureDevicePositionBack or AVCaptureDevicePositionFront. AVCaptureDevicePositionBack is default. If AVCaptureDevicePositionUnspecified is set it has no effect.
 *
 * @see #swapCamera
 */
@property (nonatomic) AVCaptureDevicePosition cameraPosition;
/**
 * \anchor hasVirtualCamera
 * Returns YES if the device is equipped with more cameras than the standard wide angle camera.
 *
 * @see #virtualCameraEnabled
 * @see #isVirtualCamera
 */
@property (nonatomic, readonly) BOOL hasVirtualCamera;
/**
 * \anchor isVirtualCamera
 * Returns YES if the camera at current #cameraPosition is equipped with more cameras than the standard wide angle camera.
 *
 * @see #virtualCameraEnabled
 * @see #hasVirtualCamera
 */
@property (nonatomic, readonly) BOOL isVirtualCamera;
/**
 * \anchor virtualCameraEnabled
 * Property to enable virtual camera. Default value is same as #hasVirtualCamera returned value. If #hasVirtualCamera returns NO this property can't be set.
 * When virtual camera is enabled BambuserView utilises all available cameras when zooming.
 * The zoom level is set to start from the wide angle camera. That means on devices equipped with ultra wide camera the zoom level is set to 2.0.
 * Set to NO to use only the standard wide angle camera.
 *
 * @see #hasVirtualCamera
 * @see #zoom
 */
@property (nonatomic) BOOL virtualCameraEnabled;
/**
 * \anchor audioAveragePowerLevel
 * A measurement of the instantaneous audio average power level
 * A return value of 0 dB indicates full scale, or maximum power; a return value of -160 dB indicates minimum power (that is, near silence).
 *
 * @see #audioPeakHoldLevel
 */
@property (nonatomic, readonly) float audioAveragePowerLevel;
/**
 * \anchor audioPeakHoldLevel
 * A measurement of the peak/hold level of the audio.
 * A return value of 0 dB indicates full scale, or maximum power; a return value of -160 dB indicates minimum power (that is, near silence).
 *
 * @see #audioAveragePowerLevel
 */
@property (nonatomic, readonly) float audioPeakHoldLevel;
/**
 * \anchor cameraController
 * Use #BambuserCameraController for exposure, focus and white balance settings.
 *
 * @see #BambuserCameraController
 */
@property (nonatomic, readonly) BambuserCameraController *cameraController;
/**
 * \anchor initWithPreset
 * Used to initialise the bambuserView.
 * This method should be called with one of the kSessionPreset* video preset constants declared in BambuserConstants.h.
 *
 * @param preset Preferred kSessionPreset-value from BambuserConstants.h. Default is kSessionPresetAuto.
 * @return Returns the BambuserView object
 * @deprecated Use #initWithPreparePreset: instead.
 */
- (id) initWithPreset: (NSString *) preset DEPRECATED_MSG_ATTRIBUTE("Use initWithPreparePreset instead");
/**
 * \anchor initWithPreparePreset
 * Used to initialise the bambuserView.
 * This method should be called with one of the kSessionPreset* video preset constants declared in BambuserConstants.h.
 * This method does not start capture immediately, but allows you to set other capture related parameters directly, before
 * starting the capture. If initializing with this method, you must call #startCapture immediately afterwards, after setting
 * all the capture related properties.
 *
 * @param preset Preferred kSessionPreset-value from BambuserConstants.h. Default is kSessionPresetAuto.
 * @return Returns the BambuserView object
 */
- (id) initWithPreparePreset: (NSString *) preset;
/**
 * \anchor startCapture
 * Start capturing with the properties set.
 *
 * If the #initWithPreparePreset: method was called, this method should be called immediately after all properties
 * that are going to be set upfront have been set. This must have been called before calling #startBroadcasting.
 *
 * This method should only be called once.
 */
- (void) startCapture;
/**
 * \anchor startBroadcasting
 * Connects to the Bambuser video server and starts a new broadcast.
 * This method should not be called if the library is trying to connect or is already connected.
 * It is advisable to check the canStart property before calling this method.
 */
- (void) startBroadcasting;
/**
 * \anchor stopBroadcasting
 * Stops the broadcast and disconnects from the Bambuser video server.
 * This method can be called at any time.
 */
- (void) stopBroadcasting;
/**
 * \anchor displayMessage
 * Display the supplied string message in chatView.
 * @param message A string containing the message to be displayed in chatView.
 */
- (void) displayMessage: (NSString*) message;
/**
 * \anchor setVideoQualityPreset
 * Sets a video quality preset for the upcoming Bambuser session. This
 * method should not be called during a broadcast.
 *
 * The only valid value for this parameter is kSessionPresetAuto.
 *
 * The preset kSessionPresetAuto will allow the video quality to dynamically be adjusted depending on the connection quality.
 *
 * The default value is kSessionPresetAuto.
 *
 * Deprecation: Some constants from AVCaptureSession.h were previously used. These are no longer supported.
 * @param preset A video input preset as declared in BambuserConstants.h.
 * @return YES if the session could apply the preset, otherwise NO.
 */
- (BOOL) setVideoQualityPreset: (NSString*) preset;
/**
 * \anchor setOrientation
 * Sets the preview orientation independently from the capture orientation.
 *
 * The previewOrientation parameter should be the orientation mode used for the application UI where the preview is shown.
 * This allows e.g. keeping the UI locked in one orientation while capturing in an orientation depending on how the device is held.
 */
- (void) setOrientation: (UIInterfaceOrientation) orientation previewOrientation: (UIInterfaceOrientation) previewOrientation;
/**
 * \anchor setOrientationWithAspect
 * Sets the preview orientation independently from the capture orientation.
 *
 * The previewOrientation parameter should be the orientation mode used for the application UI where the preview is shown.
 * This allows e.g. keeping the UI locked in one orientation while capturing in an orientation depending on how the device is held.
 * This method additionally takes integers for width and height, to set aspect ratio for the captured video. Note that the captured
 * video is cropped to fit this ratio, so edges of your preview might not be in the broadcast video. Vice versa, parts not visible
 * in the preview might appear in the broadcast video. To avoid this, make sure to set the preview frame to the same aspect ratio using
 * the #previewFrame property.
 */
- (void) setOrientation: (UIInterfaceOrientation) orientation previewOrientation: (UIInterfaceOrientation) previewOrientation withAspect: (int) w by: (int) h;
/**
 * \anchor setFramerate
 * This method allows setting the minimum framerate of the capture, in addition to the maximum framerate.
 * A minimum framerate different from the maximum framerate is advisable to set at low light conditions.
 * The minimum framerate only affects the capture from the camera itself; the actual streamed framerate may be lower.
 *
 * Default framerate is 30 fps. Default minFramerate is device dependent.
 */
- (void) setFramerate:(float)framerate minFramerate:(float)minFramerate;
/**
 * \anchor swapCamera
 * For devices with front and rear camera this method can be used to toggle
 * between them. This method can be called at any time.
 *
 * @see #cameraPosition
 */
- (void) swapCamera;
/**
 * \anchor takeSnapshot
 * Request a snapshot be returned from the camera.
 * The resulting UIImage will be returned through the #BambuserViewDelegate::snapshotTaken: method.
 */
- (void) takeSnapshot;
/**
 * \anchor acceptTalkbackRequest
 * This method is used to accept a pending talkback request.
 * The talkbackID should previously have been supplied by the delegate protocol method #BambuserViewDelegate::talkbackRequest:caller:talkbackID:.
 * @param talkbackID The talkbackID supplied in a previous talkback request during ongoing broadcast
 */
- (void) acceptTalkbackRequest: (int) talkbackID;
/**
 * \anchor declineTalkbackRequest
 * This method is used to reject a pending talkback request.
 * The talkbackID should previously have been supplied by the delegate protocol method #BambuserViewDelegate::talkbackRequest:caller:talkbackID:.
 * @param talkbackID The talkbackID supplied in a previous talkback request during ongoing broadcast
 */
- (void) declineTalkbackRequest: (int) talkbackID;
/**
 * \anchor endTalkback
 * This method is used to end an ongoing talkback session.
 */
- (void) endTalkback;
/**
 * \anchor startLinktest
 * This method is used to manually start a linktest.
 * The result will be returned through the #BambuserViewDelegate::uplinkTestComplete:recommendation: method.
 * A valid applicationId must be set before linktests can be performed.
 */
- (void) startLinktest;
@end
