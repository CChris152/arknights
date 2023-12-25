#pragma once


#ifndef __DU_ENEMY_H__
#define __DU_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Du :public Enemy
{
public:
	Du();
	~Du() = default;

	virtual void EnemyInit(); //数值初始化
	virtual void SpriteInit(); //精灵初始化


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //设置当前路径

	Sprite* DuSprite; //妒精灵
	Sprite* DuBar; //妒血条框
	Sprite* Blood; //血条
	ProgressTimer* DuBlood; //妒血条

private:
	std::vector<std::vector<int>> Road; //移动路径

	int RoadStep; //当前运行的步数
	float xvec; //x轴向量方向
	float yvec; //y轴向量方向
	float Dupercentage;//血量百分比

	float Alphawormtimer; //计时器
};

#endif // __DU_ENEMY_H__