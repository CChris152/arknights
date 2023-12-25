#include "CollectionBook.h"
#include "GameplayMenu.h"
#include "Data/AllData.h"
#include "Sprite/ExusiaiOperator.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool CollectionBook::init()
{
	if (!Scene::init())
	{
		return false;
	}
	// �������п�ĳߴ�
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//����ͼ
	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setScale(1.5f, 1.5f);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	//���ذ�ť
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(CollectionBook::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 10, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//��ʼλ��
	float  start_x = back->getContentSize().width + 50;
	float  start_y = 10;
	// ��Ԫ��ķ�Ϊ2/3
	float cellWidth = (visibleSize.width - start_x) / 3; // 
	float cellHeight = visibleSize.height / 2; // 

	// ���÷ָ���Ϊǳ��ɫ
	Color4F lightBlue = Color4F(0.5f, 0.7f, 1.0f, 1.0f);

	// ������ͼ�ڵ�
	auto drawNode = DrawNode::create();

	// ����ˮƽ�ָ���
	for (int i = 0; i < 2; ++i) { // 
		float y = start_y + i * cellHeight;
		drawNode->drawLine(Vec2(start_x, y), Vec2(visibleSize.width, y), lightBlue);
		drawNode->drawLine(Vec2(start_x, y + 10), Vec2(visibleSize.width, y + 10), lightBlue);
	}

	// ���ƴ�ֱ�ָ���
	for (int i = 0; i < 3; ++i) { // 
		float x = start_x + i * cellWidth;
		drawNode->drawLine(Vec2(x, start_y), Vec2(x, visibleSize.height), lightBlue);
		drawNode->drawLine(Vec2(x + 10, start_y), Vec2(x + 10, visibleSize.height), lightBlue);
	}
	this->addChild(drawNode);

	//����ʹͼƬ
	auto ExusiaiGuide = Sprite::create("pictures/ExusiaiGuide.png");
	ExusiaiGuide->setPosition(ExusiaiGuide->getContentSize().width / 2 + start_x + 30, visibleSize.height - cellHeight / 2);
	this->addChild(ExusiaiGuide);
	//

	colOperatorInfo();

	ExusiaiInfo->setPosition((cellWidth + ExusiaiGuide->getContentSize().width) / 2 + start_x + 30, visibleSize.height - cellHeight / 2);
	ExusiaiInfo->setTextColor(Color4B::BLACK);
	this->addChild(ExusiaiInfo);

	ExusiaiInfo->removeAllComponents();
	

	return true;
}

void CollectionBook::menuBackCallback(cocos2d::Ref* pSender)
{
	//��ͣ����
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameplayMenu::create());
}

//��Ա��Ϣ
void CollectionBook::colOperatorInfo() {
	ExusiaiInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	HongxueInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	QiubaiInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	EyjafjallaInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	
	ExusiaiInfo->setString(R"(
    Name    : Exusiai
   Expense  : 12
    MaxHP   : 1200
 AttackType : physical
   Attack   : 300
AttackSpeed : 1
AttackRange : 700
MaxStopNum  : 1)");

	HongxueInfo->setString(R"(
    Name    : Hongxue
   Expense  : 18
    MaxHP   : 1200
 AttackType : physical
   Attack   : 700
AttackSpeed : 3
AttackRange : 500
MaxStopNum  : 1)");

	QiubaiInfo->setString(R"(
    Name    : Qiubai
   Expense  : 15
    MaxHP   : 1500
 AttackType : physical
   Attack   : 300
AttackSpeed : 3
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

}
//������Ϣ
void CollectionBook::colEnemyInfo() {
	AlphawormInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	SeagliderInfo = Label::createWithTTF("", "fonts/arial.ttf", 36);
	D4Info = Label::createWithTTF("", "fonts/arial.ttf", 36);

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


}