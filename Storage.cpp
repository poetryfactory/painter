#include "Global.h"

int index = 0;
Storage storage[256];

Storage StoreCircle(int x, int y, int radius)
{
	Storage temp;
	temp.type = Circle;
	temp.color = colors[color];
	temp.width = lineWidth;
	temp.fill = isFillingMode;
	if (isFillingMode)
		temp.fillColor = colors[fillColor];
	temp.data[0] = x;
	temp.data[1] = y;
	temp.data[2] = radius;
	return temp;
}

Storage StoreRectangle(int x1, int y1, int x2, int y2)
{
	Storage temp;
	temp.type = Tangle;
	temp.color = colors[color];
	temp.width = lineWidth;
	temp.fill = isFillingMode;
	if (isFillingMode)
		temp.fillColor = colors[fillColor];
	temp.data[0] = x1;
	temp.data[1] = y1;
	temp.data[2] = x2;
	temp.data[3] = y2;
	return temp;
}

Storage StoreLine(int x1, int y1, int x2, int y2)
{
	Storage temp;
	temp.type = Line;
	temp.color = colors[color];
	temp.width = lineWidth;
	temp.data[0] = x1;
	temp.data[1] = y1;
	temp.data[2] = x2;
	temp.data[3] = y2;
	return temp;
}

Storage StorePoly(int cnt, int arr[])
{
	Storage temp;
	temp.type = Poly;
	temp.color = colors[color];
	temp.width = lineWidth;
	temp.fill = isFillingMode;
	if (isFillingMode)
		temp.fillColor = colors[fillColor];
	temp.data[0] = cnt;
	for (int i = 1;i <= 2*cnt;i++)
	{
		temp.data[i] = arr[i-1];
	}
	return temp;
}

void ClearStorage()
{
	globalBuffer.clear();
	undoBuffer.clear();
}