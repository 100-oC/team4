#include"DxLib.h"
#include"Title.h"
#include"../Scene.h"
#include"../../Map/Map.h"

//������
void Title::Init()
{
	Sound::Init();

	memset(x, 0, sizeof(int));
	memset(y, 0, sizeof(int));

	for (int i = 0; i < IMAGE_MAX_NUM; i++)
	{
		handle[i] = LoadGraph(IMAGE_PATH[i]);
	}

	x[START] = SCREEN_SIZE_X / 2 - START_SIZE / 2;
	y[START] = SCREEN_SIZE_Y / 2 + 100;

	mouse = 0;

	Sound::Bgm::Play(BGM_TITLE);
	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//�ʏ폈��
void Title::Step()
{
	GetMousePoint(&x[MOUSE_1], &y[MOUSE_1]);

	mouse = 0;
	if (Collision::Rect(
		x[START]+100, y[START]+100, START_SIZE-160, START_SIZE-160,
		x[MOUSE_1], y[MOUSE_1], MOUSE_SIZE, MOUSE_SIZE))
	{
		mouse = 1;
	}

	if (Input::Mouse::Push(MOUSE_INPUT_LEFT) && mouse == 1)
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
		Sound::Se::Play(SE_SYSTEM);
	}
}

//�`�揈��
void Title::Draw()
{
	for (int i = 0; i <= START; i++)
	{
		DrawGraph(x[i], y[i], handle[i], true);
	}

	DrawGraph(x[MOUSE_1], y[MOUSE_1], handle[MOUSE_1 + mouse], true);
}

//�I������
void Title::Fin()
{
	Sound::Bgm::StopSound(BGM_TITLE);
	Sound::Bgm::Play(BGM_PLAY);

	map.goal.SetStage();
	//���̃V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}
