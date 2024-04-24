#include"DxLib.h"
#include"Play.h"
#include"../Scene.h"
#include"../../Player/Player.h"

Player player;

//初期化
void Play::Init()
{
	player.Init();

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//通常処理
void Play::Step()
{
	player.Step();

}

//描画処理
void Play::Draw()
{
	player.Draw();

}

//終了処理
void Play::Fin()
{
	player.Fin();

	//次のシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
