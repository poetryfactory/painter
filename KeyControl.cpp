#include"Global.h"

bool keyIsPressed[256] = { false };

bool unDoDetect(key_msg msg)
{
	while (kbmsg()) 
	{
		msg = getkey();
		if (msg.msg == key_msg_down) 
		{
			if (!keyIsPressed[msg.key])      //�̰� 
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
				//�����ж�
			}
			keyIsPressed[msg.key] = true;
		}
		else if (msg.msg == key_msg_up)
		{
			//̧���ж�
			keyIsPressed[msg.key] = false;
		}
	}
}
