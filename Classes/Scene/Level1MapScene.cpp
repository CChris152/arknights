#include "Level1MapScene.h"
#include "Data/AllData.h"
#include "LevelSelectScene.h"

Scene* Level1Map::createScene()
{
	return Level1Map::create();
}

bool Level1Map::init()
{
	init_data();
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this));
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2, visibleSize.height - back->getContentSize().height / 2 + origin.y));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	return true;
}

void Level1Map::init_data()
{
	Maptime = 0;
	expenses = 0;
	BaseHP = 10;
	allenemynum = 10;
	killednum = 0;
}

void Level1Map::update(float update_time)
{
	;
}

void Level1Map::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelSelect::create());
}