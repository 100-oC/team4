#include"../Scene/Scene.h"
#include"Player.h"

void Player::Init()
{
	handle = LoadGraph(PLAYER_IMAGE_NUM);

	x = START_POS_X;
	y = START_POS_Y;

	radian = 0.0f;

	xSpeed = 0.0f;
	ySpeed = 0.0f;

	direction = false;
}

void Player::Step()
{
	float sX = x, sY = y;	//保存座標

	//Yスピードを加算
	ySpeed += Y_SPEED;

	//下に落とす
	sY += ySpeed;

	//進行方向の角度を求める
	radian = GetAngle(x, y, sX, sY);

	//座標を確定
	y = sY;

	//プレイヤーが画面下に落ちたら
	if (y >= SCREEN_SIZE_Y + 50)
	{
		x = START_POS_X;
		y = START_POS_Y;

		ySpeed = 0.0f;
	}
}
void Player::Draw()
{
	DrawRotaGraph(x, y, 0.5f, radian, handle, true, direction);
}
void Player::Fin()
{

}
