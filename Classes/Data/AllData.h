#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

extern int FinishLevelNum; //����ɵĹؿ�����

extern int Maptime; //��ͼ��ʱ��
extern int expenses; //����
extern int BaseHP; //����Ѫ��
extern int allenemynum; //��������
extern int killednum; //�����������

extern std::vector<std::string> Cards; //��Ա��Ƭ����
extern std::vector<Sprite*> CardsSpr; //��Ա��Ƭ����

#endif // __AllData_H__