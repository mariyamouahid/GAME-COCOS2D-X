#ifndef __Complete_SCENE_H__
#define __Complete_SCENE_H__

#include "cocos2d.h"

class Complete : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    // implement the "static create()" method manually
    CREATE_FUNC(Complete);

    void GoToMainMenuScene(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
