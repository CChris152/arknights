#pragma once

#ifndef __SARIA_OPERATOR_H__
#define __SARIA_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"
#include <vector>

USING_NS_CC;

class Saria :public Operator
{
public:
	Saria(int Numbering, Vec2 VecPlace); //���ñ�ź�λ��
	~Saria() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	void Remove(); //�����Ƴ�����

	Sprite* Sariasprite; //����
	Sprite* SariaBar;    //Ѫ����
	ProgressTimer* SariaBlood;  //Ѫ����ʾ
	float Sariapercentage;

private:
	float Sariatimer; //��ʱ��
};


#endif // __SARIA_OPERATOR_H__

#pragma once
