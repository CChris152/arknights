#pragma once

#ifndef __SEAGLIDER_ENEMY_H__
#define __SEAGLIDER_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Seaglider :public Enemy
{
public:
	Seaglider();
	~Seaglider() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //设置当前路径

	Sprite* SeagliderSprite; //阿尔法源石虫精灵
	Sprite* SeagliderBar; //阿尔法源石虫血条框
	Sprite* Blood; //血条
	ProgressTimer* SeagliderBlood; //阿尔法源石虫血条

private:
	std::vector<std::vector<int>> Road; //移动路径

	int RoadStep; //当前运行的步数
	int xvec; //x轴向量方向
	int yvec; //y轴向量方向
	float percentage;//阿尔法源石虫血量百分比

	float Seaglidertimer; //计时器
};

#endif // __SEAGLIDER_ENEMY_H__


