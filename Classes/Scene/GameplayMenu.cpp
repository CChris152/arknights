#include "GameplayMenu.h"
#include "Scene/LevelSelectScene.h"

USING_NS_CC;

std::vector<std::string> buttonLabels = { "Level Selection",
										  "Operation Recruitment",
										  "Collection Book",
										  "Gameplay Introduction" };

//文字按钮
void GameplayMenu::TextButtonCreat() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 设置字体大小
	int fontSize = 72;
	// 设置按钮间的垂直间距
	int verticalSpacing = 200;

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
				menuToCOllectionBook(sender);
				break;
			case 3:
				menuToGameplayIntroduction(sender);
				break;
			default:
				break;
			}
		});
		auto menu = Menu::create(menuItem, nullptr);
		menu->setPosition(Vec2(origin.x + 400, visibleSize.height - (i + 1) * verticalSpacing));
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
	////程序退出图标
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameplayMenu::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));
	auto closemenu = Menu::create(closeItem, NULL);
	closemenu->setPosition(Vec2::ZERO);
	this->addChild(closemenu, 0);

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
    //跳转至干员寻访
}
void GameplayMenu::menuToCOllectionBook(cocos2d::Ref* pSender)
{
	//跳转至干员图鉴
}
void GameplayMenu::menuToGameplayIntroduction(cocos2d::Ref* pSender)
{
	//跳转至玩法介绍
}

