#include"DxLib.h"
#include"Map.h"

Map map;

void Map::Init(int mapNum)
{
	LoadMap(mapNum);
}

void Map::LoadMap(int mapNum)
{
	FILE* fp;
	fopen_s(&fp, FILE_PATH[mapNum], "rb");
	if (fp != NULL)
	{
		fread(&mapData, sizeof(mapData), 1, fp);
		fclose(fp);
	}
}