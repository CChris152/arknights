#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(); //������������

    virtual bool init(); //��ʼ����

    void setFinishLevelNum(int num); //������ɹؿ���������

    void menuCloseCallback(cocos2d::Ref* pSender); //����رպ���
    void menuToLevel1Callback(cocos2d::Ref* pSender);

    void LevelCreate(int levelnum); //�ؿ���ť���ɺ���

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__