#include "HugeuglyEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Hugeugly::Hugeugly()
{
	//这东西一定要加上！！！
	Enemy::onEnter();

	//设置路径
	switch (CurrentLevel)
	{
	case 1:
		this->setRoad(Level1Road);
		break;
	case 2:
		this->setRoad(Level2Road);
		break;
	case 3:
		this->setRoad(Level3Road);
		break;
	default:
		break;
	}

	this->EnemyInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Hugeugly::EnemyInit()
{
	this->setAttack(1000);
	this->setAttackSpeed(5.0f);
	this->setmaxHP(20000);
	this->setcurrentHP(20000);
	this->setspeed(0.2f);
	this->setPhysicalDefense(200);
	this->setMagicalDefense(40);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;
	this->percentage = 1;
	this->IsDead = 0;
	this->IsStopped = 0;
	this->stoppedoperatornum = -1;

	movetype = walk;

	this->Hugeuglytimer = 0;
}



void Hugeugly::SpriteInit()
{
	HugeuglySprite = Sprite::create("pictures/Hugeugly.png");
	HugeuglySprite->setScale(0.6f, 0.6f);
	HugeuglySprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 80));
	this->spritevec = Vec2(HugeuglySprite->getPosition().x, HugeuglySprite->getPosition().y - 80);
	HugeuglyBar = Sprite::create("pictures/bar.png");   //创建进度框
	HugeuglyBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50 + 80));
	Blood = Sprite::create("pictures/Blood.png");
	HugeuglyBlood = ProgressTimer::create(Blood); //创建AlphawormBlood对象
	HugeuglyBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	HugeuglyBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50 + 80));
	HugeuglyBlood->setPercentage(100 * percentage);
}


void Hugeugly::update(float update_time)
{
	//先判断血量
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	//更新方向
	auto currentSprposition = this->HugeuglySprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0]) <= 2 && fabs(currentSprposition.y - 80 - this->Road[RoadStep][1]) <= 2) {
		if (RoadStep < this->Road.size() - 1) {
			float distance = sqrt(pow(this->Road[RoadStep + 1][0] - this->Road[RoadStep][0], 2) + pow(this->Road[RoadStep + 1][1] - this->Road[RoadStep][1], 2));
			this->xvec = (this->Road[RoadStep + 1][0] - this->Road[RoadStep][0]) * 1.0f / distance;
			this->yvec = (this->Road[RoadStep + 1][1] - this->Road[RoadStep][1]) * 1.0f / distance;
		}
		RoadStep++;
	}

	//到达终点后消除
	if (RoadStep == this->Road.size()) {
		IsDead = 1;
		BaseHP--;
		killednum++;
	}

	this->percentage = (float)this->getcurrentHP() / (float)this->getmaxHP();

	//攻击判定
	if (Hugeuglytimer < this->getAttackSpeed()) {
		Hugeuglytimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Hugeuglytimer = 0;
		}
	}

	//更新位置 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		HugeuglySprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));
		this->spritevec = Vec2(currentSprposition.x, currentSprposition.y - 80);

		HugeuglyBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //设置框的位置
		HugeuglyBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//血条变化
	HugeuglyBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	HugeuglyBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	HugeuglyBlood->setBarChangeRate(Vec2(1, 0));
	HugeuglyBlood->setPercentage(100 * percentage);

	//图像翻转
	if (xvec < 0) {
		this->HugeuglySprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->HugeuglySprite->setFlippedX(false);
	}

	//死亡判定
	if (IsDead) {
		this->IsStopped = 0;
		//将精灵删除
		HugeuglySprite->removeFromParent();
		HugeuglyBar->removeFromParent();
		HugeuglyBlood->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Hugeugly::setRoad(std::vector<std::vector<int>> currentRoad)
{
	for (int i = 0; i < currentRoad.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < currentRoad[0].size(); j++) {
			one.push_back(currentRoad[i][j]);
		}
		this->Road.push_back(one);
	}
}