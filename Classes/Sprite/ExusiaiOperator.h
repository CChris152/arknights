#pragma once

#ifndef __EXUSIAI_OPERATOR_H__
#define __EXUSIAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Exusiai :public Operator
{
public:
	Exusiai(int Numbering, Vec2 VecPlace); //���ñ�ź�λ��
	~Exusiai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	void Remove(); //�����Ƴ�����

	Sprite* Exusiaisprite; //����ʹ����
	Sprite* ExusiaiBar;    //Ѫ����
	ProgressTimer* ExusiaiBlood;  //Ѫ����ʾ
	float Exusiaipercentage;

private:
	float Exusiaitimer; //��ʱ��
};


#endif // __EXUSIAI_OPERATOR_H__