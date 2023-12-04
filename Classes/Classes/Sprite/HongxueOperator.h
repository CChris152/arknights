#pragma once
#ifndef __HONGXUE_OPERATOR_H__
#define __HONGXUE_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Hongxue :public Operator
{
public:
	Hongxue(int Numbering); //���ñ��
	~Hongxue() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	Sprite* Hongxuesprite; //��ѩ����

private:
	float Hongxuetimer; //��ʱ��
};


#endif // __EXUSIAI_OPERATOR_H__