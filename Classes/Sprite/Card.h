#pragma once

#ifndef __CARD_BASE_H__
#define __CARD_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Card :public cocos2d::Sprite {
public:
	Card(std::string Name, int CardExpense);

	virtual void update(float update_time);

	int getCardExpense(); //得到卡片费用

	Sprite* CardSprite; //卡片图像精灵

	bool IsCD; //是否处于CD中

	Sprite* BlackCD; //黑色CD
	ProgressTimer* BlackCDTimer; //黑色CD进度条

private:
	std::string name; //干员名称
	int cardexpense; //卡片费用
	float CD; //卡片冷却时间
	float Cardtimer; //卡片计时器
};

#endif // __CARD_BASE_H__

