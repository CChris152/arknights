#pragma once

#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include "cocos2d.h"

USING_NS_CC;

class GameLogic :public cocos2d::Node 
{
public:
	GameLogic(Scene* currentscene);
	~GameLogic() = default;

	virtual void update(float update_time);

	Scene* scece; //绑定的场景
	int victoryorfail; //胜利或失败（-1为失败，0为关卡中，1为胜利）
	float gametimer; //计时器
};


#endif // __GAMELOGIC_H__
