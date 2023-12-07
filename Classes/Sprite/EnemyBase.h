#pragma once

#ifndef __ANEMYBASE_BASE_H__
#define __ANEMYBASE_BASE_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class Enemy :public cocos2d::Sprite
{
public:
	Enemy() = default;
	~Enemy() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化
	virtual void LabelInit(); //标签初始化

	virtual void setAttack(int Attack); //设置攻击力
	virtual void setmaxHP(int MaxHP); //设置最大血量
	virtual void setcurrentHP(int CurrentHP); //设置当前血量
	virtual void decreaseHP(int DecreaseHP); //减少血量
	virtual void setspeed(float Speed); //设置移速
	virtual void setPhysicalDefense(int PhysicalDefense); //设置攻击力
	virtual void setMagicalDefense(int MagicalDefense); //设置最大血量

	virtual int getAttack(); //得到攻击力
	virtual int getmaxHP(); //得到最大血量
	virtual int getcurrentHP(); //得到当前血量
	virtual float getspeed(); //得到移速
	virtual int getPhysicalDefense(); //得到物理防御
	virtual int getMagicalDefense(); //得到魔法防御

	bool IsDead; //是否已经死亡

private:
	int attack; //攻击力
	int maxHP; //最大血量
	int currentHP; //当前血量
	float speed; //移速
	int physicaldefense; //物理防御
	int magicaldefense; //魔法防御
};

#endif // __ANEMYBASE_BASE_H__
