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
	int handle;			//æ
	float x, y;			//ÀW
	float xSpeed, ySpeed;
	float radian;		//px
	bool direction;		//¶EFtrueª¶	

};