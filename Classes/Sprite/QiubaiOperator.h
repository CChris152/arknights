#pragma once

#ifndef __QIUBAI_OPERATOR_H__
#define __QIUBAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"
#include <vector>

USING_NS_CC;

class Qiubai :public Operator
{
public:
	Qiubai(int Numbering, Vec2 VecPlace); //���ñ�ź�λ��
	~Qiubai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	void Remove(); //�����Ƴ�����

	Sprite* Qiubaisprite; //����ʹ����

private:
	float Qiubaitimer; //��ʱ��
};


#endif // __QIUBAI_OPERATOR_H__

