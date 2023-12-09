#include "QiubaiOperator.h"
#include "SwordSprite.h"
#include "Data/AllData.h"
#include "Scene/LevelMapScene.h"
#include <cmath>

#define PI acos(-1)

Qiubai::Qiubai(int Numbering, Vec2 VecPlace)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->setVecPlace(VecPlace);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Qiubai::OperatorInit()
{
	this->setBlood(1500);
	this->setAttack(300);
	this->setAttackSpeed(3);
	this->setExpense(15);
	this->setAttackRange(200);
	this->setAttackType(physical);
	this->setMaxStopNum(2);
	this->setCurrentStopNum(0);

	this->IsDead = 0;
	this->Qiubaitimer = 0;
}

void Qiubai::SpriteInit()
{
	Qiubaisprite = Sprite::create("pictures/Qiubai.png");
}

void Qiubai::update(float update_time)
{
	//�ж��Ƿ�����
	if (this->getBlood() <= 0) {
		IsDead = 1;
	}

	//���ж��Ƿ���Թ���
	if (Qiubaitimer < this->getAttackSpeed()) {
		Qiubaitimer += update_time;
	}
	else {
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//�ж��Ƿ��ڹ�����Χ��
			Vec2 From = Qiubaisprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				//ͼ��ת
				if (To.x - From.x < 0) {
					this->Qiubaisprite->setFlippedX(true);
				}
				else {
					this->Qiubaisprite->setFlippedX(false);
				}
				Sword* newsword = new Sword(this->getNumbering(), i);
				AttackEffect.push_back(newsword);
				(this->Qiubaisprite->getParent())->addChild(newsword->swordSprite);
				Qiubaitimer = 0;
				break;
			}
		}
	}

	//�赲�ĵ��������ж�
	for (std::vector<int>::iterator it = stoppedenemynum.begin(); it != stoppedenemynum.end();) {
		if (AllEnemy [*it]->IsStopped == 0) {
			it = stoppedenemynum.erase(it);
			this->setCurrentStopNum(this->getCurrentStopNum() - 1);
		}
		else {
			it++;
		}
	}

	//�赲�ж�
	if (this->getCurrentStopNum() < this->getMaxStopNum()) {
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead || AllEnemy[i]->IsStopped == 1) {
				continue;
			}
			//�ж��Ƿ����赲��Χ��
			Vec2 From = Qiubaisprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - (From.y-70), 2)) <= 20) {
				AllEnemy[i]->IsStopped = 1;
				this->setCurrentStopNum(this->getCurrentStopNum() + 1);
				stoppedenemynum.push_back(i);
				AllEnemy[i]->stoppedoperatornum = this->getNumbering();
				break;
			}
		}
	}

	//�������
	if (IsDead) {
		for (auto it : stoppedenemynum) {
			AllEnemy[it]->IsStopped = 0;
			AllEnemy[it]->stoppedoperatornum = -1;
		}
		this->Remove();
		this->Qiubaisprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Qiubai::Remove() {
	Vec2 vecplace = this->getVecPlace();
	((LevelMap*)this->Qiubaisprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}