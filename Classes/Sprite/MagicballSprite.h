#pragma once
#ifndef __MAGICBALL_SPRITE_H__
#define __MAGICBALL_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Magicball :public cocos2d::Sprite
{
public:
	Magicball(int Start, int End); //�����������յ�

	virtual void update(float update_time);

	bool IsDestroyed; //�Ƿ�����

	Sprite* magicballSprite;

private:
	float speed;
	float attackRange;

	int startoperator; //��ʼ��Ա���
	int endenemy; //�յ�������
};


#endif // __MAGICBALL_SPRITE_H__