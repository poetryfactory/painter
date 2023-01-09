#include"Global.h"


void SaveAsFile()       //存储(尚未完成)
{
	std::ofstream ofs;
	char file[100] = {};
	char ext[6] = ".draw";
	inputbox_getline("保存文件", "输入文件名以保存在项目文件夹，输入绝对路径以存储在任意文件夹", file, 90);
	strcat(file, ext);
	ofs.open(file, std::ios::trunc);
	ofs << globalBuffer.size() << std::endl;
	for (int i = 0;i < globalBuffer.size();i++)
	{
		ofs << globalBuffer[i].type << " ";
		ofs << globalBuffer[i].width << " ";
		ofs << globalBuffer[i].color << " ";
		ofs << globalBuffer[i].fill << " ";
		if (globalBuffer[i].fill == false)
			ofs << NULL << " ";
		else
			ofs << globalBuffer[i].fillColor << " ";
		if (globalBuffer[i].type == Circle)
		{
			ofs << globalBuffer[i].data[0] << " ";
			ofs << globalBuffer[i].data[1] << " ";
			ofs << globalBuffer[i].data[2] <<std::endl;
		}
		else if (globalBuffer[i].type == Tangle || globalBuffer[i].type == Line)
		{
			ofs << globalBuffer[i].data[0] << " ";
			ofs << globalBuffer[i].data[1] << " ";
			ofs << globalBuffer[i].data[2] << " ";
			ofs << globalBuffer[i].data[3] << std::endl;
		}
		else if (globalBuffer[i].type == Poly)
		{
			for (int j = 0;j < 2 * globalBuffer[i].data[0];j++)
			{
				ofs << globalBuffer[i].data[j] << " ";
			}
			ofs << globalBuffer[i].data[2 * globalBuffer[i].data[0]] << std::endl;
		}
	}
	ofs.close();
}


//Type type;
//int width;
//int color;
//bool fill;
//int fillColor;
//int data[256];