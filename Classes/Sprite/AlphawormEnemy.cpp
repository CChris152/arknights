#include "AlphawormEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Alphaworm::Alphaworm() 
{
	//这东西一定要加上！！！
	Enemy::onEnter();

	//设置路径
	switch (CurrentLevel)
	{
	case 1:
		this->setRoad(Level1Road);
		break;
	default:
		break;
	}

	this->EnemyInit();
	this->SpriteInit();
	this->LabelInit();

	this->scheduleUpdate();
}

void Alphaworm::EnemyInit()
{
	this->setmaxHP(1000);
	this->setcurrentHP(1000);
	this->setspeed(1.0f);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;

	this->IsDead = 0;
}

void Alphaworm::SpriteInit()
{
	AlphawormSprite = Sprite::create("pictures/Alphaworm.png");
	AlphawormSprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1]));
}

void Alphaworm::LabelInit()
{
	AlphawormLabel = Label::createWithTTF(std::to_string(this->getcurrentHP()) + "/" + std::to_string(this->getmaxHP()), "fonts/Marker Felt.ttf", 20);
	AlphawormLabel->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
}

void Alphaworm::update(float update_time)
{
	//先判断血量
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	auto currentSprposition = this->AlphawormSprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0])<=2 && fabs(currentSprposition.y - this->Road[RoadStep][1])<=2) {
		this->xvec = this->Road[RoadStep][2];
		this->yvec = this->Road[RoadStep][3];
		RoadStep++;
	}

	//到达终点后消除
	if (RoadStep == this->Road.size()) {
		IsDead = 1;
		BaseHP--;
		killednum++;
	}

	//更新位置
	float currentspeed = this->getspeed();
	currentSprposition.x += this->xvec * currentspeed;
	currentSprposition.y += this->yvec * currentspeed;
	AlphawormSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));
	AlphawormLabel->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	AlphawormLabel->setString(std::to_string(this->getcurrentHP()) + "/" + std::to_string(this->getmaxHP()));

	if (IsDead) {
		//将图片变透明
		AlphawormSprite->removeFromParent();
		AlphawormLabel->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Alphaworm::setRoad(std::vector<std::vector<int>> currentRoad)
{
	for (int i = 0; i < currentRoad.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < currentRoad[0].size(); j++) {
			one.push_back(currentRoad[i][j]);
		}
		this->Road.push_back(one);
	}
}