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

//初期化
void Play::Init()
{
	backHandle = LoadGraph("data/play/background.png");

	player.Init();

	//マップの種類：Map.h参照
	map.Init(MAP_TEST);

	bound.Init();
	ball.Init();

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//通常処理
void Play::Step()
{
	player.Step();
	bound.Step();
	ball.Step();
}

//描画処理
void Play::Draw()
{
	DrawGraph(0, 0, backHandle, true);

	bound.Draw();
	player.Draw();
	ball.Draw();
}

//終了処理
void Play::Fin()
{
	bound.Fin();
	player.Fin();
	ball.Fin();

	//次のシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
