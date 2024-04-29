#include"../Scene/Scene.h"
#include"Player.h"

void Player::Init()
{
	handle = LoadGraph(PLAYER_IMAGE_NUM);

	x = START_POS_X;
	y = START_POS_Y;

	radian = ChangeDegToRad(90);	//プレイヤーを90°回転
	sRad = 0;

	speed = 0.0f;

	direction = false;
}

void Player::Step()
{
	float sX = x, sY = y;	//保存座標

	//Yスピードを加算
	speed += Y_SPEED;

	//変更された角度を戻す
	if (speed > 0)
	{
		if (sRad > 0)
		{
			sRad -= 0.05f;
		}
		else if (sRad < 0)
		{
			sRad += 0.05f;
		}
	}

	//下に落とす
	Move(radian+ sRad, speed, sX, sY, direction);
	
	//進行方向の角度を求める
	if(speed>=0)
	{
		//radian = GetAngle(x, y, sX, sY);
	}

	//座標を確定
	y = sY;
	x = sX;

	//プレイヤーが画面下に落ちたら
	if (y >= SCREEN_SIZE_Y + 50)
	{
		x = START_POS_X;
		y = START_POS_Y;

		speed = 0.0f;
	}
}
void Player::Draw()
{
	DrawRotaGraphF(x, y, 0.5f, radian+ sRad, handle, true, direction);

	//当たり判定
	DrawBox(x - 32 / 2, y - 32 / 2, x+32/2, y+32/2, GetColor(255, 0, 0), false);
}
void Player::Fin()
{

}
