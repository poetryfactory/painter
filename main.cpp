#define SHOW_CONSOLE
#include"Global.h"
#include<math.h>
#include<string.h>
#include<stdio.h>


//typedef struct MenuList
//{
//	int curIndex;
//	int lIndex;
//	int nIndex;
//	void (*currentFunc)();
//	bool isActivated;
//
//} Menus;
//
//#pragma region ����
//int menuKey = 0;		  //��˵�ֵ
//mouse_msg mMsg;
//key_msg kMsg;
//int radius;
//int color = 0;
//int fillColor = 0;
//PIMAGE image;
//bool isSettingColor = 0;
//bool isSettingFLColor = 0;
//bool drawingMode = 1;
//bool isFillingMode = 0;
//int colors[5] = { 0xa80000,0x0000a8,0x00a800,0xa800a8,0xfcfc54 };
//int shapeVal = 0;
//int currentMenuIndex = 0;
//#pragma endregion
//
//
//#pragma region ��������
////��������
//void Init();
//void InitGraph();
//void ClearMenu();
//void Error();
//void Return();
//void NextMenu();
//void Menu();
//void SelectShape();
//void SelectColor();
//void SelectFLColor();
//void Draw1(int val);
//void DrawCircle();
//void DrawTangle();
////void DrawPolygon();
//void DrawLine();
//void FreeDrawing();
//void SelectMode();
//void IsFilled();
//void ReadFile();
//void MainMenu();
//void SaveAsFile();
////void FunctionStorage();
//#pragma endregion
//
//Menus menuL[7] =                                    //�˵��ṹ���ʼ��
//{
//	{0, 0, 1,ReadFile,true},             //{��ǰ����,��������,ǰ������,����ָ��,�Ƿ񼤻�}
//	{1,-1, 2,MainMenu,false},
//	{2, 1, 3,SelectColor,false},
//	{3, 1, 4,SelectShape,false},
//	{4, 1, 5,IsFilled,false},
//	{5, 1, 6,SelectFLColor,false},
//	{6, 1, 6, SelectMode,false}
//};
//
//#pragma region ������
//
//void Init()              //��ʼ��
//{
//	initgraph(1280, 960);
//	setcolor(ege::COLORS::YELLOW);
//	setfont(18, 0, "����");
//}
//
//void InitGraph()          //���ɻ���
//{
//	ClearMenu();
//	menuKey = 1;
//	Menu();
//	setcolor(ege::COLORS::YELLOW);
//	rectangle(0, 200, 1280, 845); 
//}
//
//void ClearMenu()         //��˵�
//{
//	setfillcolor(getbkcolor());
//	bar(0, 0, 1280, 200);
//}
//
//void Error()          //����
//{
//	ClearMenu();
//	outtextxy(10, 20, "����������������2s����������:");
//	delay_ms(2000);
//	ClearMenu();
//}
//
//void Return()             //����
//{
//	menuL[currentMenuIndex].isActivated = false;
//	currentMenuIndex = menuL[currentMenuIndex].lIndex;
//	if (currentMenuIndex == -1)
//		closegraph();
//	else
//	{
//		menuL[currentMenuIndex].isActivated = true;
//		menuL[currentMenuIndex].currentFunc();
//	}
//
//	
//}
//
//void NextMenu()             //��һ�˵�
//{
//	menuL[currentMenuIndex].isActivated = false;
//	if (currentMenuIndex == 4 && !isFillingMode)   //����䲻չʾ�����ɫ�˵�
//		currentMenuIndex = 6;
//	if (currentMenuIndex == 3 && shapeVal == 3)   //�� ����Ҫѡ���Ƿ����
//		currentMenuIndex = 6;
//	else
//		currentMenuIndex = menuL[currentMenuIndex].nIndex;
//	menuL[currentMenuIndex].isActivated = true;
//	menuL[currentMenuIndex].currentFunc();
//
//}
//
//void Draw1(int val)             //��ͼ
//{
//	menuL[6].isActivated = false;
//	switch (val)
//	{
//	case 1:
//	{
//		DrawCircle();
//		break;
//	}
//	case 2:
//	{
//		DrawTangle();
//		break;
//	}
//	case 3:
//	{
//		DrawLine();
//		break;
//	}
//	}
//}
//
//void DrawCircle()          //Բ
//{
//	int centerX=0, centerY=0;//Բ��
//	int mouseX=0, mouseY=0; //��뾶
//	while (1)
//	{
//		//mMsg = getmouse();
//		//if (mMsg.is_right()&&mMsg.is_down())
//		//{
//		//	printf("rB");
//		//	//break;
//		//}	
//		//else
//		//{
//			switch (drawingMode)
//			{
//			case 0:                            //����
//			{
//				char pos[30];
//				inputbox_getline("��Բ", "�밴���¸�ʽ��������:Բ��x Բ��y �뾶 (�뾶����0�Է���)", pos, 30);        
//				centerX = atoi(strtok(pos, " "));          //תint �и�
//				centerY = atoi(strtok(NULL, " "));
//				radius = atoi(strtok(NULL, " "));
//				if (centerY <= 200)
//					centerY = 205;
//				if (centerY - radius < 200)
//					radius = centerY - 200;
//				if (radius == 0)
//					Return();
//				break;
//			}
//			case 1:                              //���
//			{
//				ClearMenu();
//				setcolor(YELLOW);
//				outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
//				while (radius == 0)
//				{
//					mMsg = getmouse();
//					if (mMsg.is_left())
//					{
//						switch (mMsg.msg)
//						{
//						case mouse_msg_down:
//						{
//							if (!isSettingColor)   //δѡ����ɫ
//							{
//								setcolor(colors[random(4)]);
//							}
//							mousepos(&centerX, &centerY);
//							if (centerY < 200)        //�ݴ�
//							{
//								ClearMenu();
//								outtextxy(10, 0, "�������壬���Զ�����");
//								centerY = 205;
//							}
//							break;
//						}
//
//						case mouse_msg_up:
//						{
//							mousepos(&mouseX, &mouseY);
//							if (mouseY < 200)
//							{
//								ClearMenu();
//								outtextxy(10, 20, "�������壬���Զ�����");
//								mouseY = 205;
//							}
//							radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
//							break;
//						}
//						}
//					}	
//					if (mMsg.is_right() && mMsg.is_down())
//					{
//						Return();                //�Ҽ�����
//						break;
//					}
//						
//				}
//				break;
//			}
//			}
//			
//			
//
//			switch (isFillingMode)
//			{
//			case 0:
//			{
//				setcolor(colors[color]);
//				ege::circle(centerX, centerY, radius);
//				break;
//			}
//			case 1:
//			{
//				setfillcolor(colors[fillColor]);
//				setcolor(colors[color]);
//				ege::fillellipse(centerX, centerY, radius, radius);     //�����Բ�������Բ
//				break;
//			}
//
//			}
//			centerX = 0, centerY = 0, radius = 0;                      //���ò���
//		/*}*/
//		
//	}
//	//outtextxy(10, 20, "����Բ��λ��,�϶���겢�ɿ����ɻ���Բ,��backspace������");
//	//while (1)
//	//{
//	//	if (keystate(VK_BACK))
//	//		break;
//	//	mMsg = getmouse();
//
//	//	switch (mMsg.msg)
//	//	{
//	//	case mouse_msg_down:
//	//	{
//	//		if (!isSettingColor)   //δѡ����ɫ
//	//		{
//	//			setcolor(colors[random(4)]);
//	//		}
//	//		mousepos(&centerX, &centerY);
//	//		break;
//	//	}
//
//	//	case mouse_msg_up:
//	//	{
//	//		mousepos(&mouseX, &mouseY);
//	//		radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
//	//		setcolor(colors[color]);
//	//		circle(centerX, centerY, radius);
//	//		centerX = 0, centerY = 0, radius = 0;
//	//		break;
//	//	}
//	//	}
//	//}
//}
//
//void DrawLine()                  //����
//{
//	int beginMouseX=0, beginMouseY=0; //��ʼ��
//	int endMouseX=0, endMouseY=0; //��ֹ��
//	while (1)
//	{
//		switch (drawingMode)
//		{
//		case 0:
//		{
//			char pos[30];
//			inputbox_getline("����", "�밴���¸�ʽ��������:��ʼ��x ��ʼ��y ��ֹ��x ��ֹ��y (ȫ������0�Է���)", pos, 30);
//			beginMouseX = atoi(strtok(pos, " "));                  //תint �и�
//			beginMouseY = atoi(strtok(NULL, " "));
//			endMouseX = atoi(strtok(NULL, " "));
//			endMouseY = atoi(strtok(NULL, " "));
//			if (beginMouseY == 0 || endMouseY == 0)
//				Return();
//			break;
//		}
//		case 1:
//		{
//			ClearMenu();
//			setcolor(YELLOW);
//			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
//			while (((beginMouseY<200)||(endMouseY<200)))                  //δ����
//			{
//				mMsg = getmouse();
//				if (mMsg.is_left())
//				{
//					switch (mMsg.msg)
//					{
//					case mouse_msg_down:
//					{
//						if (!isSettingColor)   //δѡ����ɫ
//						{
//							setcolor(colors[random(4)]);
//						}
//						mousepos(&beginMouseX, &beginMouseY);
//						//printf("beginMouseX = %d", beginMouseX);     //������
//						//printf("beginMouseY = %d", beginMouseY);
//						if (beginMouseY < 200)     //�ݴ�
//						{
//							ClearMenu();
//							outtextxy(10, 20, "�������壬���Զ�����");
//							beginMouseY = 205;
//						}
//						break;
//					}
//
//					case mouse_msg_up:
//					{
//						mousepos(&endMouseX, &endMouseY);
//						printf("endMouseX = %d", beginMouseX);
//						printf("endMouseY = %d", beginMouseY);
//						if (endMouseY < 200)
//						{
//							ClearMenu();
//							outtextxy(10, 20, "�������壬���Զ�����");
//							endMouseY = 205;
//						}
//						break;
//					}
//					}
//				}
//				if (mMsg.is_right() && mMsg.is_down())
//				{
//					Return();
//				}
//			}
//		}
//		}
//				
//		setcolor(colors[color]);
//		ege::line(beginMouseX, beginMouseY, endMouseX, endMouseY);
//		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY=0;       //���ò���
//	}
//}
//
////void DrawPolygon()
////{
////	int beginMouseX = 0, beginMouseY = 0; //��ʼ��
////	int endMouseX = 0, endMouseY = 0; //��ֹ��
////FLAG2:
////	SelectMode();
////	while (!keystate(VK_BACK))
////	{
////		switch (drawingMode)
////		{
////		case 0:
////		{
////			char pos[30];
////			inputbox_getline("����", "�밴���¸�ʽ��������:��ʼ��x ��ʼ��y ��ֹ��x ��ֹ��y (ȫ������0�Է���)", pos, 30);
////			beginMouseX = atoi(strtok(pos, " "));
////			beginMouseY = atoi(strtok(NULL, " "));
////			endMouseX = atoi(strtok(NULL, " "));
////			endMouseY = atoi(strtok(NULL, " "));
////			if (beginMouseY == 0 || endMouseY == 0)
////				goto FLAG2;
////			break;
////		}
////		case 1:
////		{
////			ClearMenu();
////			setcolor(YELLOW);
////			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,��backspace������");
////			while (((beginMouseY < 200) || (endMouseY < 200)) && (!keystate(VK_BACK)))
////			{
////				mMsg = getmouse();
////				switch (mMsg.msg)
////				{
////				case mouse_msg_down:
////				{
////					if (!isSettingColor)   //δѡ����ɫ
////					{
////						setcolor(colors[random(4)]);
////					}
////					mousepos(&beginMouseX, &beginMouseY);
////					break;
////				}
////
////				case mouse_msg_up:
////				{
////					mousepos(&endMouseX, &endMouseY);
////					break;
////				}
////				}
////			}
////			break;
////		}
////		}
////		setcolor(colors[color]);
////		ege::line(beginMouseX, beginMouseY, endMouseX, endMouseY);
////		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;
////	}
////}
//
//void FreeDrawing()      //���ɻ�
//{
//	ClearMenu();
//	int MouseX = 0, MouseY = 0; //��ʼ��
//	while (!keystate(VK_BACK))
//		while(keystate(VK_LBUTTON))
//		{
//			if (!isSettingColor)   //δѡ����ɫ
//			{
//				setcolor(colors[random(4)]);
//			}
//			ege::mousepos(&MouseX, &MouseY);
//			putpixel(MouseX, MouseY,colors[color]);
//		}
//}
//
//void DrawTangle()          //����
//{
//	int beginMouseX = 0, beginMouseY = 0; //��ʼ��
//	int endMouseX = 0, endMouseY = 0; //��ֹ��
//	while (1)
//	{
//		switch (drawingMode)
//		{
//		case 0:
//		{
//			char pos[30];
//			inputbox_getline("������", "�밴���¸�ʽ��������:��ʼ��x ��ʼ��y ��ֹ��x ��ֹ��y (ȫ������0�Է���)", pos, 30);
//			beginMouseX = atoi(strtok(pos, " "));           //תint �и�
//			beginMouseY = atoi(strtok(NULL, " "));
//			endMouseX = atoi(strtok(NULL, " "));
//			endMouseY = atoi(strtok(NULL, " "));
//			if (beginMouseY == 0 || endMouseY == 0)
//				Return();
//			break;
//		}
//		case 1:
//		{
//			ClearMenu();
//			setcolor(YELLOW);
//			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
//			while ((beginMouseY < 200) || (endMouseY < 200))
//			{
//				mMsg = getmouse();
//				if (mMsg.is_left())
//				{
//					switch (mMsg.msg)
//					{
//					case mouse_msg_down:
//					{
//						if (!isSettingColor)   //δѡ����ɫ
//						{
//							setcolor(colors[random(4)]);
//						}
//						mousepos(&beginMouseX, &beginMouseY);
//						if (beginMouseY < 200)
//						{
//							ClearMenu();
//							outtextxy(10, 20, "�������壬���Զ�����");
//							beginMouseY = 205;
//						}
//						break;
//					}
//
//					case mouse_msg_up:
//					{
//						mousepos(&endMouseX, &endMouseY);
//						if (endMouseY < 200)
//						{
//							ClearMenu();
//							outtextxy(10, 20, "�������壬���Զ�����");
//							endMouseY = 205;
//						}
//						break;
//					}
//					}
//				}
//				if (mMsg.is_right() && mMsg.is_down())           //����
//				{
//					Return();
//					break;
//				}
//				
//			}
//			break;
//		}
//		}
//
//		switch (isFillingMode)
//		{
//		case 0:
//		{
//			setcolor(colors[color]);
//			ege::rectangle(beginMouseX, beginMouseY, endMouseX, endMouseY);
//			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;   //���ò���
//			break;
//		}
//		case 1:
//		{
//			setfillcolor(colors[fillColor]);
//			setcolor(colors[color]);
//			ege::bar3d(beginMouseX, beginMouseY, endMouseX, endMouseY,0,0);
//			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;    //���ò���
//			break;
//		}
//
//		}
//	}
//	//outtextxy(10, 20, "�������Ͻ�λ��,�϶���겢�ɿ����ɻ��ƾ���,��backspace������");
//	//while (1)
//	//{
//	//	if (keystate(VK_BACK))
//	//		break;
//	//	mMsg = getmouse();
//
//	//	switch (mMsg.msg)
//	//	{
//	//	case mouse_msg_down:
//	//	{
//	//		if (!isSettingColor)   //δѡ����ɫ
//	//		{
//	//			setcolor(colors[random(4)]);
//	//		}
//	//		mousepos(&beginMouseX, &beginMouseY);
//	//		break;
//	//	}
//
//	//	case mouse_msg_up:
//	//	{
//	//		mousepos(&endMouseX, &endMouseY);
//	//		setcolor(colors[color]);
//	//		rectangle(beginMouseX, beginMouseY, endMouseX, endMouseY);
//	//		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY;
//	//		break;
//	//	}
//	//	}
//	//}
//}
//
//void SelectMode()               //ѡ������ͼģʽ
//{
//	while (menuL[6].isActivated)
//	{
//		ClearMenu();
//		setcolor(YELLOW);
//		outtextxy(10, 20, "**ѡ�����ģʽ**");
//		outtextxy(10, 40, "1.���̻滭");
//		outtextxy(10, 60, "2.���滭");
//		char mode = getch();
//		switch (mode)
//		{
//		case'1':            //����
//		{
//			drawingMode = 0;
//			Draw1(shapeVal);
//			break;
//		}
//		case'2':        //���
//		{
//			drawingMode = 1;
//			Draw1(shapeVal);
//			break;
//		}
//		case'0':        //����
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			ClearMenu();
//			outtextxy(10, 20, "������������������");
//			delay_ms(1000);
//		}
//		}
//		
//	}
//
//}
//
//void IsFilled()          //ѡ�����ģʽ
//{
//	ClearMenu();
//	menuKey = 4;
//	Menu();
//	if (menuL[4].isActivated)
//	{
//		char res = getch();
//		switch (res)
//		{
//		case'1':        //�����ģʽ
//		{
//			isFillingMode = 0;
//			break;
//		}
//		case'2':       //���ģʽ
//		{
//			isFillingMode = 1;
//			break;
//		}
//		case'0':      //����
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			isFillingMode = 0;
//			ClearMenu();
//			outtextxy(10, 20, "Ĭ��Ϊ��ѡ���˲����");
//			delay_ms(1000);
//			break;
//		}
//		}
//		NextMenu();
//	}
//	else Return();
//	
//}
//
//void Menu()          //�˵�UI
//{
//	setcolor(ege::COLORS::YELLOW);
//	outtextxy(10, 0, "��ӭ�����뻭�壬����ݲ˵�ѡ��������еĲ�����(��0�������˵�,�����˵���0�˳�)");
//	if (menuKey == 0) //ģ��1
//	{
//		outtextxy(10, 20, "**��ȡ�ļ�**");
//		outtextxy(10, 40, "1.��ȡ�ļ�");
//		outtextxy(10, 60, "2.����ȡ�ļ�");
//		outtextxy(10, 80, "����������ѡ��");
//	}
//	else if (menuKey == 1) //ģ��2
//	{
//		outtextxy(10, 20, "**���˵�**");
//		outtextxy(10, 40, "1.�����Ļ");
//		outtextxy(10, 60, "2.����");
//		outtextxy(10, 80, "3.����");
//		outtextxy(10, 100, "����������ѡ��");
//	}
//	else if (menuKey == 2) //ģ��2_2_1 ��ɫ
//	{
//		outtextxy(10, 20, "**��ɫ(����)(�Ƿ����뽫Ĭ��ѡ�����)**");
//		outtextxy(10, 40, "1.��");
//		outtextxy(10, 60, "2.��");
//		outtextxy(10, 80, "3.��");
//		outtextxy(10, 100, "4.��");
//		outtextxy(10, 120, "5.��");
//		outtextxy(10, 140, "6.���");
//
//	}
//	else if (menuKey == 3)  //ͼ��
//	{
//		outtextxy(10, 20, "**ͼ��**");
//		outtextxy(10, 40, "1.Բ");
//		outtextxy(10, 60, "2.����");
//		outtextxy(10, 80, "3.��");
//		outtextxy(10, 100, "4.���ɻ�");
//	}
//	else if (menuKey == 4)  //���
//	{
//		outtextxy(10, 20, "**�Ƿ����(�Ƿ�����Ĭ�ϲ����)**");
//		outtextxy(10, 40, "1.�����(ֻ���߿�)");
//		outtextxy(10, 60, "2.���");
//	}
//}
//
//void SelectFLColor()    //���������ɫ(�����ģʽ)
//{
//	if (menuL[5].isActivated)
//	{
//		ClearMenu();
//		menuKey = 2;
//		Menu();
//		outtextxy(10, 20, "**��ɫ(���)(�Ƿ����뽫Ĭ��ѡ�����)**");
//		char flColor = getch();
//		switch (flColor)
//		{
//		case'1':
//		{
//			/*setcolor(RED);*/
//			fillColor = 0;
//			isSettingFLColor = 1;
//			menuKey = 4;
//			break;
//		}
//		case'2':
//		{
//			//setcolor(BLUE);
//			fillColor = 1;
//			isSettingFLColor = 1;
//			menuKey = 4;
//			break;
//		}
//		case'3':
//		{
//			//setcolor(GREEN);
//			fillColor = 2;
//			isSettingFLColor = 1;
//			menuKey = 4;
//			break;
//		}
//		case'4':
//		{
//			//setcolor(MAGENTA);
//			fillColor = 3;
//			isSettingFLColor = 1;
//			menuKey = 4;
//			break;
//		}
//		case'5':
//		{
//			//setcolor(YELLOW);
//			fillColor = 4;
//			isSettingFLColor = 1;
//			menuKey = 4;
//			break;
//		}
//		case'0':
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			isSettingFLColor = 0;
//			ClearMenu();
//			outtextxy(10, 20, "Ĭ��Ϊ��ѡ���������ɫ");
//			delay_ms(1000);
//			menuKey = 4;
//		}
//		}
//		NextMenu();
//	}
//	else Return();
//	
//	
//}
//
//void SelectColor()    //���ñ�����ɫ
//{
//	if (menuL[2].isActivated)
//	{
//		menuKey = 2;
//		Menu();
//		char colorc = getch();
//		switch (colorc)
//		{
//		case'1':
//		{
//			/*setcolor(RED);*/
//			color = 0;
//			isSettingColor = 1;
//			break;
//		}
//		case'2':
//		{
//			//setcolor(BLUE);
//			color = 1;
//			isSettingColor = 1;
//			break;
//		}
//		case'3':
//		{
//			//setcolor(GREEN);
//			color = 2;
//			isSettingColor = 1;
//			break;
//		}
//		case'4':
//		{
//			//setcolor(MAGENTA);
//			color = 3;
//			isSettingColor = 1;
//			break;
//		}
//		case'5':
//		{
//			//setcolor(YELLOW);
//			color = 4;
//			isSettingColor = 1;
//			break;
//		}
//		case'0':
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			isSettingColor = 0;
//			ClearMenu();
//			outtextxy(10, 20, "Ĭ��Ϊ��ѡ���������ɫ");
//			delay_ms(1000);
//			break;
//		}
//		}
//		NextMenu();
//	}
//	else
//		Return();
//	
//}
//
//void SelectShape()   //����ͼ��
//{
//	while (menuL[3].isActivated)
//	{
//		ClearMenu();
//		menuKey = 3;
//		Menu();
//		char shape = getch();
//		switch (shape)
//		{
//		case'1':       //circle
//		{
//			ClearMenu();
//			shapeVal = 1;
//			NextMenu();
//			break;
//		}
//		case'2':       //tangle
//		{
//			ClearMenu();
//			shapeVal = 2;
//			NextMenu();
//			break;
//		}
//		case'3':      //line
//		{
//			ClearMenu();
//			shapeVal = 3;
//			NextMenu();
//			break;
//		}
//		case'4':     //freedraw
//		{
//			ClearMenu();
//			FreeDrawing();
//			break;
//		}
//		case'0':     //return
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			ClearMenu();
//			outtextxy(10, 20, "����������������������:");
//			delay_ms(1000);
//		}
//		}
//	}
//		
//	
//}
//
//void ReadFile()    //�ļ���ȡ�˵�
//{
//	ClearMenu();
//	Menu();
//	char m1 = getch();
//	while (menuL[0].isActivated)
//	{
//		if (m1 == '1')
//		{
//			char file[100];
//			inputbox_getline("��ȡ�ļ�", "�������ļ�����·��", file, 100);
//			image = newimage();
//			if (!getimage_pngfile(image, file))
//			{
//				ClearMenu();
//				outtextxy(10, 0, "�Ѷ�ȡ");
//				putimage(0, 200, image);
//			}
//			else
//			{
//				ClearMenu();
//				outtextxy(10, 0, "δ��ȡ");
//			}
//			menuKey = 1;
//			//delay_ms(2000);
//		}
//		else if (m1 == '2')
//		{
//			ClearMenu();
//			outtextxy(10, 0, "δ��ȡ");
//			menuKey = 1;
//			//delay_ms(2000);
//		}
//		else
//		{
//			Error();
//			Return();
//		}
//		delay_ms(2000);
//		NextMenu();
//			
//	}
//	Return();
//	//cleardevice();
//}
//
//void MainMenu()      //���˵�
//{
//	while (menuL[1].isActivated)
//	{
//		//if (kbmsg())
//		//	kMsg = getkey();
//		//if (kMsg.key == key_esc)
//		//	break;
//		InitGraph();
//		char m2 = getch();
//		switch (m2)
//		{
//		case'1':     //����
//		{
//			clearviewport();
//			MainMenu();
//			break;
//		}
//		case'2':       //����
//		{
//			ClearMenu();
//			NextMenu();
//			break;
//		}
//		case'3':      //����(��δ���)
//		{
//			SaveAsFile();
//			break;
//		}
//		case'0':
//		{
//			menuL[1].isActivated = false;
//			break;
//		}
//		default:
//		{
//			ClearMenu();
//			outtextxy(10, 20, "������������������");
//		}
//		}
//	}
//}
//
//void SaveAsFile()       //�洢(��δ���)
//{
//	char file[100];
//	inputbox_getline("�����ļ�", "�����ļ����Ա�������Ŀ�ļ��У��������·���Դ洢�������ļ���", file, 100);
//	image = newimage();
//	getimage(image, 0, 200, 1280, 645);
//	savepng(image, file);
//}
//
//#pragma endregion



int main()
{
	Init();
	//printf("%d", menuL[0].isActivated);
	menuL[0].currentFunc();
	//Return();
	closegraph();
	return 0;
}