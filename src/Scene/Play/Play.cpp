#include"DxLib.h"
#include"Play.h"
#include"../Scene.h"
#include"../../Player/Player.h"

Player player;

//������
void Play::Init()
{
	player.Init();

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�ʏ폈��
void Play::Step()
{
	player.Step();

}

//�`�揈��
void Play::Draw()
{
	player.Draw();

}

//�I������
void Play::Fin()
{
	player.Fin();

	//���̃V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
