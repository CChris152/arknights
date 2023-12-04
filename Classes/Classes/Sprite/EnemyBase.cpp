#include "EnemyBase.h"

void Enemy::EnemyInit()
{
	//等待重写
}

void Enemy::SpriteInit()
{
	//等待重写
}

void Enemy::LabelInit()
{
	//等待重写
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

