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

	virtual void setBlood(int Blood); //设置血量
	virtual void setAttack(int Attack); //设置攻击力
	virtual void setAttackSpeed(float AttackSpeed); //设置攻速
	virtual void setExpense(int Expense); //设置费用
	virtual void setAttackRange(int AttackRange); //设置攻击范围
	virtual void setNumbering(int Numbering); //设置费用
	virtual void setVecPlace(Vec2 VecPlace); //设置数组坐标

	virtual void decreaseBlood(int DecreaseBlood); //扣除血量

	virtual int getBlood(); //得到血量
	virtual int getAttack(); //得到攻击力
	virtual float getAttackSpeed(); //得到攻速
	virtual int getExpense(); //得到费用
	virtual int getAttackRange(); //得到攻击范围
	virtual int getNumbering(); //得到编号
	virtual Vec2 getVecPlace(); //得到数组坐标

	bool IsDead; //是否死亡

private:
	int blood; //血量
	int attack; //攻击力
	float attackspeed; //攻速
	int expense; //费用
	int attackrange; //攻击范围

	int numbering; //编号

	Vec2 vecplace; //数组坐标
};


#endif // __OPERATOR_BASE_H__