#include"Global.h"
int shapeVal = 0;
int radius = 0;
mouse_msg mMsg;
key_msg kMsg;

void DrawCircle()          //圆
{
	bool error = false;
	int centerX = 0, centerY = 0;//圆心
	int mouseX = 0, mouseY = 0; //算半径
	while (1)
	{
		//mMsg = getmouse();
		//if (mMsg.is_right()&&mMsg.is_down())
		//{
		//	printf("rB");
		//	//break;
		//}	
		//else
		//{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //如果想每次画都变色就注释掉这句
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //如果想每次画都变色就注释掉这句
		}
		switch (drawingMode)
		{
		case 0:                            //键盘
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("画圆", "请按以下格式输入数据:圆心x 圆心y 半径 (半径输入0以返回)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "输入有误,请重新输入");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			if (atoi(pos) != 0)
				centerX = atoi(strtok(pos, " "));          //转int 切割
			centerY = atoi(strtok(NULL, " "));
			radius = atoi(strtok(NULL, " "));
			if (centerY <= 200)
				centerY = 205;
			if (centerY - radius < 200)
				radius = centerY - 200;
			if (radius == 0)
				Return();
			break;
		}
		case 1:                              //鼠标
		{
			ClearMenu();
			setcolor(YELLOW);
			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
			outtextxy(10, 40, "按U撤回，按R重做撤回，可无限步撤回重做");
			delay_ms(0);
			while (radius == 0)
			{
				unDoDetect(kMsg);

				if (mousemsg())
				{
					mMsg = getmouse();
					if (mMsg.is_left())
					{
						switch (mMsg.msg)
						{
						case mouse_msg_down:
						{
							mousepos(&centerX, &centerY);
							if (centerY < 200)        //容错
							{
								ClearMenu();
								outtextxy(10, 0, "超出画板，已自动调整");
								centerY = 205;
							}
							break;
						}

						case mouse_msg_up:
						{
							mousepos(&mouseX, &mouseY);
							if (mouseY < 200)
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								mouseY = 205;
							}
							radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
							break;
						}
						}
					}
					else if (mMsg.is_right() && mMsg.is_down())
					{

						Return();                //右键返回
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "鼠标位置(%d , %d)", xMouse, yMouse);
						outtextxy(1000, 20, mousep);
					}
				}
			}
			break;
		}
		}


		if (radius != 0)
		{
			switch (isFillingMode)
			{
			case 0:
			{
				setcolor(colors[color]);
				ege::circle(centerX, centerY, radius);
				globalBuffer.push_back(StoreCircle(centerX,centerY,radius));
				break;
			}
			case 1:
			{
				setfillcolor(colors[fillColor]);
				setcolor(colors[color]);
				ege::fillellipse(centerX, centerY, radius, radius);     //填充椭圆来画填充圆
				globalBuffer.push_back(StoreCircle(centerX, centerY, radius));
				break;
			}

			}
			centerX = 0, centerY = 0, radius = 0;                      //重置参数
		}
		else
			continue;

	}
	//outtextxy(10, 20, "请点击圆心位置,拖动鼠标并松开即可绘制圆,按backspace键返回");
	//while (1)
	//{
	//	if (keystate(VK_BACK))
	//		break;
	//	mMsg = getmouse();

	//	switch (mMsg.msg)
	//	{
	//	case mouse_msg_down:
	//	{
	//		if (!isSettingColor)   //未选择颜色
	//		{
	//			setcolor(colors[random(4)]);
	//		}
	//		mousepos(&centerX, &centerY);
	//		break;
	//	}

	//	case mouse_msg_up:
	//	{
	//		mousepos(&mouseX, &mouseY);
	//		radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
	//		setcolor(colors[color]);
	//		circle(centerX, centerY, radius);
	//		centerX = 0, centerY = 0, radius = 0;
	//		break;
	//	}
	//	}
	//}
}

void DrawLine()                  //画线
{
	bool error = false;
	int beginMouseX = 0, beginMouseY = 0; //起始点
	int endMouseX = 0, endMouseY = 0; //终止点
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //如果想每次画都变色就注释掉这句
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("画线", "请按以下格式输入数据:起始点x 起始点y 终止点x 终止点y (全部输入0以返回)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "输入有误,请重新输入");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			beginMouseX = atoi(strtok(pos, " "));                  //转int 切割
			beginMouseY = atoi(strtok(NULL, " "));
			endMouseX = atoi(strtok(NULL, " "));
			endMouseY = atoi(strtok(NULL, " "));
			if (beginMouseY == 0 || endMouseY == 0)
				Return();
			break;
		}
		case 1:
		{
			ClearMenu();
			setcolor(YELLOW);
			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
			outtextxy(10, 40, "按U撤回，按R重做撤回，可无限步撤回重做");
			delay_ms(0);
			while (((beginMouseY < 200) || (endMouseY < 200)))                  //未绘制
			{
				unDoDetect(kMsg);
				if (mousemsg())
				{
					mMsg = getmouse();
					if (mMsg.is_left())
					{
						switch (mMsg.msg)
						{
						case mouse_msg_down:
						{
							mousepos(&beginMouseX, &beginMouseY);
							//printf("beginMouseX = %d", beginMouseX);     //调试用
							//printf("beginMouseY = %d", beginMouseY);
							if (beginMouseY < 200)     //容错
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								beginMouseY = 205;
							}
							break;
						}

						case mouse_msg_up:
						{
							mousepos(&endMouseX, &endMouseY);
							//printf("endMouseX = %d", beginMouseX);
							//printf("endMouseY = %d", beginMouseY);
							if (endMouseY < 200)
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								endMouseY = 205;
							}
							break;
						}
						}
					}
					else if (mMsg.is_right() && mMsg.is_down())
					{
						Return();
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "鼠标位置(%d , %d)", xMouse, yMouse);
						outtextxy(1000, 20, mousep);
					}
				}
				
			}
		}
		}

		setcolor(colors[color]);
		ege::line(beginMouseX, beginMouseY, endMouseX, endMouseY);
		globalBuffer.push_back(StoreLine(beginMouseX, beginMouseY, endMouseX, endMouseY));
		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;       //重置参数
	}
}



