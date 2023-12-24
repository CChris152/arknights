#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include "Sprite/EnemyBase.h"
#include "Sprite/OperatorBase.h"
#include "Sprite/Card.h"
#include <vector>

USING_NS_CC;

extern int Jade; //所持有的合成玉数量

extern int FinishLevelNum; //已完成的关卡数量
extern int CurrentLevel; //当前执行的关卡

extern int expenses; //费用
extern int BaseHP; //基地血量
extern int allenemynum; //敌人总数
extern int killednum; //消灭敌人数量

extern std::vector<int> CardsNum; //干员卡片编号
extern std::vector<int> LackCards; //缺少的干员卡片编号
extern std::vector<std::string> OperatorName; //干员名称

extern std::vector<Card*> Cards; //干员卡片精灵
extern std::vector<Enemy*> AllEnemy; //生成的敌人
extern std::vector<Operator*> AllOperator; //生成的干员
extern std::vector<Sprite*> Allenemy; //生成的敌人精灵
extern std::vector<Sprite*> Alloperator; //生成的干员精灵
extern std::vector<Sprite*> AttackEffect; //生成的攻击特效（子弹等）

extern std::vector<std::vector<int>> Level1vec; //第一关的地图数组
extern std::vector<std::vector<int>> Level1Road; //第一关的敌人行动路径
extern std::vector<std::vector<int>> Level1EnemyWave; //第一关出现的敌人波次

extern std::vector<std::vector<int>> Level2vec; //第二关的地图数组
extern std::vector<std::vector<int>> Level2Road; //第二关的敌人行动路径
extern std::vector<std::vector<int>> Level2Fly; //第二关的飞行敌人路径
extern std::vector<std::vector<int>> Level2EnemyWave; //第二关出现的敌人波次

extern std::vector<std::vector<int>> Level3vec; //第三关的地图数组
extern std::vector<std::vector<int>> Level3Road; //第三关的敌人行动路径
extern std::vector<std::vector<int>> Level3Fly; //第三关的飞行敌人路径
extern std::vector<std::vector<int>> Level3EnemyWave; //第三关出现的敌人波次

extern std::vector<std::vector<int>> AllBaseVec; //所用关卡基地的坐标

Vec2 Level1MapTransform(int i, int j); //第一关的坐标转换函数
Vec2 Level2MapTransform(int i, int j); //第二关的坐标转换函数
Vec2 Level3MapTransform(int i, int j); //第三关的坐标转换函数


#endif // __AllData_H__