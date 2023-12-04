#include "Card.h"

Card::Card(std::string Name, int CardExpense)
{
	name = Name;
	cardexpense = CardExpense;

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
}

int Card::getCardExpense()
{
	return cardexpense;
}

