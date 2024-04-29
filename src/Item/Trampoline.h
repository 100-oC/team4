#pragma once
#include"../Map/Map.h"
#include"../Player/Player.h"

const char TRAMPOLINE_IMAGE_PATH[] =		//�摜�p�X
{
	"data/Trampoline/�o�E���h.png",
};

const int TRA_IMAGE_SIZE_X = 96;
const int TRA_IMAGE_SIZE_Y = 32;

class Trampoline
{
private:
	int handle = -1;		//�摜

	//���W
	float x[TRAMPOLINE_MAX_NUM];
	float y[TRAMPOLINE_MAX_NUM];

	float radian[TRAMPOLINE_MAX_NUM];	//��]
	bool isUse[TRAMPOLINE_MAX_NUM];		//�g�p�t���O

public:
	void Init();
	void Step(Player &pl);
	void Draw(int pX, int pY);
	void Fin();
};