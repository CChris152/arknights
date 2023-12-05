#include "HongxueOperator.h"
#include "ArrowSprite.h"
#include "Data/AllData.h"
#include "Scene/Level1MapScene.h"
#include <cmath>

Hongxue::Hongxue(int Numbering, Vec2 VecPlace)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->setVecPlace(VecPlace);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Hongxue::OperatorInit()
{
	this->setBlood(1800);
	this->setAttack(400);
	this->setAttackSpeed(3);
	this->setExpense(18);
	this->setAttackRange(500);

	this->IsDead = 0;
	this->Hongxuetimer = 0;
}

void Hongxue::SpriteInit()
{
	Hongxuesprite = Sprite::create("pictures/Hongxue.png");
}

void Hongxue::update(float update_time)
{
	//�ж��Ƿ�����
	if (this->getBlood() <= 0) {
		IsDead = 1;
	}

	//���ж��Ƿ���Թ���
	if (Hongxuetimer < this->getAttackSpeed()) {
		Hongxuetimer += update_time;
	}
	else {
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//�ж��Ƿ��ڹ�����Χ��
			Vec2 From = Hongxuesprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//ͼ��ת
				if (To.x - From.x < 0) {
					this->Hongxuesprite->setFlippedX(true);
				}
				else {
					this->Hongxuesprite->setFlippedX(false);
				}
				Arrow* newarrow = new Arrow(this->getNumbering(), i);
				AttackEffect.push_back(newarrow);
				(this->Hongxuesprite->getParent())->addChild(newarrow->arrowSprite);
				Hongxuetimer = 0;
				break;
			}
		}
	}

	//�������
	if (IsDead) {
		this->Remove();
		this->Hongxuesprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Hongxue::Remove() {
	Vec2 vecplace = this->getVecPlace();
	switch (CurrentLevel)
	{
	case 1:
		((Level1Map*)this->Hongxuesprite->getParent())->currentLevel1vec[vecplace.x][vecplace.y] -= 10;
		break;
	default:
		break;
	}
}