void FreeDrawing()      //自由画
{
	ClearMenu();
	outtextxy(10, 20, "使用鼠标随意创作，按BACK键返回主菜单");
	delay_ms(0);
	int MouseX = 0, MouseY = 0; //起始点
	while (!keystate(VK_BACK))
		while (keystate(VK_LBUTTON))
		{
			if (!isSettingColor)   //未选择颜色
			{
				color = random(5);
				isSettingColor = 1;     //如果想一直变色就注释掉这句
			}
			ege::mousepos(&MouseX, &MouseY);
			putpixel(MouseX, MouseY, colors[color]);
		}
	Return();
}

void DrawRectangle()          //矩形
{
	bool error = false;
	int beginMouseX = 0, beginMouseY = 0; //起始点
	int endMouseX = 0, endMouseY = 0; //终止点
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //如果想每次画都变色就注释掉这句
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //如果想每次画都变色就注释掉这句
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("画矩形", "请按以下格式输入数据:起始点x 起始点y 终止点x 终止点y (全部输入0以返回)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "输入有误,请重新输入");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			beginMouseX = atoi(strtok(pos, " "));           //转int 切割
			beginMouseY = atoi(strtok(NULL, " "));
			endMouseX = atoi(strtok(NULL, " "));
			endMouseY = atoi(strtok(NULL, " "));
			if (beginMouseY == 0 || endMouseY == 0)
				Return();
			break;
		}
		case 1:
		{
			ClearMenu();
			setcolor(YELLOW);
			outtextxy(10, 20, "请点击起始点位置,拖动鼠标并松开即可绘制线条,按鼠标右键返回");
			outtextxy(10, 40, "按U撤回，按R重做撤回，可无限步撤回重做");
			delay_ms(0);
			while ((beginMouseY < 200) || (endMouseY < 200))
			{
				unDoDetect(kMsg);
				if (mousemsg())
				{
					mMsg = getmouse();
					if (mMsg.is_left())
					{
						switch (mMsg.msg)
						{
						case mouse_msg_down:
						{
							mousepos(&beginMouseX, &beginMouseY);
							if (beginMouseY < 200)
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								beginMouseY = 205;
							}
							break;
						}

						case mouse_msg_up:
						{
							mousepos(&endMouseX, &endMouseY);
							if (endMouseY < 200)
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								endMouseY = 205;
							}
							break;
						}
						}
					}
					else if (mMsg.is_right() && mMsg.is_down())           //返回
					{
						Return();
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "鼠标位置(%d , %d)", xMouse, yMouse);
						outtextxy(1000, 20, mousep);
					}
				}
				

			}
			break;
		}
		}

		switch (isFillingMode)
		{
		case 0:
		{
			setcolor(colors[color]);
			ege::rectangle(beginMouseX, beginMouseY, endMouseX, endMouseY);
			globalBuffer.push_back(StoreRectangle(beginMouseX, beginMouseY, endMouseX, endMouseY));
			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;   //重置参数
			break;
		}
		case 1:
		{
			setfillcolor(colors[fillColor]);
			setcolor(colors[color]);
			ege::bar3d(beginMouseX, beginMouseY, endMouseX, endMouseY, 0, 0);
			globalBuffer.push_back(StoreRectangle(beginMouseX, beginMouseY, endMouseX, endMouseY));
			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;    //重置参数
			break;
		}

		}
	}
}

