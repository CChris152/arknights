#pragma once

#ifndef __OPERATOR_BOOK_H__
#define __OPERATOR_BOOK_H__

#include "cocos2d.h"

USING_NS_CC;

class OperatorBook : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //返回上一个场景
    void colOperatorInfo();   //干员信息

    CREATE_FUNC(OperatorBook);
private:
    //干员
    Label* ExusiaiInfo;
    Label* HongxueInfo;
    Label* QiubaiInfo;
    Label* EyjafjallaInfo;
    Label* SariaInfo;
};

#endif // __OPERATOR_BOOK_H__
#pragma once
