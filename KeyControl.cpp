#include"Global.h"

bool keyIsPressed[256] = { false };

bool unDoDetect(key_msg msg)
{
	while (kbmsg()) 
	{
		msg = getkey();
		if (msg.msg == key_msg_down) 
		{
			if (!keyIsPressed[msg.key])      //短按 
			{
				if (msg.key == 'U')
				{
					Undo();
					printf("U is pressed!");
				}
				else if (msg.key == 'R')
				{
					Redo();
					printf("R is pressed!");
				}
			}
			else
			{
				//长按判断
			}
			keyIsPressed[msg.key] = true;
		}
		else if (msg.msg == key_msg_up)
		{
			//抬起判断
			keyIsPressed[msg.key] = false;
		}
	}
}
