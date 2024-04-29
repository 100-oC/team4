#include"DxLib.h"
#include"Trampoline.h"
#include"../MathPlus/MathPlus.h"

void Trampoline::Init()
{
	//画像の読み込み
	handle = LoadGraph(TRAMPOLINE_IMAGE_PATH);

	//変数の初期化
	memset(x, -1, sizeof(float));
	memset(y, -1, sizeof(float));
	memset(radian, 0, sizeof(float));
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

void Trampoline::Step(Player &pl)
{
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		if (!map.mapData.tra[i].isUse)
		{
			continue;
		}

		//当たっていたら
		if (Collision::Rect(pl.GetPosX()-32/2, pl.GetPosY()-32/2, 32, 32,
			x[i] - TRA_IMAGE_SIZE_X / 2,
			y[i] - TRA_IMAGE_SIZE_Y / 2,
			TRA_IMAGE_SIZE_X, TRA_IMAGE_SIZE_Y))
		{
			float rad = 0.0f;
			//角度が進行方向側
			if (pl.GetRadian() >= 0)
			{
				//90°から見ての角度
				rad = 90 - ChangeRadToDeg(pl.GetRadian());

			}
			//↑の逆
			else
			{
				//90°から見ての角度
				rad = -90 + ChangeRadToDeg(pl.GetRadian());
			}
			//角度を設定
			pl.SetSRadian(ChangeDegToRad(rad * 2));
			//速さを少し早める
			pl.SetSpeed(pl.GetSpeed() * -1.1f);

		}
	}

}

void Trampoline::Draw(int pX, int pY)
{
	//トランポリン表示
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		if (isUse[i])
		{
			DrawRotaGraphF(x[i] - pX, y[i] - pY, 1.0f, radian[i], handle, true);
		}
	}
}

void Trampoline::Fin()
{

}