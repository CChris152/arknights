#include "EnemyBase.h"

void Enemy::setAttack(int Attack)
{
	this->attack = Attack;
}

void Enemy::setAttackSpeed(float AttackSpeed)
{
	this->attackspeed = AttackSpeed;
}

void Enemy::setmaxHP(int MaxHP)
{
	this->maxHP = MaxHP;
}

void Enemy::setcurrentHP(int CurrentHP)
{
	this->currentHP = CurrentHP;
}

void Enemy::decreaseHP(int DecreaseHP)
{
	this->currentHP -= DecreaseHP;
}

void Enemy::setspeed(float Speed)
{
	this->speed = Speed;
}

void Enemy::setPhysicalDefense(int PhysicalDefense)
{
	this->physicaldefense = PhysicalDefense;
}

void Enemy::setMagicalDefense(int MagicalDefense)
{
	this->magicaldefense = MagicalDefense;
}

int Enemy::getAttack()
{
	return this->attack;
}

float Enemy::getAttackSpeed()
{
	return this->attackspeed;
}

int Enemy::getmaxHP()
{
	return this->maxHP;
}

int Enemy::getcurrentHP()
{
	return this->currentHP;
}

float Enemy::getspeed()
{
	return this->speed;
}

int Enemy::getPhysicalDefense()
{
	return this->physicaldefense;
}

int Enemy::getMagicalDefense()
{
	return this->magicaldefense;
}