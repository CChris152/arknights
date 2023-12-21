#include "SeagliderEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Seaglider::Seaglider()
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
	SeagliderBar = Sprite::create("pictures/bar.png");   //�������ȿ�
	SeagliderBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");
	SeagliderBlood = ProgressTimer::create(Blood); //����AlphawormBlood����
	SeagliderBlood->setType(ProgressTimer::Type::BAR); //���ͣ���״
	SeagliderBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 70));
	SeagliderBlood->setPercentage(100 * percentage);
}


void Seaglider::update(float update_time)
{
	//���ж�Ѫ��
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

	//�����յ������
	if (RoadStep == this->Road.size()) {
		IsDead = 1;
		BaseHP--;
		killednum++;
	}

	this->percentage = (float)this->getcurrentHP() / (float)this->getmaxHP();

	//�����ж�
	if (Seaglidertimer < this->getAttackSpeed()) {
		Seaglidertimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Seaglidertimer = 0;
		}
	}

	//����λ�� 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		SeagliderSprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));

		SeagliderBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //���ÿ��λ��
		SeagliderBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//Ѫ���仯
	SeagliderBlood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	SeagliderBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	SeagliderBlood->setBarChangeRate(Vec2(1, 0));
	SeagliderBlood->setPercentage(100 * percentage);

	//ͼ��ת
	if (xvec < 0) {
		this->SeagliderSprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->SeagliderSprite->setFlippedX(false);
	}

	//�����ж�
	if (IsDead) {
		this->IsStopped = 0;
		//������ɾ��
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