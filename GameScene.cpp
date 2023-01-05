#include"GameScene.h"
#include"PauseScene.h"
#include"GameOverScene.h"
#include"MainMenuScene.h"
#include"CompleteScene.h"
#include<iostream>

using namespace ui;
using namespace cocos2d;

USING_NS_CC;
Scene* GameScreen::createScene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* world = scene->getPhysicsWorld();
	auto gravity = Vec2(0, -400.0f);
	world->setGravity(gravity);


	auto layer = GameScreen::create();
	scene->addChild(layer);

	return scene;
}

bool GameScreen::init()
{

	if (!Layer::init())
	{
		return false;

	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto pauseItem = MenuItemImage::create("res/Pause.png",
		"res/Pause.png",
		CC_CALLBACK_1(GameScreen::GoToPauseScene, this));

	pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 2) + origin.x,
		visibleSize.height - pauseItem->getContentSize().height + (pauseItem->getContentSize().width / 2) + origin.y));

	auto menu = Menu::create(pauseItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);


	auto backgroundSprite = Sprite::create("res/BACKG.png"); /*background for the main menu*/
	backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
	this->addChild(backgroundSprite, -1);
	float rx = visibleSize.width / backgroundSprite->getContentSize().width;
	float ry = visibleSize.height / backgroundSprite->getContentSize().height;

	backgroundSprite->setScaleX(rx);
	backgroundSprite->setScaleY(ry);


	hero = Sprite::create("res/HERO.png");
	hero->setPosition((Vec2(visibleSize.width * 0.1, visibleSize.height * 0.5)));
	hero->setScale(0.3);
	auto physicsBody1 = PhysicsBody::createBox(hero->getContentSize() / 1.5, PhysicsMaterial(1.0f, 1.0f, 1.0f));
	physicsBody1->setGravityEnable(true);
	physicsBody1->setDynamic(true);
	hero->setPhysicsBody(physicsBody1);
	this->addChild(hero, 1);


	//  creating physique for our hero
    road = Sprite::create("res/R0.png");
	road->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.1));
	this->addChild(road, 1);
	road->setScaleX(3);

	//creating physique for THE ROAD
	auto physicsBody_road = PhysicsBody::createBox(road->getContentSize(), PhysicsMaterial(1.0f, 0.0f, 1.0f));

	physicsBody_road->setDynamic(false);
	physicsBody_road->setCollisionBitmask(1);
	physicsBody_road->setCategoryBitmask(1);


	road->setPhysicsBody(physicsBody_road);


	star = Sprite::create("res/STAR.png");
	star->setPosition((Vec2(visibleSize.width * 5, visibleSize.height * 0.5)));
	star->setScale(0.300);
	auto physicsBody11 = PhysicsBody::createBox(star->getContentSize() / 1.5, PhysicsMaterial(1.0f, 1.0f, 1.0f));
	physicsBody11->setGravityEnable(true);
	physicsBody11->setDynamic(true);
	star->setPhysicsBody(physicsBody11);
	this->addChild(star, 1);
	
	//
	barrier = Sprite::create("res/BAF.png");
	barrier->setPosition((Vec2(visibleSize.width * 1.2, visibleSize.height * 0.2)));
	barrier->setScale(0.200);
	this->addChild(barrier, 1);
	auto physicsBody_barrier = PhysicsBody::createBox(barrier->getContentSize(), PhysicsMaterial(1.0f, 1.0f, 1.0f));

	physicsBody_barrier->setDynamic(true);
	physicsBody_barrier->setCollisionBitmask(1);
	physicsBody_barrier->setCategoryBitmask(1);
	barrier->setPhysicsBody(physicsBody_barrier);

	//

	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

		Vec2 loc = event->getCurrentTarget()->getPosition();
		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
			event->getCurrentTarget()->runAction(MoveBy::create(0.1, Vec2(-10, 0)));
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			event->getCurrentTarget()->runAction(MoveBy::create(0.1, Vec2(10, 0)));
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			event->getCurrentTarget()->runAction(JumpBy::create(0.5, Vec2(30, 50), 50, 1));
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			event->getCurrentTarget()->runAction(JumpBy::create(0.1, Vec2(100, 0), 50, 1));
			break;
		}
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, hero);

	this->scheduleUpdate();

	return true;

}

void GameScreen::update(float dt) {
	if (hero != NULL) {
		hero->setRotation(0.0f);
	}
	Size visibleSize = Director::getInstance()->
		getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	Rect PLAYER = hero->getBoundingBox();
	Rect signe = star->getBoundingBox();

	if (PLAYER.intersectsRect(signe))
	{
		auto scene = Complete::createScene();
		Director::getInstance()->replaceScene(scene);
	}
    
	auto position = road->getPosition();
	position.x -= 250 * dt;
	if (position.x < 0 - (road->getBoundingBox().size.width / 2))
		position.x = this->getBoundingBox().getMaxX() + road->getBoundingBox().size.width / 2;
	road->setPosition(position);

	auto position3 = star->getPosition();//
	position3.x -= 250 * dt;
	if (position3.x < 0 - (star->getBoundingBox().size.width / 2))
		position3.x = this->getBoundingBox().getMaxX() + star->getBoundingBox().size.width / 2;
	star->setPosition(position3);

	auto position4 = barrier->getPosition();
	position4.x -= 250 * dt;
	if (position4.x < 0 - (barrier->getBoundingBox().size.width / 2))
		position4.x = this->getBoundingBox().getMaxX() + barrier->getBoundingBox().size.width / 2;
	barrier->setPosition(position4);

	if (road->getPosition().x < -2050.0f) {
		auto scene = GameOver::createScene();
		Director::getInstance()->replaceScene(scene); 
	}


}


void GameScreen::GoToPauseScene(cocos2d::Ref* pSender)
{
	auto scene = PauseMenu::createScene();
	Director::getInstance()->pushScene(scene);

}
void GameScreen::GoToGameOverScene(cocos2d::Ref* pSender)
{
	auto scene = GameOver::createScene();
	Director::getInstance()->pushScene(scene);
}