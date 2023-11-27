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
	//数据初始化
	init_data();

	//页面数据获取
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//鼠标监听
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level1Map::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Level1Map::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level1Map::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//背景图
	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//返回按钮
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2, visibleSize.height - back->getContentSize().height / 2 + origin.y));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//费用数字
	expenseslabel = Label::createWithTTF(std::to_string(expenses), "fonts/Marker Felt.ttf", 150);
	expenseslabel->setPosition(Vec2(origin.x + visibleSize.width - 170, origin.y + 100));
	expenseslabel->setColor(Color3B::BLACK);
	this->addChild(expenseslabel, 1);

	//消灭敌人数量
	killednumlabel= Label::createWithTTF(std::to_string(killednum), "fonts/Marker Felt.ttf", 30);
	killednumlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 105, origin.y + visibleSize.height - 70));
	killednumlabel->setColor(Color3B::BLACK);
	this->addChild(killednumlabel, 1);

	//基地血量
	BaseHPlabel = Label::createWithTTF(std::to_string(BaseHP), "fonts/Marker Felt.ttf", 30);
	BaseHPlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height - 70));
	BaseHPlabel->setColor(Color3B::BLACK);
	this->addChild(BaseHPlabel, 1);

	//干员卡片
	for (int i = 0; i < Cards.size();i++) {
		auto card = Sprite::create("pictures/" + Cards[i] + "Card.png");
		card->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * card->getContentSize().width / 2, origin.y + card->getContentSize().height / 2));
		this->addChild(card, 0);
		CardsSpr.push_back(card);
	}

	//update开始运行
	this->scheduleUpdate();
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
	expensestimer = 0;
}

void Level1Map::update(float update_time)
{
	//费用刷新
	if (expensestimer >= 1) {
		if (expenses < 99) {
			expenses++;
		}
		expensestimer = 0;
	}
	else {
		expensestimer += update_time;
	}

	//更改数字
	expenseslabel->setString(std::to_string(expenses));
	killednumlabel->setString(std::to_string(killednum));
	BaseHPlabel->setString(std::to_string(BaseHP));
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
	//返回关卡选择页面
	Director::getInstance()->replaceScene(LevelSelect::create());
}