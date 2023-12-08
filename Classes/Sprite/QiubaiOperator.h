#pragma once

#ifndef __QIUBAI_OPERATOR_H__
#define __QIUBAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"
#include <vector>

USING_NS_CC;

class Qiubai :public Operator
{
public:
	Qiubai(int Numbering, Vec2 VecPlace); //设置编号和位置
	~Qiubai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	void Remove(); //数组移除函数

	Sprite* Qiubaisprite; //能天使精灵

private:
	float Qiubaitimer; //计时器
};


#endif // __QIUBAI_OPERATOR_H__

