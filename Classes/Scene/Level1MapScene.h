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

	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(Level1Map);
};


#endif // __Level1Map_Scene_H__