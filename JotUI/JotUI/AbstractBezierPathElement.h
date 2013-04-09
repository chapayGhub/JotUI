//
//  AbstractSegment.h
//  JotUI
//
//  Created by Adam Wulf on 12/19/12.
//  Copyright (c) 2012 Adonit. All rights reserved.
//

#import <UIKit/UIKit.h>

struct Vertex{
    GLfloat Position[2];    // x,y position
    GLubyte Color [4];      // rgba color
    GLfloat Size;           // pixel size
};


/**
 * This represents the number of points to move
 * along the curve before drawing another point
 * on the line.
 *
 * larger values mean that points will be further
 * apart, smaller values means closer together
 *
 * small values will also give a smoother line, but will
 * cost more in CPU
 */
#define kBrushStepSize		1

@interface AbstractBezierPathElement : NSObject{
    CGPoint startPoint;
    CGFloat width;
    UIColor* color;
    
    struct Vertex* vertexBuffer;
    CGFloat scaleOfVertexBuffer;
}

@property (nonatomic) __strong UIColor* color;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, readonly) CGPoint startPoint;

-(id) initWithStart:(CGPoint)point;

-(CGFloat) lengthOfElement;

-(NSInteger) numberOfSteps;

-(struct Vertex*) generatedVertexArrayWithPreviousElement:(AbstractBezierPathElement*)previousElement forScale:(CGFloat)scale;

@end