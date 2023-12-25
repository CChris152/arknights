#pragma once

#ifndef __ALPHAWORM_ENEMY_H__
#define __ALPHAWORM_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Alphaworm :public Enemy
{
public:
	Alphaworm();
	~Alphaworm() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��
	

	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //���õ�ǰ·��

	Sprite* AlphawormSprite; //������Դʯ�澫��
	Sprite* AlphawormBar; //������Դʯ��Ѫ����
	Sprite* Blood; //Ѫ��
	ProgressTimer* AlphawormBlood; //������Դʯ��Ѫ��

private:
	std::vector<std::vector<int>> Road; //�ƶ�·��

	int RoadStep; //��ǰ���еĲ���
	float xvec; //x����������
	float yvec; //y����������
	float percentage;//������Դʯ��Ѫ���ٷֱ�

	float Alphawormtimer; //��ʱ��
};

#endif // __ALPHAWORM_ENEMY_H__

