#include"DxLib.h"
#include"Ball.h"

void Ball::Init()
{
	//画像の読み込み
	handle = LoadGraph(BALL_IMAGE_PATH);

	//変数の初期化
	memset(x, -1, sizeof(float));
	memset(y, -1, sizeof(float));
	memset(isUse, false, sizeof(bool));

	//読み取ったデータを反映
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (map.mapData.ball[i].isUse)
		{
			x[i] = map.mapData.ball[i].x;
			y[i] = map.mapData.ball[i].y;
			isUse[i] = true;
		}
	}
}

void Ball::Step()
{

}

void Ball::Draw()
{
	//トランポリン表示
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (isUse[i])
		{
			DrawRotaGraphF(x[i], y[i], 1.0f, 0.0f, handle, true);
		}
	}
}

void Ball::Fin()
{

}