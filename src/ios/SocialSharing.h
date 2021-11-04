#import <Cordova/CDV.h>
#import <MessageUI/MFMailComposeViewController.h>
#import <LinkPresentation/LPLinkMetadata.h>

API_AVAILABLE(ios(13.0))
@interface SocialSharing : CDVPlugin <UIPopoverControllerDelegate, MFMailComposeViewControllerDelegate, UIDocumentInteractionControllerDelegate,UIActivityItemSource>

@property (nonatomic, strong) MFMailComposeViewController *globalMailComposer;
@property (nonatomic, strong) UIDocumentInteractionController * documentInteractionController;
@property (retain) NSString * tempStoredFile;
@property (retain) CDVInvokedUrlCommand * command;
@property (retain) LPLinkMetadata * metadata;

- (void)available:(CDVInvokedUrlCommand*)command;
- (void)setIPadPopupCoordinates:(CDVInvokedUrlCommand*)command;
- (void)share:(CDVInvokedUrlCommand*)command;
- (void)shareWithOptions:(CDVInvokedUrlCommand*)command;
- (void)canShareVia:(CDVInvokedUrlCommand*)command;
- (void)canShareViaEmail:(CDVInvokedUrlCommand*)command;
- (void)shareVia:(CDVInvokedUrlCommand*)command;
- (void)shareViaTwitter:(CDVInvokedUrlCommand*)command;
- (void)shareViaFacebook:(CDVInvokedUrlCommand*)command;
- (void)shareViaFacebookWithPasteMessageHint:(CDVInvokedUrlCommand*)command;
- (void)shareViaWhatsApp:(CDVInvokedUrlCommand*)command;
- (void)shareViaSMS:(CDVInvokedUrlCommand*)command;
- (void)shareViaEmail:(CDVInvokedUrlCommand*)command;
- (void)shareViaInstagram:(CDVInvokedUrlCommand*)command;

- (void)saveToPhotoAlbum:(CDVInvokedUrlCommand*)command;

@end
