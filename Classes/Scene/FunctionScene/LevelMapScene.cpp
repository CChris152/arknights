#include "LevelMapScene.h"
#include "Data/AllData.h"
#include "Scene/BranchScene/LevelSelectScene.h"
#include "Scene/BranchScene/LevelResultScene.h"
#include "Sprite/Operator/ExusiaiOperator.h"
#include "Sprite/Operator/HongxueOperator.h"
#include "Sprite/Operator/QiubaiOperator.h"
#include "Sprite/Operator/EyjafjallaOperator.h"
#include "Sprite/Operator/SariaOperator.h"
#include "Sprite/Card/Card.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
#include <vector>
#include <cmath>
#include <algorithm>

const std::vector<int> Levelallenemynum = { 11,14,30 };

bool LevelMap::init()
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
	listener->onTouchBegan = CC_CALLBACK_2(LevelMap::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//����ͼ
	auto level1map = Sprite::create("pictures/Level" + std::to_string(CurrentLevel) + "map.png");
	level1map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(level1map, 0);

	//���ذ�ť
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(LevelMap::menuBackCallback, this)); 
	back->setPosition(Vec2(origin.x + back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 + origin.y - 25));
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1000);

	//��������
	expenseslabel = Label::createWithTTF(std::to_string(expenses), "fonts/Marker Felt.ttf", 150);
	expenseslabel->setPosition(Vec2(origin.x + visibleSize.width - 170, origin.y + 100));
	expenseslabel->setColor(Color3B::BLACK);
	this->addChild(expenseslabel, 1000);

	//�����������
	killednumlabel = Label::createWithTTF(std::to_string(killednum) + "/" + std::to_string(allenemynum), "fonts/Marker Felt.ttf", 30);
	killednumlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 - 95, origin.y + visibleSize.height - 70));
	killednumlabel->setColor(Color3B::BLACK);
	this->addChild(killednumlabel, 1000);

	//����Ѫ��
	BaseHPlabel = Label::createWithTTF(std::to_string(BaseHP), "fonts/Marker Felt.ttf", 30);
	BaseHPlabel->setPosition(Vec2(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height - 70));
	BaseHPlabel->setColor(Color3B::BLACK);
	this->addChild(BaseHPlabel, 1000);

	//���ӿ�Ƭ
	Shovel = Sprite::create("pictures/Shovel.png");
	Shovel->setPosition(Vec2(origin.x + Shovel->getContentSize().width / 2 + 70, Shovel->getContentSize().height / 2 + origin.y + 25));
	this->addChild(Shovel, 1000);

	//��ͣ��ť
	Stop = MenuItemImage::create("pictures/Stop.png", "pictures/Stop.png", CC_CALLBACK_1(LevelMap::menuStopCallback, this));
	Stop->setPosition(Vec2(origin.x + visibleSize.width - Stop->getContentSize().width / 2 - 70, visibleSize.height - Stop->getContentSize().height / 2 + origin.y - 25));
	auto stopmenu = Menu::create(Stop, NULL);
	stopmenu->setPosition(Vec2::ZERO);
	this->addChild(stopmenu, 1000);

	//�����Ա��Ƭ
	for (int i = 0; i < CardsNum.size();i++) {
		switch (CardsNum[i])
		{
		case 0: 
		{
			Card* newcard = new Card("Exusiai", 12);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite, 1000);
			Cards.push_back(newcard);
			break;
		}
		case 1: 
		{
			Card* newcard = new Card("Hongxue", 18);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite, 1000);
			Cards.push_back(newcard);
			break;
		}
		case 2:
		{
			Card* newcard = new Card("Qiubai", 18);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite, 1000);
			Cards.push_back(newcard);
			break;
		}
		case 3:
		{
			Card* newcard = new Card("Eyjafjalla", 23);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite, 1000);
			Cards.push_back(newcard);
			break;
		}
		case 4:
		{
			Card* newcard = new Card("Saria", 25);
			newcard->CardSprite->setPosition(Vec2(origin.x + visibleSize.width - 300 - (2 * i + 1) * newcard->CardSprite->getContentSize().width / 2, origin.y + newcard->CardSprite->getContentSize().height / 2));
			this->addChild(newcard->CardSprite, 1000);
			Cards.push_back(newcard);
			break;
		}
		default:
			break;
		}
	}

	//����߼�
	gamelogic = new GameLogic(this);
	this->addChild(gamelogic, 600);

	//��������
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/TowerFierce.mp3", true);

	//update��ʼ����
	this->scheduleUpdate();
	return true;
}

