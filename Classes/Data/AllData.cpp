#include "AllData.h"

int FinishLevelNum = 0;

int Maptime = 0; //��ͼ��ʱ��
int expenses = 0; //����
int BaseHP; //����Ѫ��
int allenemynum; //��������
int killednum = 0; //�����������

std::vector<std::string> Cards = { "Exusiai" }; //��Ա��Ƭ����
std::vector<Sprite*> CardsSpr; //��Ա��Ƭ����

std::vector<std::vector<int>> Level1vec = { { 1, 1, 1, 1, 1, 1, 1},
                                            { 0, 1, 0, 0, 0, 0, 0},
                                            { 0, 0, 0, 1, 0, 0, 0},
                                            { 1, 1, 1, 1, 1, 1, 1} };