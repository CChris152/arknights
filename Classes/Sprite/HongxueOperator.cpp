#include "HongxueOperator.h"
#include "ArrowSprite.h"
#include "Data/AllData.h"
#include "Scene/LevelMapScene.h"
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
	this->setMaxHP(1200);
	this->setCurrentHP(1200);
	this->setAttack(700);
	this->setAttackSpeed(3);
	this->setExpense(18);
	this->setAttackRange(500);
	this->setAttackType(physical);
	this->setMaxStopNum(1);
	this->setCurrentStopNum(0);

	this->IsDead = 0;
	this->Hongxuetimer = 0;
}

void Hongxue::SpriteInit()
{
	Hongxuesprite = Sprite::create("pictures/Hongxue.png");
}

void Hongxue::update(float update_time)
{
	//ÅÐ¶ÏÊÇ·ñËÀÍö
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	//ÏÈÅÐ¶ÏÊÇ·ñ¿ÉÒÔ¹¥»÷
	if (Hongxuetimer < this->getAttackSpeed()) {
		Hongxuetimer += update_time;
	}
	else {
		//±éÀúµÐÈË
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//ÅÐ¶ÏÊÇ·ñÔÚ¹¥»÷·¶Î§ÄÚ
			Vec2 From = Hongxuesprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//Í¼Ïñ·­×ª
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

	//Èç¹ûËÀÍö
	if (IsDead) {
		this->Remove();
		this->Hongxuesprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Hongxue::Remove() {
	Vec2 vecplace = this->getVecPlace();
	((LevelMap*)this->Hongxuesprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}