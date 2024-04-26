#include"DxLib.h"
#include"Play.h"
#include"../Scene.h"
#include"../../Player/Player.h"
#include"../../Map/Map.h"
#include"../../Item/Trampoline.h"
#include"../../Item/Ball.h"

Player player;
Trampoline bound;
Ball ball;

int backHandle = - 1;

//‰Šú‰»
void Play::Init()
{
	backHandle = LoadGraph("data/play/background.png");

	player.Init();
	map.Init(0);
	bound.Init();
	ball.Init();

	//’Êíˆ—‚ÖˆÚ“®
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//’Êíˆ—
void Play::Step()
{
	player.Step();
	bound.Step();
	ball.Step();
}

//•`‰æˆ—
void Play::Draw()
{
	DrawGraph(0, 0, backHandle, true);

	bound.Draw();
	player.Draw();
	ball.Draw();
}

//I—¹ˆ—
void Play::Fin()
{
	bound.Fin();
	player.Fin();
	ball.Fin();

	//Ÿ‚ÌƒV[ƒ“‚ÉˆÚ“®
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
