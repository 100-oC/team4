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
	void Draw(int pX, int pY);
	void Fin();

	// 配列の要素にアクセスするためのゲッター関数
	float ALLGetBallx(int i) const {
		if (i >= 0 && i < BALL_MAX_NUM) return x[i];
		else return -1.0f;
	}
	float ALLGetBally(int i) const {
		if (i >= 0 && i < BALL_MAX_NUM) return y[i];
		else return -1.0f;
	}
	// 配列全体への参照を返すゲッター関数
	float* ALLGetBallx() { return x; }
	float* ALLGetBally() { return y; }
};