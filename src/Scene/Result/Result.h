#pragma once

class Result
{
private:
	int handle;

public:
	const char IMAGE_PATH[255] = { "data/result/result.png" };

	//‰Šú‰»
	void Init();
	//’Êíˆ—
	void Step();
	//•`‰æˆ—
	void Draw();
	//I—¹ˆ—
	void Fin();
};
