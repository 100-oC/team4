#pragma once

const float START_POS_X = 50.0f;
const float START_POS_Y = 50.0f;

const float Y_SPEED = 0.1f;

const char PLAYER_IMAGE_NUM[] = "data/play/player.png";

class Player
{
public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	float GetPosX() { return x; }
	float GetPosY() { return y; }

	float GetRadian() { return radian; }
	void SetRadian(float set) { radian = set; }
	void SetSRadian(float set) { sRad = set; }

	float GetSpeed() { return speed; }
	void SetSpeed(float set) { speed = set; }

private:
	int handle;			//画像
	float x, y;			//座標
	float speed;		//速さ
	float radian;		//角度
	float sRad;			//追加角度
	bool direction;		//左右：trueが左	

};