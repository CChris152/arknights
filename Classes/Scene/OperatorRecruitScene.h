#pragma once

#ifndef __OPERATOR_RECRUIT_SCENE_H__
#define __OPERATOR_RECRUIT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class OperatorRecruit : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //������һ������
    void menuRecruitCallback(cocos2d::Ref* pSender); //�鿨

    CREATE_FUNC(OperatorRecruit);
};

#endif // __OPERATOR_RECRUIT_SCENE_H__