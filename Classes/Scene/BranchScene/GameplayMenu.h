#pragma once

#ifndef __GAMEPLAY_MENU_SCENE_H__
#define __GAMEPLAY_MENU_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameplayMenu : public cocos2d::Scene
{
public:
   // static cocos2d::Scene* createScene();
    virtual bool init();

    //void setFinishLevelNum(int num); //������ɹؿ���������

    void menuCloseCallback(cocos2d::Ref* pSender);           //����ر�
    void menuToLevelSelecScene(cocos2d::Ref* pSender);       //����ؿ�ѡ��
    void menuToOperatorRecruitment(cocos2d::Ref* pSender);   //�����ԱѰ��
    void menuToCollectionBook(cocos2d::Ref* pSender);        //�����Աͼ��
    void menuToStore(cocos2d::Ref* pSender);        //�����̵�
    void menuToGameplayIntroduction(cocos2d::Ref* pSender);  //�����淨˵��

    void TextButtonCreat(); //���ְ�ť���ɺ���

    CREATE_FUNC(GameplayMenu);
};


#endif // __GAMEPLAYMENU_SCENE_H__