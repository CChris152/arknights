#include "AllData.h"

int Jade = 1000;

int FinishLevelNum = 2;
int CurrentLevel = -1;

int expenses = 0;
int BaseHP;
int allenemynum;
int killednum = 0;

std::vector<int> CardsNum = { 0 };
std::vector<int> LackCards = { 1, 2, 3 };
std::vector<std::string> OperatorName = { "Exusiai","Hongxue","Qiubai","Eyjafjalla" };

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
std::vector<std::vector<int>> Level1Road = { {1635,510,-1,0},   //解释：前两位为坐标，后两位为方向向量
                                             {1155,510,0,1},
                                             {1155,650,-1,0},
                                             {835,650,0,-1},
                                             {835,510,-1,0},
                                             {515,510,0,1},
                                             {515,650,-1,0},
                                             {355,650,0,0} };
std::vector<std::vector<int>> Level1EnemyWave = { {5,0,1}, {6,0,2}, {10,0,3}, {15,0,4} ,{25,1,1} }; //解释：第一个数字为间隔秒数，第二个数字为敌人种类，第三个数字为敌人数量

std::vector<std::vector<int>> Level2vec = { { 1, 1, 1, 1, 1, 1, 1, 1},
                                            { 1, 0, 0, 1, 0, 0, 0, 0},
                                            { 0, 0, 0, 0, 0, 1, 1, 0},
                                            { 1, 1, 1, 1, 1, 1, 1, 0} };
std::vector<std::vector<int>> Level2Road = { {253,525,1,0},
                                             {1078,525,0,1},
                                             {1078,665,1,0},
                                             {1573,665,0,-1},
                                             {1573,245,0,0} };
std::vector<std::vector<int>> Level2Fly = { {253,665},{1573,245} }; //飞行路径只记录坐标，不记录方向。
std::vector<std::vector<int>> Level2EnemyWave = { {5,0,1}, {6,0,2}, {10,0,3}, {5,2,1}, {10,0,4}, {5,2,2}, {15,1,1} };

std::vector<std::vector<int>> Level3vec = { { -1, 1, 1, 1, 1, 1, 1, 1},
                                            { -1, 0, 0, 0, 0, 0, 0, 1},
                                            { 0, 0, 0, 1, 1, 0, 0, 0},
                                            { 0, 0, 1, 1, 1, 1, 0, 0},
                                            { -1, 1, 1, 1, 1, 1, 1, 1} };
std::vector<std::vector<int>> Level3Road = { {268,460,1,0},
                                             {618,460,0,1},
                                             {618,740,1,0},
                                             {1403,740,0,-1},
                                             {1403,460,1,0},
                                             {1753,460,0,0} };
std::vector<std::vector<int>> Level3Fly = { {238,880},{588,880},{1723,460} };
std::vector<std::vector<int>> Level3EnemyWave = { {5,0,1}, {2,2,1}, {4,0,2},{10,1,1}, {10,0,6}, {5,2,4} ,{10,1,5} };

std::vector<std::vector<int>> AllBaseVec = { {355,650},{1573,245} ,{1723,460} };

Vec2 Level1MapTransform(int i, int j)
{
    return Vec2(j * 160.0f + 515, 790.0f - i * 140);
}

Vec2 Level2MapTransform(int i, int j)
{
    switch (i)
    {
    case 0:
        return Vec2(j * 155.0f + 418, 805.0f - i * 140);
        break;
    case 1:
        return Vec2(j * 160.0f + 418, 805.0f - i * 140);
        break;
    case 2:
        return Vec2(j * 165.0f + 418, 805.0f - i * 140);
        break;
    case 3:
        return Vec2(j * 170.0f + 418, 805.0f - i * 140);
        break;
    default:
        break;
    }
}

//j * 165.0f + 418, 805.0f - i * 140

Vec2 Level3MapTransform(int i, int j)
{
    switch (i)
    {
    case 0:
        return Vec2(j * 143.0f + 490, 850);
        break;
    case 1:
        return Vec2(j * 150.0f + 470, 715);
        break;
    case 2:
        return Vec2(j * 156.0f + 445, 590);
        break;
    case 3:
        return Vec2(j * 165.0f + 415, 450);
        break;
    case 4:
        return Vec2(j * 180.0f + 360, 300);
        break;
    default:
        break;
    }
    //return Vec2(j * 160.0f + 420.5f, 870.0f - i * 132);
}

//j * 160.0f + 420.5f, 870.0f - i * 132