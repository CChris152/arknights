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

void Alphaworm::EnemyInit()
{
	this->setAttack(100);
	this->setAttackSpeed(3.0f);
	this->setmaxHP(1000);
	this->setcurrentHP(1000);
	this->setspeed(1.0f);
	this->setPhysicalDefense(50);
	this->setMagicalDefense(10);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;
	this->percentage = 1;
	this->IsDead = 0;
	this->IsStopped = 0;
	this->stoppedoperatornum = -1;

	movetype = walk;

	this->Alphawormtimer = 0;
}



void Alphaworm::SpriteInit()
{
	AlphawormSprite = Sprite::create("pictures/Alphaworm.png");
	AlphawormSprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1]));
	AlphawormBar = Sprite::create("pictures/bar.png");   //创建进度框
	AlphawormBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");  
	AlphawormBlood = ProgressTimer::create(Blood); //创建AlphawormBlood对象
	AlphawormBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	AlphawormBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	AlphawormBlood->setPercentage(100 * percentage);
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

	this->percentage = (float)this->getcurrentHP()/ (float)this->getmaxHP();

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
		AlphawormSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));

		AlphawormBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //设置框的位置
		AlphawormBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//血条变化
	AlphawormBlood->setType(ProgressTimer::Type::BAR);        //类型：条状
	AlphawormBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	AlphawormBlood->setBarChangeRate(Vec2(1, 0));
	AlphawormBlood->setPercentage(100 * percentage);

	//图像翻转
	if (xvec < 0) {
		this->AlphawormSprite->setFlippedX(true);
	}
	if (xvec > 0){
		this->AlphawormSprite->setFlippedX(false);
	}

	//死亡判定
	if (IsDead) {
		this->IsStopped = 0;
		//将精灵删除
		AlphawormSprite->removeFromParent();
		AlphawormBar->removeFromParent();
		AlphawormBlood->removeFromParent();
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