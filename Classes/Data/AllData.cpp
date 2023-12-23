#include "AllData.h"

int Jade = 100;

int FinishLevelNum = 2;
int CurrentLevel = -1;

int expenses = 0;
int BaseHP;
int allenemynum;
int killednum = 0;

std::vector<int> CardsNum = { 0 , 1 , 2 , 3};
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
std::vector<std::vector<int>> Level3Road = { {238,460,1,0},
                                             {588,460,0,1},
                                             {588,740,1,0},
                                             {1373,740,0,-1},
                                             {1373,460,1,0},
                                             {1723,460,0,0} };
std::vector<std::vector<int>> Level3Fly = { {238,880},{588,880},{1723,460} };
std::vector<std::vector<int>> Level3EnemyWave = { {5,0,1}, {2,2,1}, {4,0,2},{10,1,1}, {10,0,6}, {5,2,4} ,{10,1,5} };

std::vector<std::vector<int>> AllBaseVec = { {355,650},{1573,245} ,{1723,460} };

Vec2 Level1MapTransform(int i, int j)
{
    return Vec2(j * 160.0f + 515, 790.0f - i * 140);
}

Vec2 Level2MapTransform(int i, int j)
{
    return Vec2(j * 165.0f + 418, 805.0f - i * 140);
}

Vec2 Level3MapTransform(int i, int j)
{
    return Vec2(j * 160.0f + 420.5f, 870.0f - i * 132);
}