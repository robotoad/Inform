//
//  IFPreferences.h
//  Inform
//
//  Created by Andrew Hunter on 02/02/2005.
//  Copyright 2005 Andrew Hunter. All rights reserved.
//

#import <Cocoa/Cocoa.h>

// Notifications
extern NSString* IFPreferencesAuthorDidChangeNotification;
extern NSString* IFPreferencesEditingDidChangeNotification;
extern NSString* IFPreferencesAdvancedDidChangeNotification;
extern NSString* IFPreferencesAppFontSizeDidChangeNotification;	// Change to app font size
extern NSString* IFPreferencesSkeinDidChangeNotification;

extern NSString* IFPreferencesDefault;
typedef enum IFAppFontSize {
    IFAppFontSizeMinus100,
    IFAppFontSizeMinus75,
    IFAppFontSizeMinus50,
    IFAppFontSizeMinus25,
    IFAppFontSizeNormal,
    IFAppFontSizePlus25,
    IFAppFontSizePlus50,
    IFAppFontSizePlus75,
    IFAppFontSizePlus100,
} IFAppFontSize;

// Types
typedef enum IFRelativeFontSize {
    IFFontSizeMinus30,
    IFFontSizeMinus20,
    IFFontSizeMinus10,
    IFFontSizeNormal,
    IFFontSizePlus10,
    IFFontSizePlus20,
    IFFontSizePlus30,
} IFRelativeFontSize;

typedef enum IFSyntaxHighlightingOptionType {
    IFSHOptionHeadings,
    IFSHOptionMainText,
    IFSHOptionComments,
    IFSHOptionQuotedText,
    IFSHOptionTextSubstitutions,
    
    IFSHOptionCount
} IFSyntaxHighlightingOptionType;

typedef enum IFFontStyle {
    IFFontStyleRegular,
    IFFontStyleItalic,
    IFFontStyleBold,
    IFFontStyleBoldItalic,
} IFFontStyle;

@class IFEditingPreferencesSet;

//
// General preferences class
//
// Inform's application preferences are stored here
//
@interface IFPreferences : NSObject

// Constructing the object
+ (IFPreferences*) sharedPreferences;										// The shared preference object

// Preferences
- (void) preferencesHaveChanged;											// Generates a notification that preferences have changed

-(void) startBatchEditing;
-(void) endBatchEditing;

// Editing preferences
@property (atomic, copy) NSString *sourceFontFamily;
@property (atomic) float sourceFontSize;
@property (atomic, readonly) float appFontSizeMultiplier;
@property (atomic) IFAppFontSize appFontSizeMultiplierEnum;
@property (atomic) float tabWidth;


-(IFFontStyle) sourceFontStyleForOptionType:(IFSyntaxHighlightingOptionType) optionType;
-(void) setSourceFontStyle: (IFFontStyle) style
             forOptionType: (IFSyntaxHighlightingOptionType) optionType;

-(IFRelativeFontSize) sourceRelativeFontSizeForOptionType:(IFSyntaxHighlightingOptionType) optionType;
-(void) setSourceRelativeFontSize: (IFRelativeFontSize) size
                    forOptionType: (IFSyntaxHighlightingOptionType) optionType;

-(NSColor*) sourceColourForOptionType:(IFSyntaxHighlightingOptionType) optionType;
-(void) setSourceColour: (NSColor*) colour
          forOptionType: (IFSyntaxHighlightingOptionType) optionType;

-(BOOL) sourceUnderlineForOptionType:(IFSyntaxHighlightingOptionType) optionType;
-(void) setSourceUnderline: (BOOL) underline
             forOptionType: (IFSyntaxHighlightingOptionType) optionType;

- (void) recalculateStyles;								// Regenerate the array of attribute dictionaries that make up the styles
@property (atomic, readonly, copy) NSArray *styles;		// Retrieves an array of attribute dictionaries that describe how the styles should be displayed

// Intelligence preferences
@property (atomic) BOOL enableSyntaxHighlighting;		// YES if source code should be displayed with syntax highlighting
@property (atomic) BOOL indentWrappedLines;				// ... and indentation
@property (atomic) BOOL elasticTabs;					// ... and elastic tabs
@property (atomic) BOOL indentAfterNewline;				// ... which is used to generate indentation
@property (atomic) BOOL autoNumberSections;				// ... which is used to auto-type section numbers
@property (atomic, copy) NSString *freshGameAuthorName;	// The default author to use for new Inform 7 games


@property (atomic, copy) NSColor *sourcePaperColour;
@property (atomic, copy) NSColor *extensionPaperColour;

// Advanced preferences
@property (atomic) BOOL runBuildSh;						// YES if we should run the build.sh shell script to rebuild Inform 7
@property (atomic) BOOL alwaysCompile;					// YES if we should always compile the source (no make-style dependency checking)
@property (atomic) BOOL showDebuggingLogs;				// YES if we should show the Inform 7 debugging logs + generated Inform 6 source code
@property (atomic) BOOL showConsoleDuringBuilds;        // YES if we want to see the console output during a build
@property (atomic) BOOL publicLibraryDebug;             // YES if we want to debug the public library
@property (atomic) BOOL cleanProjectOnClose;            // YES if we should clean the project when we close it (or when saving)
@property (atomic) BOOL alsoCleanIndexFiles;			// YES if we should additionally clean out the index files
@property (atomic, copy) NSString *glulxInterpreter;	// The preferred glulx interpreter


// Position of preferences window
@property (atomic) NSPoint preferencesTopLeftPosition;

@end
