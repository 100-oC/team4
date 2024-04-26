#pragma once

const int TRAMPOLINE_MAX_NUM = 50;	//�g�����|�����̍ő吔
const int BALL_MAX_NUM = 100;		//�{�[���̍ő吔

enum MAP_ID
{
	MAP_TEST,
	MAP_0,
	MAP_1,

	MAP_MAX_NUM
};

const char FILE_PATH[MAP_MAX_NUM][255] = //�f�[�^�̃t�@�C���p�X
{	"data/map/mapData_Test.bin",
	"data/map/mapData_No0.bin", 		
	"data/map/mapData_No1.bin", };		

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