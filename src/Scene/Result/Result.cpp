#include"DxLib.h"
#include"Result.h"
#include"../Scene.h"

//������
void Result::Init()
{
	handle = LoadGraph(IMAGE_PATH);

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

	Sound::Bgm::Play(BGM_RESULT);
}

//�ʏ폈��
void Result::Step()
{
	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
		Sound::Se::Play(SE_SYSTEM);
	}
}

//�`�揈��
void Result::Draw()
{
	DrawGraph(0, 0, handle, true);
}

//�I������
void Result::Fin()
{
	Sound::Bgm::StopSound(BGM_RESULT);
	//���̃V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}
