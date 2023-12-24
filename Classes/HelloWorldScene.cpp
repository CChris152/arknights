#include "HelloWorldScene.h"
#include "Scene/GameplayMenu.h"
#include "editor-support\cocostudio\SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    unsigned seed = time(0);
    srand(seed);

    if ( !Scene::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //¿ªÊ¼ÓÎÏ·Í¼±ê
    auto BeginButton = MenuItemImage::create("pictures/BeginButton.png","pictures/BeginButton.png",CC_CALLBACK_1(HelloWorld::menuNextCallback, this));
    if (BeginButton == nullptr ||
        BeginButton->getContentSize().width <= 0 ||
        BeginButton->getContentSize().height <= 0)
    {
        problemLoading("'pictures/BeginButton.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 4 * 3 +3;
        float y = origin.y + visibleSize.height / 2 + 3;
        BeginButton->setPosition(Vec2(x, y));
    }
    auto Beginmenu = Menu::create(BeginButton, NULL);
    Beginmenu->setPosition(Vec2::ZERO);
    this->addChild(Beginmenu, 1);

    //±³¾°Í¼
    auto sprite = Sprite::create("pictures/Interface.png");
    if (sprite == nullptr)
    {
        problemLoading("'pictures/Interface.png'");
    }
    else
    {
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(sprite, 0);
    }

    //¹Ø±Õ³ÌÐòÍ¼±ê
    auto closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    if (closeItem == nullptr || closeItem->getContentSize().width <= 0 || closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //ArknightsÓÎÏ·Í¼±ê
    auto label = Label::createWithTTF("Arknights", "fonts/Marker Felt.ttf", 150);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(Vec2(origin.x + visibleSize.width / 4 * 3,
            origin.y + visibleSize.height / 4 * 3));

        this->addChild(label, 1);
    }
    
    //±³¾°ÒôÀÖ
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musics/LifeFlow.mp3", true);

    return true;
}


void HelloWorld::menuNextCallback(cocos2d::Ref* pSender)
{
    auto nextScene = GameplayMenu::create();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1.0f / 60, nextScene));
}

void HelloWorld::menuCloseCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->end();
}
