#include"Global.h"

bool isFillingMode = 0;
int currentMenuIndex = 0;
int menuKey = 0;

void Return()             //返回
{
	menuL[currentMenuIndex].isActivated = false;
	currentMenuIndex = menuL[currentMenuIndex].lIndex;
	if (currentMenuIndex == -1)
		closegraph();
	else
	{
		menuL[currentMenuIndex].isActivated = true;
		menuL[currentMenuIndex].currentFunc();
	}
}

void NextMenu()             //下一菜单
{
	menuL[currentMenuIndex].isActivated = false;
	if (currentMenuIndex == 4 && !isFillingMode)   //非填充不展示填充颜色菜单
		currentMenuIndex = 6;
	if (currentMenuIndex == 3 && shapeVal == 3)   //线 不需要选择是否填充
		currentMenuIndex = 6;
	else
		currentMenuIndex = menuL[currentMenuIndex].nIndex;
	menuL[currentMenuIndex].isActivated = true;
	menuL[currentMenuIndex].currentFunc();

}

void Menu()          //菜单UI
{
	delay_ms(0);
	setcolor(ege::COLORS::YELLOW);
	outtextxy(10, 0, "欢迎您进入画板，请根据菜单选择您想进行的操作：");
	if (menuKey == 0) //模块1
	{
		outtextxy(10, 20, "**是否读取文件**");
		StoreButton(buttonArray,0);
	}
	else if (menuKey == 1) //模块2
	{
		if (isRead == 0)
		{
			strings[1][0] = "清屏";
			strings[1][1] = "作画";
		}
		else
		{
			strings[1][0] = "重画";
			strings[1][1] = "继续作画";
		}
		StoreButton(buttonArray, 1);
	}
	else if (menuKey == 2) //模块2_2_1 颜色
	{
		outtextxy(10, 20, "**颜色(边线)(非法输入将默认选择随机)**");
		//outtextxy(10, 40, "1.红");
		//outtextxy(10, 60, "2.蓝");
		//outtextxy(10, 80, "3.绿");
		//outtextxy(10, 100, "4.紫");
		//outtextxy(10, 120, "5.黄");
		//outtextxy(10, 140, "6.随机");
		StoreButton(buttonArray, 2);
	}
	else if (menuKey == 3)  //图形
	{
		outtextxy(10, 20, "**图形**");
		/*outtextxy(10, 40, "1.圆");
		outtextxy(10, 60, "2.矩形");
		outtextxy(10, 80, "3.线");
		outtextxy(10, 100, "4.多边形");
		outtextxy(10, 120, "5.自由画");*/
		StoreButton(buttonArray, 3);
	}
	else if (menuKey == 4)  //填充
	{
		outtextxy(10, 20, "**是否填充**");
		/*outtextxy(10, 40, "1.不填充(只画边框)");
		outtextxy(10, 60, "2.填充");*/
		StoreButton(buttonArray, 4);
	}
}

void ClearMenu()         //清菜单
{
	setfillcolor(getbkcolor());
	bar(0, 0, 1280, 200);
	setcolor(YELLOW);
	outtextxy(1000, 0, sWidth);
	outtextxy(1000, 20, mousep);
}

Menus menuL[7] =                                    //菜单结构体初始化
{
	{0, 0, 1, ReadFile,true},             //{当前索引,返回索引,前进索引,函数指针,是否激活}
	{1,-1, 2, MainMenu,false},
	{2, 1, 3, SelectColor,false},
	{3, 1, 4, SelectShape,false},
	{4, 1, 5, IsFilled,false},
	{5, 1, 6, SelectFLColor,false},
	{6, 1, 6, SelectMode,false}
};


void Error()          //报错
{
	ClearMenu();
	outtextxy(10, 20, "您的输入有误，请在1s后重新输入:");
	delay_ms(1000);
	ClearMenu();
}

void ClearPos()
{
	setfillcolor(getbkcolor());
	bar(1000, 20, 1280, 40);
}