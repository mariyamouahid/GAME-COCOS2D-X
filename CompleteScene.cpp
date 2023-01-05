#include "CompleteScene.h"
#include "MainMenuScene.h"


USING_NS_CC;

Scene* Complete::createScene()
{
    auto scene = Scene::create();

    auto layer = Complete::create();

    scene->addChild(layer);

    return scene;
}

bool Complete::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundSprite = Sprite::create("res/b1.jpeg"); 
    backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -1);
    float rx = visibleSize.width / backgroundSprite->getContentSize().width;
    float ry = visibleSize.height / backgroundSprite->getContentSize().height;

    auto menuTitle =
        MenuItemImage::create("res/levelC.png",
            "res/levelC.png");
    auto mainMenuItem =
        MenuItemImage::create("res/Home.png",
            "res/Home(Click).png",
            CC_CALLBACK_1(Complete::GoToMainMenuScene, this));
    auto menu = Menu::create(menuTitle, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    return true;
}



void Complete::GoToMainMenuScene(cocos2d::Ref* pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->replaceScene(scene);
}