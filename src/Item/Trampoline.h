#pragma once
#include"../Map/Map.h"
#include"../Player/Player.h"

const char TRAMPOLINE_IMAGE_PATH[] =		//画像パス
{
	"data/Trampoline/バウンド.png",
};

const int TRA_IMAGE_SIZE_X = 96;
const int TRA_IMAGE_SIZE_Y = 32;

class Trampoline
{
private:
	int handle = -1;		//画像

	//座標
	float x[TRAMPOLINE_MAX_NUM];
	float y[TRAMPOLINE_MAX_NUM];

	float radian[TRAMPOLINE_MAX_NUM];	//回転
	bool isUse[TRAMPOLINE_MAX_NUM];		//使用フラグ

public:
	void Init();
	void Step(Player &pl);
	void Draw(int pX, int pY);
	void Fin();
};