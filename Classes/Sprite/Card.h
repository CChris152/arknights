#pragma once

#ifndef __CARD_BASE_H__
#define __CARD_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Card :public cocos2d::Sprite {
public:
	Card(std::string Name, int CardExpense);

	int getCardExpense(); //得到卡片费用

	Sprite* CardSprite; //卡片图像精灵

private:
	std::string name; //干员名称
	int cardexpense; //卡片费用
	float CD; //卡片冷却时间
};

#endif // __CARD_BASE_H__

