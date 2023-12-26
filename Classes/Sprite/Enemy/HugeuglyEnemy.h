#pragma once

#ifndef __HUGEUGLY_ENEMY_H__
#define __HUGEUGLY_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Hugeugly :public Enemy
{
public:
	Hugeugly();
	~Hugeugly() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //设置当前路径

	Sprite* HugeuglySprite; //大丑精灵
	Sprite* HugeuglyBar; //大丑血条框
	Sprite* Blood; //血条
	ProgressTimer* HugeuglyBlood; //大丑血条

private:
	std::vector<std::vector<int>> Road; //移动路径

	int RoadStep; //当前运行的步数
	float xvec; //x轴向量方向
	float yvec; //y轴向量方向
	float percentage;//大丑血量百分比

	float Hugeuglytimer; //计时器
};

#endif // __HUGEUGLY_ENEMY_H__
