#pragma once

class Result
{
private:
	int handle;

public:
	const char IMAGE_PATH[255] = { "data/result/result.png" };

	//初期化
	void Init();
	//通常処理
	void Step();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
};
