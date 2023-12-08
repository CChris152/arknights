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
	this->setBlood(1200);
	this->setAttack(200);
	this->setAttackSpeed(2);
	this->setExpense(12);
	this->setAttackRange(700);
	this->setAttackType(physical);
	this->setMaxStopNum(1);
	this->setCurrentStopNum(0);

	this->IsDead = 0;
	this->Exusiaitimer = 0;
}

void Exusiai::SpriteInit()
{
	Exusiaisprite = Sprite::create("pictures/Exusiai.png");
}

void Exusiai::update(float update_time)
{
	//ÅÐ¶ÏÊÇ·ñËÀÍö
	if (this->getBlood() <= 0) {
		IsDead = 1;
	}

	//ÏÈÅÐ¶ÏÊÇ·ñ¿ÉÒÔ¹¥»÷
	if (Exusiaitimer < this->getAttackSpeed()) {
		Exusiaitimer += update_time;
	}
	else {
		//±éÀúµÐÈË
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//ÅÐ¶ÏÊÇ·ñÔÚ¹¥»÷·¶Î§ÄÚ
			Vec2 From = Exusiaisprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//Í¼Ïñ·­×ª
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

	//Èç¹ûËÀÍö
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