#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    int FinishLevelNum = 0;

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    void LevelCreate(int levelnum);

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__