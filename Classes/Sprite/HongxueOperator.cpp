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

	this->Hongxuepercentage = 1;

	this->IsDead = 0;
	this->Hongxuetimer = 0;
}

void Hongxue::SpriteInit()
{
	Hongxuesprite = Sprite::create("pictures/Hongxue.png");
	HongxueBar = Sprite::create("pictures/bar.png");
	HongxueBar->setPosition(Hongxuesprite->getPosition().x + Hongxuesprite->getContentSize().width / 2, Hongxuesprite->getPosition().y + Hongxuesprite->getContentSize().height + 15);
	Hongxuesprite->addChild(HongxueBar);
	OperatorBlood = Sprite::create("pictures/Blood.png");
	HongxueBlood = ProgressTimer::create(OperatorBlood);
	HongxueBlood->setType(ProgressTimer::Type::BAR);
	HongxueBlood->setPosition(HongxueBar->getContentSize().width / 2, HongxueBar->getContentSize().height / 2);
	HongxueBlood->setPercentage(100 * Hongxuepercentage);
	HongxueBar->addChild(HongxueBlood);
}

void Hongxue::update(float update_time)
{
	//判断是否死亡
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Hongxuepercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	HongxueBlood->setType(ProgressTimer::Type::BAR);
	HongxueBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	HongxueBlood->setBarChangeRate(Vec2(1, 0));
	HongxueBlood->setPercentage(100 * Hongxuepercentage);

	//先判断是否可以攻击
	if (Hongxuetimer < this->getAttackSpeed()) {
		Hongxuetimer += update_time;
	}
	else {
		//遍历敌人
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//判断是否在攻击范围内
			Vec2 From = Hongxuesprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//图像翻转
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

	//如果死亡
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