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