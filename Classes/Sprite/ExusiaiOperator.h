#pragma once

#ifndef __EXUSIAI_OPERATOR_H__
#define __EXUSIAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Exuasiai :public Operator
{
public:
	Exuasiai();
	~Exuasiai() = default;

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	Sprite* Exuasiaisprite; //能天使精灵
};


#endif // __EXUSIAI_OPERATOR_H__