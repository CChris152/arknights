#include "OperatorBase.h"

void Operator::OperatorInit()
{
	//�ȴ���д
}

void Operator::SpriteInit()
{
	//�ȴ���д
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