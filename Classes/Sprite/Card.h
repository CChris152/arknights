#pragma once

#ifndef __CARD_BASE_H__
#define __CARD_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Card :public cocos2d::Sprite {
public:
	Card(std::string Name, int CardExpense);

	virtual void update(float update_time);

	int getCardExpense(); //�õ���Ƭ����

	Sprite* CardSprite; //��Ƭͼ����

	bool IsCD; //�Ƿ���CD��

private:
	std::string name; //��Ա����
	int cardexpense; //��Ƭ����
	float CD; //��Ƭ��ȴʱ��
	float Cardtimer; //��Ƭ��ʱ��

	Sprite* BlackCD; //��ɫCD
	ProgressTimer* BlackCDTimer; //��ɫCD������
};

#endif // __CARD_BASE_H__

