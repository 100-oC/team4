#include"../Scene/Scene.h"
#include"Player.h"

void Player::Init()
{
	handle = LoadGraph(PLAYER_IMAGE_NUM);

	x = START_POS_X;
	y = START_POS_Y;

	radian = ChangeDegToRad(90);	//�v���C���[��90����]
	sRad = 0;

	speed = 0.0f;

	direction = false;
}

void Player::Step()
{
	float sX = x, sY = y;	//�ۑ����W

	//Y�X�s�[�h�����Z
	speed += Y_SPEED;

	//�ύX���ꂽ�p�x��߂�
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

	//���ɗ��Ƃ�
	Move(radian+ sRad, speed, sX, sY, direction);
	
	//�i�s�����̊p�x�����߂�
	if(speed>=0)
	{
		//radian = GetAngle(x, y, sX, sY);
	}

	//���W���m��
	y = sY;
	x = sX;

	//�v���C���[����ʉ��ɗ�������
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

	//�����蔻��
	DrawBox(x - 32 / 2, y - 32 / 2, x+32/2, y+32/2, GetColor(255, 0, 0), false);
}
void Player::Fin()
{

}
