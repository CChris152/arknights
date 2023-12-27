#include "QiubaiOperator.h"
#include "Sprite/AttackEffect/SwordSprite.h"
#include "Data/AllData.h"
#include "Scene/FunctionScene/LevelMapScene.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"
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
	this->setMaxHP(1500);
	this->setCurrentHP(1500);
	this->setAttack(600);
	this->setAttackSpeed(2);
	this->setExpense(18);
	this->setAttackRange(200);
	this->setAttackType(physical);
	this->setMaxStopNum(2);
	this->setCurrentStopNum(0);

	this->Qiubaipercentage = 1;

	this->IsDead = 0;
	this->Qiubaitimer = 0;
}

void Qiubai::SpriteInit()
{
	Qiubaisprite = Sprite::create("pictures/Qiubai.png");
	QiubaiBar= Sprite::create("pictures/bar.png");
	QiubaiBar->setPosition(Qiubaisprite->getPosition().x+ Qiubaisprite->getContentSize().width / 2, Qiubaisprite->getPosition().y+ Qiubaisprite->getContentSize().height + 15);
	Qiubaisprite->addChild(QiubaiBar);
	OperatorBlood = Sprite::create("pictures/Blood.png");
	QiubaiBlood = ProgressTimer::create(OperatorBlood); 
	QiubaiBlood->setType(ProgressTimer::Type::BAR);        
	QiubaiBlood->setPosition(QiubaiBar->getContentSize().width/2, QiubaiBar->getContentSize().height/2);
	QiubaiBlood->setPercentage(100 * Qiubaipercentage);
	QiubaiBar->addChild(QiubaiBlood);
}

void Qiubai::update(float update_time)
{
	//判断是否死亡
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Qiubaipercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	QiubaiBlood->setType(ProgressTimer::Type::BAR);  
	QiubaiBlood->setMidpoint(Vec2(0, 0.5));    //从右到左减少血量
	QiubaiBlood->setBarChangeRate(Vec2(1, 0));
	QiubaiBlood->setPercentage(100 * Qiubaipercentage);
	

	//先判断是否可以攻击
	if (Qiubaitimer < this->getAttackSpeed()) {
		Qiubaitimer += update_time;
	}
	else {
		int mindistance = INT_MAX; //所有敌人中与基地的最短距离
		int enemynum = -1; //敌人序号
		//遍历敌人
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead || AllEnemy[i]->movetype == fly) {
				continue;
			}
			//判断是否在攻击范围内
			Vec2 From = Qiubaisprite->getPosition();
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
			Vec2 From = Qiubaisprite->getPosition();
			Vec2 To = Allenemy[enemynum]->getPosition();
			if (To.x - From.x < 0) {
				this->Qiubaisprite->setFlippedX(true);
			}
			else {
				this->Qiubaisprite->setFlippedX(false);
			}
			Sword* newsword = new Sword(this->getNumbering(), enemynum);
			AttackEffect.push_back(newsword);
			(this->Qiubaisprite->getParent())->addChild(newsword->swordSprite, 1000);
			Qiubaitimer = 0;
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound effect/sword.mp3", false);
		}
	}

	//阻挡的敌人死亡判断
	for (std::vector<int>::iterator it = stoppedenemynum.begin(); it != stoppedenemynum.end();) {
		if (AllEnemy [*it]->IsStopped == 0) {
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
			Vec2 From = Qiubaisprite->getPosition();
			Vec2 To = AllEnemy[i]->spritevec;
			if (sqrt(pow(To.x - From.x, 2) + pow(To.y - (From.y-70), 2)) <= 40) {
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
		this->Qiubaisprite->removeFromParent();
		this->unscheduleUpdate();
	}
}

void Qiubai::Remove() {
	Vec2 vecplace = this->getVecPlace();
	((LevelMap*)this->Qiubaisprite->getParent())->currentLevelvec[vecplace.x][vecplace.y] -= 10;
}