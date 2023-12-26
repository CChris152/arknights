#pragma once

#ifndef __SELECT_BOOK_SCENE_H__
#define __SELECT_BOOK_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class SelectBookScene : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //返回上一个场景
    void ToOperatorBook(cocos2d::Ref* pSender);
    void ToEnemyBook(cocos2d::Ref* pSender);

    void TextButtonCreat(); //文字按钮生成函数

    CREATE_FUNC(SelectBookScene);
};

#endif // __SELECT_BOOK_SCENE_H__
