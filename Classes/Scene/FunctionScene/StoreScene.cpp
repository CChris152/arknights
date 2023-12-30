#include "StoreScene.h"
#include "Scene/BranchScene/GameplayMenu.h"
#include "Data/AllData.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

const std::vector<int> goodsexpenses = { 100,150,60,100 }; //商品的价格
const std::vector<std::string> goodscontents = { "MaxBaseHP + 3","MaxBaseHP + 3","InitialExpenses + 10","InitialExpenses + 10" }; //所有商品的内容名称
const std::vector<Vec2> allgoodsplace = { {325.0f,600.0f},{725.0f,600.0f},{1125.0f,600.0f},{325.0f,300.0f} }; //所有商品的位置

bool Store::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//背景图
	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setScale(1.5f, 1.5f);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	//返回按钮
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(Store::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//可露希尔看板娘
	auto Closure = Sprite::create("pictures/Closure.png");
	Closure->setPosition(visibleSize.width - Closure->getContentSize().width / 2, Closure->getContentSize().height / 2);
	this->addChild(Closure);

	//可露希尔语言气泡
	auto Bubble = Sprite::create("pictures/Bubble.png");
	Bubble->setScale(1.5f, 0.5f);
	Bubble->setPosition(Closure->getPosition().x - Closure->getContentSize().width / 2 - 200, Closure->getContentSize().height - 50);
	this->addChild(Bubble);

	//可露希尔问候语
	Closuregreeting = Label::createWithTTF("Hello, I'm Closure", "fonts/arial.ttf", 50);
	Closuregreeting->setPosition(Closure->getPosition().x - Closure->getContentSize().width / 2 - 200, Closure->getContentSize().height - 40);
	Closuregreeting->setColor(Color3B::BLACK);
	this->addChild(Closuregreeting);

	//合成玉计数器
	auto JadeCount = Sprite::create("pictures/JadeCount.png");
	JadeCount->setPosition(visibleSize.width - 130, visibleSize.height - 60);
	this->addChild(JadeCount);
	JadeNum = Label::createWithTTF(std::to_string(Jade), "fonts/Marker Felt.ttf", 50);
	JadeNum->setPosition(visibleSize.width - 95, visibleSize.height - 65);
	JadeNum->setColor(Color3B::BLACK);
	this->addChild(JadeNum);

	//作弊按钮
	auto cheat = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(Store::menuCheat, this));
	cheat->setScale(0.4f, 0.4f);
	cheat->setPosition(back->getContentSize().width / 2 + 420, visibleSize.height - 130);
	auto cheatmenu = Menu::create(cheat, NULL);
	cheatmenu->setPosition(Vec2::ZERO);
	this->addChild(cheatmenu);
	auto cheatlabel = Label::createWithTTF("Cheat", "fonts/Marker Felt.ttf", 50);
	cheatlabel->setPosition(cheat->getPosition().x, cheat->getPosition().y + 50);
	cheatlabel->setColor(Color3B::BLACK);
	this->addChild(cheatlabel);

	//商品图标和按钮建立
	for (int i = 0; i < GoodsSellout.size(); i++) {
		MenuItemImage* goods;
		switch (i)
		{
		case 0:
			goods = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(Store::menugoods_1, this));
			break;
		case 1:
			goods = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(Store::menugoods_2, this));
			break;
		case 2:
			goods = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(Store::menugoods_3, this));
			break;
		case 3:
			goods = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(Store::menugoods_4, this));
			break;
		default:
			break;
		}
		goods->setScale(0.5f, 0.5f);
		goods->setPosition(allgoodsplace[i]);
		switch (i)
		{
		case 0:
			goods_1menu = Menu::create(goods, NULL);
			goods_1menu->setPosition(Vec2::ZERO);
			this->addChild(goods_1menu);
			break;
		case 1:
			goods_2menu = Menu::create(goods, NULL);
			goods_2menu->setPosition(Vec2::ZERO);
			this->addChild(goods_2menu);
			break;
		case 2:
			goods_3menu = Menu::create(goods, NULL);
			goods_3menu->setPosition(Vec2::ZERO);
			this->addChild(goods_3menu);
			break;
		case 3:
			goods_4menu = Menu::create(goods, NULL);
			goods_4menu->setPosition(Vec2::ZERO);
			this->addChild(goods_4menu);
			break;
		default:
			break;
		}
		auto goodspricelabel = Label::createWithTTF(std::to_string(goodsexpenses[i]) + "Jade", "fonts/Marker Felt.ttf", 50);
		goodspricelabel->setPosition(goods->getPosition().x, goods->getPosition().y - 90);
		goodspricelabel->setColor(Color3B::BLACK);
		this->addChild(goodspricelabel);
		auto goodscontentlabel = Label::createWithTTF(goodscontents[i], "fonts/Marker Felt.ttf", 40);
		goodscontentlabel->setPosition(goods->getPosition().x, goods->getPosition().y + 90);
		goodscontentlabel->setColor(Color3B::BLACK);
		this->addChild(goodscontentlabel);
		if (GoodsSellout[i] == '1') {
			makesellout(i + 1);
		}
	}

	//更改背景音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/SpeedofLight.mp3", true);

	return true;
}

