#pragma once

#ifndef __D4_ENEMY_H__
#define __D4_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class D4 :public Enemy
{
public:
	D4();
	~D4() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //设置当前路径

	Sprite* D4Sprite; //阿尔法源石虫精灵
	Sprite* D4Bar; //阿尔法源石虫血条框
	Sprite* Blood; //血条
	ProgressTimer* D4Blood; //阿尔法源石虫血条

private:
	std::vector<std::vector<int>> Road; //移动路径

	int RoadStep; //当前运行的步数
	float xvec; //x轴向量方向
	float yvec; //y轴向量方向
	float percentage;//御4血量百分比

	float D4timer; //计时器
};

#endif // __D4M_ENEMY_H__
