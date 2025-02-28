#include"DxLib.h"
#include"Result.h"
#include"../Scene.h"

//初期化
void Result::Init()
{
	handle = LoadGraph(IMAGE_PATH);

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

	Sound::Bgm::Play(BGM_RESULT);
}

//通常処理
void Result::Step()
{
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
		Sound::Se::Play(SE_SYSTEM);
	}
}

//描画処理
void Result::Draw()
{
	DrawGraph(0, 0, handle, true);
}

//終了処理
void Result::Fin()
{
	Sound::Bgm::StopSound(BGM_RESULT);
	//次のシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
