#include "PauseScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    auto scene = Scene::create();

    auto layer = PauseMenu::create();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool PauseMenu::init()
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


    auto resumeItem =
        MenuItemImage::create("res/Resume.png",
            "res/Resume(Click).png",
            CC_CALLBACK_1(PauseMenu::Resume, this));
    auto retryItem =
        MenuItemImage::create("res/Retry.png",
            "res/Retry(Click).png",
            CC_CALLBACK_1(PauseMenu::Retry, this));
    auto mainMenuItem =
        MenuItemImage::create("res/Home.png",
            "res/Home(Click).png",
            CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem,
        NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 6);
    this->addChild(menu);


    return true;
}

void PauseMenu::Resume(cocos2d::Ref *pSender)
{
    Director::getInstance()->popScene();
}
void PauseMenu::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
void PauseMenu::Retry(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();

    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}

