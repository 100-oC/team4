#pragma once

class Title
{
public:
	//‰Šú‰»
	void Init();
	//’Êíˆ—
	void Step();
	//•`‰æˆ—
	void Draw();
	//I—¹ˆ—
	void Fin();

	enum IMAGE_ID
	{
		BACKGROUND,
		START,

		MOUSE_1,
		MOUSE_2,

		IMAGE_MAX_NUM
	};
	const char IMAGE_PATH[IMAGE_MAX_NUM][255] =
	{
		"data/title/all.png",
		"data/title/start.png",

		"data/title/mouse1.png",
		"data/title/mouse2.png",
	};

	const int START_SIZE = 226;
	const int MOUSE_SIZE = 111;

private:
	int handle[IMAGE_MAX_NUM];
	int mouse;

	int x[IMAGE_MAX_NUM], y[IMAGE_MAX_NUM];
};
