#pragma once
#include"../Map/Map.h"

const char TRAMPOLINE_IMAGE_PATH[] =		//�摜�p�X
{
	"data/Trampoline/�o�E���h.png",
};

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
	void Step();
	void Draw();
	void Fin();
};