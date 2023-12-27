#include "SariaOperator.h"
#include "Sprite/AttackEffect/SwordSprite.h"
#include "Data/AllData.h"
#include "Scene/FunctionScene/LevelMapScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
#include <cmath>

#define PI acos(-1)

Saria::Saria(int Numbering, Vec2 VecPlace)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->setVecPlace(VecPlace);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Saria::OperatorInit()
{
	this->setMaxHP(3000);
	this->setCurrentHP(3000);
	this->setAttack(350);
	this->setAttackSpeed(5);
	this->setExpense(25);
	this->setAttackRange(0);
	this->setAttackType(physical);
	this->setMaxStopNum(3);
	this->setCurrentStopNum(0);

	this->Sariapercentage = 1;

	this->IsDead = 0;
	this->Sariatimer = 0;
}

void Saria::SpriteInit()
{
	Sariasprite = Sprite::create("pictures/Saria.png");
	SariaBar = Sprite::create("pictures/bar.png");
	SariaBar->setPosition(Sariasprite->getPosition().x + Sariasprite->getContentSize().width / 2, Sariasprite->getPosition().y + Sariasprite->getContentSize().height + 15);
	Sariasprite->addChild(SariaBar);
	OperatorBlood = Sprite::create("pictures/Blood.png");
	SariaBlood = ProgressTimer::create(OperatorBlood);
	SariaBlood->setType(ProgressTimer::Type::BAR);
	SariaBlood->setPosition(SariaBar->getContentSize().width / 2, SariaBar->getContentSize().height / 2);
	SariaBlood->setPercentage(100 * Sariapercentage);
	SariaBar->addChild(SariaBlood);
}

void Saria::update(float update_time)
{
	//�ж��Ƿ�����
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Sariapercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	SariaBlood->setType(ProgressTimer::Type::BAR);
	SariaBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	SariaBlood->setBarChangeRate(Vec2(1, 0));
	SariaBlood->setPercentage(100 * Sariapercentage);

	//�ж��Ƿ��ʹ�ûظ�Ѫ������
	if (Sariatimer < this->getAttackSpeed()) {
		Sariatimer += update_time;
	}
	else {
		Sariatimer = 0;//����

		this->setCurrentHP(std::min(this->getCurrentHP() + this->getAttack(), this->getMaxHP()));

		// ����Ѫ���ٷֱ�
		this->Sariapercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
		SariaBlood->setPercentage(100 * Sariapercentage);

		int enemynum = -1; //�������
		if (enemynum >= 0) {
			//ͼ��ת
			Vec2 From = Sariasprite->getPosition();
			Vec2 To = Allenemy[enemynum]->getPosition();
			if (To.x - From.x < 0) {
				this->Sariasprite->setFlippedX(true);
			}
			else {
				this->Sariasprite->setFlippedX(false);
			}
		}
	}

	//�赲�ĵ��������ж�
	for (std::vector<int>::iterator it = stoppedenemynum.begin(); it != stoppedenemynum.end();) {
		if (AllEnemy[*it]->IsStopped == 0) {
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
			if (AllEnemy[i]->IsDead || AllEnemy[i]->IsStopped == 1 || AllEnemy[i]->movetype == fly) {
				continue;
			}
			//�ж��Ƿ����赲��Χ��
			Vec2 From = Sariasprite->getPosition();
			Vec2 To = AllEnemy[i]->spritevec;
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - (From.y - 70), 2)) <= 40) {
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
		this->Sariasprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Saria::Remove() {
	Vec2 vecplace = this->getVecPlace();
	((LevelMap*)this->Sariasprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}