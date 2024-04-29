#include"DxLib.h"
#include"Screen.h"

void Screen::Init()
{
	x = 0;
	y = 0;

	sX = 0;
}

void Screen::Step(Player pl)
{
	//プレイヤーが一定以上進んだら
	if (pl.GetPosX() >= 500)
	{
		//前にいた位置と今いる位置から差分を計算
		x += pl.GetPosX() - sX;
	}
	
	//左に行き過ぎないように
	if (x < 0)
	{
		x = 0;
	}

	//プレイヤーリスポーン時
	//プレイヤーが初期位置ならカメラも初期化
	if (pl.GetPosX() == START_POS_X && pl.GetPosY() == START_POS_Y)
	{
		x = 0;
		y = 0;
	}

	sX = pl.GetPosX();
}

void Screen::Fin()
{

}