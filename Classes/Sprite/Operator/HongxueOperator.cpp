#include "HongxueOperator.h"
#include "Sprite/AttackEffect/ArrowSprite.h"
#include "Data/AllData.h"
#include "Scene/FunctionScene/LevelMapScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
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
	this->setAttack(1500);
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
	//�ж��Ƿ�����
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Hongxuepercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	HongxueBlood->setType(ProgressTimer::Type::BAR);
	HongxueBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	HongxueBlood->setBarChangeRate(Vec2(1, 0));
	HongxueBlood->setPercentage(100 * Hongxuepercentage);

	//���ж��Ƿ���Թ���
	if (Hongxuetimer < this->getAttackSpeed()) {
		Hongxuetimer += update_time;
	}
	else {
		int mindistance = INT_MAX; //���е���������ص���̾���
		int enemynum = -1; //�������
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//�ж��Ƿ��ڹ�����Χ��
			Vec2 From = Hongxuesprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				if (sqrt(pow(To.x - AllBaseVec[CurrentLevel - 1][0], 2) + pow(To.y - AllBaseVec[CurrentLevel - 1][1], 2)) <= mindistance) {
					mindistance = sqrt(pow(To.x - AllBaseVec[CurrentLevel - 1][0], 2) + pow(To.y - AllBaseVec[CurrentLevel - 1][1], 2));
					enemynum = i;
				}
			}
		}
		if (enemynum >= 0) {
			//ͼ��ת
			Vec2 From = Hongxuesprite->getPosition();
			Vec2 To = Allenemy[enemynum]->getPosition();
			if (To.x - From.x < 0) {
				this->Hongxuesprite->setFlippedX(true);
			}
			else {
				this->Hongxuesprite->setFlippedX(false);
			}
			Arrow* newarrow = new Arrow(this->getNumbering(), enemynum);
			AttackEffect.push_back(newarrow);
			(this->Hongxuesprite->getParent())->addChild(newarrow->arrowSprite, 1000);
			Hongxuetimer = 0;
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound effect/arrow.mp3", false);
		}
	}

	//�������
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