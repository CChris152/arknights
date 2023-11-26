#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(); //创建场景函数

    virtual bool init(); //开始函数

    void setFinishLevelNum(int num); //设置完成关卡数量函数

    void menuCloseCallback(cocos2d::Ref* pSender); //程序关闭函数
    void menuToLevel1Callback(cocos2d::Ref* pSender);

    void LevelCreate(int levelnum); //关卡按钮生成函数

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__