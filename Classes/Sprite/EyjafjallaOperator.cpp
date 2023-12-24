#include "EyjafjallaOperator.h"
#include "MagicballSprite.h"
#include "Data/AllData.h"
#include "Scene/LevelMapScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
#include <cmath>

Eyjafjalla::Eyjafjalla(int Numbering, Vec2 VecPlace)
{
	Operator::onEnter();

	this->setNumbering(Numbering);
	this->setVecPlace(VecPlace);
	this->OperatorInit();
	this->SpriteInit();

	this->scheduleUpdate();
}

void Eyjafjalla::OperatorInit()
{
	this->setMaxHP(1200);
	this->setCurrentHP(1200);
	this->setAttack(700);
	this->setAttackSpeed(4);
	this->setExpense(23);
	this->setAttackRange(500);
	this->setAttackType(magical);
	this->setMaxStopNum(1);
	this->setCurrentStopNum(0);

	this->Eyjafjallapercentage = 1;

	this->IsDead = 0;
	this->Eyjafjallatimer = 0;
}

void Eyjafjalla::SpriteInit()
{
	Eyjafjallasprite = Sprite::create("pictures/Eyjafjalla.png");
	EyjafjallaBar = Sprite::create("pictures/bar.png");
	EyjafjallaBar->setPosition(Eyjafjallasprite->getPosition().x + Eyjafjallasprite->getContentSize().width / 2, Eyjafjallasprite->getPosition().y + Eyjafjallasprite->getContentSize().height + 15);
	Eyjafjallasprite->addChild(EyjafjallaBar);
	OperatorBlood = Sprite::create("pictures/Blood.png");
	EyjafjallaBlood = ProgressTimer::create(OperatorBlood);
	EyjafjallaBlood->setType(ProgressTimer::Type::BAR);
	EyjafjallaBlood->setPosition(EyjafjallaBar->getContentSize().width / 2, EyjafjallaBar->getContentSize().height / 2);
	EyjafjallaBlood->setPercentage(100 * Eyjafjallapercentage);
	EyjafjallaBar->addChild(EyjafjallaBlood);
}

void Eyjafjalla::update(float update_time)
{
	//判断是否死亡
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Eyjafjallapercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	EyjafjallaBlood->setType(ProgressTimer::Type::BAR);
	EyjafjallaBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	EyjafjallaBlood->setBarChangeRate(Vec2(1, 0));
	EyjafjallaBlood->setPercentage(100 * Eyjafjallapercentage);

	//先判断是否可以攻击
	if (Eyjafjallatimer < this->getAttackSpeed()) {
		Eyjafjallatimer += update_time;
	}
	else {
		int mindistance = INT_MAX; //所有敌人中与基地的最短距离
		int enemynum = -1; //敌人序号
		//遍历敌人
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead) {
				continue;
			}
			//判断是否在攻击范围内
			Vec2 From = Eyjafjallasprite->getPosition();
			Vec2 To = Allenemy[i]->getPosition();
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - From.y, 2)) <= this->getAttackRange()) {
				if (sqrt(pow(To.x - AllBaseVec[CurrentLevel - 1][0], 2) + pow(To.y - AllBaseVec[CurrentLevel - 1][1], 2)) <= mindistance) {
					mindistance = sqrt(pow(To.x - AllBaseVec[CurrentLevel - 1][0], 2) + pow(To.y - AllBaseVec[CurrentLevel - 1][1], 2));
					enemynum = i;
				}
			}
		}
		if (enemynum >= 0) {
			//图像翻转
			Vec2 From = Eyjafjallasprite->getPosition();
			Vec2 To = Allenemy[enemynum]->getPosition();
			if (To.x - From.x < 0) {
				this->Eyjafjallasprite->setFlippedX(true);
			}
			else {
				this->Eyjafjallasprite->setFlippedX(false);
			}
			Magicball* newmagicball = new Magicball(this->getNumbering(), enemynum);
			AttackEffect.push_back(newmagicball);
			(this->Eyjafjallasprite->getParent())->addChild(newmagicball->magicballSprite, 1000);
			Eyjafjallatimer = 0;
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound effect/magicball.mp3", false);
		}
	}

	//如果死亡
	if (IsDead) {
		this->Remove();
		this->Eyjafjallasprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Eyjafjalla::Remove() {
	Vec2 vecplace = this->getVecPlace();
	((LevelMap*)this->Eyjafjallasprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}