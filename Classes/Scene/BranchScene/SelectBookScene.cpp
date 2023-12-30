#include "SelectBookScene.h"
#include "GameplayMenu.h"
#include "Scene/FunctionScene/OperatorBook.h"
#include "Scene/FunctionScene/EnemyBook.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

USING_NS_CC;

const std::vector<std::string> BookButtonLabels = { "Operator Book", "Enemy Book" };

//ÎÄ×Ö°´Å¥
void SelectBookScene::TextButtonCreat()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	int fontSize = 96;
	int horizontalSpacing = visibleSize.width / 3;

	int yPos = visibleSize.height - 200; 

	for (int i = 0; i < BookButtonLabels.size(); ++i) {
		auto label = Label::createWithTTF(BookButtonLabels[i], "fonts/Marker Felt.ttf", fontSize);
		label->setColor(Color3B(255, 200, 100));
		auto menuItem = MenuItemLabel::create(label, [=](Ref* sender) {
			switch (i) {
			case 0:
				ToOperatorBook(sender);
				break;
			case 1:
				ToEnemyBook(sender);
				break;
			default:
				break;
			}
			});
		auto menu = Menu::create(menuItem, nullptr);
		menu->setPosition(Vec2(origin.x + (i + 1) * horizontalSpacing, yPos)); 
		this->addChild(menu);
	}
}

bool SelectBookScene::init() {

	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//±³¾°Í¼
	auto Gameplay_menu = Sprite::create("pictures/SelectBookScene.png");
	Gameplay_menu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(Gameplay_menu, 0);
	//·µ»Ø°´Å¥
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(SelectBookScene::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 10, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//±³¾°ÒôÀÖ
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == 0) {
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);
	}

	TextButtonCreat();
	return true;
}

void SelectBookScene::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(GameplayMenu::create());
}

void SelectBookScene::ToOperatorBook(cocos2d::Ref* pSender) 
{
	Director::getInstance()->replaceScene(OperatorBook::create());
}

void SelectBookScene::ToEnemyBook(cocos2d::Ref* pSender) 
{
	Director::getInstance()->replaceScene(EnemyBook::create());
}
