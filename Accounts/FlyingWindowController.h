/* 
 * Copyright (c) 2011, salesforce.com, inc.
 * Author: Jonathan Hersh
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided 
 * that the following conditions are met:
 * 
 *    Redistributions of source code must retain the above copyright notice, this list of conditions and the 
 *    following disclaimer.
 *  
 *    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
 *    the following disclaimer in the documentation and/or other materials provided with the distribution. 
 *    
 *    Neither the name of salesforce.com, inc. nor the names of its contributors may be used to endorse or 
 *    promote products derived from this software without specific prior written permission.
 *  
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

// This is a template for the right-side (detail) view to be extended by
// other view controllers

#import <UIKit/UIKit.h>
#import "zkSforce.h"

@class RootViewController;
@class SubNavViewController;
@class DetailViewController;

@protocol FlyingWindowDelegate;

@interface FlyingWindowController : UIViewController <UIGestureRecognizerDelegate> {
    float firstX, firstY;
}

enum FlyingWindowTypes {
    FlyingWindowNews = 0,
    FlyingWindowDetail,
    FlyingWindowRecordOverview,
    FlyingWindowWebView,
};

@property enum FlyingWindowTypes flyingWindowType;

@property (nonatomic, retain) UINavigationBar *navBar;
@property (nonatomic, retain) NSDictionary *account;
@property (nonatomic, retain) UIView *dimmer;

@property (nonatomic, assign) IBOutlet RootViewController *rootViewController;
@property (nonatomic, assign) IBOutlet SubNavViewController *subNavViewController;
@property (nonatomic, assign) IBOutlet DetailViewController *detailViewController;
@property (nonatomic, assign) id <FlyingWindowDelegate> delegate;
@property (nonatomic, assign) FlyingWindowController *rightFWC;
@property (nonatomic, assign) FlyingWindowController *leftFWC;

- (id) initWithFrame:(CGRect) frame;

- (void) selectAccount:(NSDictionary *)acc;
- (void) flyingWindowDidDrag:(id)sender;
- (void) flyingWindowDidTap:(id)sender;
- (void) slideFlyingWindowToPoint:(CGPoint) point;

- (void) setDimmerAlpha:(float)alpha;

- (CGPoint) originPoint;

@end

// START:Delegate
@protocol FlyingWindowDelegate <NSObject>

@optional

// If true, allow this window to slide left and right
- (BOOL)flyingWindowShouldDrag:(FlyingWindowController *)flyingWindowController;

// The user has dragged the flying window to a certain point. This function can be used to 
// modify that point (e.g. keep the window from flying offscreen, or introduce a lag beyond a certain boundary)
- (CGPoint) translateFlyingWindowCenterPoint:(FlyingWindowController *)flyingWindowController originalPoint:(CGPoint)originalPoint isDragging:(BOOL)isDragging;

// Flying window successfully moved
- (void)flyingWindowDidMove:(FlyingWindowController *)flyingWindowController;

@end
// END:Delegate