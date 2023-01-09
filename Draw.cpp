#include"Global.h"


void Draw1(int val)             //ªÊÕº
{
	menuL[6].isActivated = false;
	switch (val)
	{
	case 1:
	{
		DrawCircle();
		break;
	}
	case 2:
	{
		DrawRectangle();
		break;
	}
	case 3:
	{
		DrawLine();
		break;
	}
	case 4:
	{
		DrawPoly();
		break;
	}
	}
}


void DrawFromStorage(int index, std::vector<Storage>& vector)
{
	switch (vector[index].type)
	{
	case Circle:
	{
		switch (vector[index].fill)
		{
		case 0:
		{
			setcolor(vector[index].color);
			ege::circle(vector[index].data[0], vector[index].data[1], vector[index].data[2]);
			break;
		}
		case 1:
		{
			setfillcolor(vector[index].fillColor);
			setcolor(vector[index].color);
			ege::fillellipse(vector[index].data[0], vector[index].data[1], vector[index].data[2], vector[index].data[2]);     //ÃÓ≥‰Õ÷‘≤¿¥ª≠ÃÓ≥‰‘≤
			break;
		}

		}
		break;
	}
	case Tangle:
	{
		switch (vector[index].fill)
		{
		case 0:
		{
			setcolor(vector[index].color);
			ege::rectangle(vector[index].data[0], vector[index].data[1], vector[index].data[2], vector[index].data[3]);
			break;
		}
		case 1:
		{
			setfillcolor(vector[index].fillColor);
			setcolor(vector[index].color);
			ege::bar3d(vector[index].data[0], vector[index].data[1], vector[index].data[2], vector[index].data[3], 0, 0);
			break;
		}

		}
		break;
	}
	case Line:
	{
		setcolor(vector[index].color);
		ege::line(vector[index].data[0], vector[index].data[1], vector[index].data[2], vector[index].data[3]);
		break;
	}
	case Poly:
	{
		int pt[256] = { 0 };
		for (int i = 0;i < sizeof(vector[index].data) / sizeof(vector[index].data[0])-1;i++)
		{
			pt[i] = vector[index].data[i+1];
		}
		switch (vector[index].fill)
		{
		case 0:
		{
			setcolor(vector[index].color);
			ege::drawpoly(vector[index].data[0], pt);
			break;
		}
		case 1:
		{
			setfillcolor(vector[index].fillColor);
			setcolor(vector[index].color);
			ege::fillpoly(vector[index].data[0],pt);
			break;
		}

		}
		break;
	}
		
	}
}