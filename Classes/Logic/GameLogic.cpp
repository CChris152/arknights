#include "GameLogic.h"
#include "Sprite/AlphawormEnemy.h"
#include "Data/AllData.h"

GameLogic::GameLogic(Scene* currentscene)
{
	this->gametimer = 0;
	this->scece = currentscene;
	this->scheduleUpdate();
}

void GameLogic::update(float update_time)
{
	if (this->gametimer <= 5) {
		this->gametimer += update_time;
	}
	if (this->gametimer >= 5) {
		Alphaworm* firstone = new Alphaworm;
		AllEnemy.push_back(firstone);
		this->addChild(firstone->AlphawormSprite);
		this->addChild(firstone->AlphawormLabel);
		this->gametimer = 0;
	}
}