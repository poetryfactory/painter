#include "Global.h"

void Search()
{
	ClearMenu();
	bool error = false;
	char* shape = new char;
	char output[100];
	int cnt = 0;
	if (!globalBuffer.empty())
	{
		outtextxy(10, 20, "��ѡ����Ҫ��ѯ��ͼ��");
		outtextxy(10, 40, "1.Բ��");
		outtextxy(10, 60, "2.����");
		outtextxy(10, 80, "3.��");
		outtextxy(10, 100, "4.�����");
		char a = getch();
		switch (a)
		{
		case '1':
		{
			strcpy(shape, "Բ��");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Circle)
				{
					cnt++;
				}
			}
			break;
		}
		case'2':
		{
			strcpy(shape, "����");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Tangle)
				{
					cnt++;
				}
			}
			break;
		}
		case'3':
		{
			strcpy(shape, "��");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Line)
				{
					cnt++;
				}
			}
			break;
		}
		case'4':
		{
			strcpy(shape, "�����");
			for (int i = 0;i < globalBuffer.size();i++)
			{
				if (globalBuffer[i].type == Poly)
				{
					cnt++;
				}
			}
			break;
		}
		}
		ClearMenu();
		sprintf(output, "������ѯ�Ļ����е�%sͼ�ι���%d��", shape, cnt);
		outtextxy(10, 40, output);
	}
	else
	{
		outtextxy(10, 40, "����δ����Ŷ��");
	}
	outtextxy(10, 60,"���彫��3s�󷵻����˵�");
	delay_ms(1000);
	ClearMenu();
	outtextxy(10, 60,"���彫��2s�󷵻����˵�");
	delay_ms(1000);
	ClearMenu();
	outtextxy(10, 60,"���彫��1s�󷵻����˵�");
	delay_ms(1000);
}