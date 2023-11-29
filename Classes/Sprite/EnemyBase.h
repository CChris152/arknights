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

	virtual void setmaxHP(int MaxHP); //�������Ѫ��
	virtual void setcurrentHP(int CurrentHP); //���õ�ǰѪ��
	virtual void decreaseHP(int DecreaseHP); //����Ѫ��
	virtual void setspeed(float Speed); //��������

	virtual int getmaxHP(); //�õ����Ѫ��
	virtual int getcurrentHP(); //�õ���ǰѪ��
	virtual float getspeed(); //�õ�����

	bool IsDead; //�Ƿ��Ѿ�����

private:
	int maxHP; //���Ѫ��
	int currentHP; //��ǰѪ��
	float speed; //����
};

#endif // __ANEMYBASE_BASE_H__
