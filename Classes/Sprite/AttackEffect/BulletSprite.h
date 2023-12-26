#pragma once

#ifndef __BULLET_SPRITE_H__
#define __BULLET_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Bullet :public cocos2d::Sprite
{
public:
	Bullet(int Start, int End); //�����������յ�

	virtual void update(float update_time);

	bool IsDestroyed; //�Ƿ�����

	Sprite* bulletSprite;

private:
	float speed;

	int startoperator; //��ʼ��Ա���
	int endenemy; //�յ�������
};


#endif // __BULLET_SPRITE_H__