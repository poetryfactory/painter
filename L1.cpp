#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include<math.h>

char m1,m2,color,shape;
int key = 0;		  //��˵�
int centerX ,centerY ;//�����
int mouseX , mouseY ; //�����
int radius;
void Init()
{
	initgraph(640, 480);
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfont(18, 0, "����");
}

void Clear()
{
	outtextxy(10, 20, "                                                ");
	outtextxy(10, 40, "                                                ");
	outtextxy(10, 60, "                                                ");
	outtextxy(10, 80, "                                                ");
	outtextxy(10, 100, "                                                ");
	outtextxy(10, 120, "                                                ");
}

void Menu()
{
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	outtextxy(10, 0, "��ӭ������Mickey���壬����ݲ˵�ѡ��������еĲ�����");
	if (key == 0) //ģ��1
	{
		outtextxy(10, 20, "1.��ȡ�ļ�");
		outtextxy(10, 40, "2.����ȡ�ļ�");
		outtextxy(10, 60, "����������ѡ��");
	}
	else if (key == 1) //ģ��2
	{
		outtextxy(10, 20, "1.�����Ļ");
		outtextxy(10, 40, "2.����");
		outtextxy(10, 60, "3.�˳�");
		outtextxy(10, 80, "����������ѡ��");
	}
	else if (key == 2) //ģ��2_2_1 ��ɫ
	{
		outtextxy(10, 20, "��ɫ");
		outtextxy(10, 40, "1.��");
		outtextxy(10, 60, "2.��");
		outtextxy(10, 80, "3.��");
		outtextxy(10, 100, "4.��");
		outtextxy(10, 120, "5.��");
	}
	else if (key == 3)
	{
		outtextxy(10, 20, "ͼ��");
		outtextxy(10, 40, "1.Բ");
		outtextxy(10, 60, "2.����");
	}
	else if (key == 4)
	{
		int a = 0;
		outtextxy(10,20,"����Բ��λ��");
		while (radius == 0)
		{
			if (keystate(VK_LBUTTON))
			{
				mousepos(&centerX, &centerY);
				a = 1;
			}
			outtextxy(10, 40, "�����ڶ���λ�ã�ȷ���뾶��С");
			if (keystate(VK_LBUTTON) && a)
				mousepos(&mouseX, &mouseY);
			radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
		}
	}
}

void SelectColor()
{
	color = getch();
	switch (color)
	{
		case'1':
		{
			setcolor(RED);
			break;
		}
		case'2':
		{
			setcolor(BLUE);
			break;
		}
		case'3':
		{
			setcolor(GREEN);
			break;
		}
		case'4':
		{
			setcolor(MAGENTA);
			break;
		}
		case'5':
		{
			setcolor(YELLOW);
			break;
		}
	}
}

void SelectShape()
{
	shape = getch();
	switch (shape)
	{
	case'1':
	{
		Clear();
		key = 4;
		Menu();
		circle(centerX, centerY, radius);
		outtextxy(10, 20, "                                                ");
		outtextxy(10, 40, "                                                ");
		outtextxy(10, 60, "                                                ");
		outtextxy(10, 80, "                                                ");
		outtextxy(10, 100, "                                                ");
		outtextxy(10, 120, "                                                ");
		break;
	}
	}
}

void Module1()
{
	Menu();
	m1 = getch();
	cleardevice();
	if (m1 == '1')
	{
		outtextxy(10, 0, "�Ѷ�ȡ");
	}
	else if (m1 == '2')
	{
		outtextxy(10, 0, "δ��ȡ");
	}
	cleardevice();
	key = 1;
}

void Module2()
{
	while (m2 != '3')
	{
		centerX = 0, centerY = 0, mouseX = 0, mouseY = 0, radius = 0;
		key = 1;
		Menu();
		m2 = getch();
		switch (m2)
		{
			case'1':
			{
				clearviewport();
				key = 1;
				Menu();
				break;
			}
			case'2':
			{
				Clear();
				key = 2;
				Menu();
				SelectColor();
				Clear();
				key = 3;
				Menu();
				SelectShape();
				break;
			}
		}
	}
	
}

int main()
{
	Init();
	Module1();
	Module2();
	getch();
}