void LevelMap::init_data()
{
	expenses = 50;
	BaseHP = MaxBaseHP;
	allenemynum = Levelallenemynum[CurrentLevel - 1];
	killednum = 0;

	Cards.clear();
	AllEnemy.clear();
	AllOperator.clear();
	Allenemy.clear();
	Alloperator.clear();

	IsStop = 0;
	IsSelectShovel = 0;
	IsSelectCard = 0;
	expensestimer = 0;
	choosedoperatornum = -1;

	switch (CurrentLevel)
	{
	case 1:
		setLevelvec(Level1vec);
		break;
	case 2:
		setLevelvec(Level2vec);
		break;
	case 3:
		setLevelvec(Level3vec);
		break;
	default:
		break;
	}
}

void LevelMap::setLevelvec(std::vector<std::vector<int>> Levelvec)
{
	for (int i = 0; i < Levelvec.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < Levelvec[0].size(); j++) {
			one.push_back(Levelvec[i][j]);
		}
		currentLevelvec.push_back(one);
	}
}

void LevelMap::update(float update_time)
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
	killednumlabel->setString(std::to_string(killednum) + "/" + std::to_string(allenemynum));
	BaseHPlabel->setString(std::to_string(BaseHP));

	//�ж��Ƿ����
	if (victoryorfail == -1) {
		BackCall();
	}
	if (victoryorfail == 1) {
		FinishLevelNum = std::max(FinishLevelNum, CurrentLevel);
		UserDefault::getInstance()->setIntegerForKey("FinishLevelNum", FinishLevelNum);
		BackCall();
	}

}

