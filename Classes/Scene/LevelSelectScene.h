#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void setFinishLevelNum(int num); //设置完成关卡数量函数

    void menuCloseCallback(cocos2d::Ref* pSender); //程序关闭
    void menuToLevel1Callback(cocos2d::Ref* pSender); //进入关卡1

    void LevelCreate(int levelnum); //关卡按钮生成函数

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__