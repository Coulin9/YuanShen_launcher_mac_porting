//
//  VMMAlert.h
//  ObjectiveC_Extension
//
//  Created by Vitor Marques de Miranda on 22/02/17.
//  Copyright © 2017 Vitor Marques de Miranda. All rights reserved.
//

#ifndef VMMAlert_Extension_Class
#define VMMAlert_Extension_Class

#import <Cocoa/Cocoa.h>

/*!
 * @typedef VMMAlertType
 * @brief A list of predefined alert types.
 * @constant VMMAlertTypeSuccess  An alert with 'Success' as title and the default alert icon.
 * @constant VMMAlertTypeWarning  An alert with 'Warning' as title and the NSCriticalAlertStyle icon.
 * @constant VMMAlertTypeError    An alert with 'Error' as title and NSImageNameCaution as icon.
 * @constant VMMAlertTypeCritical An alert with 'Error' as title and NSImageNameStopProgressFreestandingTemplate as icon.
 * @constant VMMAlertTypeCustom   An alert with the app name as title and the default alert icon.
 */
typedef enum VMMAlertType
{
    /// An alert with 'Success' as title and the default alert icon.
    VMMAlertTypeSuccess,
    
    /// An alert with 'Warning' as title and the NSCriticalAlertStyle icon.
    VMMAlertTypeWarning,
    
    /// An alert with 'Error' as title and NSImageNameCaution as icon.
    VMMAlertTypeError,
    
    /// An alert with 'Error' as title and NSImageNameStopProgressFreestandingTemplate as icon.
    VMMAlertTypeCritical,
    
    /// An alert with the app name as title and the default alert icon.
    VMMAlertTypeCustom
} VMMAlertType;

@interface VMMAlert : NSAlert

/*!
 * @discussion  Changes the icon of a VMMAlert based in the VMMAlertType.
 * @param alertType The VMMAlertType that will be used to configure the alert icon.
 */
-(void)setIconWithAlertType:(VMMAlertType)alertType;

/*!
 * @discussion  Same as runModal, but which runs the alert in the main thread and returns the result to the active thread.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @return      The runModal output.
 */
-(NSUInteger)runThreadSafeModal;

/*!
 * @discussion  Same as runModal, but which creates and runs the alert in the main thread and returns the result to the active thread.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param alert A block that will be run in the main thread, and needs as return the VMMAlert that will be shown.
 * @return      The runModal output.
 */
+(NSUInteger)runThreadSafeModalWithAlert:(VMMAlert* (^)(void))alert;

/*!
 * @discussion  Shows a VMMAlert with the contents of a NSException and an Ok button.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param exception The exception that will be used to create the alert.
 */
+(void)showErrorAlertWithException:(NSException*)exception;

/*!
 * @discussion  Shows a VMMAlert with a predefined VMMAlertType, an informative text and an Ok button.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param alertType The VMMAlertType that will be used to configure the alert.
 * @param message   The message (aka. informative text) that will be shown in the alert.
 */
+(void)showAlertOfType:(VMMAlertType)alertType withMessage:(NSString*)message;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text, any other configurations specified in the block and an Ok button.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param title           The title that will be shown in the alert.
 * @param message         The message (aka. informative text) that will be shown in the alert.
 * @param optionsForAlert The block to make any extra adjustments in the alert before showing it.
 */
+(void)showAlertWithTitle:(NSString*)title message:(NSString*)message andSettings:(void (^)(VMMAlert* alert))optionsForAlert;

/*!
 * @discussion  Shows a VMMAlert with a title, a subtitle, an attributed informative text and an Ok button.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param title           The title that will be shown in the alert.
 * @param subtitle        The subtitle (aka. informative text) that will be shown in the alert.
 * @param message         The message (aka. attributed informative text) that will be shown in the alert.
 * @param fixedWidth      The width of the message area that will be shown in the alert (0 to use the real message width).
 */
+(void)showAlertWithTitle:(NSString*)title subtitle:(NSString*)subtitle andAttributedMessage:(NSAttributedString*)message withWidth:(CGFloat)fixedWidth;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text and Yes/No buttons.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param title     The title that will be shown in the alert.
 * @param message   The message (aka. informative text) that will be shown in the alert.
 * @param highlight The button that will be highlighted by default in the alert (Yes/No).
 * @return          true if Yes was pressed, false if No was pressed.
 */
+(BOOL)showBooleanAlertWithTitle:(NSString*)title message:(NSString*)message highlighting:(BOOL)highlight;

/*!
 * @discussion  Shows a VMMAlert with a predefined VMMAlertType, an informative text and Yes/No buttons.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param alertType The VMMAlertType that will be used to configure the alert.
 * @param message   The message (aka. informative text) that will be shown in the alert.
 * @param highlight The button that will be highlighted by default in the alert (Yes/No).
 * @return          true if Yes was pressed, false if No was pressed.
 */
+(BOOL)showBooleanAlertOfType:(VMMAlertType)alertType withMessage:(NSString*)message highlighting:(BOOL)highlight;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text, any other configurations specified in the block and Yes/No buttons.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param title           The title that will be shown in the alert.
 * @param message         The message (aka. informative text) that will be shown in the alert.
 * @param highlight       The button that will be highlighted by default in the alert (Yes/No).
 * @param optionsForAlert The block to make any extra adjustments in the alert before showing it.
 * @return                true if Yes was pressed, false if No was pressed.
 */
+(BOOL)showBooleanAlertWithTitle:(NSString*)title message:(NSString*)message highlighting:(BOOL)highlight withSettings:(void (^)(VMMAlert* alert))optionsForAlert;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text, any other configurations specified in the block and Ok/Cancel buttons.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param message         The message (aka. informative text) that will be shown in the alert.
 * @param prompt          The title that will be shown in the alert.
 * @param optionsForAlert The block to make any extra adjustments in the alert before showing it.
 * @return                true if Ok was pressed, false if Cancel was pressed.
 */
+(BOOL)confirmationDialogWithTitle:(NSString*)prompt message:(NSString*)message andSettings:(void (^)(VMMAlert* alert))optionsForAlert;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text, a text field and Ok/Cancel buttons.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param prompt       The title that will be shown in the alert.
 * @param message      The message (aka. informative text) that will be shown in the alert.
 * @param defaultValue The initial string value of the text field.
 * @return             The string value of the text field if Ok was pressed, nil if Cancel was pressed.
 */
+(NSString*)inputDialogWithTitle:(NSString*)prompt message:(NSString*)message defaultValue:(NSString*)defaultValue;

/*!
 * @discussion  Shows a VMMAlert with a title, an informative text, big squared buttons and a Cancel button.
 * @discussion  This method is thread safe, so it can be used from any thread or queue.
 * @param title         The title that will be shown in the alert.
 * @param message       The message (aka. informative text) that will be shown in the alert.
 * @param options       The list of the buttons that should appear in the dialog.
 * @param iconForOption A block that needs as return the image that will be the icon for each button title.
 * @return              The title of the pressed big button if any was pressed, nil if Cancel was pressed.
 */
+(NSString*)showAlertWithTitle:(NSString*)title message:(NSString*)message buttonOptions:(NSArray<NSString*>*)options andIconForEachOption:(NSImage* (^)(NSString* option))iconForOption;

@end

#endif
