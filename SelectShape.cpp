#include"Global.h"
int shapeVal = 0;
int radius = 0;
mouse_msg mMsg;
key_msg kMsg;

void DrawCircle()          //Բ
{
	bool error = false;
	int centerX = 0, centerY = 0;//Բ��
	int mouseX = 0, mouseY = 0; //��뾶
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
			//isSettingColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		switch (drawingMode)
		{
		case 0:                            //����
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("��Բ", "�밴���¸�ʽ��������:Բ��x Բ��y �뾶 (�뾶����0�Է���)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "��������,����������");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			if (atoi(pos) != 0)
				centerX = atoi(strtok(pos, " "));          //תint �и�
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
		case 1:                              //���
		{
			ClearMenu();
			setcolor(YELLOW);
			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
			outtextxy(10, 40, "��U���أ���R�������أ������޲���������");
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
							if (centerY < 200)        //�ݴ�
							{
								ClearMenu();
								outtextxy(10, 0, "�������壬���Զ�����");
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
								outtextxy(10, 20, "�������壬���Զ�����");
								mouseY = 205;
							}
							radius = sqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
							break;
						}
						}
					}
					else if (mMsg.is_right() && mMsg.is_down())
					{

						Return();                //�Ҽ�����
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "���λ��(%d , %d)", xMouse, yMouse);
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
				ege::fillellipse(centerX, centerY, radius, radius);     //�����Բ�������Բ
				globalBuffer.push_back(StoreCircle(centerX, centerY, radius));
				break;
			}

			}
			centerX = 0, centerY = 0, radius = 0;                      //���ò���
		}
		else
			continue;

	}
	//outtextxy(10, 20, "����Բ��λ��,�϶���겢�ɿ����ɻ���Բ,��backspace������");
	//while (1)
	//{
	//	if (keystate(VK_BACK))
	//		break;
	//	mMsg = getmouse();

	//	switch (mMsg.msg)
	//	{
	//	case mouse_msg_down:
	//	{
	//		if (!isSettingColor)   //δѡ����ɫ
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

void DrawLine()                  //����
{
	bool error = false;
	int beginMouseX = 0, beginMouseY = 0; //��ʼ��
	int endMouseX = 0, endMouseY = 0; //��ֹ��
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("����", "�밴���¸�ʽ��������:��ʼ��x ��ʼ��y ��ֹ��x ��ֹ��y (ȫ������0�Է���)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "��������,����������");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			beginMouseX = atoi(strtok(pos, " "));                  //תint �и�
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
			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
			outtextxy(10, 40, "��U���أ���R�������أ������޲���������");
			delay_ms(0);
			while (((beginMouseY < 200) || (endMouseY < 200)))                  //δ����
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
							//printf("beginMouseX = %d", beginMouseX);     //������
							//printf("beginMouseY = %d", beginMouseY);
							if (beginMouseY < 200)     //�ݴ�
							{
								ClearMenu();
								outtextxy(10, 20, "�������壬���Զ�����");
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
								outtextxy(10, 20, "�������壬���Զ�����");
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
						sprintf(mousep, "���λ��(%d , %d)", xMouse, yMouse);
						outtextxy(1000, 20, mousep);
					}
				}
				
			}
		}
		}

		setcolor(colors[color]);
		ege::line(beginMouseX, beginMouseY, endMouseX, endMouseY);
		globalBuffer.push_back(StoreLine(beginMouseX, beginMouseY, endMouseX, endMouseY));
		beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;       //���ò���
	}
}



void FreeDrawing()      //���ɻ�
{
	ClearMenu();
	outtextxy(10, 20, "ʹ��������ⴴ������BACK���������˵�");
	delay_ms(0);
	int MouseX = 0, MouseY = 0; //��ʼ��
	while (!keystate(VK_BACK))
		while (keystate(VK_LBUTTON))
		{
			if (!isSettingColor)   //δѡ����ɫ
			{
				color = random(5);
				isSettingColor = 1;     //�����һֱ��ɫ��ע�͵����
			}
			ege::mousepos(&MouseX, &MouseY);
			putpixel(MouseX, MouseY, colors[color]);
		}
	Return();
}

