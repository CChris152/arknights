#pragma once


#ifndef __DU_ENEMY_H__
#define __DU_ENEMY_H__

#include "cocos2d.h"
#include "EnemyBase.h"

USING_NS_CC;

class Du :public Enemy
{
public:
	Du();
	~Du() = default;

	virtual void EnemyInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��


	virtual void update(float update_time);

	virtual void setRoad(std::vector<std::vector<int>> currentRoad); //���õ�ǰ·��

	Sprite* DuSprite; //�ʾ���
	Sprite* DuBar; //��Ѫ����
	Sprite* Blood; //Ѫ��
	ProgressTimer* DuBlood; //��Ѫ��

private:
	std::vector<std::vector<int>> Road; //�ƶ�·��

	int RoadStep; //��ǰ���еĲ���
	float xvec; //x����������
	float yvec; //y����������
	float Dupercentage;//Ѫ���ٷֱ�

	float Alphawormtimer; //��ʱ��
};

#endif // __DU_ENEMY_H__