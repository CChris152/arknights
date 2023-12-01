#include "ExusiaiOperator.h"
#include "BulletSprite.h"
#include "Data/AllData.h"
#include <cmath>

Exuasiai::Exuasiai(int Numbering)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Exuasiai::OperatorInit()
{
	this->setAttack(200);
	this->setAttackSpeed(2);
	this->setExpense(12);
	this->setAttackRange(700);

	this->Exuasiaitimer = 0;
}

void Exuasiai::SpriteInit()
{
	Exuasiaisprite = Sprite::create("pictures/Exusiai.png");
}

void Exuasiai::update(float update_time)
{
	//���ж��Ƿ���Թ���
	if (Exuasiaitimer < this->getAttackSpeed()) {
		Exuasiaitimer += update_time;
	}
	else {
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}

			//�ж��Ƿ��ڹ�����Χ��
			Vec2 From = Exuasiaisprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				Bullet* newbullet = new Bullet(this->getNumbering(), i);
				(this->Exuasiaisprite->getParent())->addChild(newbullet->bulletSprite);
				Exuasiaitimer = 0;
				break;
			}
		}
	}
}