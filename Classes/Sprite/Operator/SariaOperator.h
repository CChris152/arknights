#pragma once

#ifndef __SARIA_OPERATOR_H__
#define __SARIA_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"
#include <vector>

USING_NS_CC;

class Saria :public Operator
{
public:
	Saria(int Numbering, Vec2 VecPlace); //设置编号和位置
	~Saria() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	void Remove(); //数组移除函数

	Sprite* Sariasprite; //精灵
	Sprite* SariaBar;    //血条框
	ProgressTimer* SariaBlood;  //血量显示
	float Sariapercentage;

private:
	float Sariatimer; //计时器
};


#endif // __SARIA_OPERATOR_H__

#pragma once
