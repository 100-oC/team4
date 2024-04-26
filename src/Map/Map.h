#pragma once

const int TRAMPOLINE_MAX_NUM = 50;	//�g�����|�����̍ő吔
const int BALL_MAX_NUM = 100;		//�{�[���̍ő吔
const char FILE_PATH[2][255] = //�f�[�^�̃t�@�C���p�X
{	"data/map/mapData_Test.bin",
	"" };		

//const char IMAGE_PATH[2][255] =		//�摜�p�X
//{
//	"data/�o�E���h.png",
//	"data/�����X�^�[�{�[��.png",
//};


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

class Map 
{
private:

public:
	SaveData mapData;

	void Init(int mapNum);
	void LoadMap(int mapNum);

	void SetPosTra();
	void SetPosBall();
};
extern Map map;