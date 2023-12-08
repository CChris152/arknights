#pragma once

#ifndef __SWORD_SPRITE_H__
#define __SWORD_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Sword :public cocos2d::Sprite
{
public:
	Sword(int Start, int End); //设置了起点和终点

	virtual void update(float update_time);

	bool IsDestroyed; //是否销毁

	Sprite* swordSprite; //剑精灵

private:
	float swordtimer; //计时器

	int startoperator; //起始干员序号
	int endenemy; //终点敌人序号
};


#endif // __SWORD_SPRITE_H__
