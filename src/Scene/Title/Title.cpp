#include"DxLib.h"
#include"Title.h"
#include"../Scene.h"

//������
void Title::Init()
{

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//�ʏ폈��
void Title::Step()
{

	if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//�`�揈��
void Title::Draw()
{

}

//�I������
void Title::Fin()
{

	//���̃V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
