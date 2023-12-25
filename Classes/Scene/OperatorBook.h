#pragma once

#ifndef __OPERATOR_BOOK_H__
#define __OPERATOR_BOOK_H__

#include "cocos2d.h"

USING_NS_CC;

class OperatorBook : public cocos2d::Scene
{
public:
    virtual bool init();

    void menuBackCallback(cocos2d::Ref* pSender); //������һ������
    void colOperatorInfo();   //��Ա��Ϣ

    CREATE_FUNC(OperatorBook);
private:
    //��Ա
    Label* ExusiaiInfo;
    Label* HongxueInfo;
    Label* QiubaiInfo;
    Label* EyjafjallaInfo;
    Label* SariaInfo;
};

#endif // __OPERATOR_BOOK_H__
#pragma once
