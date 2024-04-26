#pragma once

const int TRAMPOLINE_MAX_NUM = 50;	//トランポリンの最大数
const int BALL_MAX_NUM = 100;		//ボールの最大数

enum MAP_ID
{
	MAP_TEST,
	MAP_0,
	MAP_1,

	MAP_MAX_NUM
};

const char FILE_PATH[MAP_MAX_NUM][255] = //データのファイルパス
{	"data/map/mapData_Test.bin",
	"data/map/mapData_No0.bin", 		
	"data/map/mapData_No1.bin", };		

//基礎の構造体
struct Tra
{
	int handle = -1;		//画像
	float x = -1, y = -1;	//座標
	float radian = 0.0f;	//回転
	bool isUse = false;		//使用フラグ
};
//ファイルに読み書きする構造体
struct SaveData
{
	Tra tra[TRAMPOLINE_MAX_NUM];	//トランポリン
	Tra ball[BALL_MAX_NUM];			//モンスターボール
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