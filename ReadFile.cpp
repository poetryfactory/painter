#include"Global.h"

bool isRead = 0;
FILE* fp;
int size = 0;

void ReadFile()    //�ļ���ȡ�˵�
{
	ClearMenu();
	Menu();
	while (menuL[0].isActivated)
	{
		ButtonLogic(0);
		if (pressedButtonID == 0)
		{
			char file[100] = {};
			char ext[6] = ".draw";
			inputbox_getline("��ȡ�ļ�", "�����ļ����Զ�ȡ��ǰ��Ŀ�ļ��У��������·���Դ洢�������ļ��У�����Ҫ��Ӻ�׺��", file, 90);
			strcat(file, ext);
			fp = fopen(file, "r");
			if (fp!=NULL)
			{
				ClearMenu();
				outtextxy(10, 0, "��ȡ�ɹ�");
				isRead = 1;
				fscanf(fp, "%d", &size);
				for (int i = 0; i < size; i++)
				{
					Storage temp;
					fscanf(fp, "%d%d%d%d%d", 
						&temp.type, &temp.width, &temp.color,&temp.fill, &temp.fillColor);
					if (temp.type == Circle)
					{
						fscanf(fp, "%d%d%d", &temp.data[0], &temp.data[1], &temp.data[2]);
					}
					else if (temp.type == Tangle || temp.type == Line)
					{
						fscanf(fp, "%d%d%d%d", &temp.data[0], &temp.data[1], &temp.data[2],&temp.data[3]);
					}
					else if (temp.type == Poly)
					{
						fscanf(fp, "%d", &temp.data[0]);
						for (int i = 1;i <= 2*temp.data[0];i++)
						{
							fscanf(fp, "%d", &temp.data[i]);
						}
					}
					globalBuffer.push_back(temp);
				}
				fclose(fp);
				for (int j = 0;j < globalBuffer.size();j++)
				{
					DrawFromStorage(j, globalBuffer);
				}
			}
			else
			{
				ClearMenu();
				outtextxy(10, 0, "�ļ�������!��ȡʧ��");
				isRead = 0;
			}
			menuKey = 1;
			//delay_ms(2000);
		}
		else if (pressedButtonID == 1)
		{
			ClearMenu();
			outtextxy(10, 0, "δ��ȡ");
			isRead = 0;
			menuKey = 1;
			//delay_ms(2000);
		}
		else
		{
			Error();
			Return();
		}
		delay_ms(2000);
		NextMenu();

	}
	Return();
	//cleardevice();
}
