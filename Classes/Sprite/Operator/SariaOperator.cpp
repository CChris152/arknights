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
	//判断是否死亡
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Sariapercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	SariaBlood->setType(ProgressTimer::Type::BAR);
	SariaBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	SariaBlood->setBarChangeRate(Vec2(1, 0));
	SariaBlood->setPercentage(100 * Sariapercentage);

	//判断是否可使用回复血量技能
	if (Sariatimer < this->getAttackSpeed()) {
		Sariatimer += update_time;
	}
	else {
		Sariatimer = 0;//重置

		this->setCurrentHP(std::min(this->getCurrentHP() + this->getAttack(), this->getMaxHP()));

		// 更新血条百分比
		this->Sariapercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
		SariaBlood->setPercentage(100 * Sariapercentage);

		int enemynum = -1; //敌人序号
		if (enemynum >= 0) {
			//图像翻转
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

	//阻挡的敌人死亡判断
	for (std::vector<int>::iterator it = stoppedenemynum.begin(); it != stoppedenemynum.end();) {
		if (AllEnemy[*it]->IsStopped == 0) {
			it = stoppedenemynum.erase(it);
			this->setCurrentStopNum(this->getCurrentStopNum() - 1);
		}
		else {
			it++;
		}
	}

	//阻挡判断
	if (this->getCurrentStopNum() < this->getMaxStopNum()) {
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead || AllEnemy[i]->IsStopped == 1 || AllEnemy[i]->movetype == fly) {
				continue;
			}
			//判断是否在阻挡范围内
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

	//如果死亡
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