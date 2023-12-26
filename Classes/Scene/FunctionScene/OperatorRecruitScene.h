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

    void Recruit(); //�����ȡ���

    CREATE_FUNC(OperatorRecruit);

private:
    Label* JadeNum; //�ϳ�������
    Label* prompt; //�鿨�����������ʾ
    Label* Closuregreeting; //��¶ϣ���ʺ���
};

#endif // __OPERATOR_RECRUIT_SCENE_H__