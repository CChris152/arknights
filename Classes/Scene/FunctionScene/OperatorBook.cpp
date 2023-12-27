#include "OperatorBook.h"
#include "Scene/BranchScene/SelectBookScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool OperatorBook::init()
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
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(OperatorBook::menuBackCallback, this));
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
	colOperatorInfo();

	//能天使[1,1]
	auto ExusiaiGuide = Sprite::create("pictures/ExusiaiGuide.png");
	ExusiaiGuide->setPosition(ExusiaiGuide->getContentSize().width / 2 + start_x + 15, visibleSize.height - cellHeight / 2);
	this->addChild(ExusiaiGuide);
	ExusiaiInfo->setPosition((cellWidth + ExusiaiGuide->getContentSize().width) / 2 + start_x + 15, visibleSize.height - cellHeight / 2);
	ExusiaiInfo->setTextColor(Color4B::BLACK);
	this->addChild(ExusiaiInfo);

	//鸿雪[1,2]
	auto HongxueGuide = Sprite::create("pictures/HongxueGuide.png");
	HongxueGuide->setPosition(HongxueGuide->getContentSize().width / 2 + start_x + 15 + cellWidth, visibleSize.height - cellHeight / 2);
	this->addChild(HongxueGuide);
	HongxueInfo->setPosition((cellWidth + HongxueGuide->getContentSize().width) / 2 + start_x + 15 + 1 * cellWidth, visibleSize.height - cellHeight / 2);
	HongxueInfo->setTextColor(Color4B::BLACK);
	this->addChild(HongxueInfo);

	//仇白[1,3]
	auto QiubaiGuide = Sprite::create("pictures/QiubaiGuide.png");
	QiubaiGuide->setPosition(QiubaiGuide->getContentSize().width / 2 + start_x + 15 + 2 * cellWidth, visibleSize.height - cellHeight / 2);
	this->addChild(QiubaiGuide);
	QiubaiInfo->setPosition((cellWidth + QiubaiGuide->getContentSize().width) / 2 + start_x + 15 + 2 * cellWidth, visibleSize.height - cellHeight / 2);
	QiubaiInfo->setTextColor(Color4B::BLACK);
	this->addChild(QiubaiInfo);

	//艾雅法拉[2,1]
	auto EyjafjallaGuide = Sprite::create("pictures/EyjafjallaGuide.png");
	EyjafjallaGuide->setPosition(EyjafjallaGuide->getContentSize().width / 2 + start_x + 15, visibleSize.height - cellHeight / 2 - cellHeight);
	this->addChild(EyjafjallaGuide);
	EyjafjallaInfo->setPosition((cellWidth + EyjafjallaGuide->getContentSize().width) / 2 + start_x + 15, visibleSize.height - cellHeight / 2 - cellHeight);
	EyjafjallaInfo->setTextColor(Color4B::BLACK);
	this->addChild(EyjafjallaInfo);

	//塞雷娅[2,2]
	auto SariaGuide = Sprite::create("pictures/SariaGuide.png");
	SariaGuide->setPosition(SariaGuide->getContentSize().width / 2 + start_x + 15+ cellWidth, visibleSize.height - cellHeight / 2 - cellHeight);
	this->addChild(SariaGuide);
	SariaInfo->setPosition((cellWidth + SariaGuide->getContentSize().width) / 2 + start_x + 15 + 1 * cellWidth, visibleSize.height - cellHeight / 2 - cellHeight);
	SariaInfo->setTextColor(Color4B::BLACK);
	this->addChild(SariaInfo);

	return true;
}

void OperatorBook::menuBackCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(SelectBookScene::create());
}

//干员信息
void OperatorBook::colOperatorInfo() {
	ExusiaiInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	HongxueInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	QiubaiInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	EyjafjallaInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	SariaInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);

	ExusiaiInfo->setString(R"(
    Name    : Exusiai
   Expense  : 12
    MaxHP   : 1200
 AttackType : physical
   Attack   : 300
AttackSpeed : 0.8
AttackRange : 700
MaxStopNum  : 1)");

	HongxueInfo->setString(R"(
    Name    : Hongxue
   Expense  : 18
    MaxHP   : 1200
 AttackType : physical
   Attack   : 1500
AttackSpeed : 3
AttackRange : 500
MaxStopNum  : 1)");

	QiubaiInfo->setString(R"(
    Name    : Qiubai
   Expense  : 18
    MaxHP   : 1500
 AttackType : physical
   Attack   : 600
AttackSpeed : 2
AttackRange : 200
MaxStopNum  : 2)");

	EyjafjallaInfo->setString(R"(
    Name    : Eyjafjalla
   Expense  : 23
    MaxHP   : 1200
 AttackType : magical
   Attack   : 700
AttackSpeed : 4
AttackRange : 500
MaxStopNum  : 1)");

	SariaInfo->setString(R"(
    Name    : Saria
   Expense  : 25
    MaxHP   : 3000
 AttackType : physical
   Attack   : 350
AttackSpeed : 5
AttackRange : 0
MaxStopNum  : 3)");

}