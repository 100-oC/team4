#include"DxLib.h"
#include"Play.h"
#include"../Scene.h"
#include"../../Player/Player.h"
#include"../../Map/Map.h"
#include"../../Item/Trampoline.h"
#include"../../Item/Ball.h"
#include"../../Screen/Screen.h"

Player player;
Trampoline bound;
Ball ball;
Screen screen;

int backHandle = - 1;

//������
void Play::Init()
{
	backHandle = LoadGraph("data/play/background.png");

	player.Init();

	//�}�b�v�̎�ށFMap.h�Q��
	map.Init(MAP_TEST);

	bound.Init();
	ball.Init();

	screen.Init();

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�ʏ폈��
void Play::Step()
{
	player.Step();
	screen.Step(player);
	bound.Step(player);
	ball.Step();
}

//�`�揈��
void Play::Draw()
{
	DrawGraph(0, 0, backHandle, true);

	bound.Draw(screen.GetPosX(),screen.GetPosY());
	player.Draw(screen.GetPosX(), screen.GetPosY());
	ball.Draw(screen.GetPosX(), screen.GetPosY());
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
