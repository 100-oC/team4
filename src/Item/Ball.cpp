#include"DxLib.h"
#include"Ball.h"

void Ball::Init()
{
	//�摜�̓ǂݍ���
	handle = LoadGraph(BALL_IMAGE_PATH);

	//�ϐ��̏�����
	memset(x, -1, sizeof(float));
	memset(y, -1, sizeof(float));
	memset(isUse, false, sizeof(bool));

	//�ǂݎ�����f�[�^�𔽉f
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
	//�g�����|�����\��
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