#pragma once

#ifndef __COLLECTION_RECRUIT_SCENE_H__
#define __COLLECTION_RECRUIT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class CollectionBook : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //������һ������
    void colOperatorInfo();   //��Ա��Ϣ
    void colEnemyInfo();  //������Ϣ

    CREATE_FUNC(CollectionBook);
private:
    //��Ա
    Label* ExusiaiInfo;
    Label* HongxueInfo;
    Label* QiubaiInfo;
    Label* EyjafjallaInfo;
    Label* SariaInfo;
    //����
    Label* AlphawormInfo;
    Label* SeagliderInfo;
    Label* D4Info;
    Label* DuInfo;
    Label* HugeuglyInfo;
};

#endif // __COLLECTION_RECRUIT_SCENE_H__
