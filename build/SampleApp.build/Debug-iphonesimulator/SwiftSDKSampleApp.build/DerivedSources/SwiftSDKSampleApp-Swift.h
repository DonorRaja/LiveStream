// Generated by Apple Swift version 3.0 (swiftlang-800.0.46.2 clang-800.0.38)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import JSQMessagesViewController;
@import Foundation;
@import CoreGraphics;
@import WowzaGoCoderSDK;
@import CoreVideo;
@import CoreMedia;
@import CoreFoundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UIWindow;
@class UIApplication;

SWIFT_CLASS("_TtC17SwiftSDKSampleApp11AppDelegate")
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow * _Nullable window;
- (BOOL)application:(UIApplication * _Nonnull)application didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> * _Nullable)launchOptions;
- (void)applicationWillResignActive:(UIApplication * _Nonnull)application;
- (void)applicationDidEnterBackground:(UIApplication * _Nonnull)application;
- (void)applicationWillEnterForeground:(UIApplication * _Nonnull)application;
- (void)applicationDidBecomeActive:(UIApplication * _Nonnull)application;
- (void)applicationWillTerminate:(UIApplication * _Nonnull)application;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class JSQMessage;
@class NSUserDefaults;
@class JSQMessagesBubbleImage;
@class UIBarButtonItem;
@class UIButton;
@class JSQVideoMediaItem;
@class JSQAudioMediaItem;
@class JSQLocationMediaItem;
@class JSQMediaItem;
@class UICollectionView;
@class JSQMessagesCollectionView;
@protocol JSQMessageData;
@protocol JSQMessageBubbleImageDataSource;
@protocol JSQMessageAvatarImageDataSource;
@class NSAttributedString;
@class JSQMessagesCollectionViewFlowLayout;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC17SwiftSDKSampleApp18ChatViewController")
@interface ChatViewController : JSQMessagesViewController
@property (nonatomic, copy) NSArray<JSQMessage *> * _Nonnull messages;
@property (nonatomic, readonly, strong) NSUserDefaults * _Nonnull defaults;
@property (nonatomic, strong) JSQMessagesBubbleImage * _Null_unspecified incomingBubble;
@property (nonatomic, strong) JSQMessagesBubbleImage * _Null_unspecified outgoingBubble;
- (void)viewDidLoad;
- (void)setupBackButton;
- (void)backButtonTapped;
- (void)receiveMessagePressed:(UIBarButtonItem * _Nonnull)sender;
- (void)didPressSendButton:(UIButton * _Nonnull)button withMessageText:(NSString * _Nonnull)text senderId:(NSString * _Nonnull)senderId senderDisplayName:(NSString * _Nonnull)senderDisplayName date:(NSDate * _Nonnull)date;
- (void)didPressAccessoryButton:(UIButton * _Nonnull)sender;
- (JSQVideoMediaItem * _Nonnull)buildVideoItem;
- (JSQAudioMediaItem * _Nonnull)buildAudioItem;
- (JSQLocationMediaItem * _Nonnull)buildLocationItem;
- (void)addMedia:(JSQMediaItem * _Nonnull)media;
- (NSInteger)collectionView:(UICollectionView * _Nonnull)collectionView numberOfItemsInSection:(NSInteger)section;
- (id <JSQMessageData> _Nonnull)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView messageDataForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (id <JSQMessageBubbleImageDataSource> _Nonnull)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView messageBubbleImageDataForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (id <JSQMessageAvatarImageDataSource> _Nullable)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView avatarImageDataForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (NSAttributedString * _Nullable)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView attributedTextForCellTopLabelAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (NSAttributedString * _Nullable)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView attributedTextForMessageBubbleTopLabelAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (CGFloat)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView layout:(JSQMessagesCollectionViewFlowLayout * _Nonnull)collectionViewLayout heightForCellTopLabelAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (CGFloat)collectionView:(JSQMessagesCollectionView * _Nonnull)collectionView layout:(JSQMessagesCollectionViewFlowLayout * _Nonnull)collectionViewLayout heightForMessageBubbleTopLabelAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIColor;

