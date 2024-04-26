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

//‰Šú‰»
void Play::Init()
{
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
