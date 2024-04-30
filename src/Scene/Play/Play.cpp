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

	int map1Num = GetRand(MAP1_MAX_NUM - 1);
	int map2Num = GetRand(MAP2_MAX_NUM - 1);
	int map3Num = GetRand(MAP3_MAX_NUM - 1);
	//�}�b�v�̎�ށFMap.h�Q��
	map.Init(map1Num, map2Num, map3Num);

	bound.Init();
	ball.Init();
	
	screen.Init();

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}

//�ʏ폈��
void Play::Step()
{
	player.Step(ball.ALLGetBallx(), ball.ALLGetBally());
	screen.Step(player);
	bound.Step(player);
	ball.Step();
	map.goal.Step(player.GetPosX(), player.GetPosY());
}

//�`�揈��
void Play::Draw()
{
	DrawGraph(0, 0, backHandle, true);

	map.goal.Draw(screen.GetPosX());

	bound.Draw(screen.GetPosX(),screen.GetPosY());
	player.Draw(screen.GetPosX(), screen.GetPosY(), ball.ALLGetBallx(), ball.ALLGetBally());
	ball.Draw(screen.GetPosX(), screen.GetPosY());
}

//�I������
void Play::Fin()
{
	bound.Fin();
	player.Fin();
	ball.Fin();

	int st = map.goal.GetStage();
	if (st >= 10)
	{
		//���̃V�[���Ɉړ�
		g_CurrentSceneID = SCENE_ID_INIT_RESULT;
		Sound::Bgm::StopSound(BGM_PLAY);
	}
	else
	{
		g_CurrentSceneID = SCENE_ID_INIT_PLAY;
	}
}
