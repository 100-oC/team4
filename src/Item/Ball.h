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
	void Draw(int pX, int pY);
	void Fin();

	// �z��̗v�f�ɃA�N�Z�X���邽�߂̃Q�b�^�[�֐�
	float ALLGetBallx(int i) const {
		if (i >= 0 && i < BALL_MAX_NUM) return x[i];
		else return -1.0f;
	}
	float ALLGetBally(int i) const {
		if (i >= 0 && i < BALL_MAX_NUM) return y[i];
		else return -1.0f;
	}
	// �z��S�̂ւ̎Q�Ƃ�Ԃ��Q�b�^�[�֐�
	float* ALLGetBallx() { return x; }
	float* ALLGetBally() { return y; }
};