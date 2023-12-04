#pragma once
#ifndef __HONGXUE_OPERATOR_H__
#define __HONGXUE_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Hongxue :public Operator
{
public:
	Hongxue(int Numbering); //设置编号
	~Hongxue() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	Sprite* Hongxuesprite; //鸿雪精灵

private:
	float Hongxuetimer; //计时器
};


#endif // __EXUSIAI_OPERATOR_H__