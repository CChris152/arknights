#pragma once
#ifndef __HONGXUE_OPERATOR_H__
#define __HONGXUE_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Hongxue :public Operator
{
public:
	Hongxue(int Numbering, Vec2 VecPlace); //���ñ�ź�λ��
	~Hongxue() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	void Remove(); //�����Ƴ�����

	Sprite* Hongxuesprite; //��ѩ����
	Sprite* HongxueBar;    //Ѫ����
	ProgressTimer* HongxueBlood;  //Ѫ����ʾ
	float Hongxuepercentage;

private:
	float Hongxuetimer; //��ʱ��
};


#endif // __EXUSIAI_OPERATOR_H__