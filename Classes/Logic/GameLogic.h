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

	void setEnemyWave(std::vector<std::vector<int>> EnemyWave); //���ùؿ����˲��ηֲ�

	Scene* scece; //�󶨵ĳ���

private:
	float gametimer1; //��ʱ��
	float gametimer2;

	int currentwave; //��ǰ����
	std::vector<std::vector<int>> enemywave; //��ǰ�ؿ����˲��ηֲ�
};


#endif // __GAMELOGIC_H__
