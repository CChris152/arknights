#pragma once

#ifndef __SWORD_SPRITE_H__
#define __SWORD_SPRITE_H__

#include "cocos2d.h"

USING_NS_CC;

class Sword :public cocos2d::Sprite
{
public:
	Sword(int Start, int End); //�����������յ�

	virtual void update(float update_time);

	bool IsDestroyed; //�Ƿ�����

	Sprite* swordSprite; //������

private:
	float swordtimer; //��ʱ��

	int startoperator; //��ʼ��Ա���
	int endenemy; //�յ�������
};


#endif // __SWORD_SPRITE_H__
