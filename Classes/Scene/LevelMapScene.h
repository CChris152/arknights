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

	bool onTouchBegan(Touch* touch, Event* unused_event); //����¼�����

	void setLevelvec(std::vector<std::vector<int>> Levelvec); //���������ͼ

	void BackCall(); //������һ������

	void menuBackCallback(cocos2d::Ref* pSender); //���ذ�ť
	void menuStopCallback(cocos2d::Ref* pSender); //��ͣ��ť

	std::vector<std::vector<int>> currentLevelvec; //�����ͼ

	GameLogic* gamelogic; //�󶨵���Ϸ�߼�

	CREATE_FUNC(LevelMap);

private:
	Label* expenseslabel; //���������пɸĶ������ݱ�ǩ
	Label* killednumlabel;
	Label* BaseHPlabel;
	Sprite* Shovel; //���Ӿ���
	MenuItemImage* Stop; //��ͣ��ť

	bool IsStop; //�Ƿ���ͣ
	bool IsSelectShovel; //�Ƿ����Ѿ�ѡ���˲��ӵ�״̬
	bool IsSelectCard; //�Ƿ����Ѿ�ѡ���˿�Ƭ��״̬
	float expensestimer; //���ü�ʱ��(1s = 1����)
	int choosedoperatornum; //ѡ�еĸ�Ա���
};


#endif // __Level1Map_Scene_H__