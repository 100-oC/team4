#pragma once
#include"../Player/Player.h"

class Screen
{
public:
	void Init();
	void Step(Player pl);
	void Fin();

	int GetPosX() { return x; }
	int GetPosY() { return y; }

private:
	int x, y;
	int sX;	//À•W‚Ì•Û‘¶
};