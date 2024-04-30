#include"DxLib.h"
#include"Ball.h"

void Ball::Init()
{
	//画像の読み込み
	handle = LoadGraph(BALL_IMAGE_PATH);

	//変数の初期化
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		x[i] = -1;
		y[i] = -1;
		isUse[i] = false;
	}

	//読み取ったデータを反映
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (!map.mapData1.ball[i].isUse)
		{
			continue;
		}
		for (int n = 0; n < BALL_MAX_NUM; n++)
		{
			if (isUse[n])
			{
				continue;
			}

			x[n] = map.mapData1.ball[i].x;
			y[n] = map.mapData1.ball[i].y;
			isUse[n] = true;
			break;
		}
	}

	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (!map.mapData2.ball[i].isUse)
		{
			continue;
		}
		for (int n = 0; n < BALL_MAX_NUM; n++)
		{
			if (isUse[n])
			{
				continue;
			}

			x[n] = map.mapData2.ball[i].x;
			y[n] = map.mapData2.ball[i].y;
			isUse[n] = true;
			break;
		}
	}

	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (!map.mapData3.ball[i].isUse)
		{
			continue;
		}
		for (int n = 0; n < BALL_MAX_NUM; n++)
		{
			if (isUse[n])
			{
				continue;
			}

			x[n] = map.mapData3.ball[i].x;
			y[n] = map.mapData3.ball[i].y;
			isUse[n] = true;
			break;
		}
	}
}

void Ball::Step()
{

}

void Ball::Draw(int pX, int pY)
{
	//トランポリン表示
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (isUse[i])
		{
			DrawRotaGraphF(x[i] - pX, y[i] - pY, 1.0f, 0.0f, handle, true);
		}
	}
}

void Ball::Fin()
{
}