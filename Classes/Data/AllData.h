#pragma once

#ifndef __AllData_H__
#define __AllData_H__

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

extern int FinishLevelNum; //已完成的关卡数量

extern int Maptime; //地图计时器
extern int expenses; //费用
extern int BaseHP; //基地血量
extern int allenemynum; //敌人总数
extern int killednum; //消灭敌人数量

extern std::vector<std::string> Cards; //干员卡片名称
extern std::vector<Sprite*> CardsSpr; //干员卡片精灵

#endif // __AllData_H__