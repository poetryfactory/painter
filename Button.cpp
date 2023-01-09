#include"Global.h"

int btnID = BUTTON_ID_NONE;
int pressedButtonID = BUTTON_ID_NONE;
int hoveredButtonId = BUTTON_ID_NONE;
int xMouse = 0, yMouse = 0;
bool redraw = true;
Button buttonArray[BUTTON_SIZE];
const char* strings[6][7] = 
{
	"读取","不读取"," "," "," "," "," ",
	"清屏","作画","查询","保存","退出"," "," ",
	"红色","蓝色","绿色","紫色","黄色","随机","返回",
	"圆","矩形","线","多边形","自由画","返回"," ",
	"非填充","填充","返回"," "," "," "," ",
	"键盘绘画","鼠标绘画","返回"," "," "," "," "
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
	setfont(30, 0, "宋体");
	color_t lastFillColor = getfillcolor();

	for (int i = 0; i < buttonSize[stage]; i++) 
	{
		//根据状态进行不同的绘制，这里按状态改变颜色
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

		//为了减少颜色设置操作进行的优化操作，少量绘制可有可无
		if (lastFillColor != curColor) 
		{
			setfillcolor(curColor);
			lastFillColor = curColor;
		}

		// 绘制按钮
		bar(buttonArray[i].x1, buttonArray[i].y1, buttonArray[i].x2, buttonArray[i].y2);
		xyprintf((buttonArray[i].x1+buttonArray[i].x2)/2, (buttonArray[i].y1+buttonArray[i].y2)/2, "%s", buttonArray[i].text);
	}
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(YELLOW);
	outtextxy(10, 0, "欢迎您进入画板，请选择您想进行的操作：");
	setfont(18, 0, "宋体");
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
			break;   //退出，已经检测到，后面的按钮不再检测
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

			// 判断鼠标左键按下（左键按下确定位置，同时判断是否为按钮区域
			// 抬起则解除按下状态
			if (msg.is_left())
			{
				if (msg.is_down())
				{
					// 检查是否有按钮被按下
					int btnId = SearchButton(msg.x, msg.y, buttonArray, BUTTON_SIZE);

					// 将被按下的按钮设置为按下状态
					if (btnId != BUTTON_ID_NONE) {
						pressedButtonID = btnId;
						buttonArray[pressedButtonID].pressed = true;
						redraw = true;
					}
				}
				else {
					//左键抬起，如果有按钮被按下，解除按下状态
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
				sprintf(mousep, "鼠标位置(%d , %d)", xMouse, yMouse);
				outtextxy(1000, 20, mousep);
			}
		}
		if (mouseMoved)
		{
			//查找悬停的按钮
			int btnId = SearchButton(xMouse, yMouse, buttonArray, BUTTON_SIZE);

			// 悬停按钮改变
			if (btnId != hoveredButtonId) {
				// 标记原先的按钮为非悬停状态
				if (hoveredButtonId != BUTTON_ID_NONE) {
					buttonArray[hoveredButtonId].hovered = false;
				}

				// 标记当前悬停的按钮为悬停状态
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
