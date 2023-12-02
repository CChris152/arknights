#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include "Sprite/EnemyBase.h"
#include "Sprite/OperatorBase.h"
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
extern std::vector<Operator*> AllOperator; //���ɵĸ�Ա
extern std::vector<Sprite*> Allenemy; //���ɵĵ��˾���
extern std::vector<Sprite*> Alloperator; //���ɵĸ�Ա����

extern std::vector<std::vector<int>> Level1vec; //��һ�صĵ�ͼ����
extern std::vector<std::vector<int>> Level1Road; //��һ�صĵ����ж�·��

extern std::vector<std::vector<std::vector<int>>> EnemyWave; //���йؿ����ֵĵ��˲���

#endif // __AllData_H__