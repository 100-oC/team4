#pragma once

const int TRAMPOLINE_MAX_NUM = 50;	//�g�����|�����̍ő吔
const int BALL_MAX_NUM = 100;		//�{�[���̍ő吔

enum MAP1_ID
{
	MAP1_1,
	MAP1_2,
	MAP1_3,
	MAP1_4,
	MAP1_5,

	MAP1_MAX_NUM
};
enum MAP2_ID
{
	MAP2_1,
	MAP2_2,
	MAP2_3,
	MAP2_4,
	MAP2_5,

	MAP2_MAX_NUM
};
enum MAP3_ID
{
	MAP3_1,
	MAP3_2,
	MAP3_3,
	MAP3_4,
	MAP3_5,

	MAP3_MAX_NUM
};


const char FILE1_PATH[MAP1_MAX_NUM][255] = //�f�[�^�̃t�@�C���p�X
{			
	"data/map/1/mapData_No1.bin", 
	"data/map/1/mapData_No2.bin", 
	"data/map/1/mapData_No3.bin", 
	"data/map/1/mapData_No4.bin", 
	"data/map/1/mapData_No5.bin", 
};		
const char FILE2_PATH[MAP2_MAX_NUM][255] = //�f�[�^�̃t�@�C���p�X
{
	"data/map/2/mapData_No1.bin",
	"data/map/2/mapData_No2.bin",
	"data/map/2/mapData_No3.bin",
	"data/map/2/mapData_No4.bin",
	"data/map/2/mapData_No5.bin",
};
const char FILE3_PATH[MAP3_MAX_NUM][255] = //�f�[�^�̃t�@�C���p�X
{
	"data/map/3/mapData_No1.bin",
	"data/map/3/mapData_No2.bin",
	"data/map/3/mapData_No3.bin",
	"data/map/3/mapData_No4.bin",
	"data/map/3/mapData_No5.bin",
};

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

class Goal
{
private:
	int x;
	int handle;
	int stage;

public:
	const char IMAGE_PATH[255] = { "data/play/goal.png" };
	void Init();
	void Step(float plX, float plY);
	void Draw(int screenX);

	int GetStage() { return stage; }
	void SetStage(int set = 0) { stage = set; }
};

class Map 
{
private:

public:
	SaveData mapData1;
	SaveData mapData2;
	SaveData mapData3;

	Goal goal;

	void Init(int map1Num,int map2Num,int map3Num);
	void LoadMap(int map1Num, int map2Num, int map3Num);
};
extern Map map;