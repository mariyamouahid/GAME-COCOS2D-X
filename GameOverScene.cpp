#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"


USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();

    auto layer = GameOver::create();

    scene->addChild(layer);

    return scene;
}

bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
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
        MenuItemImage::create("res/Over.jpg",
            "res/Over.jpg");
    auto retryItem =
        MenuItemImage::create("res/Retry.png",
            "res/Retry(Click).png",
            CC_CALLBACK_1(GameOver::GoToGameScene, this));
    auto mainMenuItem =
        MenuItemImage::create("res/Home.png",
            "res/Home(Click).png",
            CC_CALLBACK_1(GameOver::GoToMainMenuScene, this));
    auto menu = Menu::create(menuTitle, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height /6);
    this->addChild(menu);

    return true;
}

void GameOver::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();

    Director::getInstance()->replaceScene(scene);
}
void GameOver::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->replaceScene(scene);
}