void DrawPoly()          //多边形
{
	bool error = false;
	int limit = 20;            //鼠标作画时自动封闭的距离
	int count = 0;             //多边形的边数
	int ptArr[200] = { 0 };
	bool isComplete = false;
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //如果想每次画都变色就注释掉这句
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //如果想每次画都变色就注释掉这句
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			outtextxy(10, 0, "若绘制封闭多边形，请在输入边数时将边数+1，并在输入点时手动将最后一点输入与起始点相同");
			outtextxy(10, 20, "例如，若绘制封闭五边形，在边数中输入6，并使始末点重合");
			char cnt[10];
			char pos[500];
			do
			{
				inputbox_getline("画多边形", "请输入多边形边数(边数输入0以返回)", cnt, 10);
				for (int i = 0;i < strlen(cnt);i++)
					if ((cnt[i] < '0' || cnt[i]>'9') && cnt[i] != ' ')
					{
						for (int j = 0;j < sizeof(cnt);j++)
							cnt[j] = ' ';
						ClearMenu();
						outtextxy(10, 0, "若绘制封闭多边形，请在输入边数时将边数+1，并在输入点时手动将最后一点输入与起始点相同");
						outtextxy(10, 20, "例如，若绘制封闭五边形，在边数中输入6，并使始末点重合");
						outtextxy(10, 40, "输入有误,请重新输入");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			count = atoi(cnt);           //转int 切割
			if (count == 0)
				Return();
			do
			{
				inputbox_getline("画多边形", "请按以下格式输入数据:第一个点x 第一个点y...", pos, 500);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "输入有误,请重新输入");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			ptArr[0] = atoi(strtok(pos, " "));
			for (int i = 1;i < 2 * count;i++)
			{
				ptArr[i] = atoi(strtok(NULL, " "));
			}
			for (int j = 0;j < 2 * count;j++)
			{
				printf("%d ", ptArr[j]);
			}

			break;
		}
		case 1:
		{
			ClearMenu();
			setcolor(YELLOW);
			outtextxy(10, 20, "单击鼠标以选择各个点的位置，当最后一个点距离第一个点的距离小于20时生成多边形");
			outtextxy(10, 40, "按U撤回，按R重做撤回，可无限步撤回重做");
			delay_ms(0);
			while (((ptArr[0] == 0 && ptArr[1] == 0) || count == 0) || !isComplete)
			{
				unDoDetect(kMsg);
				if (mousemsg())
				{
					mMsg = getmouse();
					if (mMsg.is_left())
					{

						switch (mMsg.msg)
						{
						case mouse_msg_down:
						{
							mousepos(&ptArr[2 * count], &ptArr[2 * count + 1]);
							printf("%d %d ", ptArr[2 * count], ptArr[2 * count + 1]);
							if (ptArr[2 * count + 1] < 200)
							{
								ClearMenu();
								outtextxy(10, 20, "超出画板，已自动调整");
								ptArr[2 * count + 1] = 205;
							}
							setfillcolor(colors[color]);
							setlinewidth(1);
							if (sqrt(pow(ptArr[0] - ptArr[2 * count], 2) +
								pow(ptArr[1] - ptArr[2 * count + 1], 2)) <= limit
								&& count >= 3)
							{
								ptArr[2 * count] = ptArr[0];
								ptArr[2 * count + 1] = ptArr[1];
								isComplete = true;
							}
							else
								ege::fillellipse(ptArr[2 * count], ptArr[2 * count + 1], 3, 3);
							setlinewidth(lineWidth);
							delay_ms(0);
							printf("%d ", count);
							count++;
							printf("%d ", isComplete);

							break;
						}
						}

					}
					else if (mMsg.is_right() && mMsg.is_down())           //返回
					{
						Return();
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "鼠标位置(%d , %d)", xMouse, yMouse);
						outtextxy(1000, 20, mousep);
					}
				}
			}
			break;
		}
		}

		switch (isFillingMode)
		{
		case 0:
		{
			setcolor(colors[color]);
			ege::drawpoly(count, ptArr);
			globalBuffer.push_back(StorePoly(count, ptArr));
			for (int i = 0;i < sizeof(ptArr) / sizeof(ptArr[0]);i++)
				ptArr[i] = 0;
			count = 0, isComplete = false;       //重置参数
			break;
		}
		case 1:
		{
			setfillcolor(colors[fillColor]);
			setcolor(colors[color]);
			ege::fillpoly(count, ptArr);
			globalBuffer.push_back(StorePoly(count, ptArr));
			count = 0, isComplete = false;
			for (int i = 0;i < sizeof(ptArr) / sizeof(ptArr[0]);i++)
				ptArr[i] = 0;    //重置参数
			break;
		}

		}
	}
}



void SelectShape()   //设置图形
{
	while (menuL[3].isActivated)
	{
		ClearMenu();
		menuKey = 3;
		Menu();
		ButtonLogic(3);
		switch (pressedButtonID)
		{
		case 0:       //circle
		{
			ClearMenu();
			shapeVal = 1;
			NextMenu();
			break;
		}
		case 1:       //tangle
		{
			ClearMenu();
			shapeVal = 2;
			NextMenu();
			break;
		}
		case 2:      //line
		{
			ClearMenu();
			shapeVal = 3;
			NextMenu();
			break;
		}
		case 3:
		{
			ClearMenu();
			shapeVal = 4;
			NextMenu();
		}
		case 4:     //freedraw
		{
			ClearMenu();
			FreeDrawing();
			break;
		}
		case 5:     //return
		{
			Return();
			break;
		}
		default:
		{
			ClearMenu();
			outtextxy(10, 20, "您的输入有误，请重新输入:");
			delay_ms(1000);
		}
		}
	}


}