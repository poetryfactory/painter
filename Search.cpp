#include "Global.h"

void Search()
{
	ClearMenu();
	bool error = false;
	char* shape = new char;
	char output[100];
	int cnt = 0;
	if (!globalBuffer.empty())
	{
		outtextxy(10, 20, "请选择您要查询的图形");
		outtextxy(10, 40, "1.圆形");
		outtextxy(10, 60, "2.矩形");
		outtextxy(10, 80, "3.线");
		outtextxy(10, 100, "4.多边形");
		char a = getch();
		switch (a)
		{
		case '1':
		{
			strcpy(shape, "圆形");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Circle)
				{
					cnt++;
				}
			}
			break;
		}
		case'2':
		{
			strcpy(shape, "矩形");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Tangle)
				{
					cnt++;
				}
			}
			break;
		}
		case'3':
		{
			strcpy(shape, "线");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Line)
				{
					cnt++;
				}
			}
			break;
		}
		case'4':
		{
			strcpy(shape, "多边形");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Poly)
				{
					cnt++;
				}
			}
			break;
		}
		}
		ClearMenu();
		sprintf(output, "您所查询的画板中的%s图形共有%d个", shape, cnt);
		outtextxy(10, 40, output);
	}
	else
	{
		outtextxy(10, 40, "您还未作画哦！");
	}
	outtextxy(10, 60,"画板将在3s后返回主菜单");
	delay_ms(1000);
	ClearMenu();
	outtextxy(10, 60,"画板将在2s后返回主菜单");
	delay_ms(1000);
	ClearMenu();
	outtextxy(10, 60,"画板将在1s后返回主菜单");
	delay_ms(1000);
}