void Store::menuBackCallback(cocos2d::Ref* pSender)
{
	//关停音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameplayMenu::create());
}

void Store::menuCheat(cocos2d::Ref* pSender)
{
	UserDefault::getInstance()->setIntegerForKey("Jade", 1000);
	UserDefault::getInstance()->setIntegerForKey("FinishLevelNum", 3);
	UserDefault::getInstance()->setIntegerForKey("MaxBaseHP", 9);
	UserDefault::getInstance()->setIntegerForKey("InitialExpenses", 30);
	UserDefault::getInstance()->setStringForKey("cardsnum", "s01234");
	UserDefault::getInstance()->setStringForKey("lackcards", "s");
	UserDefault::getInstance()->setStringForKey("GoodsSellout", "1111");
	Jade = 1000;
	JadeNum->setString(std::to_string(Jade));
	FinishLevelNum = 3;
	MaxBaseHP = 9;
	InitialExpenses = 30;
	CardsNum.clear();
	for (int i = 0; i <= 4; i++)
	{
		CardsNum.push_back(i);
	}
	LackCards.clear();
	for (int i = 0; i < GoodsSellout.size(); i++) {
		if (GoodsSellout[i] == '0') {
			GoodsSellout[i] = '1';
			makesellout(i + 1);
		}
	}
	Closuregreeting->setString("Hope you're not a gamer.");
}

void Store::menugoods_1(cocos2d::Ref* pSender)
{
	if (Jade >= goodsexpenses[0]) {
		Jade -= goodsexpenses[0];
		GoodsSellout[0] = '1';
		makesellout(1);
		MaxBaseHP += 3;
		JadeNum->setString(std::to_string(Jade));
		Closuregreeting->setString("Thanks for buying!");
	}
	else {
		Closuregreeting->setString("Insufficient Jade!");
	}
}

void Store::menugoods_2(cocos2d::Ref* pSender)
{
	if (Jade >= goodsexpenses[1]) {
		Jade -= goodsexpenses[1];
		GoodsSellout[1] = '1';
		makesellout(2);
		MaxBaseHP += 3;
		JadeNum->setString(std::to_string(Jade));
		Closuregreeting->setString("Thanks for buying!");
	}
	else {
		Closuregreeting->setString("Insufficient Jade!");
	}
}

void Store::menugoods_3(cocos2d::Ref* pSender)
{
	if (Jade >= goodsexpenses[2]) {
		Jade -= goodsexpenses[2];
		GoodsSellout[2] = '1';
		makesellout(3);
		InitialExpenses += 10;
		JadeNum->setString(std::to_string(Jade));
		Closuregreeting->setString("Thanks for buying!");
	}
	else {
		Closuregreeting->setString("Insufficient Jade!");
	}
}

void Store::menugoods_4(cocos2d::Ref* pSender)
{
	if (Jade >= goodsexpenses[3]) {
		Jade -= goodsexpenses[3];
		GoodsSellout[3] = '1';
		makesellout(4);
		InitialExpenses += 10;
		JadeNum->setString(std::to_string(Jade));
		Closuregreeting->setString("Thanks for buying!");
	}
	else {
		Closuregreeting->setString("Insufficient Jade!");
	}
}

void Store::makesellout(int goodsnum)
{
	//产生遮挡与文字
	auto occlusion = Sprite::create("pictures/Whitebackground.png");
	occlusion->setScale(0.25f, 0.22f);
	occlusion->setOpacity(200);
	occlusion->setPosition(allgoodsplace[goodsnum - 1]);
	this->addChild(occlusion, 5);
	auto selloutlabel = Label::createWithTTF("SELLOUT", "fonts/arial.ttf", 50);
	selloutlabel->setColor(Color3B::BLACK);
	selloutlabel->setPosition(allgoodsplace[goodsnum - 1]);
	this->addChild(selloutlabel, 10);

	//使按钮失效
	switch (goodsnum)
	{
	case 1:
		goods_1menu->setEnabled(false);
		break;
	case 2:
		goods_2menu->setEnabled(false);
		break;
	case 3:
		goods_3menu->setEnabled(false);
		break;
	case 4:
		goods_4menu->setEnabled(false);
		break;
	default:
		break;
	}
}