/* 
 * Copyright (c) 2011, salesforce.com, inc.
 * Author: Jonathan Hersh jhersh@salesforce.com
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

// The main panel for an account's record view. This panel is always visible and
// you can launch other panels from here.

#import <UIKit/UIKit.h>
#import "zkSforce.h"
#import "FlyingWindowController.h"
#import "AccountAddEditController.h"
#import "AQGridView.h"
#import <MapKit/MapKit.h>
#import "FollowButton.h"

@class FieldPopoverButton;

#define GEOCODE_ENDPOINT @"https://maps.googleapis.com/maps/api/geocode/json?address="

@interface RecordOverviewController : FlyingWindowController <MKMapViewDelegate, AccountAddEditControllerDelegate, AQGridViewDelegate, AQGridViewDataSource, FollowButtonDelegate> {
    BOOL isLoading;
}

enum {
    AccountNameCell = 0,
    AccountPhoneCell,
    AccountWebsiteCell,
    AccountIndustryCell,
    AccountGridNumItems
};

@property (nonatomic, retain) UIView *mapView;
@property (nonatomic, retain) MKMapView *accountMap;
@property (nonatomic, retain) AQGridView *gridView;
@property (nonatomic, retain) UIView *recordLayoutView;
@property (nonatomic, retain) UIScrollView *scrollView;
@property (nonatomic, retain) NSMutableArray *commButtons;
@property (nonatomic, retain) UIView *commButtonBackground;
@property (nonatomic, retain) FollowButton *followButton;

@property (nonatomic, assign) FieldPopoverButton *addressButton;
@property (nonatomic, assign) UIButton *recenterButton;
@property (nonatomic, assign) UIButton *geocodeButton;
@property (nonatomic, assign) UIButton *detailButton;

- (id) initWithFrame:(CGRect) frame;

- (void) selectAccount:(NSDictionary *)acc;
- (void) layoutView;
- (void) loadAccount;
- (void) refreshSubNav;

// Map view
- (void) configureMap;
- (IBAction) recenterMap:(id)sender;

// Editing
- (IBAction) editLocalAccount:(id)sender;

@end
