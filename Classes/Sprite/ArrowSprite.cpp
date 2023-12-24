#include "ArrowSprite.h"
#include "Data/AllData.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
#include <cmath>
#define PI acos(-1)

Arrow::Arrow(int Start, int End)
{
	Sprite::onEnter();

	//��ʼ������
	this->startoperator = Start;
	this->endenemy = End;
	this->IsDestroyed = 0;
	this->speed = 6;
	arrowSprite = Sprite::create("pictures/Arrow.png");
	arrowSprite->setPosition(Alloperator[startoperator]->getPosition());

	this->scheduleUpdate();
}

void Arrow::update(float update_time)
{
	//���Ŀ������
	if (endenemy >= AllEnemy.size() || AllEnemy[endenemy]->IsDead) {
		IsDestroyed = 1;
	}
	else {
		//�ж��Ƿ����Ŀ��
		Vec2 from = arrowSprite->getPosition();
		Vec2 to = Allenemy[endenemy]->getPosition();
		if (sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2)) <= 20) {
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
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound effect/hit.mp3", false);
		}

		//��������
		float vecx = (to.x - from.x) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		float vecy = (to.y - from.y) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		arrowSprite->setPosition(Vec2(from.x + static_cast<int>(vecx * this->speed), from.y + static_cast<int>(vecy * this->speed)));

		//�ı�Ƕȳ���
		if (vecy >= 0) {
			arrowSprite->setRotation(atan(vecx / vecy) * 180.0f / PI);
		}
		else {
			arrowSprite->setRotation(atan(vecx / vecy) * 180.0f / PI + 180);
		}
	}

	//����
	if (IsDestroyed) {
		arrowSprite->removeFromParent();
		this->unscheduleUpdate();
	}
}