#include "OperatorBase.h"

void Operator::OperatorInit()
{
	//等待重写
}

void Operator::SpriteInit()
{
	//等待重写
}

void Operator::setAttack(int Attack)
{
	this->attack = Attack;
}

void Operator::setAttackSpeed(float AttackSpeed)
{
	this->attackspeed = AttackSpeed;
}

void Operator::setExpense(int Expense)
{
	this->expense = Expense;
}

int Operator::getExpense()
{
	return expense;
}