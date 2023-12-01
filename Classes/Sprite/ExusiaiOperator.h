#pragma once

#ifndef __EXUSIAI_OPERATOR_H__
#define __EXUSIAI_OPERATOR_H__

#include "cocos2d.h"
#include "OperatorBase.h"

USING_NS_CC;

class Exuasiai :public Operator
{
public:
	Exuasiai(int Numbering); //���ñ��
	~Exuasiai() = default;

	virtual void update(float update_time);

	virtual void OperatorInit(); //��ֵ��ʼ��
	virtual void SpriteInit(); //�����ʼ��

	Sprite* Exuasiaisprite; //����ʹ����

private:
	float Exuasiaitimer; //��ʱ��
};


#endif // __EXUSIAI_OPERATOR_H__