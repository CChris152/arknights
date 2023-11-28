#pragma once

#ifndef __Level1Map_Scene_H__
#define __Level1Map_Scene_H__

#include "cocos2d.h"

USING_NS_CC;

class Level1Map : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void init_data();

	virtual void update(float update_time);

	bool onTouchBegan(Touch* touch, Event* unused_event); //鼠标事件函数
	void onTouchMoved(Touch* touch, Event* unused_event);
	void onTouchEnded(Touch* touch, Event* unused_event);

	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(Level1Map);

private:
	Label* expenseslabel; //三个场景中可改动的数据标签
	Label* killednumlabel;
	Label* BaseHPlabel;

	bool IsSelectCard; //是否处于已经选择了卡片的状态
	float expensestimer; //费用计时器(1s = 1费用)
	int choosedoperatornum; //选中的干员编号

	std::vector<std::vector<int>> currentLevel1vec;
};


#endif // __Level1Map_Scene_H__