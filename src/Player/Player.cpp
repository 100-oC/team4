#include"../Scene/Scene.h"
#include"Player.h"
#include"../Item/Ball.h"
#include<math.h>
#include <vector>

void Player::Init()
{
	handle = LoadGraph(PLAYER_IMAGE_NUM);

	x = START_POS_X;
	y = START_POS_Y;

	radian = ChangeDegToRad(0);	//�v���C���[��90����]
	sRad = 0;

	speed = 0.0f;

	direction = false;

	
	angle = 0.0;            
	angularVelocity = 0.0;  
	pendulumLength = 0;     
	isPendulumActive = false;  

	velocityX = 0;
	velocityY = 0;
	currentPoleIndex = -1;
	float timeStep = 0;

	nearestPoleIndex = -1;

	isBounce = false;
}

void Player::Step(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	//float sX = x, sY = y;	//�ۑ����W

	////Y�X�s�[�h�����Z
	//speed += Y_SPEED;

	////�ύX���ꂽ�p�x��߂�
	//if (speed > 0)
	//{
	//	if (sRad > 0)
	//	{
	//		sRad -= 0.05f;
	//	}
	//	else if (sRad < 0)
	//	{
	//		sRad += 0.05f;
	//	}
	//}

	////���ɗ��Ƃ�
	//Move(radian+ sRad, speed, sX, sY, direction);
	//
	////�i�s�����̊p�x�����߂�
	//if(speed>=0)
	//{
	//	//radian = GetAngle(x, y, sX, sY);
	//}

	////���W���m��
	//y = sY;
	//x = sX;

	if (angle > 360)angle = 0.0;

	if (CheckHitKey(KEY_INPUT_F) && !isPendulumActive) {

		ConnectToNearestPole(poleX, poleY); // F�L�[�������ꂽ�Ƃ��̏���
	}
	if (!CheckHitKey(KEY_INPUT_F) && isPendulumActive) {
		isPendulumActive = false;
		ReleaseKey();
	}
	// �v���C���[�̍��W���X�V
	x += velocityX;
	y += velocityY;
	// �d�͂��V�~�����[�g
	velocityY += 0.5;

	UpdatePendulum(poleX, poleY); // �U��q�̍X�V

	Bounce();

	//�v���C���[����ʉ��ɗ�������
	if (y >= SCREEN_SIZE_Y + 50&& !CheckHitKey(KEY_INPUT_F))
	{
		x = START_POS_X;
		y = START_POS_Y;

		speed = 0.0f;
		velocityY = 0.0;
		velocityX = 0.0;
	}

}
void Player::Draw(int pX, int pY, float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	// �A�N�e�B�u�ȃ|�[���̐U��q�̐���`��
	if (isPendulumActive && currentPoleIndex != -1) {
		// �U��q�̐���`��
		DrawLine(poleX[currentPoleIndex] - pX, poleY[currentPoleIndex] - pY, x - pX, y - pY, GetColor(255, 255, 255));
	}
	DrawRotaGraphF(x - pX, y - pY, 0.5f, radian + sRad, handle, true, direction);

	//�����蔻��
	//DrawBox(x - 32 / 2-pX, y - 32 / 2-pY, x+32/2-pX, y+32/2-pY, GetColor(255, 0, 0), false);
}
void Player::Fin()
{

}
void Player::InitializePendulum(int poleIndex,float poleX[BALL_MAX_NUM],float poleY[BALL_MAX_NUM])
{
	// �v���C���[�̌��݈ʒu����|�[���܂ł̋������v�Z
	pendulumLength = CalculateDistance(x, y, poleX[poleIndex], poleY[poleIndex]);

	// �v���C���[�ƃ|�[����Y���W���߂��ꍇ�̏���
	if ((poleY[poleIndex] - y) <= 100 && (y - poleY[poleIndex]) <= 100)
	{
		// �v���C���[���|�[���̍��ɂ���ꍇ
		if (x < poleX[poleIndex]) {
			angle = 270.0;
		}
		// �v���C���[���|�[���̉E�ɂ���ꍇ
		else {
			angle = 90.0;
		}
	}
	// �v���C���[�ƃ|�[����X���W���߂��ꍇ�̏���
	else if ((poleX[poleIndex] - x) <= 100 && (x - poleX[poleIndex]) <= 100)
	{
		// �v���C���[���|�[���̏�ɂ���ꍇ
		if (y > poleY[poleIndex]){
			// �v���C���[���|�[���̍��ɂ���ꍇ
			if (x < poleX[poleIndex])angle = 350.0;
			// �v���C���[���|�[���̉E�ɂ���ꍇ
			else angle = 10.0;
		}
		// �v���C���[���|�[���̉��ɂ���ꍇ
		else {
			// �v���C���[���|�[���̍��ɂ���ꍇ
			if (x < poleX[poleIndex])angle = 190.0;
			// �v���C���[���|�[���̉E�ɂ���ꍇ
			else angle = 170.0;
		}
	}
	else
	{
		// �v���C���[�̌��݈ʒu����|�[���܂ł̊p�x���v�Z
		angle = atan2(poleY[poleIndex] - y, poleX[poleIndex] - x) * 180.0 / DX_PI;

		// �v���C���[�̈ʒu�ɉ����Ċp�x�𒲐�
		if ((x > poleX[poleIndex] && y > poleY[poleIndex]) ||
			(x < poleX[poleIndex] && y < poleY[poleIndex])) {
			angle += 180.0;
		}
	}


	// �p���x���v�Z
	angularVelocity = (velocityX * cos(DX_PI * angle / 180.0) + velocityY * sin(DX_PI * angle / 180.0)) / pendulumLength;

	// �v���C���[�̏����ʒu���|�[���̈ʒu�Ɗp�x����ݒ�
	x = poleX[poleIndex] + int(pendulumLength * cos(DX_PI * angle / 180.0));
	y = poleY[poleIndex] + int(pendulumLength * sin(DX_PI * angle / 180.0));
}

