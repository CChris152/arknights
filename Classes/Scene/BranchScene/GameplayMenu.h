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

    //void setFinishLevelNum(int num); //设置完成关卡数量函数

    void menuCloseCallback(cocos2d::Ref* pSender);           //程序关闭
    void menuToLevelSelecScene(cocos2d::Ref* pSender);       //进入关卡选择
    void menuToOperatorRecruitment(cocos2d::Ref* pSender);   //进入干员寻访
    void menuToCollectionBook(cocos2d::Ref* pSender);        //进入干员图鉴
    void menuToStore(cocos2d::Ref* pSender);        //进入商店
    void menuToGameplayIntroduction(cocos2d::Ref* pSender);  //进入玩法说明

    void TextButtonCreat(); //文字按钮生成函数

    CREATE_FUNC(GameplayMenu);
};


#endif // __GAMEPLAYMENU_SCENE_H__