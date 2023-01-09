#include"Global.h"
PIMAGE image;

int lineWidth = 1;
char sWidth[20];
char mousep[30];


void Init()              //初始化
{
	bool error = false;
	initgraph(1280, 960);         //生成窗口
	image = newimage();          //初始化对象
	setcolor(ege::COLORS::YELLOW);   //初始颜色
	setbkmode(TRANSPARENT);
	setcaption("画板"); //设置窗口的标题，string为要显示的标题。
	char width[3];
	do
	{
		delay_ms(0);
		inputbox_getline("选择线宽", "请选择绘画线宽，输入一个1-99的整数以继续，程序默认为1", width, 3);
		for (int i = 0;i < strlen(width);i++)
			if ((width[i] < '0' || width[i]>'9') && width[i]!=' ')
			{
				for (int j = 0;j < sizeof(width);j++)
					width[j] = ' ';
				ClearMenu();
				outtextxy(10, 20, "输入有误,请重新输入");
				delay_ms(10);
				error = true;
				break;
			}
			else
				error = false;
	} while (error);
	lineWidth = atoi(width);
	setfont(18, 0, "宋体");  //字
	sprintf(sWidth, "当前线宽:%d", lineWidth);
	outtextxy(1000, 0, sWidth);
}

void InitGraph()          //生成画布
{
	ClearMenu();
	menuKey = 1;
	Menu();
	setcolor(ege::COLORS::YELLOW);
	setlinewidth(2);
	rectangle(0, 200, 1280, 960);      //边框
	setlinewidth(lineWidth);          //绘画线宽
}