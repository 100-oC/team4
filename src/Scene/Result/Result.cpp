#include"DxLib.h"
#include"Result.h"
#include"../Scene.h"

//‰Šú‰»
void Result::Init()
{
	handle = LoadGraph(IMAGE_PATH);

	//’Êíˆ—‚ÖˆÚ“®
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;
}

//’Êíˆ—
void Result::Step()
{
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

//•`‰æˆ—
void Result::Draw()
{
	DrawGraph(0, 0, handle, true);
}

//I—¹ˆ—
void Result::Fin()
{

	//Ÿ‚ÌƒV[ƒ“‚ÉˆÚ“®
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
