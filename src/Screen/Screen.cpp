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
	//�v���C���[�����ȏ�i�񂾂�
	if (pl.GetPosX() >= 500)
	{
		//�O�ɂ����ʒu�ƍ�����ʒu���獷�����v�Z
		x += pl.GetPosX() - sX;
	}
	
	//���ɍs���߂��Ȃ��悤��
	if (x < 0)
	{
		x = 0;
	}

	//�v���C���[���X�|�[����
	//�v���C���[�������ʒu�Ȃ�J������������
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