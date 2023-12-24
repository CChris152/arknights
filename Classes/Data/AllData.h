#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include "Sprite/EnemyBase.h"
#include "Sprite/OperatorBase.h"
#include "Sprite/Card.h"
#include <vector>

USING_NS_CC;

extern int Jade; //�����еĺϳ�������

extern int FinishLevelNum; //����ɵĹؿ�����
extern int CurrentLevel; //��ǰִ�еĹؿ�

extern int expenses; //����
extern int BaseHP; //����Ѫ��
extern int allenemynum; //��������
extern int killednum; //�����������

extern std::vector<int> CardsNum; //��Ա��Ƭ���
extern std::vector<int> LackCards; //ȱ�ٵĸ�Ա��Ƭ���
extern std::vector<std::string> OperatorName; //��Ա����

extern std::vector<Card*> Cards; //��Ա��Ƭ����
extern std::vector<Enemy*> AllEnemy; //���ɵĵ���
extern std::vector<Operator*> AllOperator; //���ɵĸ�Ա
extern std::vector<Sprite*> Allenemy; //���ɵĵ��˾���
extern std::vector<Sprite*> Alloperator; //���ɵĸ�Ա����
extern std::vector<Sprite*> AttackEffect; //���ɵĹ�����Ч���ӵ��ȣ�

extern std::vector<std::vector<int>> Level1vec; //��һ�صĵ�ͼ����
extern std::vector<std::vector<int>> Level1Road; //��һ�صĵ����ж�·��
extern std::vector<std::vector<int>> Level1EnemyWave; //��һ�س��ֵĵ��˲���

extern std::vector<std::vector<int>> Level2vec; //�ڶ��صĵ�ͼ����
extern std::vector<std::vector<int>> Level2Road; //�ڶ��صĵ����ж�·��
extern std::vector<std::vector<int>> Level2Fly; //�ڶ��صķ��е���·��
extern std::vector<std::vector<int>> Level2EnemyWave; //�ڶ��س��ֵĵ��˲���

extern std::vector<std::vector<int>> Level3vec; //�����صĵ�ͼ����
extern std::vector<std::vector<int>> Level3Road; //�����صĵ����ж�·��
extern std::vector<std::vector<int>> Level3Fly; //�����صķ��е���·��
extern std::vector<std::vector<int>> Level3EnemyWave; //�����س��ֵĵ��˲���

extern std::vector<std::vector<int>> AllBaseVec; //���ùؿ����ص�����

Vec2 Level1MapTransform(int i, int j); //��һ�ص�����ת������
Vec2 Level2MapTransform(int i, int j); //�ڶ��ص�����ת������
Vec2 Level3MapTransform(int i, int j); //�����ص�����ת������


#endif // __AllData_H__