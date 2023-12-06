#pragma once

#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class GameLogic :public cocos2d::Node 
{
public:
	GameLogic(Scene* currentscene);
	~GameLogic() = default;

	virtual void update(float update_time);

	void setEnemyWave(std::vector<std::vector<int>> EnemyWave); //设置关卡敌人波次分布

	Scene* scece; //绑定的场景
	int victoryorfail; //胜利或失败（-1为失败，0为关卡中，1为胜利）

private:
	float gametimer1; //计时器
	float gametimer2;

	int currentwave; //当前波次
	std::vector<std::vector<int>> enemywave; //当前关卡敌人波次分布
};


#endif // __GAMELOGIC_H__
