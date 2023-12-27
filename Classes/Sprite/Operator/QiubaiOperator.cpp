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
	//�ж��Ƿ�����
	if (this->getCurrentHP() <= 0) {
		IsDead = 1;
	}

	this->Qiubaipercentage = (float)this->getCurrentHP() / (float)this->getMaxHP();
	QiubaiBlood->setType(ProgressTimer::Type::BAR);  
	QiubaiBlood->setMidpoint(Vec2(0, 0.5));    //���ҵ������Ѫ��
	QiubaiBlood->setBarChangeRate(Vec2(1, 0));
	QiubaiBlood->setPercentage(100 * Qiubaipercentage);
	

	//���ж��Ƿ���Թ���
	if (Qiubaitimer < this->getAttackSpeed()) {
		Qiubaitimer += update_time;
	}
	else {
		int mindistance = INT_MAX; //���е���������ص���̾���
		int enemynum = -1; //�������
		//��������
		for (int i = 0; i < AllEnemy.size(); i++) {
			if (AllEnemy[i]->IsDead || AllEnemy[i]->movetype == fly) {
				continue;
			}
			//�ж��Ƿ��ڹ�����Χ��
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
			//ͼ��ת
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
			if (AllEnemy[i]->IsDead || AllEnemy[i]->IsStopped == 1 || AllEnemy[i]->movetype == fly) {
				continue;
			}
			//�ж��Ƿ����赲��Χ��
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