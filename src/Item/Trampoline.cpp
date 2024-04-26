#include"DxLib.h"
#include"Trampoline.h"
#include"../MathPlus/MathPlus.h"

void Trampoline::Init()
{
	//�摜�̓ǂݍ���
	handle = LoadGraph(TRAMPOLINE_IMAGE_PATH);

	//�ϐ��̏�����
	memset(x, -1.0f, sizeof(float));
	memset(y, -1.0f, sizeof(float));
	memset(radian, 0.0f, sizeof(float));
	memset(isUse, false, sizeof(bool));

	//�ǂݎ�����f�[�^�𔽉f
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

		if (Collision::Rect(pl.GetPosX(), pl.GetPosY(), 64, 64,
			x[i] - TRA_IMAGE_SIZE_X / 2,
			y[i] - TRA_IMAGE_SIZE_Y / 2,
			TRA_IMAGE_SIZE_X, TRA_IMAGE_SIZE_Y))
		{
			
		}
	}

}

void Trampoline::Draw()
{
	//�g�����|�����\��
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