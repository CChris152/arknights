#pragma once

#ifndef __COLLECTION_RECRUIT_SCENE_H__
#define __COLLECTION_RECRUIT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class CollectionBook : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //返回上一个场景
    void colOperatorInfo();   //干员信息
    void colEnemyInfo();  //敌人信息

    CREATE_FUNC(CollectionBook);
private:
    //干员
    Label* ExusiaiInfo;
    Label* HongxueInfo;
    Label* QiubaiInfo;
    Label* EyjafjallaInfo;
    Label* SariaInfo;
    //敌人
    Label* AlphawormInfo;
    Label* SeagliderInfo;
    Label* D4Info;
    Label* DuInfo;
    Label* HugeuglyInfo;
};

#endif // __COLLECTION_RECRUIT_SCENE_H__
