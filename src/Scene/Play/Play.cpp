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

//������
void Play::Init()
{
	backHandle = LoadGraph("data/play/background.png");

	player.Init();
	map.Init(0);
	bound.Init();
	ball.Init();

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�ʏ폈��
void Play::Step()
{
	player.Step();
	bound.Step();
	ball.Step();
}

//�`�揈��
void Play::Draw()
{
	DrawGraph(0, 0, backHandle, true);

	bound.Draw();
	player.Draw();
	ball.Draw();
}

//�I������
void Play::Fin()
{
	bound.Fin();
	player.Fin();
	ball.Fin();

	//���̃V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}
