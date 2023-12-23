#include "D4Enemy.h"
#include "Data/AllData.h"
#include "Logic/GameLogic.h"
#include "cmath"

D4::D4()
{
	//�ⶫ��һ��Ҫ���ϣ�����
	Enemy::onEnter();

	//����·��
	switch (CurrentLevel)
	{
	case 2:
		this->setRoad(Level2Fly);
		break;
	case 3:
		this->setRoad(Level3Fly);
		break;
	default:
		break;
	}

	this->EnemyInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void D4::EnemyInit()
{
	this->setAttack(0);
	this->setAttackSpeed(10.0f);
	this->setmaxHP(1800);
	this->setcurrentHP(1800);
	this->setspeed(1.0f);
	this->setPhysicalDefense(300);
	this->setMagicalDefense(5);

	this->RoadStep = 0;
	this->xvec = 0;
	this->yvec = 0;
	this->percentage = 1;
	this->IsDead = 0;
	this->IsStopped = 0;
	this->stoppedoperatornum = -1;

	movetype = fly;

	this->D4timer = 0;
}



void D4::SpriteInit()
{
	D4Sprite = Sprite::create("pictures/D4.png");
	D4Sprite->setPosition(Vec2(this->Road[0][0], this->Road[0][1]));
	D4Bar = Sprite::create("pictures/bar.png");   //�������ȿ�
	D4Bar->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	Blood = Sprite::create("pictures/Blood.png");
	D4Blood = ProgressTimer::create(Blood); //����AlphawormBlood����
	D4Blood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	D4Blood->setPosition(Vec2(this->Road[0][0], this->Road[0][1] + 50));
	D4Blood->setPercentage(100 * percentage);
}


void D4::update(float update_time)
{
	//���ж�Ѫ��
	if (getcurrentHP() <= 0) {
		IsDead = 1;
		killednum++;
	}

	//���·���
	auto currentSprposition = this->D4Sprite->getPosition();
	if (fabs(currentSprposition.x - this->Road[RoadStep][0]) <= 2 && fabs(currentSprposition.y - this->Road[RoadStep][1]) <= 2) {
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
	if (D4timer < this->getAttackSpeed()) {
		D4timer += update_time;
	}
	else {
		if (this->stoppedoperatornum != -1) {
			AllOperator[stoppedoperatornum]->decreaseBlood(this->getAttack());
			D4timer = 0;
		}
	}

	//����λ�� 
	if (IsStopped == 0) {
		float currentspeed = this->getspeed();
		currentSprposition.x += this->xvec * currentspeed;
		currentSprposition.y += this->yvec * currentspeed;
		D4Sprite->setPosition(Vec2(currentSprposition.x, currentSprposition.y));

		D4Bar->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50)); //���ÿ��λ��
		D4Blood->setPosition(Vec2(currentSprposition.x, currentSprposition.y + 50));
	}
	else {

	}

	//Ѫ���仯
	D4Blood->setType(ProgressTimer::Type::BAR);        //���ͣ���״
	D4Blood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	D4Blood->setBarChangeRate(Vec2(1, 0));
	D4Blood->setPercentage(100 * percentage);

	//ͼ��ת
	if (xvec < 0) {
		this->D4Sprite->setFlippedX(true);
	}
	if (xvec > 0) {
		this->D4Sprite->setFlippedX(false);
	}

	//�����ж�
	if (IsDead) {
		this->IsStopped = 0;
		//������ɾ��
		D4Sprite->removeFromParent();
		D4Bar->removeFromParent();
		D4Blood->removeFromParent();
		this->unscheduleUpdate();
	}
}

void D4::setRoad(std::vector<std::vector<int>> currentRoad)
{
	for (int i = 0; i < currentRoad.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < currentRoad[0].size(); j++) {
			one.push_back(currentRoad[i][j]);
		}
		this->Road.push_back(one);
	}
}