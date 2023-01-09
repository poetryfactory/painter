#ifndef GLOBAL_H
#define GLOBAL_H
#endif
#define SHOW_CONSOLE
#define BUTTON_SIZE 7
#define BUTTON_ID_NONE -1

#include"graphics.h"
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<iostream>

typedef struct MenuList
{
	int curIndex;
	int lIndex;
	int nIndex;
	void (*currentFunc)();
	bool isActivated;

} Menus;

typedef enum Type
{
	Circle, Tangle, Line, Poly
};

typedef struct GraphicStorage
{
	Type type;
	int width;
	int color;
	bool fill;
	int fillColor;
	int data[256];
} Storage;

typedef struct RectangleButton
{
	int x1, y1;		/* 左上角*/
	int x2, y2;		/* 右下角*/
	const char* text;
	bool hovered;	/* 是否悬停*/
	bool pressed;	/* 是否按下*/
} Button;

extern const int buttonSize[6];
extern const char* strings[6][7];

extern PIMAGE image;
extern mouse_msg mMsg;
extern key_msg kMsg;
extern Menus menuL[7];
extern Button buttonArray[BUTTON_SIZE];

extern std::vector<Storage> globalBuffer;
extern std::vector<Storage> undoBuffer;

extern int currentMenuIndex;
extern int index;
extern int size;
extern int menuKey;
extern int lineWidth;
extern int color;
extern int fillColor;
extern int shapeVal;
extern int radius;
extern int colors[5];
extern int pressedButtonID;
extern int hoveredButtonId;
extern int btnId;
extern int xMouse, yMouse;

extern bool redraw;
extern bool isFillingMode;
extern bool isRead;
extern bool isSettingColor;
extern bool isUndo;
extern bool isSettingFLColor;
extern bool drawingMode;
extern bool keyIsPressed[256];

extern char sWidth[20];
extern char mousep[30];

void Init();
void InitGraph();
void Draw1(int val);
void DrawFromStorage(int index, std::vector<Storage> &vector);
void IsFilled();
void ReadFile();
void Error();
void MainMenu();
void Return();
void NextMenu();
void Menu();
bool unDoDetect(key_msg msg);
void ClearMenu();
void ClearPos();
void ClearStorage();
void SaveAsFile();
void SelectColor();
void SelectFLColor();
void SelectMode();
void SelectShape();
void DrawCircle();
void DrawRectangle();
void DrawPoly();
void DrawLine();
void FreeDrawing();
void Undo();
void Redo();
void Search();
void ButtonLogic(int stage);
void StoreButton(Button buttonArray[],int stage);
bool insideButton(const Button* button, int x, int y);          //判断鼠标在按钮范围内
void DrawButton(const Button buttonArray[], int length);        //初始化按钮
int SearchButton(int x, int y, const Button buttonArray[], int length);
Storage StoreCircle(int x, int y, int radius);
Storage StoreRectangle(int x1,int y1,int x2,int y2);
Storage StoreLine(int x1, int y1, int x2, int y2);
Storage StorePoly(int cnt,int arr[]);