#include "GameBeginScene.h"
#include "GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

USING_NS_CC;

const std::vector<std::string> buttonLabels = { "New Game",
                                                "Continue Game",
                                                "Game Over" };

const int fontSize = 72;

Scene* GameBegin::createScene()
{
    return GameBegin::create();
}

bool GameBegin::init()
{
    //��������
    unsigned seed = time(0);
    srand(seed);

    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //����ͼ
    auto sprite = Sprite::create("pictures/Interface.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(sprite, 0);

    //New Gameͼ��
    auto NewGamelabel = Label::createWithTTF(buttonLabels[0], "fonts/Marker Felt.ttf", fontSize);
    NewGamelabel->setColor(Color3B::BLACK);
    auto NewGamemenuitem = MenuItemLabel::create(NewGamelabel, [=](Ref* sender) {menuNewGameCallback(sender); });
    auto NewGamemenu = Menu::create(NewGamemenuitem, nullptr);
    NewGamemenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 + 50);
    this->addChild(NewGamemenu,1);

    //Continue Gameͼ��
    auto ContinueGamelabel = Label::createWithTTF(buttonLabels[1], "fonts/Marker Felt.ttf", fontSize);
    ContinueGamelabel->setColor(Color3B::BLACK);
    auto ContinueGamemenuitem = MenuItemLabel::create(ContinueGamelabel, [=](Ref* sender) {menuContinueGameCallback(sender); });
    auto ContinueGamemenu = Menu::create(ContinueGamemenuitem, nullptr);
    ContinueGamemenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 - 50);
    this->addChild(ContinueGamemenu, 1);

    //Game Overͼ��
    auto GameOverlabel = Label::createWithTTF(buttonLabels[2], "fonts/Marker Felt.ttf", fontSize);
    GameOverlabel->setColor(Color3B::BLACK);
    auto GameOvermenuitem = MenuItemLabel::create(GameOverlabel, [=](Ref* sender) {menuCloseCallback(sender); });
    auto GameOvermenu = Menu::create(GameOvermenuitem, nullptr);
    GameOvermenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 - 150);
    this->addChild(GameOvermenu, 1);

    //Arknights��Ϸͼ��
    auto label = Label::createWithTTF("Arknights", "fonts/Marker Felt.ttf", 150);
    label->setPosition(Vec2(origin.x + visibleSize.width / 4 * 3, origin.y + visibleSize.height / 4 * 3));
    this->addChild(label, 1);
    
    //��������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);

    return true;
}


void GameBegin::menuNewGameCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(GameplayMenu::create());
}

void GameBegin::menuContinueGameCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(GameplayMenu::create());
}

void GameBegin::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}
