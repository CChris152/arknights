#pragma once

#ifndef __EXUSIAI_OPERATOR_H__
#define __EXUSIAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Exusiai :public Operator
{
public:
	Exusiai(int Numbering, Vec2 VecPlace); //设置编号和位置
	~Exusiai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	void Remove(); //数组移除函数

	Sprite* Exusiaisprite; //能天使精灵
	Sprite* ExusiaiBar;    //血条框
	ProgressTimer* ExusiaiBlood;  //血量显示
	float Exusiaipercentage;

private:
	float Exusiaitimer; //计时器
};


#endif // __EXUSIAI_OPERATOR_H__