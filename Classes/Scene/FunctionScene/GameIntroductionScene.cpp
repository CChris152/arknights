#include "GameIntroductionScene.h"
#include "Scene/BranchScene/GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool GameIntroductionScene::init() 
{

	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1.5f, 1.5f);
	this->addChild(background, 0);

	auto Gameintroduction = Sprite::create("pictures/Gamedescription.png");
	Gameintroduction->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(Gameintroduction, 1);
	//·µ»Ø°´Å¥
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(GameIntroductionScene::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 10, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);
	return true;
}

void GameIntroductionScene::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(GameplayMenu::create());
}