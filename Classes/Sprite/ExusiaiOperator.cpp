#include "ExusiaiOperator.h"

Exuasiai::Exuasiai()
{
	this->OperatorInit();
	this->SpriteInit();
}

void Exuasiai::OperatorInit()
{
	this->setAttack(200);
	this->setAttackSpeed(2);
	this->setExpense(12);
}

void Exuasiai::SpriteInit()
{
	Exuasiaisprite = Sprite::create("pictures/Exusiai.png");
}