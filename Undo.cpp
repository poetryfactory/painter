#include"Global.h"
std::vector<Storage> undoBuffer;
std::vector<Storage> globalBuffer;
bool isUndo = 0;


void Undo()
{
	if (globalBuffer.empty())
		return;
	else
	{
		setfillcolor(getbkcolor());
		bar(2, 202, 1278, 958);
		undoBuffer.push_back(globalBuffer[globalBuffer.size()-1]);
		globalBuffer.pop_back();
		for (int i = 0;i < globalBuffer.size();i++)
		{
			DrawFromStorage(i, globalBuffer);
		}
		delay_ms(0);
		isUndo = 1;
		return;
	}
}

void Redo()
{
	if (!isUndo||undoBuffer.empty())
		return;
	else
	{
		DrawFromStorage(undoBuffer.size() - 1,undoBuffer);
		delay_ms(0);
		globalBuffer.push_back(undoBuffer[undoBuffer.size() - 1]);
		undoBuffer.pop_back();
	}
}