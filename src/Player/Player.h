#pragma once
#include<math.h>
#include"../Item/Ball.h"
const float START_POS_X = 50.0f;
const float START_POS_Y = 50.0f;

const float Y_SPEED = 0.01f;

const char PLAYER_IMAGE_NUM[] = "data/play/player.png";

class Player
{
public:
	void Init();
	void Step(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM]);
	void Draw(int pX, int pY, float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM]);
	void Fin();

	float GetPosX() { return x; }
	float GetPosY() { return y; }

	float GetRadian() { return radian; }
	void SetRadian(float set) { radian = set; }
	void SetSRadian(float set) { sRad = set; }

	float GetSpeed() { return speed; }
	void SetSpeed(float set) { speed = set; }

	double CalculateDistance(int x1, int y1, int x2, int y2) 
	{ return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

	void InitializePendulum(int poleIndex, float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM]);

	void ConnectToNearestPole(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM]);

	void UpdatePendulum(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM]);

	void ReleaseKey();

	int GetnearestPoleIndex() { return nearestPoleIndex; }

	float GetvelocityX() { return velocityX; }
	float GetvelocityY() { return velocityY; }
private:
	int handle;			//�摜
	float x, y;			//���W
	float speed;		//����
	float radian;		//�p�x
	float sRad;			//�ǉ��p�x
	bool direction;		//���E�Ftrue����	

	const int circleRadius = 10;    // �U��q�̋��̔��a
	const double gravity = 50.8;     // �d�͉����x
	double angle;             // �U��q�̊p�x�i�x�j
	double angularVelocity;   // �p���x
	double pendulumLength;      // �U��q�̒���
	bool isPendulumActive;  // �U��q�^�����A�N�e�B�u���ǂ���
	int nearestPole;				// �ł��߂��|�[��
	// �v���C���[�̑��x
	float velocityX;
	float velocityY;

	// ���x�̍ő�l
	const int maxVelocity = 10;
	// ���ݐڑ����Ă���|�[���̃C���f�b�N�X
	int currentPoleIndex = -1;
	// �����ꂽ��̌o�ߎ��Ԃ�\���ϐ�
	float timeStep;

	int nearestPoleIndex;
};