#pragma once

#ifndef __OPERATOR_BASE_H__
#define __OPERATOR_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Operator :public cocos2d::Sprite
{
public:
	Operator() = default;
	~Operator() = default;

	virtual void OperatorInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化

	virtual void setAttack(int Attack); //设置攻击力
	virtual void setAttackSpeed(float AttackSpeed); //设置攻速
	virtual void setExpense(int Expense); //设置费用
	virtual void setAttackRange(int AttackRange); //设置攻击范围

	virtual void setNumbering(int Numbering); //设置费用


	virtual int getAttack(); //得到攻击力
	virtual float getAttackSpeed(); //得到攻速
	virtual int getExpense(); //得到费用
	virtual int getAttackRange(); //得到攻击范围

	virtual int getNumbering(); //得到编号

private:
	int attack; //攻击力
	float attackspeed; //攻速
	int expense; //费用
	int attackrange; //攻击范围

	int numbering; //编号
};


#endif // __OPERATOR_BASE_H__