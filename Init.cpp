#include"Global.h"
PIMAGE image;

int lineWidth = 1;
char sWidth[20];
char mousep[30];


void Init()              //��ʼ��
{
	bool error = false;
	initgraph(1280, 960);         //���ɴ���
	image = newimage();          //��ʼ������
	setcolor(ege::COLORS::YELLOW);   //��ʼ��ɫ
	setbkmode(TRANSPARENT);
	setcaption("����"); //���ô��ڵı��⣬stringΪҪ��ʾ�ı��⡣
	char width[3];
	do
	{
		delay_ms(0);
		inputbox_getline("ѡ���߿�", "��ѡ��滭�߿�����һ��1-99�������Լ���������Ĭ��Ϊ1", width, 3);
		for (int i = 0;i < strlen(width);i++)
			if ((width[i] < '0' || width[i]>'9') && width[i]!=' ')
			{
				for (int j = 0;j < sizeof(width);j++)
					width[j] = ' ';
				ClearMenu();
				outtextxy(10, 20, "��������,����������");
				delay_ms(10);
				error = true;
				break;
			}
			else
				error = false;
	} while (error);
	lineWidth = atoi(width);
	setfont(18, 0, "����");  //��
	sprintf(sWidth, "��ǰ�߿�:%d", lineWidth);
	outtextxy(1000, 0, sWidth);
}

void InitGraph()          //���ɻ���
{
	ClearMenu();
	menuKey = 1;
	Menu();
	setcolor(ege::COLORS::YELLOW);
	setlinewidth(2);
	rectangle(0, 200, 1280, 960);      //�߿�
	setlinewidth(lineWidth);          //�滭�߿�
}