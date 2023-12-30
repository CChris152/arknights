#pragma once

#ifndef __OPERATOR_BASE_H__
#define __OPERATOR_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

enum AttackType {
	physical,
	magical
};

class Operator :public cocos2d::Sprite
{
public:
	Operator() = default;
	~Operator() = default;

	virtual void OperatorInit() = 0; //��ֵ��ʼ��
	virtual void SpriteInit() = 0; //�����ʼ��

	virtual void setMaxHP(int MaxHP); //����Ѫ��
	virtual void setCurrentHP(int CurrentHP); //�õ���ǰѪ��
	virtual void setAttack(int Attack); //���ù�����
	virtual void setAttackSpeed(float AttackSpeed); //���ù���
	virtual void setExpense(int Expense); //���÷���
	virtual void setAttackRange(int AttackRange); //���ù�����Χ
	virtual void setNumbering(int Numbering); //���÷���
	virtual void setVecPlace(Vec2 VecPlace); //������������
	virtual void setMaxStopNum(int MaxStopNum); //��������赲��
	virtual void setCurrentStopNum(int CurrentStopNum); //���õ�ǰ�赲��

	virtual void setAttackType(AttackType attacktype_); //���ù�������

	virtual void decreaseBlood(int DecreaseBlood); //�۳�Ѫ��

	virtual int getMaxHP(); //�õ�Ѫ��
	virtual int getCurrentHP(); //�õ���ǰѪ��
	virtual int getAttack(); //�õ�������
	virtual float getAttackSpeed(); //�õ�����
	virtual int getExpense(); //�õ�����
	virtual int getAttackRange(); //�õ�������Χ
	virtual int getNumbering(); //�õ����
	virtual Vec2 getVecPlace(); //�õ���������
	virtual int getMaxStopNum(); //�õ�����赲��
	virtual int getCurrentStopNum(); //�õ���ǰ�赲��

	virtual AttackType getAttackType(); //�õ���������

	bool IsDead; //�Ƿ�����
	Sprite* OperatorBlood; //Ѫ��
	std::vector<int> stoppedenemynum; //���赲�ĵ��˱��

private:
	int maxHP; //Ѫ��
	int currentHP; //��ǰѪ��
	int attack; //������
	float attackspeed; //����
	int expense; //����
	int attackrange; //������Χ
	int maxstopnum; //����赲��
	int currentstopnum; //��ǰ�赲��

	AttackType attacktype; //��������

	int numbering; //���

	Vec2 vecplace; //��������
	
};


#endif // __OPERATOR_BASE_H__