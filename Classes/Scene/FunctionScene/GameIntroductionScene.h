#pragma once

#ifndef __GAME_INTRODUCTION_SCENE_H__
#define __GAME_INTRODUCTION_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameIntroductionScene : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //返回上一个场景
    CREATE_FUNC(GameIntroductionScene);
};

#endif // __GAME_INTRODUCTION_SCENE_H__
