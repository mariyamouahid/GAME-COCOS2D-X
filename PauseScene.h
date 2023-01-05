
#ifndef __PAUSEMENU_SCENE_H__
#define __PAUSEMENU_SCENE_H__

#include "cocos2d.h"

class PauseMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(PauseMenu);

    void Resume(Ref* pSender);
    void GoToMainMenuScene(Ref* pSender);
    void Retry(Ref* pSender);
};

#endif // __PAUSE_SCENE_H__
