#pragma once
#ifndef __EYJAFJALLA_OPERATOR_H__
#define __EYJAFJALLA_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Eyjafjalla :public Operator
{
public:
	Eyjafjalla(int Numbering, Vec2 VecPlace); //���ñ�ź�λ��
	~Eyjafjalla() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	void Remove(); //�����Ƴ�����

	Sprite* Eyjafjallasprite; //����
	Sprite* EyjafjallaBar;    //Ѫ����
	ProgressTimer* EyjafjallaBlood;  //Ѫ����ʾ
	float Eyjafjallapercentage;

private:
	float Eyjafjallatimer; //��ʱ��
};


#endif // __EYJAFJALLA_OPERATOR_H__