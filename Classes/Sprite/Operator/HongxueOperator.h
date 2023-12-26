#pragma once
#ifndef __HONGXUE_OPERATOR_H__
#define __HONGXUE_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Hongxue :public Operator
{
public:
	Hongxue(int Numbering, Vec2 VecPlace); //设置编号和位置
	~Hongxue() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	void Remove(); //数组移除函数

	Sprite* Hongxuesprite; //鸿雪精灵
	Sprite* HongxueBar;    //血条框
	ProgressTimer* HongxueBlood;  //血量显示
	float Hongxuepercentage;

private:
	float Hongxuetimer; //计时器
};


#endif // __EXUSIAI_OPERATOR_H__