bool LevelMap::onTouchBegan(Touch* touch, Event* unused_event)
{
	//��ȡ�������
	auto touchposition = touch->getLocation();

	//����ѡ��״̬�ж�
	if (IsSelectCard == 0) {
		if (IsSelectShovel == 0) {
			auto position = Shovel->getPosition();
			if (abs(touchposition.x - position.x) < Shovel->getContentSize().width / 2 && abs(touchposition.y - position.y) < Shovel->getContentSize().height / 2) {
				//ʹѡ��Ƭ������̬Ч��
				Shovel->setPosition(Vec2(position.x, position.y + 50));
				IsSelectShovel = 1;
				return false;
			}
		}
		else {
			for (int i = 0; i < AllOperator.size(); i++) {
				if (AllOperator[i]->IsDead == 0) {
					auto position = Alloperator[i]->getPosition();
					if (abs(touchposition.x - position.x) < Alloperator[i]->getContentSize().width / 2 && abs(touchposition.y - position.y) < Alloperator[i]->getContentSize().height / 2) {
						AllOperator[i]->IsDead = 1;
						expenses = std::min(99, AllOperator[i]->getExpense() / 2 + expenses);
						AllOperator[i]->unscheduleUpdate();
						Alloperator[i]->removeFromParent();
						currentLevelvec[AllOperator[i]->getVecPlace().x][AllOperator[i]->getVecPlace().y] -= 10;
						for (auto it : AllOperator[i]->stoppedenemynum) {
							AllEnemy[it]->IsStopped = 0;
						}
						break;
					}
				}
			}
			IsSelectShovel = 0;
			auto position = Shovel->getPosition();
			Shovel->setPosition(Vec2(position.x, position.y - 50));
			//ˢ�·���
			expenseslabel->setString(std::to_string(expenses));
			return false;
		}
	}

	//��Ƭѡ��״̬�ж�
	if (IsSelectCard == 0) {
		//�ж��Ƿ��ڿ�Ƭ��Χ������ǣ����л�״̬
		for (int i = 0; i < Cards.size(); i++) {
			auto position = Cards[i]->CardSprite->getPosition();
			if (abs(touchposition.x - position.x) < 80 && abs(touchposition.y - position.y) < 135 && expenses >= Cards[i]->getCardExpense() && Cards[i]->IsCD == 0) {
				//ʹѡ��Ƭ������̬Ч��
				Cards[i]->CardSprite->setPosition(Vec2(position.x, position.y + 50));
				choosedoperatornum = CardsNum[i];
				IsSelectCard = 1;
				break;
			}
		}
	}
	else {

		//һ�������жϵı���
		bool out = 0;

		int place;
		for (place = 0; place < CardsNum.size() && CardsNum[place] != choosedoperatornum; place++) {}
		//����ѡ�еĲ�ͬ��Ƭ�����費ͬ���ж�
		switch (choosedoperatornum) {
		case 0:
			for (int i = 0; i < currentLevelvec.size(); i++) {
				for (int j = 0; j < currentLevelvec[0].size(); j++) {
					if (currentLevelvec[i][j] == 1) {
						//����������ӳ�䵽ʵ������
						Vec2 currentposition;
						switch (CurrentLevel)
						{
						case 1:
							currentposition = Level1MapTransform(i, j);
							break;
						case 2:
							currentposition = Level2MapTransform(i, j);
							break;
						case 3:
							currentposition = Level3MapTransform(i, j);
							break;
						default:
							break;
						}
						//�ж��Ƿ��ڸ��ӷ�Χ�ڣ�����ǣ������ɲ�����
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Exusiai(AllOperator.size(), Vec2(i, j));
							newoperator->Exusiaisprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Exusiaisprite);
							this->addChild(newoperator->Exusiaisprite, 1000 - newoperator->Exusiaisprite->getPosition().y / 2);

							//���ٷ���
							expenses -= Cards[place]->getCardExpense();
							currentLevelvec[i][j] += 10;

							Cards[place]->IsCD = 1;
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
			for (int i = 0; i < currentLevelvec.size(); i++) {
				for (int j = 0; j < currentLevelvec[0].size(); j++) {
					if (currentLevelvec[i][j] == 1) {
						Vec2 currentposition;
						switch (CurrentLevel)
						{
						case 1:
							currentposition = Level1MapTransform(i, j);
							break;
						case 2:
							currentposition = Level2MapTransform(i, j);
							break;
						case 3:
							currentposition = Level3MapTransform(i, j);
							break;
						default:
							break;
						}
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Hongxue(AllOperator.size(), Vec2(i, j));
							newoperator->Hongxuesprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Hongxuesprite);
							this->addChild(newoperator->Hongxuesprite, 1000 - newoperator->Hongxuesprite->getPosition().y / 2);
							expenses -= Cards[place]->getCardExpense();
							currentLevelvec[i][j] += 10;
							Cards[place]->IsCD = 1;
							Cards[place]->BlackCDTimer->setPercentage(100.0f);
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
		case 2:
			for (int i = 0; i < currentLevelvec.size(); i++) {
				for (int j = 0; j < currentLevelvec[0].size(); j++) {
					if (currentLevelvec[i][j] == 0) {
						Vec2 currentposition;
						switch (CurrentLevel)
						{
						case 1:
							currentposition = Level1MapTransform(i, j);
							break;
						case 2:
							currentposition = Level2MapTransform(i, j);
							break;
						case 3:
							currentposition = Level3MapTransform(i, j);
							break;
						default:
							break;
						}
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Qiubai(AllOperator.size(), Vec2(i, j));
							newoperator->Qiubaisprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Qiubaisprite);
							this->addChild(newoperator->Qiubaisprite, 1000 - newoperator->Qiubaisprite->getPosition().y / 2);
							expenses -= Cards[place]->getCardExpense();
							currentLevelvec[i][j] += 10;
							Cards[place]->IsCD = 1;
							Cards[place]->BlackCDTimer->setPercentage(100.0f);
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
		case 3:
			for (int i = 0; i < currentLevelvec.size(); i++) {
				for (int j = 0; j < currentLevelvec[0].size(); j++) {
					if (currentLevelvec[i][j] == 1) {
						Vec2 currentposition;
						switch (CurrentLevel)
						{
						case 1:
							currentposition = Level1MapTransform(i, j);
							break;
						case 2:
							currentposition = Level2MapTransform(i, j);
							break;
						case 3:
							currentposition = Level3MapTransform(i, j);
							break;
						default:
							break;
						}
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Eyjafjalla(AllOperator.size(), Vec2(i, j));
							newoperator->Eyjafjallasprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Eyjafjallasprite);
							this->addChild(newoperator->Eyjafjallasprite, 1000 - newoperator->Eyjafjallasprite->getPosition().y / 2);
							expenses -= Cards[place]->getCardExpense();
							currentLevelvec[i][j] += 10;
							Cards[place]->IsCD = 1;
							Cards[place]->BlackCDTimer->setPercentage(100.0f);
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
		case 4:
			for (int i = 0; i < currentLevelvec.size(); i++) {
				for (int j = 0; j < currentLevelvec[0].size(); j++) {
					if (currentLevelvec[i][j] == 0) {
						Vec2 currentposition;
						switch (CurrentLevel)
						{
						case 1:
							currentposition = Level1MapTransform(i, j);
							break;
						case 2:
							currentposition = Level2MapTransform(i, j);
							break;
						case 3:
							currentposition = Level3MapTransform(i, j);
							break;
						default:
							break;
						}
						if (sqrt(pow(touchposition.x - currentposition.x, 2) + pow(touchposition.y - currentposition.y, 2)) < 70) {
							auto newoperator = new Saria(AllOperator.size(), Vec2(i, j));
							newoperator->Sariasprite->setPosition(Vec2(currentposition.x, currentposition.y + 70));
							AllOperator.push_back(newoperator);
							Alloperator.push_back(newoperator->Sariasprite);
							this->addChild(newoperator->Sariasprite, 1000 - newoperator->Sariasprite->getPosition().y / 2);
							expenses -= Cards[place]->getCardExpense();
							currentLevelvec[i][j] += 10;
							Cards[place]->IsCD = 1;
							Cards[place]->BlackCDTimer->setPercentage(100.0f);
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
		auto position = Cards[place]->CardSprite->getPosition();
		Cards[place]->CardSprite->setPosition(Vec2(position.x, position.y - 50));
		IsSelectCard = 0;
		choosedoperatornum = -1;
	}

	//ˢ�·���
	expenseslabel->setString(std::to_string(expenses));

	return false;
}

void LevelMap::BackCall()
{
	//���ʤ�����Ӻϳ���
	if (victoryorfail == 1) {
		Jade += CurrentLevel * 10;
		UserDefault::getInstance()->setIntegerForKey("Jade", Jade);
	}

	//�����ϵľ���ȫ����ͣ
	for (auto it : AllOperator) {
		it->unscheduleUpdate();
	}
	for (auto it : AllEnemy) {
		it->unscheduleUpdate();
	}
	for (auto it : AttackEffect) {
		it->unscheduleUpdate();
	}
	for (auto it : Cards) {
		it->unscheduleUpdate();
	}

	//��ͣ�߼�
	gamelogic->unscheduleUpdate();

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

	std::vector<Node*> logic;
	logic.push_back(gamelogic);
	logic.clear();
	for (auto it : logic) {
		delete it;
	}
	logic.clear();

	this->unscheduleUpdate();
	this->removeAllChildren();

	//�ص���ͣ
	Director::getInstance()->resume();

	//�����ʾ
	if (victoryorfail != 0) {
		Director::getInstance()->replaceScene(LevelResult::create());
	}
	else {
		//��ͣ����
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

		//���عؿ�ѡ��ҳ��
		Director::getInstance()->replaceScene(LevelSelect::create());
	}
}

void LevelMap::menuBackCallback(cocos2d::Ref* pSender)
{
	BackCall();
}

void LevelMap::menuStopCallback(cocos2d::Ref* pSender)
{
	if (IsStop) {
		Stop->setNormalImage(Sprite::create("pictures/Stop.png"));
		Stop->setSelectedImage(Sprite::create("pictures/Stop.png"));
		IsStop = 0;
		Director::getInstance()->resume();
	}
	else {
		Stop->setNormalImage(Sprite::create("pictures/Continue.png"));
		Stop->setSelectedImage(Sprite::create("pictures/Continue.png"));
		IsStop = 1;
		Director::getInstance()->pause();
	}
}