#include "ExusiaiOperator.h"
#include "BulletSprite.h"
#include "Data/AllData.h"
#include "Scene/LevelMapScene.h"
#include <cmath>

Exusiai::Exusiai(int Numbering, Vec2 VecPlace)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->setVecPlace(VecPlace);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Exusiai::OperatorInit()
{
	this->setMaxHP(1200);
	this->setCurrentHP(1200);
	this->setAttack(200);
	this->setAttackSpeed(1);
	this->setExpense(12);
	this->setAttackRange(700);
	this->setAttackType(physical);
	this->setMaxStopNum(1);
	this->setCurrentStopNum(0);

	this->Exusiaipercentage = 1;

	this->IsDead = 0;
	this->Exusiaitimer = 0;
}

void Exusiai::SpriteInit()
{
	Exusiaisprite = Sprite::create("pictures/Exusiai.png"); 
	ExusiaiBar = Sprite::create("pictures/bar.png");
	ExusiaiBar->setPosition(Exusiaisprite->getPosition().x + Exusiaisprite->getContentSize().width / 2, Exusiaisprite->getPosition().y + Exusiaisprite->getContentSize().height + 15);
	Exusiaisprite->addChild(ExusiaiBar);
	OperatorBlood = Sprite::create("pictures/Blood.png");
	ExusiaiBlood = ProgressTimer::create(OperatorBlood);
	ExusiaiBlood->setType(ProgressTimer::Type::BAR);
	ExusiaiBlood->setPosition(ExusiaiBar->getContentSize().width / 2, ExusiaiBar->getContentSize().height / 2);
	ExusiaiBlood->setPercentage(100 * Exusiaipercentage);
	ExusiaiBar->addChild(ExusiaiBlood);
}


void Exusiai::update(float update_time)
{
	//�ж��Ƿ�����
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Exusiaipercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	ExusiaiBlood->setType(ProgressTimer::Type::BAR);
	ExusiaiBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	ExusiaiBlood->setBarChangeRate(Vec2(1, 0));
	ExusiaiBlood->setPercentage(100 * Exusiaipercentage);

	//���ж��Ƿ���Թ���
	if (Exusiaitimer < this->getAttackSpeed()) {
		Exusiaitimer += update_time;
	}
	else {
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//�ж��Ƿ��ڹ�����Χ��
			Vec2 From = Exusiaisprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//ͼ��ת
				if (To.x - From.x < 0) {
					this->Exusiaisprite->setFlippedX(true);
				}
				else {
					this->Exusiaisprite->setFlippedX(false);
				}
				Bullet* newbullet = new Bullet(this->getNumbering(), i);
				AttackEffect.push_back(newbullet);
				(this->Exusiaisprite->getParent())->addChild(newbullet->bulletSprite);
				Exusiaitimer = 0;
				break;
			}
		}
	}

	//�������
	if (IsDead) {
		this->Remove();
		this->Exusiaisprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Exusiai::Remove() {
	Vec2 vecplace = this->getVecPlace();
    ((LevelMap*)this->Exusiaisprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}