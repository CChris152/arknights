#include "Card.h"

//��ƬCD
const float CD = 5.0f;

Card::Card(std::string Name, int CardExpense)
{
	Sprite::onEnter();

	IsCD = 1;

	name = Name;
	cardexpense = CardExpense;
	Cardtimer = 0;

	//����ͼƬ
	CardSprite = Sprite::create("pictures/" + Name + "Card.png");

	//�������Ʊ�ǩ
	Label* namelabel = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 30);
	namelabel->setPosition(Vec2(CardSprite->getContentSize().width / 2, CardSprite->getContentSize().height / 2 + 105));
	namelabel->setColor(Color3B::BLACK);
	CardSprite->addChild(namelabel);

	//������ñ�ǩ
	Label* cardexpenseslabel = Label::createWithTTF("Expense:  " + std::to_string(cardexpense), "fonts/Marker Felt.ttf", 20);
	cardexpenseslabel->setPosition(Vec2(CardSprite->getContentSize().width / 2, CardSprite->getContentSize().height / 2 + 75));
	cardexpenseslabel->setColor(Color3B::BLACK);
	CardSprite->addChild(cardexpenseslabel);

	//�����ɫCD������
	BlackCD = Sprite::create("pictures/BlackCD.png");
	BlackCD->setOpacity(80);
	BlackCDTimer = ProgressTimer::create(BlackCD);
	BlackCDTimer->setType(ProgressTimer::Type::BAR);
	BlackCDTimer->setMidpoint(Vec2(0, 1));
	BlackCDTimer->setBarChangeRate(Vec2(0, 1));
	BlackCDTimer->setPercentage(100.0f);
	BlackCDTimer->setPosition(CardSprite->getContentSize().width / 2, CardSprite->getContentSize().height / 2);
	CardSprite->addChild(BlackCDTimer);

	this->scheduleUpdate();
}

int Card::getCardExpense()
{
	return cardexpense;
}

void Card::update(float update_time)
{
	if (IsCD) {
		if (Cardtimer >= CD) {
			Cardtimer = 0;
			IsCD = 0;
		}
		else {
			Cardtimer += update_time;
			BlackCDTimer->setPercentage(100.0f - Cardtimer / CD * 100.0f);
		}
	}
}

