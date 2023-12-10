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
	//���ݳ�ʼ��
	init_data();

	//ҳ�����ݻ�ȡ
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//������
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Level1Map::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//����ͼ
	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//���ذ�ť
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 + origin.y - 25));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//��������
	expenseslabel = Label::createWithTTF(std::to_string(expenses), "fonts/Marker Felt.ttf", 150);
	expenseslabel->setPosition(Vec2(origin.x + visibleSize.width - 170, origin.y + 100));
	expenseslabel->setColor(Color3B::BLACK);
	this->addChild(expenseslabel, 1);

	//�����������
	killednumlabel = Label::createWithTTF(std::to_string(killednum) + "/" + std::to_string(allenemynum), "fonts/Marker Felt.ttf", 30);
	killednumlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 95, origin.y + visibleSize.height - 70));
	killednumlabel->setColor(Color3B::BLACK);
	this->addChild(killednumlabel, 1);

	//����Ѫ��
	BaseHPlabel = Label::createWithTTF(std::to_string(BaseHP), "fonts/Marker Felt.ttf", 30);
	BaseHPlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height - 70));
	BaseHPlabel->setColor(Color3B::BLACK);
	this->addChild(BaseHPlabel, 1);

	//�����Ա��Ƭ
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
	
	//����߼�
	gamelogic = new GameLogic(this);
	this->addChild(gamelogic);

	//��������
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/TowerFierce.mp3", true);

	//update��ʼ����
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
	//�ж��Ƿ����
	if (gamelogic->victoryorfail == -1) {
		BackCall();
	}
	if (gamelogic->victoryorfail == 1) {
		FinishLevelNum = std::max(FinishLevelNum, 1);
		BackCall();
	}

	//����ˢ��
	if (expensestimer >= 1) {
		if (expenses < 99) {
			expenses++;
		}
		expensestimer = 0;
	}
	else {
		expensestimer += update_time;
	}

	//��������
	expenseslabel->setString(std::to_string(expenses));
	killednumlabel->setString(std::to_string(killednum) + "/" + std::to_string(allenemynum));
	BaseHPlabel->setString(std::to_string(BaseHP));
}

bool Level1Map::onTouchBegan(Touch* touch, Event* unused_event)
{
	//��ȡ�������
	auto touchposition = touch->getLocation();

	if (IsSelectCard == 0) {

		//�ж��Ƿ��ڿ�Ƭ��Χ������ǣ����л�״̬
		for (int i = 0; i < Cards.size(); i++) {
			auto position = Cards[i]->CardSprite->getPosition();
			if (abs(touchposition.x - position.x) < 80 && abs(touchposition.y - position.y) < 135 && expenses >= Cards[i]->getCardExpense()) {
				//ʹѡ��Ƭ������̬Ч��
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

		//һ�������жϵı���
		bool out = 0;

		//����ѡ�еĲ�ͬ��Ƭ�����費ͬ���ж�
		switch (choosedoperatornum) {
		case 0:
			for (int i = 0; i < currentLevel1vec.size(); i++) {
				for (int j = 0; j < currentLevel1vec[0].size(); j++) {
					if (currentLevel1vec[i][j] == 1) {

						//����������ӳ�䵽ʵ������
						Vec2 currentposition = { j * 160.0f + 515 ,790.0f - i * 140 };

						//�ж��Ƿ��ڸ��ӷ�Χ�ڣ�����ǣ������ɲ�����
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Exuasiai(AllOperator.size());
							newoperator->Exuasiaisprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Exuasiaisprite);
							this->addChild(newoperator->Exuasiaisprite);

							currentLevel1vec[i][j] = 11;

							//���ٷ���
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

						//����������ӳ�䵽ʵ������
						Vec2 currentposition = { j * 160.0f + 515 ,790.0f - i * 140 };

						//�ж��Ƿ��ڸ��ӷ�Χ�ڣ�����ǣ������ɲ�����
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Hongxue(AllOperator.size());
							newoperator->Hongxuesprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Hongxuesprite);
							this->addChild(newoperator->Hongxuesprite);

							currentLevel1vec[i][j] = 11;

							//���ٷ���
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
	//�����ϵľ���ȫ����ͣ
	for (auto it : AllOperator) {
		it->unscheduleUpdate();
	}
	for (auto it : AllEnemy) {
		if (it->IsDead == 0) {
			it->IsDead = 1;
		}
	}

	//��ֹ�ڴ�й©
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

	//��ͣ����
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	//���عؿ�ѡ��ҳ��
	Director::getInstance()->replaceScene(LevelSelect::create());
}

void Level1Map::menuBackCallback(cocos2d::Ref* pSender)
{
	BackCall();
}