#include "OperatorBase.h"
#include "Data/AllData.h"

void Operator::OperatorInit()
{
	//�ȴ���д
}

void Operator::SpriteInit()
{
	//�ȴ���д
}

void Operator::setBlood(int Blood)
{
	this->blood = Blood;
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

void Operator::setVecPlace(Vec2 VecPlace)
{
	this->vecplace = VecPlace;
}

void Operator::setAttackType(AttackType attacktype_)
{
	this->attacktype = attacktype_;
}

void Operator::decreaseBlood(int DecreaseBlood)
{
	this->blood -= DecreaseBlood;
}

int Operator::getBlood()
{
	return blood;
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

Vec2 Operator::getVecPlace()
{
	return vecplace;
}

AttackType Operator::getAttackType()
{
	return attacktype;
}