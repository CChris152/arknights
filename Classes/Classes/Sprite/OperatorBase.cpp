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

void Operator::setAttackRange(int AttackRange)
{
	this->attackrange = AttackRange;
}

void Operator::setNumbering(int Numbering)
{
	this->numbering = Numbering;
}

int Operator::getAttack()
{
	return attack;
}

float Operator::getAttackSpeed()
{
	return attackspeed;
}

int Operator::getExpense()
{
	return expense;
}

int Operator::getAttackRange()
{
	return attackrange;
}

int Operator::getNumbering()
{
	return numbering;
}