#import "RGLProcessParams.h"

@import UIKit;

@class RGLDocReaderVersion, RGLScenario,
RGLDocumentReaderResults, RGLFunctionality,
RGLCustomization, RGLInitializationResponse, RGLDocumentReaderCameraViewController, RGLLicense;

typedef NS_ENUM(NSInteger, RGLDocReaderAction) {
  RGLDocReaderActionComplete = 0,
  RGLDocReaderActionProcess = 1,
  RGLDocReaderActionMorePagesAvailable = 2,
  RGLDocReaderActionCancel = 3,
  RGLDocReaderActionError = 4,
};

typedef NS_ENUM(NSInteger, RGLCommand) {
    RGLCommandUnknown = 0,
    RGLCommandRfidSendData = 100,
    RGLCommandRfidNotify = 101,
    RGLCommandRfidGetDataForScenario = 102,
    RGLCommandTorchGetUVFoto = 200,
    RGLCommandCommandInternetSend = 300
};

typedef void (^RGLDocumentReaderInitializationCompletion)(BOOL successfull,
                                                          NSString * _Nullable error);
typedef void (^RGLDocumentReaderPrepareCompletion)(BOOL sucessfull, NSString * _Nullable error);
typedef void (^RGLDocumentReaderCompletion)(RGLDocReaderAction action,
                                            RGLDocumentReaderResults * _Nullable results,
                                            NSString * _Nullable error);
typedef void (^RGLCallbackCompletionBlock)(NSInteger command, NSData * _Nonnull data, NSString * _Nonnull string);
typedef void (^RGLRfidCallbackCompletionBlock)(RGLCommand command, NSData * _Nonnull data, NSString * _Nonnull json, RGLCallbackCompletionBlock _Nonnull completionBlock);

@interface RGLDocReader : NSObject

@property(nonatomic, strong, nonnull) RGLProcessParams *processParams;
@property(nonatomic, strong, readonly, nullable) RGLDocReaderVersion *version;
@property(nonatomic, strong, readonly, nonnull) NSArray<RGLScenario *> *availableScenarios;
@property(nonatomic, assign, readonly, getter=isDocumentReaderIsReady) BOOL documentReaderIsReady;
@property(nonatomic, assign, readonly, getter=isRfidAvailable) BOOL rfidAvailable;
@property(nonatomic, assign, readwrite, getter=isCameraSessionIsPaused) BOOL cameraSessionIsPaused;
@property(nonatomic, strong, readonly, nonnull) NSString *documentReaderStatus;
@property(nonatomic, nonnull) dispatch_queue_t scanPhotoQueue;
@property(nonatomic, strong, nullable) RGLLicense *license;

@property(nonatomic, strong, nonnull) RGLFunctionality *functionality;
@property(nonatomic, strong, nonnull) RGLCustomization *customization;

+ (nonnull RGLDocReader *)shared;
- (void)initializeReaderWithLicense:(nonnull NSData *)license
                         completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion;
- (void)initializeReaderWithLicense:(nonnull NSData *)license
                       databasePath:(nonnull NSString *)databasePath
                         completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion;
- (void)prepareDatabaseWithDatabaseID:(nonnull NSString *)databaseID
                      progressHandler:(void (^_Nullable)(NSProgress * _Nullable progress))progress
                           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion;
- (void)prepareDatabaseWithDatabaseID:(nonnull NSString *)databaseID
                           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion;
- (void)runAutoUpdateWithDatabaseID:(nonnull NSString *)databaseID
                    progressHandler:(void (^_Nullable)(NSProgress * _Nullable progress))progress
                         completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion;
- (void)runAutoUpdateWithDatabaseID:(nonnull NSString *)databaseID
                         completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion;
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCameraViewController *_Nullable)controller cameraHandler:(RGLDocumentReaderCompletion _Nonnull)completion;
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCompletion _Nonnull)completion;

- (void)startNewPage;
- (void)startNewSession;
- (void)recognizeImage:(UIImage * _Nonnull)image
            cameraMode:(BOOL)cameraMode
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)showScannerFromPresenter:(UIViewController * _Nonnull)presenter
                      completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)startRFIDReaderFromPresenter:(UIViewController * _Nonnull)presenter
                          completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)startRFIDReading:(RGLRfidCallbackCompletionBlock _Nullable )handler completion:(void(^_Nullable)(UInt32 resultCode, RGLDocumentReaderResults * _Nullable result))completion;
- (void)stopScanner:(void(^_Nullable)(void))completion;

- (RGLScenario * _Nullable)selectedScenario;

- (void)deinitializeReader;

@end
