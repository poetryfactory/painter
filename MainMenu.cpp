#include"Global.h"

void MainMenu()      //���˵�
{
	while (menuL[1].isActivated)
	{
		//if (kbmsg())
		//	kMsg = getkey();
		//if (kMsg.key == key_esc)
		//	break;
		InitGraph();
		delay_ms(0);
		ButtonLogic(1);
		switch (pressedButtonID)
		{
		case 0:     //����
		{
			clearviewport();
			isRead = false;
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			ClearStorage();
			MainMenu();
			break;
		}
		case 1:       //����
		{
			ClearMenu();
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			NextMenu();
			break;
		}
		case 2:      //��ѯ
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			Search();
			break;
		}
		case 3:      //����
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			SaveAsFile();
			break;
		}
		case 4:   //�˳�
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			Return();
			break;
		}
		}
	}
}