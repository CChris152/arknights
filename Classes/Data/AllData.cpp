#include "AllData.h"

int FinishLevelNum = 0;
int CurrentLevel = -1;

int Maptime = 0;
int expenses = 0;
int BaseHP;
int allenemynum;
int killednum = 0;

std::vector<std::string> Cards = { "Exusiai" };
std::vector<Sprite*> CardsSpr;
std::vector<int> CardsExpenses = { 12 };

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

std::vector<std::vector<std::vector<int>>> EnemyWave = { {{5,0,1}, {6,0,2}, {10,0,3}, {15,0,4}} }; //解释：第一个数字为间隔秒数，第二个数字为敌人种类，第三个数字为敌人数量