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
    void OperatorOverview(cocos2d::Ref* pSender);   //��Ա����

    CREATE_FUNC(CollectionBook);
};

#endif // __COLLECTION_RECRUIT_SCENE_H__#pragma once
