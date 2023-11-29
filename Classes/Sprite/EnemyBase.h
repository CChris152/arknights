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

	virtual void setmaxHP(int MaxHP); //设置最大血量
	virtual void setcurrentHP(int CurrentHP); //设置当前血量
	virtual void decreaseHP(int DecreaseHP); //减少血量
	virtual void setspeed(float Speed); //设置移速

	virtual int getmaxHP(); //得到最大血量
	virtual int getcurrentHP(); //得到当前血量
	virtual float getspeed(); //得到移速

	bool IsDead; //是否已经死亡

private:
	int maxHP; //最大血量
	int currentHP; //当前血量
	float speed; //移速
};

#endif // __ANEMYBASE_BASE_H__
