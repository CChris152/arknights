#include "Level1MapScene.h"
#include "Data/AllData.h"
#include "LevelSelectScene.h"
#include <vector>

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

	// Û±Íº‡Ã˝
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level1Map::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Level1Map::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level1Map::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//±≥æ∞Õº
	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//∑µªÿ∞¥≈•
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2, visibleSize.height - back->getContentSize().height / 2 + origin.y));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//∏…‘±ø®∆¨
	for (int i = 0; i < Cards.size();i++) {
		auto card = Sprite::create("pictures/" + Cards[i] + "Card.png");
		card->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * card->getContentSize().width / 2, origin.y + card->getContentSize().height / 2));
		this->addChild(card, 0);
		CardsSpr.push_back(card);
	}

	return true;
}

void Level1Map::init_data()
{
	Maptime = 0;
	expenses = 0;
	BaseHP = 10;
	allenemynum = 10;
	killednum = 0;

	CardsSpr.clear();

	IsSelectCard = 0;
}

void Level1Map::update(float update_time)
{
	;
}

bool Level1Map::onTouchBegan(Touch* touch, Event* unused_event)
{
	if (IsSelectCard == 0) {

	}
	else {

	}

	return false;
}

void Level1Map::onTouchMoved(Touch* touch, Event* unused_event)
{
	;
}

void Level1Map::onTouchEnded(Touch* touch, Event* unused_event)
{
	;
}

void Level1Map::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelSelect::create());
}