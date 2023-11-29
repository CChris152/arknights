#include "Level1MapScene.h"
#include "Data/AllData.h"
#include "LevelSelectScene.h"
#include "Sprite/ExusiaiOperator.h"
#include <vector>
#include <cmath>

Scene* Level1Map::createScene()
{
	return Level1Map::create();
}

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
	listener->onTouchMoved = CC_CALLBACK_2(Level1Map::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Level1Map::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//����ͼ
	auto level1map = Sprite::create("pictures/Level1map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//����ê��
	auto BlackDot = Sprite::create("BlackDot.png");
	BlackDot->setPosition(Vec2(origin.x+995, origin.y+370));
	this->addChild(BlackDot, 0);

	//���ذ�ť
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Level1Map::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2, visibleSize.height - back->getContentSize().height / 2 + origin.y));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//��������
	expenseslabel = Label::createWithTTF(std::to_string(expenses), "fonts/Marker Felt.ttf", 150);
	expenseslabel->setPosition(Vec2(origin.x + visibleSize.width - 170, origin.y + 100));
	expenseslabel->setColor(Color3B::BLACK);
	this->addChild(expenseslabel, 1);

	//�����������
	killednumlabel= Label::createWithTTF(std::to_string(killednum), "fonts/Marker Felt.ttf", 30);
	killednumlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 105, origin.y + visibleSize.height - 70));
	killednumlabel->setColor(Color3B::BLACK);
	this->addChild(killednumlabel, 1);

	//����Ѫ��
	BaseHPlabel = Label::createWithTTF(std::to_string(BaseHP), "fonts/Marker Felt.ttf", 30);
	BaseHPlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height - 70));
	BaseHPlabel->setColor(Color3B::BLACK);
	this->addChild(BaseHPlabel, 1);

	//��Ա��Ƭ
	for (int i = 0; i < Cards.size();i++) {
		auto card = Sprite::create("pictures/" + Cards[i] + "Card.png");
		card->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * card->getContentSize().width / 2, origin.y + card->getContentSize().height / 2));
		this->addChild(card, 0);
		CardsSpr.push_back(card);
	}
	
	//����߼�
	gamelogic = new GameLogic(this);
	this->addChild(gamelogic);

	//update��ʼ����
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
	AllEnemy.clear();

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
	killednumlabel->setString(std::to_string(killednum));
	BaseHPlabel->setString(std::to_string(BaseHP));
}

bool Level1Map::onTouchBegan(Touch* touch, Event* unused_event)
{
	//��ȡ�������
	auto touchposition = touch->getLocation();

	if (IsSelectCard == 0) {

		//�ж��Ƿ��ڿ�Ƭ��Χ������ǣ����л�״̬
		for (int i = 0; i < CardsSpr.size(); i++) {
			auto position = CardsSpr[i]->getPosition();
			if (abs(touchposition.x - position.x) < 80 && abs(touchposition.y - position.y) < 135 && expenses >= CardsExpenses[i]) {
				//ʹѡ��Ƭ������̬Ч��
				CardsSpr[i]->setPosition(Vec2(position.x, position.y + 50));
				choosedoperatornum = i;
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
							auto newoperator = new Exuasiai;
							newoperator->Exuasiaisprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							this->addChild(newoperator->Exuasiaisprite);
							currentLevel1vec[i][j] = 11;
							//���ٷ���
							expenses -= CardsExpenses[choosedoperatornum];
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
		auto position = CardsSpr[choosedoperatornum]->getPosition();
		CardsSpr[choosedoperatornum]->setPosition(Vec2(position.x, position.y - 50));
		IsSelectCard = 0;
		choosedoperatornum = -1;
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
	//���عؿ�ѡ��ҳ��
	Director::getInstance()->replaceScene(LevelSelect::create());
}