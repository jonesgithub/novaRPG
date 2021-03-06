//
//  CharacterModel.h
//  novaRPG
//
//  Created by nova on 02.01.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"
#import "MapModel.h";

typedef enum {
	kStateIdle = 0,
	kStateDown,
	kStateUp,
	kStateLeft,
	kStateRight
} _moveState;

@interface CharacterModel : CCNode {
	CCSprite *_characterSprite;
	CCSpriteBatchNode *_spriteSheet;
	CCAnimation *_walkDownAnim;
	CCAnimation *_walkUpAnim;
	CCAnimation *_walkLeftAnim;
	CCAnimation *_walkRightAnim;

	float _moveSpeed;
	float _animSpeed;
	
	int _moveState;
	BOOL _isMoving;

	NSString *_spriteName;
	
	MapModel *_currentMap;
}

// Sprite and Spritesheet
@property (nonatomic,retain) CCSprite *characterSprite;
@property (nonatomic,retain) CCSpriteBatchNode *spriteSheet;

// Animations
@property (nonatomic,retain) CCAnimation *walkDownAnim;
@property (nonatomic,retain) CCAnimation *walkUpAnim;
@property (nonatomic,retain) CCAnimation *walkLeftAnim;
@property (nonatomic,retain) CCAnimation *walkRightAnim;

// Speeds
@property (readwrite,assign) float moveSpeed;
@property (readwrite,assign) float animSpeed;

// States
@property (readwrite,assign) int moveState;
@property (readwrite,assign) BOOL isMoving;


-(id) loadSprite:(NSString *)spriteName onMap:(MapModel *) currentMap;
-(void) loadExtraAnimations;
-(void) lookInDirection:(int) lookDirection;
-(void) update;

@end
