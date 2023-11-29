#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include "Sprite/EnemyBase.h"
#include <vector>

USING_NS_CC;

extern int FinishLevelNum; //已完成的关卡数量
extern int CurrentLevel; //当前执行的关卡

extern int Maptime; //地图计时器
extern int expenses; //费用
extern int BaseHP; //基地血量
extern int allenemynum; //敌人总数
extern int killednum; //消灭敌人数量

extern std::vector<std::string> Cards; //干员卡片名称
extern std::vector<Sprite*> CardsSpr; //干员卡片精灵
extern std::vector<int> CardsExpenses; //干员卡片部署费用

extern std::vector<Enemy*> AllEnemy; //生成的敌人

extern std::vector<std::vector<int>> Level1vec; //第一关的地图数组
extern std::vector<std::vector<int>> Level1Road; //第一关的敌人行动路径

#endif // __AllData_H__