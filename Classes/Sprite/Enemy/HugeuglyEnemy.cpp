#include "HugeuglyEnemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

Hugeugly::Hugeugly()
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
	HugeuglyBar = Sprite::create("pictures/bar.png");   //�������ȿ�
	HugeuglyBar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50 + 80));
	Blood = Sprite::create("pictures/Blood.png");
	HugeuglyBlood = ProgressTimer::create(Blood); //����AlphawormBlood����
	HugeuglyBlood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	HugeuglyBlood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50 + 80));
	HugeuglyBlood->setPercentage(100 * percentage);
}


void Hugeugly::update(float update_time)
{
	//���ж�Ѫ��
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	//���·���
	auto currentSprposition = this->HugeuglySprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0]) <= 2 && fabs(currentSprposition.y - 80 - this->Road[RoadStep][1]) <= 2) {
		if (RoadStep < this->Road.size() - 1) {
			float distance = sqrt(pow(this->Road[RoadStep + 1][0] - this->Road[RoadStep][0], 2) + pow(this->Road[RoadStep + 1][1] - this->Road[RoadStep][1], 2));
			this->xvec = (this->Road[RoadStep + 1][0] - this->Road[RoadStep][0]) * 1.0f / distance;
			this->yvec = (this->Road[RoadStep + 1][1] - this->Road[RoadStep][1]) * 1.0f / distance;
		}
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
	if (Hugeuglytimer < this->getAttackSpeed()) {
		Hugeuglytimer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			Hugeuglytimer = 0;
		}
	}

	//����λ�� 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		HugeuglySprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));
		this->spritevec = Vec2(currentSprposition.x, currentSprposition.y - 80);

		HugeuglyBar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //���ÿ��λ��
		HugeuglyBlood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//Ѫ���仯
	HugeuglyBlood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	HugeuglyBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	HugeuglyBlood->setBarChangeRate(Vec2(1, 0));
	HugeuglyBlood->setPercentage(100 * percentage);

	//ͼ��ת
	if (xvec < 0) {
		this->HugeuglySprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->HugeuglySprite->setFlippedX(false);
	}

	//�����ж�
	if (IsDead) {
		this->IsStopped = 0;
		//������ɾ��
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