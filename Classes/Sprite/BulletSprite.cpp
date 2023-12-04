#include "BulletSprite.h"
#include "Data/AllData.h"
#include <cmath>
#define PI acos(-1)

Bullet::Bullet(int Start, int End)
{
	Sprite::onEnter();

	//��ʼ������
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
	//���Ŀ������
	if (endenemy >= AllEnemy.size() || AllEnemy[endenemy]->IsDead) {
		IsDestroyed = 1;
	}
	else {
		//�ж��Ƿ����Ŀ��
		Vec2 from = bulletSprite->getPosition();
		Vec2 to = Allenemy[endenemy]->getPosition();
		if (sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2)) <= 20) {
			AllEnemy[endenemy]->decreaseHP(AllOperator[startoperator]->getAttack());
			IsDestroyed = 1;
		}

		//��������
		float vecx = (to.x - from.x) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		float vecy = (to.y - from.y) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		bulletSprite->setPosition(Vec2(from.x + static_cast<int>(vecx * this->speed), from.y + static_cast<int>(vecy * this->speed)));

		//�ı�Ƕȳ���
		if (vecy >= 0) {
			bulletSprite->setRotation(atan(vecx / vecy) * 180.0f / PI);
		}
		else {
			bulletSprite->setRotation(atan(vecx / vecy) * 180.0f / PI + 180);
		}
	}

	//����
	if (IsDestroyed) {
		bulletSprite->removeFromParent();
		this->unscheduleUpdate();
	}
}