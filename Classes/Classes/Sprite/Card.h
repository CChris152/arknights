#pragma once

#ifndef __CARD_BASE_H__
#define __CARD_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Card :public cocos2d::Sprite {
public:
	Card(std::string Name, int CardExpense);

	int getCardExpense(); //�õ���Ƭ����

	Sprite* CardSprite; //��Ƭͼ����

private:
	std::string name; //��Ա����
	int cardexpense; //��Ƭ����
	float CD; //��Ƭ��ȴʱ��
};

#endif // __CARD_BASE_H__

