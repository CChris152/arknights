#include "LevelSelectScene.h"
#include "Data/AllData.h"
#include "Scene/FunctionScene/LevelMapScene.h"
#include "GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

USING_NS_CC;

void LevelSelect::setFinishLevelNum(int num)
{
    FinishLevelNum = num;
}

void LevelSelect::LevelCreate(int levelnum)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //先创建封锁的关卡图片，然后再添加解锁的图片按钮
    auto UnlockedLevel2 = Sprite::create("pictures/UnlockedLevel2.jpg");
    UnlockedLevel2->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300 , origin.y + visibleSize.height / 4 * 3));
    this->addChild(UnlockedLevel2, 0);
   
    auto UnlockedLevel3 = Sprite::create("pictures/UnlockedLevel3.jpg");
    UnlockedLevel3->setPosition(Vec2(origin.x + visibleSize.width / 2 + 600, origin.y + visibleSize.height / 4 * 3));
    this->addChild(UnlockedLevel3, 0);

    //创建第关卡1图标
    auto Level1Button = MenuItemImage::create("pictures/Level1.png", "pictures/Level1.png", CC_CALLBACK_1(LevelSelect::menuToLevel1Callback, this));
    float x = origin.x + visibleSize.width / 2;
    float y = origin.y + visibleSize.height / 4 * 3;
    Level1Button->setPosition(Vec2(x, y));
    auto level1menu = Menu::create(Level1Button, NULL);
    level1menu->setPosition(Vec2::ZERO);
    this->addChild(level1menu, 1);

    //创建第关卡2图标
    if (levelnum >= 1) {
        auto Level2Button = MenuItemImage::create("pictures/Level2.png", "pictures/Level2.png", CC_CALLBACK_1(LevelSelect::menuToLevel2Callback, this));
        float x = origin.x + visibleSize.width / 2 + 300;
        float y = origin.y + visibleSize.height / 4 * 3;
        Level2Button->setPosition(Vec2(x, y));
        auto level2menu = Menu::create(Level2Button, NULL);
        level2menu->setPosition(Vec2::ZERO);
        this->addChild(level2menu, 1);
    }

    //创建第关卡3图标
    if (levelnum >= 2) {
        auto Level3Button = MenuItemImage::create("pictures/Level3.png", "pictures/Level3.png", CC_CALLBACK_1(LevelSelect::menuToLevel3Callback, this));
        float x = origin.x + visibleSize.width / 2 + 600;
        float y = origin.y + visibleSize.height / 4 * 3;
        Level3Button->setPosition(Vec2(x, y));
        auto level3menu = Menu::create(Level3Button, NULL);
        level3menu->setPosition(Vec2::ZERO);
        this->addChild(level3menu, 1);
    }
}

bool LevelSelect::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //背景图
    auto levelselect = Sprite::create("pictures/LevelSelect.png");
    levelselect->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(levelselect, 0);

    //返回按钮
    auto back = MenuItemImage::create("pictures/Back.png", "pictures/Back.png", CC_CALLBACK_1(LevelSelect::menuBackCallback, this));
    back->setPosition(Vec2(origin.x + back->getContentSize().width / 2 + 70, visibleSize.height - back->getContentSize().height / 2 + origin.y - 25));
    auto backmenu = Menu::create(back, NULL);
    backmenu->setPosition(Vec2::ZERO);
    this->addChild(backmenu, 1);

    //通过不同的关数来添加不同的关卡
    LevelCreate(FinishLevelNum);

    //合成玉计数器
    auto JadeCount = Sprite::create("pictures/JadeCount.png");
    JadeCount->setPosition(visibleSize.width - 130, visibleSize.height - 60);
    this->addChild(JadeCount);
    auto JadeNum = Label::createWithTTF(std::to_string(Jade), "fonts/Marker Felt.ttf", 50);
    JadeNum->setPosition(visibleSize.width - 95, visibleSize.height - 65);
    JadeNum->setColor(Color3B::BLACK);
    this->addChild(JadeNum);

    //背景音乐
    if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == 0) {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);
    }

    return true;
}

void LevelSelect::menuBackCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(GameplayMenu::create());
}

void LevelSelect::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}

void LevelSelect::menuToLevel1Callback(cocos2d::Ref* pSender)
{
    CurrentLevel = 1;
    Director::getInstance()->replaceScene(LevelMap::create());
}

void LevelSelect::menuToLevel2Callback(cocos2d::Ref* pSender)
{
    CurrentLevel = 2;
    Director::getInstance()->replaceScene(LevelMap::create());
}

void LevelSelect::menuToLevel3Callback(cocos2d::Ref* pSender)
{
    CurrentLevel = 3;
    Director::getInstance()->replaceScene(LevelMap::create());
}