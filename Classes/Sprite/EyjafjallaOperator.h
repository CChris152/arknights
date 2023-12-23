#pragma once
#ifndef __EYJAFJALLA_OPERATOR_H__
#define __EYJAFJALLA_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Eyjafjalla :public Operator
{
public:
	Eyjafjalla(int Numbering, Vec2 VecPlace); //设置编号和位置
	~Eyjafjalla() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	void Remove(); //数组移除函数

	Sprite* Eyjafjallasprite; //精灵
	Sprite* EyjafjallaBar;    //血条框
	ProgressTimer* EyjafjallaBlood;  //血量显示
	float Eyjafjallapercentage;

private:
	float Eyjafjallatimer; //计时器
};


#endif // __EYJAFJALLA_OPERATOR_H__