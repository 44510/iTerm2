//
//  iTermMinimalComposerViewController.h
//  iTerm2
//
//  Created by George Nachman on 3/31/20.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class TmuxController;
@protocol VT100RemoteHostReading;
@class iTermMinimalComposerViewController;
@class iTermVariableScope;

@protocol iTermMinimalComposerViewControllerDelegate<NSObject>
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
            sendCommand:(NSString *)command
                dismiss:(BOOL)dismiss;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
         enqueueCommand:(NSString *)command
                dismiss:(BOOL)dismiss;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
            sendControl:(NSString *)control;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
    sendToAdvancedPaste:(NSString *)content;
- (NSRect)minimalComposer:(iTermMinimalComposerViewController *)composer
           frameForHeight:(CGFloat)desiredHeight;
- (CGFloat)minimalComposerMaximumHeight:(iTermMinimalComposerViewController *)composer;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
       frameDidChangeTo:(NSRect)newFrame;
- (CGFloat)minimalComposerLineHeight:(iTermMinimalComposerViewController *)composer;
- (void)minimalComposerOpenHistory:(iTermMinimalComposerViewController *)composer;
- (BOOL)minimalComposer:(iTermMinimalComposerViewController *)composer wantsKeyEquivalent:(NSEvent *)event;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer performFindPanelAction:(id)sender;
- (void)minimalComposer:(iTermMinimalComposerViewController *)composer
 desiredHeightDidChange:(CGFloat)desiredHeight;
- (void)minimalComposerClear:(iTermMinimalComposerViewController *)composer;

@end

@interface iTermMinimalComposerViewController : NSViewController
@property (nonatomic, weak) id<iTermMinimalComposerViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *stringValue;
@property (nonatomic) BOOL isAutoComposer;
@property (nonatomic, readonly) CGFloat desiredHeight;
@property (nonatomic) BOOL isSeparatorVisible;
@property (nonatomic, strong) NSColor *separatorColor;
@property (nonatomic, readonly) NSRect cursorFrameInScreenCoordinates;

- (void)updateFrame;
- (void)makeFirstResponder;
- (void)setHost:(id<VT100RemoteHostReading>)host
workingDirectory:(NSString *)pwd
          scope:(iTermVariableScope *)scope
 tmuxController:(TmuxController *)tmuxController;
- (void)setFont:(NSFont *)font;
- (void)setTextColor:(NSColor *)textColor cursorColor:(NSColor *)cursorColor;
- (void)setPrefix:(NSMutableAttributedString * _Nullable)prefix;

- (BOOL)composerIsFirstResponder;
- (void)insertText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
