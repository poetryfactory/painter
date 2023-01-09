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
//#pragma region 参数
//int menuKey = 0;		  //存菜单值
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
//#pragma region 函数声明
////函数声明
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
//Menus menuL[7] =                                    //菜单结构体初始化
//{
//	{0, 0, 1,ReadFile,true},             //{当前索引,返回索引,前进索引,函数指针,是否激活}
//	{1,-1, 2,MainMenu,false},
//	{2, 1, 3,SelectColor,false},
//	{3, 1, 4,SelectShape,false},
//	{4, 1, 5,IsFilled,false},
//	{5, 1, 6,SelectFLColor,false},
//	{6, 1, 6, SelectMode,false}
//};
//
//#pragma region 函数体
//
//void Init()              //初始化
//{
//	initgraph(1280, 960);
//	setcolor(ege::COLORS::YELLOW);
//	setfont(18, 0, "宋体");
//}
//
//void InitGraph()          //生成画布
//{
//	ClearMenu();
//	menuKey = 1;
//	Menu();
//	setcolor(ege::COLORS::YELLOW);
//	rectangle(0, 200, 1280, 845); 
//}
//
//void ClearMenu()         //清菜单
//{
//	setfillcolor(getbkcolor());
//	bar(0, 0, 1280, 200);
//}
//
//void Error()          //报错
//{
//	ClearMenu();
//	outtextxy(10, 20, "您的输入有误，请在2s后重新输入:");
//	delay_ms(2000);
//	ClearMenu();
//}
//
//void Return()             //返回
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
//void NextMenu()             //下一菜单
//{
//	menuL[currentMenuIndex].isActivated = false;
//	if (currentMenuIndex == 4 && !isFillingMode)   //非填充不展示填充颜色菜单
//		currentMenuIndex = 6;
//	if (currentMenuIndex == 3 && shapeVal == 3)   //线 不需要选择是否填充
//		currentMenuIndex = 6;
//	else
//		currentMenuIndex = menuL[currentMenuIndex].nIndex;
//	menuL[currentMenuIndex].isActivated = true;
//	menuL[currentMenuIndex].currentFunc();
//
//}
//
//void Draw1(int val)             //绘图
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
//void DrawCircle()          //圆
//{
//	int centerX=0, centerY=0;//圆心
//	int mouseX=0, mouseY=0; //算半径
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
//			case 0:                            //键盘
//			{
//				char pos[30];
//				inputbox_getline("画圆", "请按以下格式输入数据:圆心x 圆心y 半径 (半径输入0以返回)", pos, 30);        
//				centerX = atoi(strtok(pos, " "));          //转int 切割
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
//			case 1:                              //鼠标
//			{
//				ClearMenu();
//				setcolor(YELLOW);
//				outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
//				while (radius == 0)
//				{
//					mMsg = getmouse();
//					if (mMsg.is_left())
//					{
//						switch (mMsg.msg)
//						{
//						case mouse_msg_down:
//						{
//							if (!isSettingColor)   //未选择颜色
//							{
//								setcolor(colors[random(4)]);
//							}
//							mousepos(&centerX, &centerY);
//							if (centerY < 200)        //容错
//							{
//								ClearMenu();
//								outtextxy(10, 0, "超出画板，已自动调整");
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
//								outtextxy(10, 20, "超出画板，已自动调整");
//								mouseY = 205;
//							}
//							radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
//							break;
//						}
//						}
//					}	
//					if (mMsg.is_right() && mMsg.is_down())
//					{
//						Return();                //右键返回
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
//				ege::fillellipse(centerX, centerY, radius, radius);     //填充椭圆来画填充圆
//				break;
//			}
//
//			}
//			centerX = 0, centerY = 0, radius = 0;                      //重置参数
//		/*}*/
//		
//	}
//	//outtextxy(10, 20, "请点击圆心位置,拖动鼠标并松开即可绘制圆,按backspace键返回");
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
//	//		if (!isSettingColor)   //未选择颜色
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
//void DrawLine()                  //画线
//{
//	int beginMouseX=0, beginMouseY=0; //起始点
//	int endMouseX=0, endMouseY=0; //终止点
//	while (1)
//	{
//		switch (drawingMode)
//		{
//		case 0:
//		{
//			char pos[30];
//			inputbox_getline("画线", "请按以下格式输入数据:起始点x 起始点y 终止点x 终止点y (全部输入0以返回)", pos, 30);
//			beginMouseX = atoi(strtok(pos, " "));                  //转int 切割
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
//			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
//			while (((beginMouseY<200)||(endMouseY<200)))                  //未绘制
//			{
//				mMsg = getmouse();
//				if (mMsg.is_left())
//				{
//					switch (mMsg.msg)
//					{
//					case mouse_msg_down:
//					{
//						if (!isSettingColor)   //未选择颜色
//						{
//							setcolor(colors[random(4)]);
//						}
//						mousepos(&beginMouseX, &beginMouseY);
//						//printf("beginMouseX = %d", beginMouseX);     //调试用
//						//printf("beginMouseY = %d", beginMouseY);
//						if (beginMouseY < 200)     //容错
//						{
//							ClearMenu();
//							outtextxy(10, 20, "超出画板，已自动调整");
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
//							outtextxy(10, 20, "超出画板，已自动调整");
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
//		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY=0;       //重置参数
//	}
//}
//
////void DrawPolygon()
////{
////	int beginMouseX = 0, beginMouseY = 0; //起始点
////	int endMouseX = 0, endMouseY = 0; //终止点
////FLAG2:
////	SelectMode();
////	while (!keystate(VK_BACK))
////	{
////		switch (drawingMode)
////		{
////		case 0:
////		{
////			char pos[30];
////			inputbox_getline("画线", "请按以下格式输入数据:起始点x 起始点y 终止点x 终止点y (全部输入0以返回)", pos, 30);
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
////			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按backspace键返回");
////			while (((beginMouseY < 200) || (endMouseY < 200)) && (!keystate(VK_BACK)))
////			{
////				mMsg = getmouse();
////				switch (mMsg.msg)
////				{
////				case mouse_msg_down:
////				{
////					if (!isSettingColor)   //未选择颜色
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
//void FreeDrawing()      //自由画
//{
//	ClearMenu();
//	int MouseX = 0, MouseY = 0; //起始点
//	while (!keystate(VK_BACK))
//		while(keystate(VK_LBUTTON))
//		{
//			if (!isSettingColor)   //未选择颜色
//			{
//				setcolor(colors[random(4)]);
//			}
//			ege::mousepos(&MouseX, &MouseY);
//			putpixel(MouseX, MouseY,colors[color]);
//		}
//}
//
//void DrawTangle()          //矩形
//{
//	int beginMouseX = 0, beginMouseY = 0; //起始点
//	int endMouseX = 0, endMouseY = 0; //终止点
//	while (1)
//	{
//		switch (drawingMode)
//		{
//		case 0:
//		{
//			char pos[30];
//			inputbox_getline("画矩形", "请按以下格式输入数据:起始点x 起始点y 终止点x 终止点y (全部输入0以返回)", pos, 30);
//			beginMouseX = atoi(strtok(pos, " "));           //转int 切割
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
//			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
//			while ((beginMouseY < 200) || (endMouseY < 200))
//			{
//				mMsg = getmouse();
//				if (mMsg.is_left())
//				{
//					switch (mMsg.msg)
//					{
//					case mouse_msg_down:
//					{
//						if (!isSettingColor)   //未选择颜色
//						{
//							setcolor(colors[random(4)]);
//						}
//						mousepos(&beginMouseX, &beginMouseY);
//						if (beginMouseY < 200)
//						{
//							ClearMenu();
//							outtextxy(10, 20, "超出画板，已自动调整");
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
//							outtextxy(10, 20, "超出画板，已自动调整");
//							endMouseY = 205;
//						}
//						break;
//					}
//					}
//				}
//				if (mMsg.is_right() && mMsg.is_down())           //返回
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
//			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;   //重置参数
//			break;
//		}
//		case 1:
//		{
//			setfillcolor(colors[fillColor]);
//			setcolor(colors[color]);
//			ege::bar3d(beginMouseX, beginMouseY, endMouseX, endMouseY,0,0);
//			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;    //重置参数
//			break;
//		}
//
//		}
//	}
//	//outtextxy(10, 20, "请点击左上角位置,拖动鼠标并松开即可绘制矩形,按backspace键返回");
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
//	//		if (!isSettingColor)   //未选择颜色
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
//void SelectMode()               //选择键鼠绘图模式
//{
//	while (menuL[6].isActivated)
//	{
//		ClearMenu();
//		setcolor(YELLOW);
//		outtextxy(10, 20, "**选择绘制模式**");
//		outtextxy(10, 40, "1.键盘绘画");
//		outtextxy(10, 60, "2.鼠标绘画");
//		char mode = getch();
//		switch (mode)
//		{
//		case'1':            //键盘
//		{
//			drawingMode = 0;
//			Draw1(shapeVal);
//			break;
//		}
//		case'2':        //鼠标
//		{
//			drawingMode = 1;
//			Draw1(shapeVal);
//			break;
//		}
//		case'0':        //返回
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			ClearMenu();
//			outtextxy(10, 20, "输入有误，请重新输入");
//			delay_ms(1000);
//		}
//		}
//		
//	}
//
//}
//
//void IsFilled()          //选择填充模式
//{
//	ClearMenu();
//	menuKey = 4;
//	Menu();
//	if (menuL[4].isActivated)
//	{
//		char res = getch();
//		switch (res)
//		{
//		case'1':        //非填充模式
//		{
//			isFillingMode = 0;
//			break;
//		}
//		case'2':       //填充模式
//		{
//			isFillingMode = 1;
//			break;
//		}
//		case'0':      //返回
//		{
//			Return();
//			break;
//		}
//		default:
//		{
//			isFillingMode = 0;
//			ClearMenu();
//			outtextxy(10, 20, "默认为您选择了不填充");
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
//void Menu()          //菜单UI
//{
//	setcolor(ege::COLORS::YELLOW);
//	outtextxy(10, 0, "欢迎您进入画板，请根据菜单选择您想进行的操作：(按0返回主菜单,在主菜单按0退出)");
//	if (menuKey == 0) //模块1
//	{
//		outtextxy(10, 20, "**读取文件**");
//		outtextxy(10, 40, "1.读取文件");
//		outtextxy(10, 60, "2.不读取文件");
//		outtextxy(10, 80, "请输入您的选择：");
//	}
//	else if (menuKey == 1) //模块2
//	{
//		outtextxy(10, 20, "**主菜单**");
//		outtextxy(10, 40, "1.清除屏幕");
//		outtextxy(10, 60, "2.作画");
//		outtextxy(10, 80, "3.保存");
//		outtextxy(10, 100, "请输入您的选择：");
//	}
//	else if (menuKey == 2) //模块2_2_1 颜色
//	{
//		outtextxy(10, 20, "**颜色(边线)(非法输入将默认选择随机)**");
//		outtextxy(10, 40, "1.红");
//		outtextxy(10, 60, "2.蓝");
//		outtextxy(10, 80, "3.绿");
//		outtextxy(10, 100, "4.紫");
//		outtextxy(10, 120, "5.黄");
//		outtextxy(10, 140, "6.随机");
//
//	}
//	else if (menuKey == 3)  //图形
//	{
//		outtextxy(10, 20, "**图形**");
//		outtextxy(10, 40, "1.圆");
//		outtextxy(10, 60, "2.矩形");
//		outtextxy(10, 80, "3.线");
//		outtextxy(10, 100, "4.自由画");
//	}
//	else if (menuKey == 4)  //填充
//	{
//		outtextxy(10, 20, "**是否填充(非法操作默认不填充)**");
//		outtextxy(10, 40, "1.不填充(只画边框)");
//		outtextxy(10, 60, "2.填充");
//	}
//}
//
//void SelectFLColor()    //设置填充颜色(仅填充模式)
//{
//	if (menuL[5].isActivated)
//	{
//		ClearMenu();
//		menuKey = 2;
//		Menu();
//		outtextxy(10, 20, "**颜色(填充)(非法输入将默认选择随机)**");
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
//			outtextxy(10, 20, "默认为您选择了随机颜色");
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
//void SelectColor()    //设置边线颜色
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
//			outtextxy(10, 20, "默认为您选择了随机颜色");
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
//void SelectShape()   //设置图形
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
//			outtextxy(10, 20, "您的输入有误，请重新输入:");
//			delay_ms(1000);
//		}
//		}
//	}
//		
//	
//}
//
//void ReadFile()    //文件读取菜单
//{
//	ClearMenu();
//	Menu();
//	char m1 = getch();
//	while (menuL[0].isActivated)
//	{
//		if (m1 == '1')
//		{
//			char file[100];
//			inputbox_getline("读取文件", "请输入文件绝对路径", file, 100);
//			image = newimage();
//			if (!getimage_pngfile(image, file))
//			{
//				ClearMenu();
//				outtextxy(10, 0, "已读取");
//				putimage(0, 200, image);
//			}
//			else
//			{
//				ClearMenu();
//				outtextxy(10, 0, "未读取");
//			}
//			menuKey = 1;
//			//delay_ms(2000);
//		}
//		else if (m1 == '2')
//		{
//			ClearMenu();
//			outtextxy(10, 0, "未读取");
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
//void MainMenu()      //主菜单
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
//		case'1':     //清屏
//		{
//			clearviewport();
//			MainMenu();
//			break;
//		}
//		case'2':       //作画
//		{
//			ClearMenu();
//			NextMenu();
//			break;
//		}
//		case'3':      //保存(尚未完成)
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
//			outtextxy(10, 20, "输入有误，请重新输入");
//		}
//		}
//	}
//}
//
//void SaveAsFile()       //存储(尚未完成)
//{
//	char file[100];
//	inputbox_getline("保存文件", "输入文件名以保存在项目文件夹，输入绝对路径以存储在任意文件夹", file, 100);
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