#include "GameLogic.h"
#include "Sprite/AlphawormEnemy.h"
#include "Data/AllData.h"

GameLogic::GameLogic(Scene* currentscene)
{
	//将当前关卡敌人波次进行复制
	for (int i = 0; i < EnemyWave[0].size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < EnemyWave[0][0].size(); j++) {
			one.push_back(EnemyWave[CurrentLevel - 1][i][j]);
		}
		this->enemywave.push_back(one);
	}

	this->currentwave = 0;
	this->gametimer1 = 0;
	this->gametimer2 = 0;
	this->scece = currentscene;
	this->victoryorfail = 0;
	this->scheduleUpdate();
}

void GameLogic::update(float update_time)
{
	//判断胜负
	if (BaseHP == 0) {
		victoryorfail = -1;
	}
	else {
		if (killednum == allenemynum) {
			victoryorfail = 1;
		}
	}
	
	//依据波次出现敌人
	if (currentwave != enemywave.size()) {
		if (gametimer1 < enemywave[currentwave][0]) {
			gametimer1 += update_time;
		}
		else {
			if (gametimer2 < 1) {
				gametimer2 += update_time;
			}
			else {
				switch (enemywave[currentwave][1]) {
				case 0: {
					auto newenemy = new Alphaworm;
					AllEnemy.push_back(newenemy);
					Allenemy.push_back(newenemy->AlphawormSprite);
					this->addChild(newenemy->AlphawormSprite);
					this->addChild(newenemy->AlphawormBar);
					this->addChild(newenemy->AlphawormBlood);
					break;
				}
				default:
					break;
				}
				gametimer2 = 0;
				enemywave[currentwave][2]--;
				if (enemywave[currentwave][2] == 0) {
					currentwave++;
					gametimer1 = 0;
				}
			}
		}
	}
}