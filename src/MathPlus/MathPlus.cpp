#include"DxLib.h"
#define _USE_MATH_DEFINES	//�~����
#include<math.h>

#include"MathPlus.h"

//�Q����P�ւ̐i�s�����ƈړ��ʁF��������������XY1  �������ꏊXY2  X��Y�̂ǂ�����o����  ������
float GetMoving(float x1, float y1, float x2, float y2, char moji,float s)
{
	float x = x2 - x1;
	float y = y2 - y1;

	float n = x * x + y * y;

	n = sqrtf(n);

	if (moji == 'x')
	{
		return x / n * s;
	}
	else if (moji == 'y')
	{
		return y / n * s;
	}
	return 0;
}

//2�_�Ԃ̋����F�J�n�n�_XY�@�I���n�_XY
float GetDistance(float startX, float startY, float endX, float endY)
{
	float num = 0.0f;
	num = ((startX - endX) * (startX - endX)) + ((startY - endY) * (startY - endY));
	num = sqrtf(num);

	return num;
}

//1����2�ւ̊p�x(���W�A��)�F��������ꏊXY�@��������������XY
float GetAngle(float Ax, float Ay, float Bx, float By)
{
	float num = 0.0f;
	num=atan2f(By - Ay, Bx - Ax);

	return num;
}

//�x�N�g���̓��ς����߂Đ�������Ԃ��F��������������XY�@��������ꏊXY
bool GetInnerProduct(float Ax, float Ay, float Bx, float By)
{
	float num = 0.0f;

	num = Bx * Ax + By * Ay;
	if (num > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�x�N�^�[�̑����Z
VECTOR AddVec(VECTOR vecA, VECTOR vecB)
{
	VECTOR ret;

	ret.x = vecA.x + vecB.x;
	ret.y = vecA.y + vecB.y;
	ret.z = vecA.z + vecB.z;

	return ret;
}
VECTOR AddVec(VECTOR vecA, float x, float y, float z)
{
	VECTOR ret;

	ret.x = vecA.x + x;
	ret.y = vecA.y + y;
	ret.z = vecA.z + z;

	return ret;
}

//�x�N�^�[�̈����Z
VECTOR SudVec(VECTOR vecA, VECTOR vecB)
{
	VECTOR ret;

	ret.x = vecA.x - vecB.x;
	ret.y = vecA.y - vecB.y;
	ret.z = vecA.z - vecB.z;

	return ret;
}

//�x�����W�A���ɕϊ��i�����F�x�j
float ChangeDegToRad(float degree)
{
	return degree * (float)M_PI / 180.0f;
}