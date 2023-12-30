#include "AllData.h"

int Jade;
int FinishLevelNum;
int CurrentLevel = -1;
int MaxBaseHP;
int InitialExpenses;
std::string GoodsSellout;

int expenses = 0;
int BaseHP = 3;
int allenemynum;
int killednum = 0;
int victoryorfail = 0;

std::vector<int> CardsNum;
std::vector<int> LackCards;
std::vector<std::string> OperatorName = { "Exusiai","Hongxue","Qiubai","Eyjafjalla","Saria"};

std::vector<Card*> Cards;
std::vector<Enemy*> AllEnemy;
std::vector<Operator*> AllOperator;
std::vector<Sprite*> Allenemy;
std::vector<Sprite*> Alloperator;
std::vector<Sprite*> AttackEffect;

std::vector<std::vector<int>> Level1vec = { { 1, 1, 1, 1, 1, 1, 1},
                                            { 0, 1, 0, 0, 0, 0, 0},
                                            { 0, 0, 0, 1, 0, 0, 0},
                                            { 1, 1, 1, 1, 1, 1, 1} };
std::vector<std::vector<int>> Level1Road = { {1654,525}, {1162,525}, {1149,665}, {837,665}, {834,525}, {506,525}, {525,665}, {369,665} }; //节点坐标
std::vector<std::vector<int>> Level1EnemyWave = { {5,0,1}, {6,0,2}, {10,0,3}, {10,0,4} ,{10,1,1} }; //解释：第一个数字为间隔秒数，第二个数字为敌人种类，第三个数字为敌人数量

std::vector<std::vector<int>> Level2vec = { { 1, 1, 1, 1, 1, 1, 1, 1},
                                            { 1, 0, 0, 1, 0, 0, 0, 0},
                                            { 0, 0, 0, 0, 0, 1, 1, 0},
                                            { 1, 1, 1, 1, 1, 1, 1, 0} };
std::vector<std::vector<int>> Level2Road = { {242,525}, {1062,525}, {1059,665}, {1527,665}, {1599,245} };
std::vector<std::vector<int>> Level2Fly = { {242,665}, {1599,245} };
std::vector<std::vector<int>> Level2EnemyWave = { {5,0,1}, {6,0,2}, {7,2,3}, {5,3,1}, {7,0,4}, {5,1,2}, {10,3,1} };

std::vector<std::vector<int>> Level3vec = { { -1, 1, 1, 1, 1, 1, 1, 1},
                                            { -1, 0, 0, 0, 0, 0, 0, 1},
                                            { 0, 0, 0, 1, 1, 0, 0, 0},
                                            { 0, 0, 1, 1, 1, 1, 0, 0},
                                            { -1, 1, 1, 1, 1, 1, 1, 1} };
std::vector<std::vector<int>> Level3Road = { {250,450}, {580,450}, {620,715}, {1370,715}, {1405,450}, {1735,450} };
std::vector<std::vector<int>> Level3Fly = { {238,880},{588,880},{1723,460} };
std::vector<std::vector<int>> Level3Boss = { {250,450}, {580,450}, {620,715}, {770,715}, {757,590}, {601,590}, {620,715}, {770,715}, {757,590}, {601,590}, {620,715}, {1370,715}, {1405,450}, {1750,450} };
std::vector<std::vector<int>> Level3EnemyWave = { {5,0,1}, {2,2,1}, {4,0,2}, {3,3,1}, {10,1,1}, {10,0,3}, {5,2,4}, {5,1,2}, {3,3,1}, {10,1,3}, {10,-1,1}, {5,1,2}, {5,2,2}, {5,3,1}, {15,1,2}, {15,3,3} };

std::vector<std::vector<int>> AllBaseVec = { {355,650},{1573,245} ,{1723,460} };

Vec2 Level1MapTransform(int i, int j)
{
    switch (i)
    {
    case 0:
        return Vec2(j * 148.0f + 548.0f, 805.0f);
        break;
    case 1:
        return Vec2(j * 156.0f + 525.0f, 665.0f);
        break;
    case 2:
        return Vec2(j * 164.0f + 506.0f, 525.0f);
        break;
    case 3:
        return Vec2(j * 172.0f + 472.0f, 385.0f);
        break;
    default:
        break;
    }
}

Vec2 Level2MapTransform(int i, int j)
{
    switch (i)
    {
    case 0:
        return Vec2(j * 148.0f + 468.0f, 805.0f);
        break;
    case 1:
        return Vec2(j * 156.0f + 435.0f, 665.0f);
        break;
    case 2:
        return Vec2(j * 164.0f + 406.0f, 525.0f);
        break;
    case 3:
        return Vec2(j * 172.0f + 372.0f, 385.0f);
        break;
    default:
        break;
    }
}

Vec2 Level3MapTransform(int i, int j)
{
    switch (i)
    {
    case 0:
        return Vec2(j * 143.0f + 490.0f, 850.0f);
        break;
    case 1:
        return Vec2(j * 150.0f + 470.0f, 715.0f);
        break;
    case 2:
        return Vec2(j * 156.0f + 445.0f, 590.0f);
        break;
    case 3:
        return Vec2(j * 165.0f + 415.0f, 450.0f);
        break;
    case 4:
        return Vec2(j * 180.0f + 360.0f, 300.0f);
        break;
    default:
        break;
    }
}