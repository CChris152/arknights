#pragma once

#ifndef __LEVELSELECT_SCENE_H__
#define __LEVELSELECT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene
{
public:
    virtual bool init();

    void setFinishLevelNum(int num); //������ɹؿ���������

    void menuBackCallback(cocos2d::Ref* pSender); //����
    void menuCloseCallback(cocos2d::Ref* pSender); //����ر�
    void menuToLevel1Callback(cocos2d::Ref* pSender); //����ؿ�1
    void menuToLevel2Callback(cocos2d::Ref* pSender); //����ؿ�2

    void LevelCreate(int levelnum); //�ؿ���ť���ɺ���

    CREATE_FUNC(LevelSelect);
};




#endif // __LEVELSELECT_SCENE_H__