#pragma once

#ifndef __HUGEUGLY_ENEMY_H__
#define __HUGEUGLY_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Hugeugly :public Enemy
{
public:
	Hugeugly();
	~Hugeugly() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //���õ�ǰ·��

	Sprite* HugeuglySprite; //�����
	Sprite* HugeuglyBar; //���Ѫ����
	Sprite* Blood; //Ѫ��
	ProgressTimer* HugeuglyBlood; //���Ѫ��

private:
	std::vector<std::vector<int>> Road; //�ƶ�·��

	int RoadStep; //��ǰ���еĲ���
	float xvec; //x����������
	float yvec; //y����������
	float percentage;//���Ѫ���ٷֱ�

	float Hugeuglytimer; //��ʱ��
};

#endif // __HUGEUGLY_ENEMY_H__
