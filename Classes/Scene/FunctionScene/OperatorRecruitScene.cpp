#include "OperatorRecruitScene.h"
#include "Scene/BranchScene/GameplayMenu.h"
#include "Data/AllData.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

const int onetryjade = 30; //���γ�ȡ�۸�
const float probability = 30.0f; //�����Ա�ĸ���

bool OperatorRecruit::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//����ͼ
	auto background = Sprite::create("pictures/Whitebackground.png");
	background->setScale(1.5f, 1.5f);
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(background);

	//���ذ�ť
	auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(OperatorRecruit::menuBackCallback, this));
	back->setPosition(back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 - 25);
	auto backmenu = Menu::create(back, NULL);
	backmenu->setPosition(Vec2::ZERO);
	this->addChild(backmenu, 1);

	//��¶ϣ��������
	auto Closure = Sprite::create("pictures/Closure.png");
	Closure->setPosition(visibleSize.width - Closure->getContentSize().width / 2, Closure->getContentSize().height / 2);
	this->addChild(Closure);

	//��¶ϣ����������
	auto Bubble = Sprite::create("pictures/Bubble.png");
	Bubble->setScale(1.5f, 0.5f);
	Bubble->setPosition(Closure->getPosition().x - Closure->getContentSize().width / 2-200, Closure->getContentSize().height-50);
	this->addChild(Bubble);

	//��¶ϣ���ʺ���
	Closuregreeting = Label::createWithTTF("Hello, I'm Closure", "fonts/arial.ttf", 50);
	Closuregreeting->setPosition(Closure->getPosition().x - Closure->getContentSize().width / 2-200, Closure->getContentSize().height-40);
	Closuregreeting->setColor(Color3B::BLACK);
	this->addChild(Closuregreeting);

	//�鿨��ť
	auto recruit = MenuItemImage::create("pictures/RecruitButton1.png", "pictures/RecruitButton2.png", CC_CALLBACK_1(OperatorRecruit::menuRecruitCallback, this));
	recruit->setScale(0.8f, 0.8f);
	recruit->setPosition(700,350);
	auto recruitmenu = Menu::create(recruit, NULL);
	recruitmenu->setPosition(Vec2::ZERO);
	this->addChild(recruitmenu);

	//�ϳ��������
	auto JadeCount = Sprite::create("pictures/JadeCount.png");
	JadeCount->setPosition(visibleSize.width - 130, visibleSize.height - 60);
	this->addChild(JadeCount);
	JadeNum = Label::createWithTTF(std::to_string(Jade), "fonts/Marker Felt.ttf", 50);
	JadeNum->setPosition(visibleSize.width - 95, visibleSize.height - 65);
	JadeNum->setColor(Color3B::BLACK);
	this->addChild(JadeNum);

	//�鿨�����������ʾ
	prompt = Label::createWithTTF("", "fonts/Marker Felt.ttf", 100);
	prompt->setPosition(700, 550);
	this->addChild(prompt);

	//�鿨������ʾ
	auto decreasejade = Label::createWithTTF(std::to_string(onetryjade) + " Jade / 1 Try", "fonts/Marker Felt.ttf", 75);
	decreasejade->setPosition(700, 200);
	decreasejade->setColor(Color3B::BLACK);
	this->addChild(decreasejade);

	//���ı�������
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/SpeedofLight.mp3", true);

	return true;
}

void OperatorRecruit::menuBackCallback(cocos2d::Ref* pSender)
{
	//��ͣ����
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameplayMenu::create());
}

void OperatorRecruit::menuRecruitCallback(cocos2d::Ref* pSender)
{
	if (Jade >= onetryjade) {
		Jade -= onetryjade;
		UserDefault::getInstance()->setIntegerForKey("Jade", Jade);
		JadeNum->setString(std::to_string(Jade));
		Recruit();
	}
	else {
		prompt->setColor(Color3B::RED);
		prompt->setString("Insufficient Jade!");
		Closuregreeting->setString("Play the game to get Jade.");
	}
}

void OperatorRecruit::Recruit()
{
	bool IsOperator = rand() % 10000 / 100.0f <= probability;
	if (IsOperator && LackCards.size() >= 1) {
		int randomOperator = rand() % LackCards.size();
		CardsNum.push_back(LackCards[randomOperator]);
		prompt->setColor(Color3B::ORANGE);
		prompt->setString("You get the Operator " + OperatorName[LackCards[randomOperator]]);
		Closuregreeting->setString("Congralutions!\nYou get a new Operator!");
		std::vector<int>::iterator it = LackCards.begin();
		while (1) {
			if (*it == LackCards[randomOperator]) {
				LackCards.erase(it);
				break;
			}
			it++;
		}
		//�浵�и�Աˢ��
		std::string cardsnum = "s";
		std::string lackcards = "s";
		for (int i = 0; i < CardsNum.size(); i++) {
			cardsnum += static_cast<char>(CardsNum[i] + 48);
		}
		for (int i = 0; i < LackCards.size(); i++) {
			lackcards += static_cast<char>(LackCards[i] + 48);
		}
		UserDefault::getInstance()->setStringForKey("cardsnum", cardsnum);
		UserDefault::getInstance()->setStringForKey("lackcards", lackcards);
	}
	else {
		int randomJade = rand() % 31 + 10;
		Jade += randomJade;
		UserDefault::getInstance()->setIntegerForKey("Jade", Jade);
		JadeNum->setString(std::to_string(Jade));
		prompt->setColor(Color3B::BLACK);
		prompt->setString("You get " + std::to_string(randomJade) + " Jade");
		Closuregreeting->setString("What a pity!");
	}
}