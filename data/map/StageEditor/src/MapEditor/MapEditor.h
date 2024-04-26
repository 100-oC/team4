#pragma once
#include"../input/Input.h"
#include"../MathPlus/MathPlus.h"
#include"../Collision/Collision.h"

// define
#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

const int TRAMPOLINE_MAX_NUM = 50;	//�g�����|�����̍ő吔
const int BALL_MAX_NUM = 100;		//�{�[���̍ő吔
const char IMAGE_PATH[2][255] =		//�摜�p�X
{
	"data/�o�E���h.png",
	"data/�����X�^�[�{�[��.png",
};
const char FILE_PATH[] = { "data/mapData_No.bin" };		//�f�[�^�̃t�@�C���p�X

//��b�̍\����
struct Tra
{
	int handle = -1;		//�摜
	float x = -1, y = -1;	//���W
	float radian = 0.0f;	//��]
	bool isUse = false;		//�g�p�t���O
};
//�t�@�C���ɓǂݏ�������\����
struct SaveData
{
	Tra tra[TRAMPOLINE_MAX_NUM];	//�g�����|����
	Tra ball[BALL_MAX_NUM];			//�����X�^�[�{�[��
};

//�}�b�v�G�f�B�^
class MapEditor
{
public:
	//�ݒu����A�C�e��
	enum SET_ITEM
	{
		TRAMPOLINE,
		BALL,
	};

	void Init();
	void Step();
	void Draw();

private:
	SaveData setData;	//�ǂݏ����f�[�^

	int progress = 0;	//�i�s�x
	int moX, moY;		//�}�E�X�̍��W
	SET_ITEM sel = TRAMPOLINE;	//�ݒu�A�C�e��
	int moveItem = -1;	//���ݓ������Ă�A�C�e���̈���

	int screenNum = 0;	//��ʂ̈ʒu

	void SetItem();
	void MoveItem();

	void DeleteItem();
	void SelectItem();
	void TurnItem();
	void MapMove();

	void Save();
	void Load();
};