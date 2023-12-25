#include "CollectionBook.h"
#include "GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

bool CollectionBook::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void CollectionBook::menuBackCallback(cocos2d::Ref* pSender)
{
	//��ͣ����
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameplayMenu::create());
}
//��Ա����
void CollectionBook::OperatorOverview(cocos2d::Ref* pSender) {

}