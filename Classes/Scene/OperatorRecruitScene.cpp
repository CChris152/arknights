#include "OperatorRecruitScene.h"
#include "GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool OperatorRecruit::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void OperatorRecruit::menuBackCallback(cocos2d::Ref* pSender)
{
	//¹ØÍ£ÒôÀÖ
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameplayMenu::create());
}

void OperatorRecruit::menuRecruitCallback(cocos2d::Ref* pSender)
{

}