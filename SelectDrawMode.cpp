#include"Global.h"

bool drawingMode = 1;

void SelectMode()               //ѡ������ͼģʽ
{
	while (menuL[6].isActivated)
	{
		ClearMenu();
		setcolor(YELLOW);
		outtextxy(10, 20, "**ѡ�����ģʽ**");
		/*outtextxy(10, 40, "1.���̻滭");
		outtextxy(10, 60, "2.���滭(������Σ�ֻ���Դ˻���ն����)");*/
		StoreButton(buttonArray, 5);
		ButtonLogic(5);
		switch (pressedButtonID)
		{
		case 0:            //����
		{
			drawingMode = 0;
			Draw1(shapeVal);
			break;
		}
		case 1:        //���
		{
			drawingMode = 1;
			Draw1(shapeVal);
			break;
		}
		case 2:        //����
		{
			Return();
			break;
		}
		default:
		{
			ClearMenu();
			outtextxy(10, 20, "������������������");
			delay_ms(1000);
		}
		}

	}

}