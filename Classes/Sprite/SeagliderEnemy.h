#pragma once

#ifndef __SEAGLIDER_ENEMY_H__
#define __SEAGLIDER_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Seaglider :public Enemy
{
public:
	Seaglider();
	~Seaglider() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //���õ�ǰ·��

	Sprite* SeagliderSprite; //������Դʯ�澫��
	Sprite* SeagliderBar; //������Դʯ��Ѫ����
	Sprite* Blood; //Ѫ��
	ProgressTimer* SeagliderBlood; //������Դʯ��Ѫ��

private:
	std::vector<std::vector<int>> Road; //�ƶ�·��

	int RoadStep; //��ǰ���еĲ���
	int xvec; //x����������
	int yvec; //y����������
	float percentage;//������Դʯ��Ѫ���ٷֱ�

	float Seaglidertimer; //��ʱ��
};

#endif // __SEAGLIDER_ENEMY_H__


