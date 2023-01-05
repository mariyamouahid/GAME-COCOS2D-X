#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
#include "cocos2d.h"
#include "physics/CCPhysicsWorld.h"
#include "physics-nodes/CCPhysicsSprite.h"
#include "physics/CCPhysicsContact.h"
#include "Box2D/Box2D.h"
#include "Box2D/Dynamics/b2WorldCallbacks.h"
#include <iostream>

using namespace cocos2d;

USING_NS_CC;

class GameScreen : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init() override;

	CREATE_FUNC(GameScreen);

	void GoToPauseScene(Ref* pSender);
	void GoToGameOverScene(Ref* pSender);
	void update(float) override;


	cocos2d::Sprite* backgroundSpriteArray;
	cocos2d::Sprite* hero;
	cocos2d::Sprite* road;
	cocos2d::Sprite* star;
	cocos2d::Sprite* barrier;

};
#endif