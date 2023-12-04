#pragma once

#ifndef __EXUSIAI_OPERATOR_H__
#define __EXUSIAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Exuasiai :public Operator
{
public:
	Exuasiai(int Numbering); //设置编号
	~Exuasiai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	Sprite* Exuasiaisprite; //能天使精灵

private:
	float Exuasiaitimer; //计时器
};


#endif // __EXUSIAI_OPERATOR_H__