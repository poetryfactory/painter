#include"Global.h"


void IsFilled()          //选择填充模式
{
	ClearMenu();
	menuKey = 4;
	Menu();
	if (menuL[4].isActivated)
	{
		ButtonLogic(4);
		switch (pressedButtonID)
		{
		case 0:        //非填充模式
		{
			isFillingMode = 0;
			break;
		}
		case 1:       //填充模式
		{
			isFillingMode = 1;
			break;
		}
		case 2:      //返回
		{
			Return();
			break;
		}
		default:
		{
			isFillingMode = 0;
			ClearMenu();
			outtextxy(10, 20, "默认为您选择了不填充");
			delay_ms(1000);
			break;
		}
		}
		NextMenu();
	}
	else Return();

}