#include "SwordSprite.h"
#include "Data/AllData.h"
#include <cmath>
#define PI acos(-1)

Sword::Sword(int Start, int End)
{
	Sprite::onEnter();

	//初始化操作
	this->startoperator = Start;
	this->endenemy = End;
	this->IsDestroyed = 0;
	this->swordtimer = 0;
	swordSprite = Sprite::create("pictures/Sword.png");
	swordSprite->setPosition(Alloperator[startoperator]->getPosition());

	//设置初始角度
	Vec2 From = Alloperator[startoperator]->getPosition();
	Vec2 To = Allenemy[endenemy]->getPosition();
	float vecx = To.x - From.x;
	float vecy = To.y - From.y;
	if (vecy >= 0) {
		swordSprite->setRotation(atan(vecx / vecy) * 180.0f / PI - 45);
	}
	else {
		swordSprite->setRotation(atan(vecx / vecy) * 180.0f / PI + 180 - 45);
	}

	this->scheduleUpdate();
}

void Sword::update(float update_time)
{
	if (endenemy >= AllEnemy.size() || AllEnemy[endenemy]->IsDead) {
		IsDestroyed = 1;
	}
	else {
		//攻击时间为1s
		if (this->swordtimer >= 0.5f) {
			switch (AllOperator[startoperator]->getAttackType())
			{
			case physical:
				AllEnemy[endenemy]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() - AllEnemy[endenemy]->getPhysicalDefense(), 5));
				break;
			case magical:
				AllEnemy[endenemy]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() * (100 - AllEnemy[endenemy]->getMagicalDefense()) / 100, 5));
				break;
			default:
				break;
			}
			IsDestroyed = 1;
		}
		else {
			swordtimer += update_time;
			swordSprite->setRotation(swordSprite->getRotation() + 1.0f / 30 * 90);
		}
	}
	
	//销毁
	if (IsDestroyed) {
		swordSprite->removeFromParent();
		this->unscheduleUpdate();
	}
}