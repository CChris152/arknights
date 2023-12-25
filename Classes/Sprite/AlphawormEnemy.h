#pragma once

#ifndef __ALPHAWORM_ENEMY_H__
#define __ALPHAWORM_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Alphaworm :public Enemy
{
public:
	Alphaworm();
	~Alphaworm() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化
	

	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //设置当前路径

	Sprite* AlphawormSprite; //阿尔法源石虫精灵
	Sprite* AlphawormBar; //阿尔法源石虫血条框
	Sprite* Blood; //血条
	ProgressTimer* AlphawormBlood; //阿尔法源石虫血条

private:
	std::vector<std::vector<int>> Road; //移动路径

	int RoadStep; //当前运行的步数
	float xvec; //x轴向量方向
	float yvec; //y轴向量方向
	float percentage;//阿尔法源石虫血量百分比

	float Alphawormtimer; //计时器
};

#endif // __ALPHAWORM_ENEMY_H__

