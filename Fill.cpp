#include"Global.h"


void IsFilled()          //ѡ�����ģʽ
{
	ClearMenu();
	menuKey = 4;
	Menu();
	if (menuL[4].isActivated)
	{
		ButtonLogic(4);
		switch (pressedButtonID)
		{
		case 0:        //�����ģʽ
		{
			isFillingMode = 0;
			break;
		}
		case 1:       //���ģʽ
		{
			isFillingMode = 1;
			break;
		}
		case 2:      //����
		{
			Return();
			break;
		}
		default:
		{
			isFillingMode = 0;
			ClearMenu();
			outtextxy(10, 20, "Ĭ��Ϊ��ѡ���˲����");
			delay_ms(1000);
			break;
		}
		}
		NextMenu();
	}
	else Return();

}