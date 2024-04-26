#pragma once
#include"../input/Input.h"
#include"../MathPlus/MathPlus.h"
#include"../Collision/Collision.h"

// define
#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720		// Y方向の画面サイズを指定

const int TRAMPOLINE_MAX_NUM = 50;	//トランポリンの最大数
const int BALL_MAX_NUM = 100;		//ボールの最大数
const char IMAGE_PATH[2][255] =		//画像パス
{
	"data/バウンド.png",
	"data/モンスターボール.png",
};
const char FILE_PATH[] = { "data/mapData_No.bin" };		//データのファイルパス

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

//マップエディタ
class MapEditor
{
public:
	//設置するアイテム
	enum SET_ITEM
	{
		TRAMPOLINE,
		BALL,
	};

	void Init();
	void Step();
	void Draw();

private:
	SaveData setData;	//読み書きデータ

	int progress = 0;	//進行度
	int moX, moY;		//マウスの座標
	SET_ITEM sel = TRAMPOLINE;	//設置アイテム
	int moveItem = -1;	//現在動かしてるアイテムの引数

	int screenNum = 0;	//画面の位置

	void SetItem();
	void MoveItem();

	void DeleteItem();
	void SelectItem();
	void TurnItem();
	void MapMove();

	void Save();
	void Load();
};