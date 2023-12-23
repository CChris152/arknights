#include "AlphawormEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Alphaworm::Alphaworm() 
{
	//�ⶫ��һ��Ҫ���ϣ�����
	Enemy::onEnter();

	//����·��
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
	AlphawormBar = Sprite::create("pictures/bar.png");   //�������ȿ�
	AlphawormBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");  
	AlphawormBlood = ProgressTimer::create(Blood); //����AlphawormBlood����
	AlphawormBlood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	AlphawormBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	AlphawormBlood->setPercentage(100 * percentage);
}


void Alphaworm::update(float update_time)
{
	//���ж�Ѫ��
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

	//�����յ������
	if (RoadStep == this->Road.size()) {
		IsDead = 1;
		BaseHP--;
		killednum++;
	}

	this->percentage = (float)this->getcurrentHP()/ (float)this->getmaxHP();

	//�����ж�
	if (Alphawormtimer < this->getAttackSpeed()) {
		Alphawormtimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Alphawormtimer = 0;
		}
	}

	//����λ�� 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		AlphawormSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));

		AlphawormBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //���ÿ��λ��
		AlphawormBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//Ѫ���仯
	AlphawormBlood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	AlphawormBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	AlphawormBlood->setBarChangeRate(Vec2(1, 0));
	AlphawormBlood->setPercentage(100 * percentage);

	//ͼ��ת
	if (xvec < 0) {
		this->AlphawormSprite->setFlippedX(true);
	}
	if (xvec > 0){
		this->AlphawormSprite->setFlippedX(false);
	}

	//�����ж�
	if (IsDead) {
		this->IsStopped = 0;
		//������ɾ��
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