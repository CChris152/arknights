#include "Level1MapScene.h"
#include "Data/AllData.h"
#include "LevelSelectScene.h"
#include "Sprite/ExusiaiOperator.h"
#include "Sprite/HongxueOperator.h"
#include "Sprite/Card.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
#include <vector>
#include <cmath>
#include <algorithm>

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
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//背景图
	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//返回按钮
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 + origin.y - 25));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//费用数字
	expenseslabel = Label::createWithTTF(std::to_string(expenses), "fonts/Marker Felt.ttf", 150);
	expenseslabel->setPosition(Vec2(origin.x + visibleSize.width - 170, origin.y + 100));
	expenseslabel->setColor(Color3B::BLACK);
	this->addChild(expenseslabel, 1);

	//消灭敌人数量
	killednumlabel = Label::createWithTTF(std::to_string(killednum) + "/" + std::to_string(allenemynum), "fonts/Marker Felt.ttf", 30);
	killednumlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 95, origin.y + visibleSize.height - 70));
	killednumlabel->setColor(Color3B::BLACK);
	this->addChild(killednumlabel, 1);

	//基地血量
	BaseHPlabel = Label::createWithTTF(std::to_string(BaseHP), "fonts/Marker Felt.ttf", 30);
	BaseHPlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height - 70));
	BaseHPlabel->setColor(Color3B::BLACK);
	this->addChild(BaseHPlabel, 1);

	//加入干员卡片
	for (int i = 0; i < CardsNum.size();i++) {
		switch (CardsNum[i])
		{
		case 0: 
		{
			Card* newcard = new Card("Exusiai", 12);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite);
			Cards.push_back(newcard);
			break;
		}
		case 1: 
		{
			Card* newcard = new Card("Hongxue", 18);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite);
			Cards.push_back(newcard);
			break;
		}
		
		default:
			break;
		}
	}
	
	//添加逻辑
	gamelogic = new GameLogic(this);
	this->addChild(gamelogic);

	//背景音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/TowerFierce.mp3", true);

	//update开始运行
	this->scheduleUpdate();
	return true;
}

void Level1Map::init_data()
{
	Maptime = 0;
	expenses = 0;
	BaseHP = 3;
	allenemynum = 10;
	killednum = 0;

	Cards.clear();
	AllEnemy.clear();
	AllOperator.clear();
	Allenemy.clear();
	Alloperator.clear();

	IsSelectCard = 0;
	expensestimer = 0;
	choosedoperatornum = -1;

	CurrentLevel = 1;

	currentLevel1vec = { { 1, 1, 1, 1, 1, 1, 1},
						 { 0, 1, 0, 0, 0, 0, 0},
						 { 0, 0, 0, 1, 0, 0, 0},
						 { 1, 1, 1, 1, 1, 1, 1} };
}

void Level1Map::update(float update_time)
{
	//判断是否结束
	if (gamelogic->victoryorfail == -1) {
		BackCall();
	}
	if (gamelogic->victoryorfail == 1) {
		FinishLevelNum = std::max(FinishLevelNum, 1);
		BackCall();
	}

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
	killednumlabel->setString(std::to_string(killednum) + "/" + std::to_string(allenemynum));
	BaseHPlabel->setString(std::to_string(BaseHP));
}

bool Level1Map::onTouchBegan(Touch* touch, Event* unused_event)
{
	//获取鼠标坐标
	auto touchposition = touch->getLocation();

	if (IsSelectCard == 0) {

		//判断是否在卡片范围，如果是，就切换状态
		for (int i = 0; i < Cards.size(); i++) {
			auto position = Cards[i]->CardSprite->getPosition();
			if (abs(touchposition.x - position.x) < 80 && abs(touchposition.y - position.y) < 135 && expenses >= Cards[i]->getCardExpense()) {
				//使选择卡片产生动态效果
				Cards[i]->CardSprite->setPosition(Vec2(position.x, position.y + 50));
				choosedoperatornum = CardsNum[i];
				break;
			}
		}

		if (choosedoperatornum != -1) {
			IsSelectCard = 1;
		}
	}
	else {

		//一个辅助判断的变量
		bool out = 0;

		//对于选中的不同卡片，给予不同的判定
		switch (choosedoperatornum) {
		case 0:
			for (int i = 0; i < currentLevel1vec.size(); i++) {
				for (int j = 0; j < currentLevel1vec[0].size(); j++) {
					if (currentLevel1vec[i][j] == 1) {

						//将数组坐标映射到实际坐标
						Vec2 currentposition = { j * 160.0f + 515 ,790.0f - i * 140 };

						//判断是否在格子范围内，如果是，则生成并放置
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Exuasiai(AllOperator.size());
							newoperator->Exuasiaisprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Exuasiaisprite);
							this->addChild(newoperator->Exuasiaisprite);

							currentLevel1vec[i][j] = 11;

							//减少费用
							expenses -= Cards[choosedoperatornum]->getCardExpense();
							out = 1;
							break;
						}
					}
				}
				if (out) {
					break;
				}
			}
			break;
		case 1:
			for (int i = 0; i < currentLevel1vec.size(); i++) {
				for (int j = 0; j < currentLevel1vec[0].size(); j++) {
					if (currentLevel1vec[i][j] == 1) {

						//将数组坐标映射到实际坐标
						Vec2 currentposition = { j * 160.0f + 515 ,790.0f - i * 140 };

						//判断是否在格子范围内，如果是，则生成并放置
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Hongxue(AllOperator.size());
							newoperator->Hongxuesprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Hongxuesprite);
							this->addChild(newoperator->Hongxuesprite);

							currentLevel1vec[i][j] = 11;

							//减少费用
							expenses -= Cards[choosedoperatornum]->getCardExpense();
							out = 1;
							break;
						}
					}
				}
				if (out) {
					break;
				}
			}
			break;
		default:
			break;
		}
		auto position = Cards[choosedoperatornum]->CardSprite->getPosition();
		Cards[choosedoperatornum]->CardSprite->setPosition(Vec2(position.x, position.y - 50));
		IsSelectCard = 0;
		choosedoperatornum = -1;
	}

	return false;
}

void Level1Map::BackCall()
{
	//将场上的精灵全部关停
	for (auto it : AllOperator) {
		it->unscheduleUpdate();
	}
	for (auto it : AllEnemy) {
		if (it->IsDead == 0) {
			it->IsDead = 1;
		}
	}

	//防止内存泄漏
	AllOperator.clear();
	for (auto it : AllOperator) {
		delete it;
	}
	AllOperator.clear();
	AllEnemy.clear();
	for (auto it : AllEnemy) {
		delete it;
	}
	AllEnemy.clear();
	AttackEffect.clear();
	for (auto it : AttackEffect) {
		delete it;
	}
	AttackEffect.clear();
	Cards.clear();
	for (auto it : Cards) {
		delete it;
	}
	Cards.clear();

	//关停音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	//返回关卡选择页面
	Director::getInstance()->replaceScene(LevelSelect::create());
}

void Level1Map::menuBackCallback(cocos2d::Ref* pSender)
{
	BackCall();
}