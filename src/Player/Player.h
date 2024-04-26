#pragma once

const float START_POS_X = 50.0f;
const float START_POS_Y = 50.0f;

const float Y_SPEED = 0.5f;

const char PLAYER_IMAGE_NUM[] = "data/play/player.png";

class Player
{
public:
	void Init();
	void Step();
	void Draw();
	void Fin();

private:
	int handle;			//画像
	float x, y;			//座標
	float speed;
	float radian;		//角度
	bool direction;		//左右：trueが左	

};