SWIFT_CLASS("_TtC17SwiftSDKSampleApp16DesignableButton")
@interface DesignableButton : UIButton
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, strong) UIColor * _Nonnull borderColor;
@property (nonatomic) CGFloat cornerRadius;
@property (nonatomic) CGFloat borderWidth;
@end


SWIFT_CLASS("_TtC17SwiftSDKSampleApp9TextField")
@interface TextField : UITextField
@property (nonatomic) CGFloat insetX;
@property (nonatomic) CGFloat insetY;
- (CGRect)textRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIView;
@class WowzaGoCoder;
@class WowzaConfig;
@class SocketIOClient;
@class WZStatus;
@class NSError;

SWIFT_CLASS("_TtC17SwiftSDKSampleApp19VideoViewController")
@interface VideoViewController : UIViewController <WZMediaSink, WZVideoSink, WZAudioSink, WZStatusCallback>
@property (nonatomic, readonly, copy) NSString * _Nonnull SDKSampleSavedConfigKey;
@property (nonatomic, readonly, copy) NSString * _Nonnull SDKSampleAppLicenseKey;
@property (nonatomic, readonly, copy) NSString * _Nonnull BlackAndWhiteEffectKey;
@property (nonatomic, readonly, copy) NSString * _Nonnull serverUrl;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified broadcastButton;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified settingsButton;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified switchCameraButton;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified torchButton;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified micButton;
@property (nonatomic, strong) IBOutlet TextField * _Null_unspecified chatField;
@property (nonatomic, strong) IBOutlet UIView * _Null_unspecified chatContainerView;
@property (nonatomic, strong) WowzaGoCoder * _Nullable goCoder;
@property (nonatomic, strong) WowzaConfig * _Null_unspecified goCoderConfig;
@property (nonatomic) BOOL blackAndWhiteVideoEffect;
@property (nonatomic) BOOL goCoderRegistrationChecked;
@property (nonatomic, strong) SocketIOClient * _Null_unspecified socket;
- (void)viewDidLoad;
- (void)didReceiveMemoryWarning;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidLayoutSubviews;
- (void)viewDidAppear:(BOOL)animated;
@property (nonatomic, readonly) BOOL prefersStatusBarHidden;
- (void)start;
- (void)stop;
- (IBAction)didTapBroadcastButton:(id _Nullable)sender;
- (IBAction)didTapSwitchCameraButton:(id _Nullable)sender;
- (IBAction)didTapTorchButton:(id _Nullable)sender;
- (IBAction)didTapMicButton:(id _Nullable)sender;
- (IBAction)didTapSettingsButton:(id _Nullable)sender;
- (void)updateUIControls;
- (void)onWZStatus:(WZStatus * _Null_unspecified)status;
- (void)onWZEvent:(WZStatus * _Null_unspecified)status;
- (void)onWZError:(WZStatus * _Null_unspecified)status;
- (void)videoFrameWasCaptured:(CVImageBufferRef _Nonnull)imageBuffer framePresentationTime:(CMTime)framePresentationTime frameDuration:(CMTime)frameDuration;
- (void)videoCaptureInterruptionStarted;
- (void)audioLevelDidChange:(float)level;
- (void)showAlert:(NSString * _Nonnull)title status:(WZStatus * _Nonnull)status;
- (void)showAlert:(NSString * _Nonnull)title error:(NSError * _Nonnull)error;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface VideoViewController (SWIFT_EXTENSION(SwiftSDKSampleApp)) <UITextFieldDelegate>
@end

@class CALayer;
@class UIBezierPath;
@class UIImage;

SWIFT_CLASS("_TtC17SwiftSDKSampleApp15WaveEmitterView")
@interface WaveEmitterView : UIView
@property (nonatomic) NSInteger amplitudeRange;
@property (nonatomic) NSInteger amplitude;
@property (nonatomic) CFTimeInterval duration;
@property (nonatomic) CFTimeInterval durationRange;
@property (nonatomic) NSInteger maximumCount;
@property (nonatomic) NSInteger currentCount;
@property (nonatomic, copy) NSArray<CALayer *> * _Nonnull unusedLayers;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)setup;
- (UIBezierPath * _Nonnull)getPathInRect:(CGRect)rect;
- (void)emitImage:(UIImage * _Nonnull)image;
@end

#pragma clang diagnostic pop
