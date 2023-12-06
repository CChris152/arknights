#pragma once

#ifndef __Level1Map_Scene_H__
#define __Level1Map_Scene_H__

#include "cocos2d.h"
#include "Logic/GameLogic.h"

USING_NS_CC;

class LevelMap : public cocos2d::Scene
{
public:
	virtual bool init();
	void init_data();

	virtual void update(float update_time);

	bool onTouchBegan(Touch* touch, Event* unused_event); //鼠标事件函数

	void setLevelvec(std::vector<std::vector<int>> Levelvec); //设置数组地图

	void BackCall(); //返回上一个场景

	void menuBackCallback(cocos2d::Ref* pSender); //返回按钮
	void menuStopCallback(cocos2d::Ref* pSender); //暂停按钮

	std::vector<std::vector<int>> currentLevelvec; //数组地图

	GameLogic* gamelogic; //绑定的游戏逻辑

	CREATE_FUNC(LevelMap);

private:
	Label* expenseslabel; //三个场景中可改动的数据标签
	Label* killednumlabel;
	Label* BaseHPlabel;
	Sprite* Shovel; //铲子精灵
	MenuItemImage* Stop; //暂停按钮

	bool IsStop; //是否暂停
	bool IsSelectShovel; //是否处于已经选择了铲子的状态
	bool IsSelectCard; //是否处于已经选择了卡片的状态
	float expensestimer; //费用计时器(1s = 1费用)
	int choosedoperatornum; //选中的干员编号
};


#endif // __Level1Map_Scene_H__