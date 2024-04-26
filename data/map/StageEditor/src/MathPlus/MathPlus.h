#pragma once

//�Q����P�ւ̐i�s�����ƈړ��ʁF��������������XY1  �������ꏊXY2  'x'��'y'�̂ǂ�����o����  ������
float GetMoving(float x1, float y1, float x2, float y2, char moji, float s);

//2�_�Ԃ̋����F�J�n�n�_XY�@�I���n�_XY
float GetDistance(float startX, float startY, float endX, float endY);

//1����2�ւ̊p�x(���W�A��)�F��������ꏊXY�@��������������XY
float GetAngle(float Ax, float Ay, float Bx, float By);

//�x�N�g���̓��ς����߂Đ�������Ԃ��F��������ꏊXY�@��������������XY
bool GetInnerProduct(float Ax, float Ay, float Bx, float By);

//�x�N�^�[�̑����Z
VECTOR AddVec(VECTOR vecA, VECTOR vecB);
VECTOR AddVec(VECTOR vecA, float x = 0.0f, float y = 0.0f, float z = 0.0f);

//�x�N�^�[�̈����Z
VECTOR SudVec(VECTOR vecA, VECTOR vecB);

//�x�����W�A���ɕϊ��i�����F�x�j
float ChangeDegToRad(float degree);