#include "EnemyBook.h"
#include "Scene/BranchScene/SelectBookScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool EnemyBook::init()
{
	if (!Scene::init())
	{
		return false;
	}
	// 计算运行框的尺寸
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//背景图
	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setScale(1.5f, 1.5f);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	//返回按钮
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(EnemyBook::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 10, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//开始位置
	float  start_x = back->getContentSize().width + 50;
	float  start_y = 10;
	// 单元格的分为2/3
	float cellWidth = (visibleSize.width - start_x) / 3; // 
	float cellHeight = visibleSize.height / 2; // 

	// 设置分割线为浅蓝色
	Color4F lightBlue = Color4F(0.5f, 0.7f, 1.0f, 1.0f);

	// 创建绘图节点
	auto drawNode = DrawNode::create();

	// 绘制水平分割线
	for (int i = 0; i < 2; ++i) { // 
		float y = start_y + i * cellHeight;
		drawNode->drawLine(Vec2(start_x, y), Vec2(visibleSize.width, y), lightBlue);
		drawNode->drawLine(Vec2(start_x, y + 10), Vec2(visibleSize.width, y + 10), lightBlue);
	}

	// 绘制垂直分割线
	for (int i = 0; i < 3; ++i) { // 
		float x = start_x + i * cellWidth;
		drawNode->drawLine(Vec2(x, start_y), Vec2(x, visibleSize.height), lightBlue);
		drawNode->drawLine(Vec2(x + 10, start_y), Vec2(x + 10, visibleSize.height), lightBlue);
	}
	this->addChild(drawNode);

	//设置干员和敌人的信息
	colEnemyInfo();
	//设置图片大小
	float customWidth = 200; 
	float customHeight = 200; 

	//Alphaworm[1,1]
	auto AlphawormGuide = Sprite::create("pictures/Alphaworm.png");
	AlphawormGuide->setScale(customWidth / AlphawormGuide->getContentSize().width, customHeight / AlphawormGuide->getContentSize().height);
	AlphawormGuide->setPosition(AlphawormGuide->getContentSize().width / 2 + start_x + 30, visibleSize.height - cellHeight / 2);
	this->addChild(AlphawormGuide);
	AlphawormInfo->setPosition((cellWidth + AlphawormGuide->getContentSize().width) / 2 + start_x + 15, visibleSize.height - cellHeight / 2);
	AlphawormInfo->setTextColor(Color4B::BLACK);
	this->addChild(AlphawormInfo);

	//Seaglider[1,2]
	auto SeagliderGuide = Sprite::create("pictures/Seaglider.png");
	SeagliderGuide->setScale(customWidth / SeagliderGuide->getContentSize().width, customHeight / SeagliderGuide->getContentSize().height);
	SeagliderGuide->setPosition(SeagliderGuide->getContentSize().width / 2 + start_x + 30 + cellWidth, visibleSize.height - cellHeight / 2);
	this->addChild(SeagliderGuide);
	SeagliderInfo->setPosition((cellWidth + SeagliderGuide->getContentSize().width) / 2 + start_x + 15 + cellWidth, visibleSize.height - cellHeight / 2);
	SeagliderInfo->setTextColor(Color4B::BLACK);
	this->addChild(SeagliderInfo);

	//D4[1,3]
	auto D4Guide = Sprite::create("pictures/D4.png");
	D4Guide->setScale(customWidth / D4Guide->getContentSize().width, customHeight / D4Guide->getContentSize().height);
	D4Guide->setPosition(D4Guide->getContentSize().width / 2 + start_x + 30 + 2 * cellWidth, visibleSize.height - cellHeight / 2);
	this->addChild(D4Guide);
	D4Info->setPosition((cellWidth + D4Guide->getContentSize().width) / 2 + start_x + 15 + 2 * cellWidth, visibleSize.height - cellHeight / 2);
	D4Info->setTextColor(Color4B::BLACK);
	this->addChild(D4Info);

	//Du[2,1]
	auto DuGuide = Sprite::create("pictures/Du.png");
	DuGuide->setScale(customWidth / DuGuide->getContentSize().width, customHeight / DuGuide->getContentSize().height);
	DuGuide->setPosition(DuGuide->getContentSize().width / 2 + start_x + 30 - 50, visibleSize.height - cellHeight / 2 - cellHeight);
	this->addChild(DuGuide);
	DuInfo->setPosition((cellWidth + DuGuide->getContentSize().width) / 2 + start_x + 15 - 50, visibleSize.height - cellHeight / 2 - cellHeight);
	DuInfo->setTextColor(Color4B::BLACK);
	this->addChild(DuInfo);
	
	//Hugeugly[2,2]
	auto HugeuglyGuide = Sprite::create("pictures/Hugeugly.png");
	HugeuglyGuide->setScale(customWidth / HugeuglyGuide->getContentSize().width, customHeight / DuGuide->getContentSize().height);
	HugeuglyGuide->setPosition(HugeuglyGuide->getContentSize().width / 2 + start_x + 30  + cellWidth - 120, visibleSize.height - cellHeight / 2 - cellHeight);
	this->addChild(HugeuglyGuide);
	HugeuglyInfo->setPosition((cellWidth + DuGuide->getContentSize().width) / 2 + start_x + 15 + cellWidth - 60, visibleSize.height - cellHeight / 2 - cellHeight);
	HugeuglyInfo->setTextColor(Color4B::BLACK);
	this->addChild(HugeuglyInfo);
	return true;
}

void EnemyBook::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(SelectBookScene::create());
}

//敌人信息
void EnemyBook::colEnemyInfo() {
	AlphawormInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	SeagliderInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	D4Info = Label::createWithTTF("", "fonts/arial.ttf", 36);
	DuInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	HugeuglyInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);

	AlphawormInfo->setString(R"(
      Name      : Alphaworm
      MaxHP     : 1000
      Speed     : 1.0
     Attack     : 100
  AttackSpeed   : 3.0
PhysicalDefense : 50
 MagicalDefense : 10)");

	SeagliderInfo->setString(R"(
      Name      : Seaglider
      MaxHP     : 2500
      Speed     : 2.0
     Attack     : 400
  AttackSpeed   : 2.0
PhysicalDefense : 200
 MagicalDefense : 25)");

	D4Info->setString(R"(
      Name      : D4
      MaxHP     : 1800
      Speed     : 1.0
     Attack     : 0
  AttackSpeed   : 10.0
PhysicalDefense : 300
 MagicalDefense : 5)");

	DuInfo->setString(R"(
      Name      : Du
      MaxHP     : 3500
      Speed     : 1.0
     Attack     : 500
  AttackSpeed   : 4.0
PhysicalDefense : 100
 MagicalDefense : 75)");

	HugeuglyInfo->setString(R"(
      Name      : Hugeugly
      MaxHP     : 20000
      Speed     : 0.2
     Attack     : 1000
  AttackSpeed   : 5.0
PhysicalDefense : 200
 MagicalDefense : 40)");


}