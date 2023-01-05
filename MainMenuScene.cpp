#include "MainMenuScene.h"
#include "GameScene.h"


USING_NS_CC;


Scene* MainMenu::createScene()
{
    auto scene = Scene::create();

    auto layer = MainMenu::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
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
    
    auto menuTitle = MenuItemImage::create("res/GAME.png", "res/GAME.png");
    auto playItem = MenuItemImage::create("res/PLAY01.png",
        "res/PLAY01.png",
        CC_CALLBACK_1(MainMenu::GoToGameScene, this));

    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 6);

    this->addChild(menu);

    return true;

}

void MainMenu::GoToGameScene(cocos2d::Ref* pSender)
{

    auto scene = GameScreen::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(2.0, scene));

}