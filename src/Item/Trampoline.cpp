#include"DxLib.h"
#include"Trampoline.h"

void Trampoline::Init()
{
	//画像の読み込み
	handle = LoadGraph(TRAMPOLINE_IMAGE_PATH);

	//変数の初期化
	memset(x, -1.0f, sizeof(float));
	memset(y, -1.0f, sizeof(float));
	memset(radian, 0.0f, sizeof(float));
	memset(isUse, false, sizeof(bool));

	//読み取ったデータを反映
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		if (map.mapData.tra[i].isUse)
		{
			x[i] = map.mapData.tra[i].x;
			y[i] = map.mapData.tra[i].y;
			radian[i] = map.mapData.tra[i].radian;
			isUse[i] = true;
		}
	}
}

void Trampoline::Step()
{

}

void Trampoline::Draw()
{
	//トランポリン表示
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		if (isUse[i])
		{
			DrawRotaGraph(x[i], y[i], 1.0f, radian[i], handle, true);
		}
	}
}

void Trampoline::Fin()
{

}