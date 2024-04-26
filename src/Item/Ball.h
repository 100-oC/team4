#pragma once
#include"../Map/Map.h"

const char BALL_IMAGE_PATH[] =		//画像パス
{
	"data/monster boal/モンスターボール.png",
};

class Ball
{
private:
	int handle = -1;		//画像

	//座標
	float x[TRAMPOLINE_MAX_NUM];
	float y[TRAMPOLINE_MAX_NUM];

	bool isUse[TRAMPOLINE_MAX_NUM];		//使用フラグ

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};