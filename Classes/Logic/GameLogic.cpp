#include "GameLogic.h"
#include "Sprite/AlphawormEnemy.h"
#include "Sprite/SeagliderEnemy.h"
#include "Data/AllData.h"

GameLogic::GameLogic(Scene* currentscene)
{
	//����ǰ�ؿ����˲��ν��и���
	switch (CurrentLevel)
	{
	case 1:
		setEnemyWave(Level1EnemyWave);
		break;
	case 2:
		setEnemyWave(Level2EnemyWave);
	case 3:
		setEnemyWave(Level3EnemyWave);
	default:
		break;
	}

	this->currentwave = 0;
	this->gametimer1 = 0;
	this->gametimer2 = 0;
	this->scece = currentscene;
	this->victoryorfail = 0;
	this->scheduleUpdate();
}

void GameLogic::setEnemyWave(std::vector<std::vector<int>> EnemyWave)
{
	for (int i = 0; i < EnemyWave.size(); i++) {
		std::vector<int> one;
		for (int j = 0; j < EnemyWave[0].size(); j++) {
			one.push_back(EnemyWave[i][j]);
		}
		this->enemywave.push_back(one);
	}
}

void GameLogic::update(float update_time)
{
	//�ж�ʤ��
	if (BaseHP == 0) {
		victoryorfail = -1;
	}
	else {
		if (killednum == allenemynum) {
			victoryorfail = 1;
		}
	}
	
	//���ݲ��γ��ֵ���
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
				case 1: {
					auto newenemy = new Seaglider;
					AllEnemy.push_back(newenemy);
					Allenemy.push_back(newenemy->SeagliderSprite);
					this->addChild(newenemy->SeagliderSprite);
					this->addChild(newenemy->SeagliderBar);
					this->addChild(newenemy->SeagliderBlood);
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