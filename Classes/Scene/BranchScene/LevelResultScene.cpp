#include "LevelResultScene.h"
#include "LevelSelectScene.h"
#include "Data/AllData.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool LevelResult::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	this->setOpacity(0);

	//结果提示背景板
	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1.5f, 0.8f);
	this->addChild(background, 1);

	//结果提示
	auto resultlabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 160);
	resultlabel->setColor(Color3B::BLACK);
	resultlabel->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	switch (victoryorfail)
	{
	case 1:
		resultlabel->setString("V i c t o r y");
		break;
	case -1:
		resultlabel->setString("F a i l");
		break;
	default:
		break;
	}
	this->addChild(resultlabel, 2);

	//获得Jade提示
	auto getJadelabel = Label::createWithTTF("", "fonts/Marker Felt.ttf", 120);
	getJadelabel->setColor(Color3B::BLACK);
	getJadelabel->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 100);
	switch (victoryorfail)
	{
	case 1:
		getJadelabel->setString("get  " + std::to_string(CurrentLevel * 10) + "  Jade");
		break;
	case -1:
		getJadelabel->setString("get  0  Jade");
		break;
	default:
		break;
	}
	this->addChild(getJadelabel, 2);

	//两秒后自动结束
	this->scheduleOnce([](float dt) { CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	                                  Director::getInstance()->replaceScene(LevelSelect::create()); }, 2.0f, "LevelResult");

	return true;
}