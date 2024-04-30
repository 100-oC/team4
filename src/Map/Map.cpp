#include"DxLib.h"
#include"Map.h"
#include"../Scene/Scene.h"

Map map;

void Map::Init(int map1Num, int map2Num, int map3Num)
{
	LoadMap(map1Num, map2Num, map3Num);
	goal.Init();
}

void Map::LoadMap(int map1Num, int map2Num, int map3Num)
{
	FILE* fp1;
	fopen_s(&fp1, FILE1_PATH[map1Num], "rb");
	if (fp1 != NULL)
	{
		fread(&mapData1, sizeof(mapData1), 1, fp1);
		fclose(fp1);
	}

	FILE* fp2;
	fopen_s(&fp2, FILE2_PATH[map2Num], "rb");
	if (fp2 != NULL)
	{
		fread(&mapData2, sizeof(mapData2), 1, fp2);
		fclose(fp2);
	}

	FILE* fp3;
	fopen_s(&fp3, FILE3_PATH[map3Num], "rb");
	if (fp3 != NULL)
	{
		fread(&mapData3, sizeof(mapData3), 1, fp3);
		fclose(fp3);
	}

}

//==============================================================

void Goal::Init()
{
	x = SCREEN_SIZE_X * 3;
	handle = LoadGraph(IMAGE_PATH);
}

void Goal::Step(float plX, float plY)
{
	if (plX >= x + 50)
	{
		stage++;
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

void Goal::Draw(int screenX)
{
	DrawGraph(x - screenX, 0, handle, true);
}