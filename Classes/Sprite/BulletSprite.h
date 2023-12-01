#pragma once

#ifndef __BULLET_SPRITE_H__
#define __BULLET_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Bullet :public cocos2d::Sprite
{
public:
	Bullet(int Start, int End); //设置了起点和终点

	virtual void update(float update_time);

	bool IsDestroyed; //是否销毁

	Sprite* bulletSprite;

private:
	float speed;

	int startoperator; //起始干员序号
	int endenemy; //终点敌人序号
};


#endif // __BULLET_SPRITE_H__