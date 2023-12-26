#pragma once
#ifndef __MAGICBALL_SPRITE_H__
#define __MAGICBALL_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Magicball :public cocos2d::Sprite
{
public:
	Magicball(int Start, int End); //设置了起点和终点

	virtual void update(float update_time);

	bool IsDestroyed; //是否销毁

	Sprite* magicballSprite;

private:
	float speed;
	float attackRange;

	int startoperator; //起始干员序号
	int endenemy; //终点敌人序号
};


#endif // __MAGICBALL_SPRITE_H__