void DrawRectangle()          //����
{
	bool error = false;
	int beginMouseX = 0, beginMouseY = 0; //��ʼ��
	int endMouseX = 0, endMouseY = 0; //��ֹ��
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			char pos[30];
			do
			{
				inputbox_getline("������", "�밴���¸�ʽ��������:��ʼ��x ��ʼ��y ��ֹ��x ��ֹ��y (ȫ������0�Է���)", pos, 30);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "��������,����������");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			beginMouseX = atoi(strtok(pos, " "));           //תint �и�
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
			outtextxy(10, 20, "������ʼ��λ��,�϶���겢�ɿ����ɻ�������,������Ҽ�����");
			outtextxy(10, 40, "��U���أ���R�������أ������޲���������");
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
								outtextxy(10, 20, "�������壬���Զ�����");
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
								outtextxy(10, 20, "�������壬���Զ�����");
								endMouseY = 205;
							}
							break;
						}
						}
					}
					else if (mMsg.is_right() && mMsg.is_down())           //����
					{
						Return();
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "���λ��(%d , %d)", xMouse, yMouse);
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
			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;   //���ò���
			break;
		}
		case 1:
		{
			setfillcolor(colors[fillColor]);
			setcolor(colors[color]);
			ege::bar3d(beginMouseX, beginMouseY, endMouseX, endMouseY, 0, 0);
			globalBuffer.push_back(StoreRectangle(beginMouseX, beginMouseY, endMouseX, endMouseY));
			beginMouseX = 0, beginMouseY = 0, endMouseX = 0, endMouseY = 0;    //���ò���
			break;
		}

		}
	}
}

void DrawPoly()          //�����
{
	bool error = false;
	int limit = 20;            //�������ʱ�Զ���յľ���
	int count = 0;             //����εı���
	int ptArr[200] = { 0 };
	bool isComplete = false;
	while (1)
	{
		if (!isSettingColor)
		{
			color = random(5);
			//isSettingColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		if (!isSettingFLColor)
		{
			fillColor = random(5);
			//isSettingFLColor = 1;           //�����ÿ�λ�����ɫ��ע�͵����
		}
		switch (drawingMode)
		{
		case 0:
		{
			ClearMenu();
			outtextxy(10, 0, "�����Ʒ�ն���Σ������������ʱ������+1�����������ʱ�ֶ������һ����������ʼ����ͬ");
			outtextxy(10, 20, "���磬�����Ʒ������Σ��ڱ���������6����ʹʼĩ���غ�");
			char cnt[10];
			char pos[500];
			do
			{
				inputbox_getline("�������", "���������α���(��������0�Է���)", cnt, 10);
				for (int i = 0;i < strlen(cnt);i++)
					if ((cnt[i] < '0' || cnt[i]>'9') && cnt[i] != ' ')
					{
						for (int j = 0;j < sizeof(cnt);j++)
							cnt[j] = ' ';
						ClearMenu();
						outtextxy(10, 0, "�����Ʒ�ն���Σ������������ʱ������+1�����������ʱ�ֶ������һ����������ʼ����ͬ");
						outtextxy(10, 20, "���磬�����Ʒ������Σ��ڱ���������6����ʹʼĩ���غ�");
						outtextxy(10, 40, "��������,����������");
						delay_ms(10);
						error = true;
						break;
					}
					else
						error = false;
			} while (error);
			count = atoi(cnt);           //תint �и�
			if (count == 0)
				Return();
			do
			{
				inputbox_getline("�������", "�밴���¸�ʽ��������:��һ����x ��һ����y...", pos, 500);
				for (int i = 0;i < strlen(pos);i++)
					if ((pos[i] < '0' || pos[i]>'9') && pos[i] != ' ')
					{
						for (int j = 0;j < sizeof(pos);j++)
							pos[j] = ' ';
						ClearMenu();
						outtextxy(10, 20, "��������,����������");
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
			outtextxy(10, 20, "���������ѡ��������λ�ã������һ��������һ����ľ���С��20ʱ���ɶ����");
			outtextxy(10, 40, "��U���أ���R�������أ������޲���������");
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
								outtextxy(10, 20, "�������壬���Զ�����");
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
					else if (mMsg.is_right() && mMsg.is_down())           //����
					{
						Return();
						break;
					}
					else if (mMsg.is_move())
					{
						xMouse = mMsg.x;
						yMouse = mMsg.y;
						ClearPos();
						sprintf(mousep, "���λ��(%d , %d)", xMouse, yMouse);
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
			count = 0, isComplete = false;       //���ò���
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
				ptArr[i] = 0;    //���ò���
			break;
		}

		}
	}
}



void SelectShape()   //����ͼ��
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
			outtextxy(10, 20, "����������������������:");
			delay_ms(1000);
		}
		}
	}


}