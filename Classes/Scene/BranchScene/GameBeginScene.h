#ifndef __GAMEBEGIN_SCENE_H__
#define __GAMEBEGIN_SCENE_H__

#include "cocos2d.h"

class GameBegin : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuNewGameCallback(cocos2d::Ref* pSender);
    void menuContinueGameCallback(cocos2d::Ref* pSender);
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(GameBegin);
};

#endif // __GAMEBEGIN_SCENE_H__
