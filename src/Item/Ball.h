#pragma once
#include"../Map/Map.h"

const char BALL_IMAGE_PATH[] =		//�摜�p�X
{
	"data/monster boal/�����X�^�[�{�[��.png",
};

class Ball
{
private:
	int handle = -1;		//�摜

	//���W
	float x[TRAMPOLINE_MAX_NUM];
	float y[TRAMPOLINE_MAX_NUM];

	bool isUse[TRAMPOLINE_MAX_NUM];		//�g�p�t���O

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};