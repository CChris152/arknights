#include "HongxueOperator.h"
#include "ArrowSprite.h"
#include "Data/AllData.h"
#include <cmath>

Hongxue::Hongxue(int Numbering)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Hongxue::OperatorInit()
{
	this->setAttack(400);
	this->setAttackSpeed(3);
	this->setExpense(18);
	this->setAttackRange(500);

	this->Hongxuetimer = 0;
}

void Hongxue::SpriteInit()
{
	Hongxuesprite = Sprite::create("pictures/Hongxue.png");
}

void Hongxue::update(float update_time)
{
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
}