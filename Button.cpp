#include"Global.h"

int btnID = BUTTON_ID_NONE;
int pressedButtonID = BUTTON_ID_NONE;
int hoveredButtonId = BUTTON_ID_NONE;
int xMouse = 0, yMouse = 0;
bool redraw = true;
Button buttonArray[BUTTON_SIZE];
const char* strings[6][7] = 
{
	"��ȡ","����ȡ"," "," "," "," "," ",
	"����","����","��ѯ","����","�˳�"," "," ",
	"��ɫ","��ɫ","��ɫ","��ɫ","��ɫ","���","����",
	"Բ","����","��","�����","���ɻ�","����"," ",
	"�����","���","����"," "," "," "," ",
	"���̻滭","���滭","����"," "," "," "," "
};
const int buttonSize[6] = { 2,5,7,6,3,3 };

void StoreButton(Button buttonArray[],int stage)
{
	for (int i = 0; i < buttonSize[stage]; i++) 
	{
		buttonArray[i].x1 = (0.25 + 1.5 * i) * 1280/(1.5* buttonSize[stage]);
		buttonArray[i].y1 = 50;
		buttonArray[i].x2 = (1.25 + 1.5 * i) * 1280/(1.5* buttonSize[stage]);
		buttonArray[i].y2 = buttonArray[i].y1+100;
		buttonArray[i].text = strings[stage][i];
		buttonArray[i].pressed = false;
		buttonArray[i].hovered = false;
	}
}

bool insideButton(const Button* button, int x, int y)
{
	return (button->x1 < x && button->x2 > x && button->y1 < y && button->y2 > y);
}

void DrawButton(const Button buttonArray[], int stage)
{

	setfillcolor(EGEARGB(0xFF, 0x1E, 0x90, 0xFF));
	setcolor(WHITE);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	setfont(30, 0, "����");
	color_t lastFillColor = getfillcolor();

	for (int i = 0; i < buttonSize[stage]; i++) 
	{
		//����״̬���в�ͬ�Ļ��ƣ����ﰴ״̬�ı���ɫ
		color_t curColor;
		if (buttonArray[i].pressed) 
		{
			curColor = BLUE;
		}
		else if(buttonArray[i].hovered)
		{
			curColor = MAGENTA;
		}
		else
		{
			curColor = LIGHTBLUE;
		}

		//Ϊ�˼�����ɫ���ò������е��Ż��������������ƿ��п���
		if (lastFillColor != curColor) 
		{
			setfillcolor(curColor);
			lastFillColor = curColor;
		}

		// ���ư�ť
		bar(buttonArray[i].x1, buttonArray[i].y1, buttonArray[i].x2, buttonArray[i].y2);
		xyprintf((buttonArray[i].x1+buttonArray[i].x2)/2, (buttonArray[i].y1+buttonArray[i].y2)/2, "%s", buttonArray[i].text);
	}
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(YELLOW);
	outtextxy(10, 0, "��ӭ�����뻭�壬��ѡ��������еĲ�����");
	setfont(18, 0, "����");
	setfillcolor(getbkcolor());
	
}

int SearchButton(int x, int y, const Button buttonArray[], int length)
{
	int buttonId = BUTTON_ID_NONE;

	for (int i = 0; i < length; i++) 
	{
		if (insideButton(&buttonArray[i], x, y)) 
		{
			buttonId = i;
			break;   //�˳����Ѿ���⵽������İ�ť���ټ��
		}
	}

	return buttonId;
}

void ButtonLogic(int stage)
{
	pressedButtonID = BUTTON_ID_NONE;
	for (bool flag = true; is_run() && flag; delay_fps(60))
	{
		bool mouseMoved = false;
		DrawButton(buttonArray, stage);
		while (mousemsg())
		{
			mouse_msg msg = getmouse();

			// �ж����������£��������ȷ��λ�ã�ͬʱ�ж��Ƿ�Ϊ��ť����
			// ̧����������״̬
			if (msg.is_left())
			{
				if (msg.is_down())
				{
					// ����Ƿ��а�ť������
					int btnId = SearchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE);

					// �������µİ�ť����Ϊ����״̬
					if (btnId != BUTTON_ID_NONE) {
						pressedButtonID = btnId;
						buttonArray[pressedButtonID].pressed = true;
						redraw = true;
					}
				}
				else {
					//���̧������а�ť�����£��������״̬
					if (pressedButtonID != BUTTON_ID_NONE) {
						redraw = true;
						flag = false;
						break;
					}
				}
			}
			else if (msg.is_move())
			{
				mouseMoved = true;
				xMouse = msg.x;
				yMouse = msg.y;
				ClearPos();
				sprintf(mousep, "���λ��(%d , %d)", xMouse, yMouse);
				outtextxy(1000, 20, mousep);
			}
		}
		if (mouseMoved)
		{
			//������ͣ�İ�ť
			int btnId = SearchButton(xMouse, yMouse, buttonArray, BUTTON_SIZE);

			// ��ͣ��ť�ı�
			if (btnId != hoveredButtonId) {
				// ���ԭ�ȵİ�ťΪ����ͣ״̬
				if (hoveredButtonId != BUTTON_ID_NONE) {
					buttonArray[hoveredButtonId].hovered = false;
				}

				// ��ǵ�ǰ��ͣ�İ�ťΪ��ͣ״̬
				if (btnId != BUTTON_ID_NONE) {
					buttonArray[btnId].hovered = true;
				}

				hoveredButtonId = btnId;
				redraw = true;
			}
		}
		if (redraw)
		{
			ClearMenu();
			DrawButton(buttonArray, stage);
			redraw = false;
		}
		delay_ms(0);
	}
}
