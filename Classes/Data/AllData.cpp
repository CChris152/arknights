#include "AllData.h"

int FinishLevelNum = 0;

int Maptime = 0; //��ͼ��ʱ��
int expenses = 0; //����
int BaseHP; //����Ѫ��
int allenemynum; //��������
int killednum = 0; //�����������

std::vector<std::string> Cards = { "Exusiai" }; //��Ա��Ƭ����
std::vector<Sprite*> CardsSpr; //��Ա��Ƭ����