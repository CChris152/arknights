#pragma once

#ifndef __D4_ENEMY_H__
#define __D4_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class D4 :public Enemy
{
public:
	D4();
	~D4() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //���õ�ǰ·��

	Sprite* D4Sprite; //������Դʯ�澫��
	Sprite* D4Bar; //������Դʯ��Ѫ����
	Sprite* Blood; //Ѫ��
	ProgressTimer* D4Blood; //������Դʯ��Ѫ��

private:
	std::vector<std::vector<int>> Road; //�ƶ�·��

	int RoadStep; //��ǰ���еĲ���
	float xvec; //x����������
	float yvec; //y����������
	float percentage;//��4Ѫ���ٷֱ�

	float D4timer; //��ʱ��
};

#endif // __D4M_ENEMY_H__
