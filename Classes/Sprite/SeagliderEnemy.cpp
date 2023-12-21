#include "SeagliderEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Seaglider::Seaglider()
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

void Seaglider::EnemyInit()
{
	this->setAttack(400);
	this->setAttackSpeed(2.0f);
	this->setmaxHP(2500);
	this->setcurrentHP(2500);
	this->setspeed(2.0f);
	this->setPhysicalDefense(200);
	this->setMagicalDefense(25);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;
	this->percentage = 1;
	this->IsDead = 0;
	this->IsStopped = 0;
	this->stoppedoperatornum = -1;

	this->Seaglidertimer = 0;
}



void Seaglider::SpriteInit()
{
	SeagliderSprite = Sprite::create("pictures/Seaglider.png");
	SeagliderSprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1]));
	SeagliderBar = Sprite::create("pictures/bar.png");   //创建进度框
	SeagliderBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");
	SeagliderBlood = ProgressTimer::create(Blood); //创建AlphawormBlood对象
	SeagliderBlood->setType(ProgressTimer::Type::BAR); //类型：条状
	SeagliderBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 70));
	SeagliderBlood->setPercentage(100 * percentage);
}


void Seaglider::update(float update_time)
{
	//先判断血量
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	auto currentSprposition = this->SeagliderSprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0]) <= 2 && fabs(currentSprposition.y - this->Road[RoadStep][1]) <= 2) {
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

	this->percentage = (float)this->getcurrentHP() / (float)this->getmaxHP();

	//攻击判定
	if (Seaglidertimer < this->getAttackSpeed()) {
		Seaglidertimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Seaglidertimer = 0;
		}
	}

	//更新位置 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		SeagliderSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));

		SeagliderBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //设置框的位置
		SeagliderBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//血条变化
	SeagliderBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	SeagliderBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	SeagliderBlood->setBarChangeRate(Vec2(1, 0));
	SeagliderBlood->setPercentage(100 * percentage);

	//图像翻转
	if (xvec < 0) {
		this->SeagliderSprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->SeagliderSprite->setFlippedX(false);
	}

	//死亡判定
	if (IsDead) {
		this->IsStopped = 0;
		//将精灵删除
		SeagliderSprite->removeFromParent();
		SeagliderBar->removeFromParent();
		SeagliderBlood->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Seaglider::setRoad(std::vector<std::vector<int>> currentRoad)
{
	for (int i = 0; i < currentRoad.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < currentRoad[0].size(); j++) {
			one.push_back(currentRoad[i][j]);
		}
		this->Road.push_back(one);
	}
}