void Player::ConnectToNearestPole(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	timeStep = 0.0;
	nearestPoleIndex = -1;
	double minDistance = DBL_MAX; // �ŏ���������ɑ傫�Ȓl�ŏ�����

	// �S�Ẵ|�[���Ƃ̋������v�Z���A�ł��߂��|�[����������
	for (int i = 0; i < BALL_MAX_NUM; ++i) {
		double distance = CalculateDistance(x, y, poleX[i], poleY[i]);
		if (distance < minDistance) {
			minDistance = distance;
			nearestPoleIndex = i;
		}
	}

	// �ł��߂��|�[�������������ꍇ�A�U��q�̏��������s��
	if (nearestPoleIndex != -1) {
		velocityX = 0;
		velocityY = 0;
		InitializePendulum(nearestPoleIndex,
			poleX, poleY);
		currentPoleIndex = nearestPoleIndex; // ���݂̃|�[�����X�V
		isPendulumActive = true; // �U��q�^�����A�N�e�B�u�ɂ���
	}
}

void Player::UpdatePendulum(float poleX[BALL_MAX_NUM], float poleY[BALL_MAX_NUM])
{
	if (isPendulumActive && currentPoleIndex != -1) {
		// �p�x�����W�A���ɕϊ�
		double radian = angle * DX_PI / 180.0;

		// �p���x�̍X�V
		angularVelocity += (-gravity / pendulumLength * sin(radian));
		// �p�x�̍X�V
		angle += angularVelocity;

		// �U��q�̒[�̍��W���X�V
		x = poleX[currentPoleIndex] + int(pendulumLength * sin(radian));
		y = poleY[currentPoleIndex] + int(pendulumLength * cos(radian)); // Y���W�̍X�V���@���C��
	}
}

void Player::ReleaseKey() 
{
	isPendulumActive = false;

	// �p�x�����W�A���ɕϊ�
	double radian = angle * DX_PI / 180.0;

	// �p���x�ɉ����ď����x��ݒ�
	double initialVelocityX = pendulumLength * angularVelocity * cos(radian);
	double initialVelocityY = pendulumLength * angularVelocity * sin(radian);

	// �d�͂̉e�����l���������x�̌v�Z
	velocityX = initialVelocityX;
	velocityY = -initialVelocityY - (gravity * timeStep);

	// ���Ԃ̌o�߂ɂ�鑬�x�̍X�V
	timeStep += 0.1;

	// ���x�̐���
	if (abs(velocityX) > maxVelocity) velocityX = (velocityX > 0) ? maxVelocity : -maxVelocity;
	if (abs(velocityY) > maxVelocity) velocityY = (velocityY > 0) ? maxVelocity : -maxVelocity;
}

void Player::Bounce() 
{
	if (isBounce) {
		x += velocityX;
		y += velocityY;
		if (x == velocityX || y == velocityY)
			isBounce = false;
	}
}

void Player::SetisBounce()
{
	if (!isBounce)isBounce = true;
	else isBounce = false;
}

void Player::SetvelocityX(float i)
{
	velocityX = i;
}
void Player::SetvelocityY(float i)
{
	velocityY = i;
}