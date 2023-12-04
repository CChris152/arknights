#pragma once

#ifndef __ARROW_SPRITE_H__
#define __ARROW_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Arrow :public cocos2d::Sprite
{
public:
	Arrow(int Start, int End); //设置了起点和终点

	virtual void update(float update_time);

	bool IsDestroyed; //是否销毁

	Sprite* arrowSprite;

private:
	float speed;

	int startoperator; //起始干员序号
	int endenemy; //终点敌人序号
};


#endif // __BULLET_SPRITE_H__