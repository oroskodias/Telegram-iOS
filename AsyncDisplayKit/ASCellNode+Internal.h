//
//  ASCellNode+Internal.h
//  AsyncDisplayKit
//
//  Created by Max Gu on 2/19/16.
//
//  Copyright (c) 2014-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the root directory of this source tree. An additional grant
//  of patent rights can be found in the PATENTS file in the same directory.
//

#import "ASCellNode.h"

@protocol ASCellNodeLayoutDelegate <NSObject>

/**
 * Notifies the delegate that the specified cell node has done a relayout.
 * The notification is done on main thread.
 *
 * This will not be called due to measurement passes before the node has loaded
 * its view, even if triggered by -setNeedsLayout, as it is assumed these are
 * not relevant to UIKit.  Indeed, these calls can cause consistency issues.
 *
 * @param node A node informing the delegate about the relayout.
 * @param sizeChanged `YES` if the node's `calculatedSize` changed during the relayout, `NO` otherwise.
 */
- (void)nodeDidRelayout:(ASCellNode *)node sizeChanged:(BOOL)sizeChanged;

@end

@interface ASCellNode ()

/*
 * A delegate to be notified (on main thread) after a relayout.
 */
@property (nonatomic, weak) id<ASCellNodeLayoutDelegate> layoutDelegate;

/*
 * Back-pointer to the containing scrollView instance, set only for visible cells.  Used for Cell Visibility Event callbacks.
 */
@property (nonatomic, weak) UIScrollView *scrollView;

@end
