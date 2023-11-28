#pragma once

#ifndef __OPERATOR_BASE_H__
#define __OPERATOR_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class Operator :public cocos2d::Sprite
{
public:
	Operator() = default;
	~Operator() = default;

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	virtual void setAttack(int Attack); //���ù�����
	virtual void setAttackSpeed(float AttackSpeed); //���ù���
	virtual void setExpense(int Expense); //���÷���

	virtual int getExpense(); //�õ�����

private:
	int attack; //������
	float attackspeed; //����
	int expense; //����
};


#endif // __OPERATOR_BASE_H__