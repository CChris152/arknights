#include "EnemyBase.h"

void Enemy::EnemyInit()
{
	//�ȴ���д
}

void Enemy::SpriteInit()
{
	//�ȴ���д
}

void Enemy::LabelInit()
{
	//�ȴ���д
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

