#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include "Sprite/EnemyBase.h"
#include <vector>

USING_NS_CC;

extern int FinishLevelNum; //����ɵĹؿ�����
extern int CurrentLevel; //��ǰִ�еĹؿ�

extern int Maptime; //��ͼ��ʱ��
extern int expenses; //����
extern int BaseHP; //����Ѫ��
extern int allenemynum; //��������
extern int killednum; //�����������

extern std::vector<std::string> Cards; //��Ա��Ƭ����
extern std::vector<Sprite*> CardsSpr; //��Ա��Ƭ����
extern std::vector<int> CardsExpenses; //��Ա��Ƭ�������

extern std::vector<Enemy*> AllEnemy; //���ɵĵ���

extern std::vector<std::vector<int>> Level1vec; //��һ�صĵ�ͼ����
extern std::vector<std::vector<int>> Level1Road; //��һ�صĵ����ж�·��

#endif // __AllData_H__