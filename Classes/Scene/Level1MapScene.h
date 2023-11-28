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

	bool onTouchBegan(Touch* touch, Event* unused_event); //����¼�����
	void onTouchMoved(Touch* touch, Event* unused_event);
	void onTouchEnded(Touch* touch, Event* unused_event);

	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(Level1Map);

private:
	Label* expenseslabel; //���������пɸĶ������ݱ�ǩ
	Label* killednumlabel;
	Label* BaseHPlabel;

	bool IsSelectCard; //�Ƿ����Ѿ�ѡ���˿�Ƭ��״̬
	float expensestimer; //���ü�ʱ��(1s = 1����)
	int choosedoperatornum; //ѡ�еĸ�Ա���

	std::vector<std::vector<int>> currentLevel1vec;
};


#endif // __Level1Map_Scene_H__