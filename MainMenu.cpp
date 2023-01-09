#include"Global.h"

void MainMenu()      //主菜单
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
		case 0:     //清屏
		{
			clearviewport();
			isRead = false;
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			ClearStorage();
			MainMenu();
			break;
		}
		case 1:       //作画
		{
			ClearMenu();
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			NextMenu();
			break;
		}
		case 2:      //查询
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			Search();
			break;
		}
		case 3:      //保存
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			SaveAsFile();
			break;
		}
		case 4:   //退出
		{
			buttonArray[pressedButtonID].pressed = false;
			pressedButtonID = BUTTON_ID_NONE;
			Return();
			break;
		}
		}
	}
}