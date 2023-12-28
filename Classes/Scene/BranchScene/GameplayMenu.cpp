#include "GameplayMenu.h"
#include "LevelSelectScene.h"
#include "Scene/FunctionScene/OperatorRecruitScene.h"
#include "SelectBookScene.h"
#include "Scene/FunctionScene/StoreScene.h"
#include "Data/AllData.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

USING_NS_CC;

const std::vector<std::string> buttonLabels = { "Level Selection",
										        "Operator Recruitment",
										        "Game Book",
	                                            "Closure's Store",
										        "Game Introduction",
	                                            "Game Over"};

// 设置字体大小
const int fontSize = 72;

// 设置按钮间的垂直间距
const int verticalSpacing = 150;

//文字按钮
void GameplayMenu::TextButtonCreat() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 逐个创建按钮
	for (int i = 0; i < buttonLabels.size(); ++i) {

		auto label = Label::createWithTTF(buttonLabels[i], "fonts/Marker Felt.ttf", fontSize);
		label->setColor(Color3B(255, 200, 100));//字体颜色
		auto menuItem = MenuItemLabel::create(label, [=](Ref* sender) {
			switch (i) {
			case 0: 
				menuToLevelSelecScene(sender);
				break;
			case 1:
				menuToOperatorRecruitment(sender);
				break;
			case 2:
				menuToCollectionBook(sender);
				break;
			case 3:
				menuToStore(sender);
				break;
			case 4:
				menuToGameplayIntroduction(sender);
				break;
			case 5:
				menuCloseCallback(sender);
				break;
			default:
				break;
			}
		});
		auto menu = Menu::create(menuItem, nullptr);
		menu->setPosition(Vec2(origin.x + 600, visibleSize.height - (i + 1) * verticalSpacing));
		this->addChild(menu);
	}
}

bool GameplayMenu::init() {

	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景图
	auto Gameplay_menu = Sprite::create("pictures/GameplayMenu.png");
	Gameplay_menu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(Gameplay_menu, 0);

	//合成玉计数器
	auto JadeCount = Sprite::create("pictures/JadeCount.png");
	JadeCount->setPosition(visibleSize.width - 130, visibleSize.height - 60);
	this->addChild(JadeCount);
	auto JadeNum = Label::createWithTTF(std::to_string(Jade), "fonts/Marker Felt.ttf", 50);
	JadeNum->setPosition(visibleSize.width - 95, visibleSize.height - 65);
	JadeNum->setColor(Color3B::BLACK);
	this->addChild(JadeNum);

	//背景音乐
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == 0) {
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);
	}

	TextButtonCreat();
	return true;
}

void GameplayMenu::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}

void GameplayMenu::menuToLevelSelecScene(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(LevelSelect::create());
}

void GameplayMenu::menuToOperatorRecruitment(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(OperatorRecruit::create());
}

void GameplayMenu::menuToCollectionBook(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(SelectBookScene::create());
}

void GameplayMenu::menuToStore(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(Store::create());
}

void GameplayMenu::menuToGameplayIntroduction(cocos2d::Ref* pSender)
{
	//跳转至玩法介绍
}

