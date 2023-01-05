
#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);

    void GoToGameScene(Ref *pSender);
    void GoToMainMenuScene(Ref *pSender);
};

#endif // __HELLOWORLD_SCENE_H__
