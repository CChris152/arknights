#pragma once

#ifndef __Level1Map_Scene_H__
#define __Level1Map_Scene_H__

#include "cocos2d.h"
#include "Logic/GameLogic.h"

USING_NS_CC;

class Level1Map : public cocos2d::Scene
{
public:
	virtual bool init();
	void init_data();

	virtual void update(float update_time);

	bool onTouchBegan(Touch* touch, Event* unused_event); //����¼�����

	void BackCall(); //������һ������

	void menuBackCallback(cocos2d::Ref* pSender);

	GameLogic* gamelogic; //�󶨵���Ϸ�߼�

	CREATE_FUNC(Level1Map);

private:
	Label* expenseslabel; //���������пɸĶ������ݱ�ǩ
	Label* killednumlabel;
	Label* BaseHPlabel;

	bool IsSelectCard; //�Ƿ����Ѿ�ѡ���˿�Ƭ��״̬
	float expensestimer; //���ü�ʱ��(1s = 1����)
	int choosedoperatornum; //ѡ�еĸ�Ա���

	std::vector<std::vector<int>> currentLevel1vec; //�����ͼ
};


#endif // __Level1Map_Scene_H__