#include"Global.h"

bool isFillingMode = 0;
int currentMenuIndex = 0;
int menuKey = 0;

void Return()             //����
{
	menuL[currentMenuIndex].isActivated = false;
	currentMenuIndex = menuL[currentMenuIndex].lIndex;
	if (currentMenuIndex == -1)
		closegraph();
	else
	{
		menuL[currentMenuIndex].isActivated = true;
		menuL[currentMenuIndex].currentFunc();
	}
}

void NextMenu()             //��һ�˵�
{
	menuL[currentMenuIndex].isActivated = false;
	if (currentMenuIndex == 4 && !isFillingMode)   //����䲻չʾ�����ɫ�˵�
		currentMenuIndex = 6;
	if (currentMenuIndex == 3 && shapeVal == 3)   //�� ����Ҫѡ���Ƿ����
		currentMenuIndex = 6;
	else
		currentMenuIndex = menuL[currentMenuIndex].nIndex;
	menuL[currentMenuIndex].isActivated = true;
	menuL[currentMenuIndex].currentFunc();

}

void Menu()          //�˵�UI
{
	delay_ms(0);
	setcolor(ege::COLORS::YELLOW);
	outtextxy(10, 0, "��ӭ�����뻭�壬����ݲ˵�ѡ��������еĲ�����");
	if (menuKey == 0) //ģ��1
	{
		outtextxy(10, 20, "**�Ƿ��ȡ�ļ�**");
		StoreButton(buttonArray,0);
	}
	else if (menuKey == 1) //ģ��2
	{
		if (isRead == 0)
		{
			strings[1][0] = "����";
			strings[1][1] = "����";
		}
		else
		{
			strings[1][0] = "�ػ�";
			strings[1][1] = "��������";
		}
		StoreButton(buttonArray, 1);
	}
	else if (menuKey == 2) //ģ��2_2_1 ��ɫ
	{
		outtextxy(10, 20, "**��ɫ(����)(�Ƿ����뽫Ĭ��ѡ�����)**");
		//outtextxy(10, 40, "1.��");
		//outtextxy(10, 60, "2.��");
		//outtextxy(10, 80, "3.��");
		//outtextxy(10, 100, "4.��");
		//outtextxy(10, 120, "5.��");
		//outtextxy(10, 140, "6.���");
		StoreButton(buttonArray, 2);
	}
	else if (menuKey == 3)  //ͼ��
	{
		outtextxy(10, 20, "**ͼ��**");
		/*outtextxy(10, 40, "1.Բ");
		outtextxy(10, 60, "2.����");
		outtextxy(10, 80, "3.��");
		outtextxy(10, 100, "4.�����");
		outtextxy(10, 120, "5.���ɻ�");*/
		StoreButton(buttonArray, 3);
	}
	else if (menuKey == 4)  //���
	{
		outtextxy(10, 20, "**�Ƿ����**");
		/*outtextxy(10, 40, "1.�����(ֻ���߿�)");
		outtextxy(10, 60, "2.���");*/
		StoreButton(buttonArray, 4);
	}
}

void ClearMenu()         //��˵�
{
	setfillcolor(getbkcolor());
	bar(0, 0, 1280, 200);
	setcolor(YELLOW);
	outtextxy(1000, 0, sWidth);
	outtextxy(1000, 20, mousep);
}

Menus menuL[7] =                                    //�˵��ṹ���ʼ��
{
	{0, 0, 1, ReadFile,true},             //{��ǰ����,��������,ǰ������,����ָ��,�Ƿ񼤻�}
	{1,-1, 2, MainMenu,false},
	{2, 1, 3, SelectColor,false},
	{3, 1, 4, SelectShape,false},
	{4, 1, 5, IsFilled,false},
	{5, 1, 6, SelectFLColor,false},
	{6, 1, 6, SelectMode,false}
};


void Error()          //����
{
	ClearMenu();
	outtextxy(10, 20, "����������������1s����������:");
	delay_ms(1000);
	ClearMenu();
}

void ClearPos()
{
	setfillcolor(getbkcolor());
	bar(1000, 20, 1280, 40);
}