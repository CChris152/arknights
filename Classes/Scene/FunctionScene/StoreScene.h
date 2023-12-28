#pragma once

#ifndef __STORE_SCENE_H__
#define __STORE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Store : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //������һ������

    void menuCheat(cocos2d::Ref* pSender); //һ������

    void menugoods_1(cocos2d::Ref* pSender); //������Ʒһ
    void menugoods_2(cocos2d::Ref* pSender); //������Ʒ��

    void makesellout(int goodsnum); //ʹĳһ��Ʒ��������״̬

    CREATE_FUNC(Store);

private:
    Label* JadeNum; //�ϳ�������
    Label* Closuregreeting; //��¶ϣ���ʺ���

    Menu* goods_1menu;//��Ʒһ��ť
    Menu* goods_2menu;//��Ʒһ��ť
};

#endif // __STORE_SCENE_H__
