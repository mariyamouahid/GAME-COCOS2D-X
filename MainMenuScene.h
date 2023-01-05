#ifndef _MAINMENU_SCENE_H_
#define _MAINMENU_SCENE_H_

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback


    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);

    void GoToGameScene(Ref* pSender);
};

#endif // _MAINMENU_SCENE_H_