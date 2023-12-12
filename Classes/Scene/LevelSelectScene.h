#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:
    virtual bool init();

    void setFinishLevelNum(int num); //设置完成关卡数量函数

    void menuBackCallback(cocos2d::Ref* pSender); //返回
    void menuCloseCallback(cocos2d::Ref* pSender); //程序关闭
    void menuToLevel1Callback(cocos2d::Ref* pSender); //进入关卡1
    void menuToLevel2Callback(cocos2d::Ref* pSender); //进入关卡2

    void LevelCreate(int levelnum); //关卡按钮生成函数

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__