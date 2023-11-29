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

	Scene* scece; //�󶨵ĳ���
	float gametimer; //��ʱ��
};


#endif // __GAMELOGIC_H__
