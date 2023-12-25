#pragma once

#ifndef __ENEMY_BOOK_H__
#define __ENEMY_BOOK_H__

#include "cocos2d.h"

USING_NS_CC;

class EnemyBook : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //������һ������
    void colEnemyInfo();  //������Ϣ

    CREATE_FUNC(EnemyBook);
private:
    //����
    Label* AlphawormInfo;
    Label* SeagliderInfo;
    Label* D4Info;
    Label* DuInfo;
    Label* HugeuglyInfo;
};

#endif // _ENEMY__BOOK_H__
#pragma once
