#include"Global.h"

int colors[5] = { 0xa80000,0x0000a8,0x00a800,0xa800a8,0xfcfc54 };
bool isSettingColor = 0;
int color = 0;
int fillColor = 0;
bool isSettingFLColor = 0;

void SelectFLColor()    //设置填充颜色(仅填充模式)
{
	if (menuL[5].isActivated)
	{
		ClearMenu();
		menuKey = 2;
		Menu();
		outtextxy(10, 20, "**颜色(填充)**");
		ButtonLogic(2);
		switch (pressedButtonID)
		{
		case 0:
		{
			/*setcolor(RED);*/
			fillColor = 0;
			isSettingFLColor = 1;
			menuKey = 4;
			break;
		}
		case 1:
		{
			//setcolor(BLUE);
			fillColor = 1;
			isSettingFLColor = 1;
			menuKey = 4;
			break;
		}
		case 2:
		{
			//setcolor(GREEN);
			fillColor = 2;
			isSettingFLColor = 1;
			menuKey = 4;
			break;
		}
		case 3:
		{
			//setcolor(MAGENTA);
			fillColor = 3;
			isSettingFLColor = 1;
			menuKey = 4;
			break;
		}
		case 4:
		{
			//setcolor(YELLOW);
			fillColor = 4;
			isSettingFLColor = 1;
			menuKey = 4;
			break;
		}
		case 6:
		{
			Return();
			break;
		}
		case 5:
		{
			isSettingFLColor = 0;
			ClearMenu();
			outtextxy(10, 20, "默认为您选择了随机颜色");
			delay_ms(1000);
			menuKey = 4;
		}
		}
		NextMenu();
	}
	else Return();


}

void SelectColor()    //设置边线颜色
{
	if (menuL[2].isActivated)
	{
		menuKey = 2;
		Menu();
		ButtonLogic(2);
		switch (pressedButtonID)
		{
		case 0:
		{
			/*setcolor(RED);*/
			color = 0;
			isSettingColor = 1;
			break;
		}
		case 1:
		{
			//setcolor(BLUE);
			color = 1;
			isSettingColor = 1;
			break;
		}
		case 2:
		{
			//setcolor(GREEN);
			color = 2;
			isSettingColor = 1;
			break;
		}
		case 3:
		{
			//setcolor(MAGENTA);
			color = 3;
			isSettingColor = 1;
			break;
		}
		case 4:
		{
			//setcolor(YELLOW);
			color = 4;
			isSettingColor = 1;
			break;
		}
		case 6:
		{
			Return();
			break;
		}
		case 5:
		{
			isSettingColor = 0;
			ClearMenu();
			outtextxy(10, 20, "默认为您选择了随机颜色");
			delay_ms(1000);
			break;
		}
		}
		NextMenu();
	}
	else
		Return();

}