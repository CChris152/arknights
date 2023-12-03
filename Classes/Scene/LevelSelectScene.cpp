#include "LevelSelectScene.h"
#include "Data/AllData.h"
#include "Level1MapScene.h"
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

    //�ȴ��������Ĺؿ�ͼƬ��Ȼ������ӽ�����ͼƬ��ť
    auto UnlockedLevel2 = Sprite::create("pictures/UnlockedLevel2.jpg");
    UnlockedLevel2->setPosition(Vec2(origin.x + visibleSize.width / 2 + 300 , origin.y + visibleSize.height / 4 * 3));
    this->addChild(UnlockedLevel2, 0);
   
    auto UnlockedLevel3 = Sprite::create("pictures/UnlockedLevel3.jpg");
    UnlockedLevel3->setPosition(Vec2(origin.x + visibleSize.width / 2 + 600, origin.y + visibleSize.height / 4 * 3));
    this->addChild(UnlockedLevel3, 0);

    //�����ڹؿ�1ͼ��
    auto Level1Button = MenuItemImage::create("pictures/Level1.png", "pictures/Level1.png", CC_CALLBACK_1(LevelSelect::menuToLevel1Callback, this));
    float x = origin.x + visibleSize.width / 2;
    float y = origin.y + visibleSize.height / 4 * 3;
    Level1Button->setPosition(Vec2(x, y));
    auto level1menu = Menu::create(Level1Button, NULL);
    level1menu->setPosition(Vec2::ZERO);
    this->addChild(level1menu, 1);

    //�����ڹؿ�2ͼ��
    if (levelnum >= 1) {
        auto Level2Button = MenuItemImage::create("pictures/Level2.png", "pictures/Level2.png", CC_CALLBACK_1(LevelSelect::menuCloseCallback, this));
        float x = origin.x + visibleSize.width / 2 + 300;
        float y = origin.y + visibleSize.height / 4 * 3;
        Level2Button->setPosition(Vec2(x, y));
        auto level2menu = Menu::create(Level2Button, NULL);
        level2menu->setPosition(Vec2::ZERO);
        this->addChild(level2menu, 1);
    }

    //�����ڹؿ�3ͼ��
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

    //����ͼ
    auto levelselect = Sprite::create("pictures/LevelSelect.png");
    levelselect->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(levelselect, 0);

    ////�����˳�ͼ��
    auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(LevelSelect::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2, origin.y + closeItem->getContentSize().height / 2));
    auto closemenu = Menu::create(closeItem, NULL);
    closemenu->setPosition(Vec2::ZERO);
    this->addChild(closemenu, 0);

    //ͨ����ͬ�Ĺ�������Ӳ�ͬ�Ĺؿ�
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

    //��������
    if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == 0) {
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);
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