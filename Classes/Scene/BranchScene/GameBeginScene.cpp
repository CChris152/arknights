#include "GameBeginScene.h"
#include "GameplayMenu.h"
#include "Data/AllData.h"
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
    //更新种子
    unsigned seed = time(0);
    srand(seed);

    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //背景图
    auto sprite = Sprite::create("pictures/Interface.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(sprite, 0);

    //New Game图标
    auto NewGamelabel = Label::createWithTTF(buttonLabels[0], "fonts/Marker Felt.ttf", fontSize);
    NewGamelabel->setColor(Color3B::BLACK);
    auto NewGamemenuitem = MenuItemLabel::create(NewGamelabel, [=](Ref* sender) {menuNewGameCallback(sender); });
    auto NewGamemenu = Menu::create(NewGamemenuitem, nullptr);
    NewGamemenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 + 50);
    this->addChild(NewGamemenu,1);

    //Continue Game图标
    auto ContinueGamelabel = Label::createWithTTF(buttonLabels[1], "fonts/Marker Felt.ttf", fontSize);
    ContinueGamelabel->setColor(Color3B::BLACK);
    auto ContinueGamemenuitem = MenuItemLabel::create(ContinueGamelabel, [=](Ref* sender) {menuContinueGameCallback(sender); });
    auto ContinueGamemenu = Menu::create(ContinueGamemenuitem, nullptr);
    ContinueGamemenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 - 50);
    this->addChild(ContinueGamemenu, 1);

    //Game Over图标
    auto GameOverlabel = Label::createWithTTF(buttonLabels[2], "fonts/Marker Felt.ttf", fontSize);
    GameOverlabel->setColor(Color3B::BLACK);
    auto GameOvermenuitem = MenuItemLabel::create(GameOverlabel, [=](Ref* sender) {menuCloseCallback(sender); });
    auto GameOvermenu = Menu::create(GameOvermenuitem, nullptr);
    GameOvermenu->setPosition(visibleSize.width / 4 * 3 + 3, visibleSize.height / 2 - 150);
    this->addChild(GameOvermenu, 1);

    //Arknights游戏图标
    auto label = Label::createWithTTF("Arknights", "fonts/Marker Felt.ttf", 150);
    label->setPosition(Vec2(origin.x + visibleSize.width / 4 * 3, origin.y + visibleSize.height / 4 * 3));
    this->addChild(label, 1);
    
    //背景音乐
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);

    return true;
}

void GameBegin::datainit()
{
    //存档数据载入
    Jade = UserDefault::getInstance()->getIntegerForKey("Jade", 100);
    FinishLevelNum = UserDefault::getInstance()->getIntegerForKey("FinishLevelNum", 0);
    MaxBaseHP = UserDefault::getInstance()->getIntegerForKey("MaxBaseHP", 3);
    InitialExpenses = UserDefault::getInstance()->getIntegerForKey("InitialExpenses", 10);
    std::string cardsnum = UserDefault::getInstance()->getStringForKey("cardsnum", "s0");
    std::string lackcards = UserDefault::getInstance()->getStringForKey("lackcards", "s1234");
    GoodsSellout = UserDefault::getInstance()->getStringForKey("GoodsSellout", "0000");
    for (int i = 1; i < cardsnum.size(); i++) {
        CardsNum.push_back(static_cast<int> (cardsnum[i] - 48));
    }
    for (int i = 1; i < lackcards.size(); i++) {
        LackCards.push_back(static_cast<int> (lackcards[i] - 48));
    }
}

void GameBegin::menuNewGameCallback(cocos2d::Ref* pSender)
{
    //数据初始化
    UserDefault::getInstance()->setIntegerForKey("Jade", 100);
    UserDefault::getInstance()->setIntegerForKey("FinishLevelNum", 0);
    UserDefault::getInstance()->setIntegerForKey("MaxBaseHP", 3);
    UserDefault::getInstance()->setIntegerForKey("InitialExpenses", 10);
    UserDefault::getInstance()->setStringForKey("cardsnum", "s0");
    UserDefault::getInstance()->setStringForKey("lackcards", "s1234");
    UserDefault::getInstance()->setStringForKey("GoodsSellout", "0000");
    datainit();
    Director::getInstance()->replaceScene(GameplayMenu::create());
}

void GameBegin::menuContinueGameCallback(cocos2d::Ref* pSender)
{
    datainit();
    Director::getInstance()->replaceScene(GameplayMenu::create());
}

void GameBegin::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}
