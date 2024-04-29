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
	int handle;			//画像
	float x, y;			//座標
	float speed;		//速さ
	float radian;		//角度
	float sRad;			//追加角度
	bool direction;		//左右：trueが左	

	const int circleRadius = 10;    // 振り子の球の半径
	const double gravity = 50.8;     // 重力加速度
	double angle;             // 振り子の角度（度）
	double angularVelocity;   // 角速度
	double pendulumLength;      // 振り子の長さ
	bool isPendulumActive;  // 振り子運動がアクティブかどうか
	int nearestPole;				// 最も近いポール
	// プレイヤーの速度
	float velocityX;
	float velocityY;

	// 速度の最大値
	const int maxVelocity = 10;
	// 現在接続しているポールのインデックス
	int currentPoleIndex = -1;
	// 放された後の経過時間を表す変数
	float timeStep;

	int nearestPoleIndex;
};