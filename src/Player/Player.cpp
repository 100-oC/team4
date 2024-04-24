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
	float sX = x, sY = y;	//�ۑ����W

	//Y�X�s�[�h�����Z
	ySpeed += Y_SPEED;

	//���ɗ��Ƃ�
	sY += ySpeed;

	//�i�s�����̊p�x�����߂�
	radian = GetAngle(x, y, sX, sY);

	//���W���m��
	y = sY;

	//�v���C���[����ʉ��ɗ�������
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
