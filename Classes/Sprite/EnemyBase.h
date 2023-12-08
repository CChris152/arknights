#pragma once

#ifndef __ANEMYBASE_BASE_H__
#define __ANEMYBASE_BASE_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class Enemy :public cocos2d::Sprite
{
public:
	Enemy() = default;
	~Enemy() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��
	virtual void LabelInit(); //��ǩ��ʼ��

	virtual void setAttack(int Attack); //���ù�����
	virtual void setAttackSpeed(float AttackSpeed); //���ù����ٶ�
	virtual void setmaxHP(int MaxHP); //�������Ѫ��
	virtual void setcurrentHP(int CurrentHP); //���õ�ǰѪ��
	virtual void decreaseHP(int DecreaseHP); //����Ѫ��
	virtual void setspeed(float Speed); //��������
	virtual void setPhysicalDefense(int PhysicalDefense); //���ù�����
	virtual void setMagicalDefense(int MagicalDefense); //�������Ѫ��

	virtual int getAttack(); //�õ�������
	virtual float getAttackSpeed(); //�õ������ٶ�
	virtual int getmaxHP(); //�õ����Ѫ��
	virtual int getcurrentHP(); //�õ���ǰѪ��
	virtual float getspeed(); //�õ�����
	virtual int getPhysicalDefense(); //�õ��������
	virtual int getMagicalDefense(); //�õ�ħ������

	bool IsDead; //�Ƿ��Ѿ�����
	bool IsStopped; //�Ƿ��赲
	int stoppedoperatornum; //���赲�ĸ�Ա���

private:
	int attack; //������
	float attackspeed; //�����ٶȣ�ʱ������
	int maxHP; //���Ѫ��
	int currentHP; //��ǰѪ��
	float speed; //����
	int physicaldefense; //�������
	int magicaldefense; //ħ������
};

#endif // __ANEMYBASE_BASE_H__
