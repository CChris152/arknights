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
    void OperatorOverview(cocos2d::Ref* pSender);   //干员总览

    CREATE_FUNC(CollectionBook);
};

#endif // __COLLECTION_RECRUIT_SCENE_H__#pragma once
