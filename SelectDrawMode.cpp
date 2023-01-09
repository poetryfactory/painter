#include"Global.h"

bool drawingMode = 1;

void SelectMode()               //选择键鼠绘图模式
{
	while (menuL[6].isActivated)
	{
		ClearMenu();
		setcolor(YELLOW);
		outtextxy(10, 20, "**选择绘制模式**");
		/*outtextxy(10, 40, "1.键盘绘画");
		outtextxy(10, 60, "2.鼠标绘画(若多边形，只可以此画封闭多边形)");*/
		StoreButton(buttonArray, 5);
		ButtonLogic(5);
		switch (pressedButtonID)
		{
		case 0:            //键盘
		{
			drawingMode = 0;
			Draw1(shapeVal);
			break;
		}
		case 1:        //鼠标
		{
			drawingMode = 1;
			Draw1(shapeVal);
			break;
		}
		case 2:        //返回
		{
			Return();
			break;
		}
		default:
		{
			ClearMenu();
			outtextxy(10, 20, "输入有误，请重新输入");
			delay_ms(1000);
		}
		}

	}

}