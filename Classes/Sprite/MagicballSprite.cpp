#include "MagicballSprite.h"
#include "Data/AllData.h"
#include <cmath>
#define PI acos(-1)

Magicball::Magicball(int Start, int End)
{
	Sprite::onEnter();

	//��ʼ������
	this->startoperator = Start;
	this->endenemy = End;
	this->IsDestroyed = 0;
	this->speed = 6;
	this->attackRange = 100;
	magicballSprite = Sprite::create("pictures/Magicball.png");
	magicballSprite->setPosition(Alloperator[startoperator]->getPosition());

	this->scheduleUpdate();
}

void Magicball::update(float update_time)
{
	//���Ŀ������
	if (endenemy >= AllEnemy.size() || AllEnemy[endenemy]->IsDead) {
		IsDestroyed = 1;
	}
	else {
		//�ж��Ƿ����Ŀ��
		Vec2 from = magicballSprite->getPosition();
		Vec2 to = Allenemy[endenemy]->getPosition();
		if (sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2)) <= 20) {
			for (int i = 0; i < AllEnemy.size(); i++) {
				if (AllEnemy[i]->IsDead) {
					continue;
				}
				//�ж��Ƿ��ڹ�����Χ��
				Vec2 From = Allenemy[endenemy]->getPosition();
				Vec2 To = Allenemy[i]->getPosition();
				if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->attackRange) {
					switch (AllOperator[startoperator]->getAttackType())
					{
					case physical:
						AllEnemy[i]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() - AllEnemy[i]->getPhysicalDefense(), 5));
						break;
					case magical:
						AllEnemy[i]->decreaseHP(std::max(AllOperator[startoperator]->getAttack() * (100 - AllEnemy[i]->getMagicalDefense()) / 100, 5));
						break;
					default:
						break;
					}
					IsDestroyed = 1;
					// ����DrawNode
					auto drawNode = DrawNode::create();
					(this->magicballSprite->getParent())->addChild(drawNode);
					Color4F semiTransparentColor = Color4F(0.8f, 0.0f, 0.0f, 0.15f);
					// ����ײ��Ϊ���ģ�����һ���뾶Ϊthis->attackRange��Բ
					drawNode->drawDot(to, this->attackRange, semiTransparentColor);

					// �������һЩ����Ч�������罥����ʧ
					drawNode->runAction(Sequence::create(
						FadeOut::create(0.2f),
						RemoveSelf::create(),
						nullptr
					));
				}
			}
			
		}

		//��������
		float vecx = (to.x - from.x) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		float vecy = (to.y - from.y) / sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
		magicballSprite->setPosition(Vec2(from.x + static_cast<int>(vecx * this->speed), from.y + static_cast<int>(vecy * this->speed)));

		//�ı�Ƕȳ���
		if (vecy >= 0) {
			magicballSprite->setRotation(atan(vecx / vecy) * 180.0f / PI);
		}
		else {
			magicballSprite->setRotation(atan(vecx / vecy) * 180.0f / PI + 180);
		}
	}

	//����
	if (IsDestroyed) {
		magicballSprite->removeFromParent();
		this->unscheduleUpdate();
	}
}