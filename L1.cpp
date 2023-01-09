#define _CRT_SECURE_NO_WARNINGS
#include "graphics.h"
#include<math.h>

char m1,m2,color,shape;
int key = 0;		  //存菜单
int centerX ,centerY ;//存鼠标
int mouseX , mouseY ; //存鼠标
int radius;
void Init()
{
	initgraph(640, 480);
	setcolor(EGERGB(0xFF, 0xFF, 0x0));
	setfont(18, 0, "宋体");
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
	outtextxy(10, 0, "欢迎您进入Mickey画板，请根据菜单选择您想进行的操作：");
	if (key == 0) //模块1
	{
		outtextxy(10, 20, "1.读取文件");
		outtextxy(10, 40, "2.不读取文件");
		outtextxy(10, 60, "请输入您的选择：");
	}
	else if (key == 1) //模块2
	{
		outtextxy(10, 20, "1.清除屏幕");
		outtextxy(10, 40, "2.作画");
		outtextxy(10, 60, "3.退出");
		outtextxy(10, 80, "请输入您的选择：");
	}
	else if (key == 2) //模块2_2_1 颜色
	{
		outtextxy(10, 20, "颜色");
		outtextxy(10, 40, "1.红");
		outtextxy(10, 60, "2.蓝");
		outtextxy(10, 80, "3.绿");
		outtextxy(10, 100, "4.紫");
		outtextxy(10, 120, "5.黄");
	}
	else if (key == 3)
	{
		outtextxy(10, 20, "图形");
		outtextxy(10, 40, "1.圆");
		outtextxy(10, 60, "2.矩形");
	}
	else if (key == 4)
	{
		int a = 0;
		outtextxy(10,20,"请点击圆心位置");
		while (radius == 0)
		{
			if (keystate(VK_LBUTTON))
			{
				mousepos(&centerX, &centerY);
				a = 1;
			}
			outtextxy(10, 40, "请点击第二个位置，确定半径大小");
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
		outtextxy(10, 0, "已读取");
	}
	else if (m1 == '2')
	{
		outtextxy(10, 0, "未读取");
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