// Generated by Apple Swift version 3.0.2 (swiftlang-800.0.63 clang-800.0.42.1)
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
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
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
@import ObjectiveC;
@import AppKit;
@import Foundation;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

SWIFT_CLASS("_TtC11audiokit_0211AppDelegate")
@interface AppDelegate : NSObject <NSApplicationDelegate>
- (void)applicationDidFinishLaunching:(NSNotification * _Nonnull)aNotification;
- (void)applicationWillTerminate:(NSNotification * _Nonnull)aNotification;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSImage (SWIFT_EXTENSION(audiokit_02))
- (NSImage * _Nonnull)imageRotatedByDegreessWithDegrees:(CGFloat)degrees;
@end

@class EZAudioPlot;
@class NSImageView;
@class NSButton;
@class NSSlider;
@class NSTextField;
@class AKAmplitudeTracker;
@class AKAudioFile;
@class AKAudioPlayer;
@class AKLowPassFilter;
@class AKHighPassFilter;
@class AKMixer;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC11audiokit_0214ViewController")
@interface ViewController : NSViewController
@property (nonatomic, strong) IBOutlet EZAudioPlot * _Null_unspecified audioInputPlot;
@property (nonatomic, weak) IBOutlet NSTextField * _Null_unspecified visualizer;
@property (nonatomic, strong) IBOutlet NSImageView * _Null_unspecified imgView;
@property (nonatomic, strong) IBOutlet NSButton * _Null_unspecified playButton;
@property (nonatomic, strong) IBOutlet NSSlider * _Null_unspecified playbackSlider;
@property (nonatomic, strong) IBOutlet NSButton * _Null_unspecified ffButton;
@property (nonatomic, strong) IBOutlet NSButton * _Null_unspecified rwButton;
@property (nonatomic, strong) IBOutlet NSTextField * _Null_unspecified playerBgLabel;
@property (nonatomic, strong) IBOutlet NSTextField * _Null_unspecified timeKeeper;
@property (nonatomic, strong) IBOutlet NSTextField * _Null_unspecified maxTime;
@property (nonatomic, strong) IBOutlet NSTextField * _Null_unspecified titleLabel;
@property (nonatomic, strong) AKAmplitudeTracker * _Null_unspecified lowTracker;
@property (nonatomic, strong) AKAmplitudeTracker * _Null_unspecified midTracker;
@property (nonatomic, strong) AKAmplitudeTracker * _Null_unspecified highTracker;
@property (nonatomic, strong) AKAmplitudeTracker * _Null_unspecified allTracker;
@property (nonatomic, strong) AKAudioFile * _Null_unspecified audioFile;
@property (nonatomic, strong) AKAudioPlayer * _Null_unspecified audioPlayer;
@property (nonatomic, strong) AKLowPassFilter * _Null_unspecified lowFilter;
@property (nonatomic, strong) AKHighPassFilter * _Null_unspecified midFilter1;
@property (nonatomic, strong) AKLowPassFilter * _Null_unspecified midFilter2;
@property (nonatomic, strong) AKHighPassFilter * _Null_unspecified highFilter;
@property (nonatomic, strong) AKMixer * _Null_unspecified mixer;
@property (nonatomic) CGFloat theta;
@property (nonatomic) BOOL rotate;
@property (nonatomic, readonly, strong) NSImage * _Nonnull centerImage;
@property (nonatomic, copy) NSArray<NSString *> * _Null_unspecified musicQueue;
- (IBAction)playPausePress:(NSButton * _Nonnull)sender;
- (IBAction)playbackSliderMovement:(NSSlider * _Nonnull)sender;
- (IBAction)browseFileWithSender:(id _Nonnull)sender;
- (NSString * _Nonnull)secondsToMinutesSecondsWithSeconds:(double)seconds;
- (void)setupPlot;
- (void)setupTracker;
- (void)viewDidLoad;
- (void)refresh;
- (void)viewDidAppear;
@property (nonatomic) id _Nullable representedObject;
- (void)updatePlayback;
- (void)updateImg;
- (void)updateVisualizer;
- (nullable instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop
