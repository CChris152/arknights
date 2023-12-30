#pragma once

#ifndef __OPERATOR_BASE_H__
#define __OPERATOR_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

enum AttackType {
	physical,
	magical
};

class Operator :public cocos2d::Sprite
{
public:
	Operator() = default;
	~Operator() = default;

	virtual void OperatorInit() = 0; //数值初始化
	virtual void SpriteInit() = 0; //精灵初始化

	virtual void setMaxHP(int MaxHP); //设置血量
	virtual void setCurrentHP(int CurrentHP); //得到当前血量
	virtual void setAttack(int Attack); //设置攻击力
	virtual void setAttackSpeed(float AttackSpeed); //设置攻速
	virtual void setExpense(int Expense); //设置费用
	virtual void setAttackRange(int AttackRange); //设置攻击范围
	virtual void setNumbering(int Numbering); //设置费用
	virtual void setVecPlace(Vec2 VecPlace); //设置数组坐标
	virtual void setMaxStopNum(int MaxStopNum); //设置最大阻挡数
	virtual void setCurrentStopNum(int CurrentStopNum); //设置当前阻挡数

	virtual void setAttackType(AttackType attacktype_); //设置攻击种类

	virtual void decreaseBlood(int DecreaseBlood); //扣除血量

	virtual int getMaxHP(); //得到血量
	virtual int getCurrentHP(); //得到当前血量
	virtual int getAttack(); //得到攻击力
	virtual float getAttackSpeed(); //得到攻速
	virtual int getExpense(); //得到费用
	virtual int getAttackRange(); //得到攻击范围
	virtual int getNumbering(); //得到编号
	virtual Vec2 getVecPlace(); //得到数组坐标
	virtual int getMaxStopNum(); //得到最大阻挡数
	virtual int getCurrentStopNum(); //得到当前阻挡数

	virtual AttackType getAttackType(); //得到攻击种类

	bool IsDead; //是否死亡
	Sprite* OperatorBlood; //血条
	std::vector<int> stoppedenemynum; //被阻挡的敌人编号

private:
	int maxHP; //血量
	int currentHP; //当前血量
	int attack; //攻击力
	float attackspeed; //攻速
	int expense; //费用
	int attackrange; //攻击范围
	int maxstopnum; //最大阻挡数
	int currentstopnum; //当前阻挡数

	AttackType attacktype; //攻击种类

	int numbering; //编号

	Vec2 vecplace; //数组坐标
	
};


#endif // __OPERATOR_BASE_H__