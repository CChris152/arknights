#include "AllData.h"

int FinishLevelNum = 0;

int Maptime = 0; //地图计时器
int expenses = 0; //费用
int BaseHP; //基地血量
int allenemynum; //敌人总数
int killednum = 0; //消灭敌人数量

std::vector<std::string> Cards = { "Exusiai" }; //干员卡片名称
std::vector<Sprite*> CardsSpr; //干员卡片精灵

std::vector<std::vector<int>> Level1vec = { { 1, 1, 1, 1, 1, 1, 1},
                                            { 0, 1, 0, 0, 0, 0, 0},
                                            { 0, 0, 0, 1, 0, 0, 0},
                                            { 1, 1, 1, 1, 1, 1, 1} };