#include "LevelSelectScene.h"
#include "Data/AllData.h"
#include "Level1MapScene.h"

USING_NS_CC;

Scene* LevelSelect::createScene()
{
	return LevelSelect::create();
}

void LevelSelect::setFinishLevelNum(int num)
{
    FinishLevelNum = num;
}

void LevelSelect::LevelCreate(int levelnum)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //创建第关卡1图标
    auto Level1Button = MenuItemImage::create("pictures/Level1.png","pictures/Level1.png",CC_CALLBACK_1(LevelSelect::menuToLevel1Callback, this));
    float x = origin.x + visibleSize.width / 2;
    float y = origin.y + visibleSize.height / 4 * 3;
    Level1Button->setPosition(Vec2(x, y));
    auto level1menu = Menu::create(Level1Button, NULL);
    level1menu->setPosition(Vec2::ZERO);
    this->addChild(level1menu, 1);

    //创建第关卡2图标
    if (levelnum >= 1) {
        auto Level2Button = MenuItemImage::create("pictures/Level2.png", "pictures/Level2.png", CC_CALLBACK_1(LevelSelect::menuCloseCallback, this));

        float x = origin.x + visibleSize.width / 2 + 300;
        float y = origin.y + visibleSize.height / 4 * 3;
        Level2Button->setPosition(Vec2(x, y));

        auto level2menu = Menu::create(Level2Button, NULL);
        level2menu->setPosition(Vec2::ZERO);
        this->addChild(level2menu, 1);
    }

    //创建第关卡3图标
    if (levelnum >= 2) {
        auto Level3Button = MenuItemImage::create("pictures/Level3.png", "pictures/Level3.png", CC_CALLBACK_1(LevelSelect::menuCloseCallback, this));

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

    ////程序退出图标
    auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(LevelSelect::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));
    auto closemenu = Menu::create(closeItem, NULL);
    closemenu->setPosition(Vec2::ZERO);
    this->addChild(closemenu, 0);

    //通过不同的关数来添加不同的关卡
    switch (FinishLevelNum) { 
    case 0:
        LevelCreate(0);
        break;
    case 1:
        LevelCreate(1);
        break;
    case 2:
        LevelCreate(2);
        break;
    }
    return true;
}

void LevelSelect::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}

void LevelSelect::menuToLevel1Callback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(Level1Map::create());
}