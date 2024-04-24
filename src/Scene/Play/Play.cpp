#include"DxLib.h"
#include"Play.h"
#include"../Scene.h"
#include"../../Player/Player.h"

Player player;

//‰Šú‰»
void Play::Init()
{
	player.Init();

	//’Êíˆ—‚ÖˆÚ“®
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//’Êíˆ—
void Play::Step()
{
	player.Step();

}

//•`‰æˆ—
void Play::Draw()
{
	player.Draw();

}

//I—¹ˆ—
void Play::Fin()
{
	player.Fin();

	//Ÿ‚ÌƒV[ƒ“‚ÉˆÚ“®
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
