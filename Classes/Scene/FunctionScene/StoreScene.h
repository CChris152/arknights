#pragma once

#ifndef __STORE_SCENE_H__
#define __STORE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Store : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //返回上一个场景

    void menuCheat(cocos2d::Ref* pSender); //一键作弊

    void menugoods_1(cocos2d::Ref* pSender); //购买商品一
    void menugoods_2(cocos2d::Ref* pSender); //购买商品二

    void makesellout(int goodsnum); //使某一商品处于售罄状态

    CREATE_FUNC(Store);

private:
    Label* JadeNum; //合成玉数量
    Label* Closuregreeting; //可露希尔问候语

    Menu* goods_1menu;//商品一按钮
    Menu* goods_2menu;//商品一按钮
};

#endif // __STORE_SCENE_H__
