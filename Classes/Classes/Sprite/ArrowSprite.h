#pragma once

#ifndef __ARROW_SPRITE_H__
#define __ARROW_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Arrow :public cocos2d::Sprite
{
public:
	Arrow(int Start, int End); //�����������յ�

	virtual void update(float update_time);

	bool IsDestroyed; //�Ƿ�����

	Sprite* arrowSprite;

private:
	float speed;

	int startoperator; //��ʼ��Ա���
	int endenemy; //�յ�������
};


#endif // __BULLET_SPRITE_H__