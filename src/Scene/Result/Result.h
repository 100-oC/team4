#pragma once

class Result
{
private:
	int handle;

public:
	const char IMAGE_PATH[255] = { "data/result/result.png" };

	//������
	void Init();
	//�ʏ폈��
	void Step();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();
};
