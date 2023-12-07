#include "BulletSprite.h"
#include "Data/AllData.h"
#include <cmath>
#include <algorithm>
#define PI acos(-1)

Bullet::Bullet(int Start, int End)
{
	Sprite::onEnter();

	//初始化操作
	this->startoperator = Start;
	this->endenemy = End;
	this->IsDestroyed = 0;
	this->speed = 10;
	bulletSprite = Sprite::create("pictures/Bullet.png");
	bulletSprite->setPosition(Alloperator[startoperator]->getPosition());

	this->scheduleUpdate();
}

void Bullet::update(float update_time)
{
	//如果目标死亡
	if (endenemy >= AllEnemy.size() || AllEnemy[endenemy]->IsDead) {
		IsDestroyed = 1;
	}
	else {
		//判断是否击中目标
		Vec2 from = bulletSprite->getPosition();
		Vec2 to = Allenemy[endenemy]->getPosition();
		if (sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2)) <= 20) {
			switch(AllOperator[startoperator]->getAttackType())
			{
			//保底伤害为5
			case physical:
				//物理伤害为：干员伤害-敌人物理防御
				AllEnemy[endenemy]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() - AllEnemy[endenemy]->getPhysicalDefense(), 5));
				break;
			case magical:
				//魔法伤害为：干员伤害*（100-敌人魔法防御）/100
				AllEnemy[endenemy]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() * (100 - AllEnemy[endenemy]->getMagicalDefense()) / 100, 5));
				break;
			default:
				break;
			}
			IsDestroyed = 1;
		}

		//更新坐标
		float vecx = (to.x - from.x) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		float vecy = (to.y - from.y) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		bulletSprite->setPosition(Vec2(from.x + static_cast<int>(vecx * this->speed), from.y + static_cast<int>(vecy * this->speed)));

		//改变角度朝向
		if (vecy >= 0) {
			bulletSprite->setRotation(atan(vecx / vecy) * 180.0f / PI);
		}
		else {
			bulletSprite->setRotation(atan(vecx / vecy) * 180.0f / PI + 180);
		}
	}

	//销毁
	if (IsDestroyed) {
		bulletSprite->removeFromParent();
		this->unscheduleUpdate();
	}
}