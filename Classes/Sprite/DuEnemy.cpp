#include "DuEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Du::Du()
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

void Du::EnemyInit()
{
	this->setAttack(500);
	this->setAttackSpeed(4.0f);
	this->setmaxHP(3500);
	this->setcurrentHP(3500);
	this->setspeed(1.0f);
	this->setPhysicalDefense(100);
	this->setMagicalDefense(75);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;
	this->Dupercentage = 1;
	this->IsDead = 0;
	this->IsStopped = 0;
	this->stoppedoperatornum = -1;

	movetype = walk;

	this->Alphawormtimer = 0;
}



void Du::SpriteInit()
{
	DuSprite = Sprite::create("pictures/Du.png");
	DuSprite->setScale(0.5f, 0.5f);
	DuSprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 30));
	this->spritevec = Vec2(DuSprite->getPosition().x, DuSprite->getPosition().y - 30);
	DuBar = Sprite::create("pictures/bar.png");   //创建进度框
	DuBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");
	DuBlood = ProgressTimer::create(Blood); //创建AlphawormBlood对象
	DuBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	DuBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	DuBlood->setPercentage(100 * Dupercentage);
}


void Du::update(float update_time)
{
	//先判断血量
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	auto currentSprposition = this->DuSprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0]) <= 2 && fabs(currentSprposition.y - 30 - this->Road[RoadStep][1]) <= 2) {
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

	this->Dupercentage = (float)this->getcurrentHP() / (float)this->getmaxHP();

	//攻击判定
	if (Alphawormtimer < this->getAttackSpeed()) {
		Alphawormtimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Alphawormtimer = 0;
		}
	}

	//更新位置 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		DuSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));
		this->spritevec = Vec2(currentSprposition.x, currentSprposition.y - 30);

		DuBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //设置框的位置
		DuBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//血条变化
	DuBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	DuBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	DuBlood->setBarChangeRate(Vec2(1, 0));
	DuBlood->setPercentage(100 * Dupercentage);

	//图像翻转
	if (xvec < 0) {
		this->DuSprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->DuSprite->setFlippedX(false);
	}

	//死亡判定
	if (IsDead) {
		this->IsStopped = 0;
		//将精灵删除
		DuSprite->removeFromParent();
		DuBar->removeFromParent();
		DuBlood->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Du::setRoad(std::vector<std::vector<int>> currentRoad)
{
	for (int i = 0; i < currentRoad.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < currentRoad[0].size(); j++) {
			one.push_back(currentRoad[i][j]);
		}
		this->Road.push_back(one);
	}
}