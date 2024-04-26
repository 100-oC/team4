#include"DxLib.h"
#include"MapEditor.h"

void MapEditor::Init()
{
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		setData.tra[i].handle = LoadGraph(IMAGE_PATH[0]);
	}
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		setData.ball[i].handle = LoadGraph(IMAGE_PATH[1]);
	}
}

void MapEditor::Step()
{
	switch (progress)
	{
	case 0:	//�V�Kor�p��
		if (Input::Key::Push(KEY_INPUT_1))
		{
			progress = 1;	//�V�K
		}
		else if (Input::Key::Push(KEY_INPUT_2))
		{
			progress = 2;	//�p��
		}

		break;

	case 1://�V�K�i�G�f�B�b�g�j

		//�}�E�X�̍��W�擾
		GetMousePoint(&moX, &moY);

		//�V�t�g��������Ă�����
		if (Input::Key::Keep(KEY_INPUT_LSHIFT))
		{
			//�A�C�e���̈ړ�
			MoveItem();
		}
		//������Ă��Ȃ�������
		else
		{
			//�A�C�e���ݒu
			SetItem();
		}

		//�A�C�e���폜
		DeleteItem();
		//�ݒu�A�C�e���̐؂�ւ�
		SelectItem();
		//�}�b�v�̈ړ�
		MapMove();

		//�ۑ�
		Save();

		break;

	case 2://�p��

		//�ǂݍ���
		Load();
		//�G�f�B�b�g��
		progress = 1;

		break;
	default:
		break;
	}

}

void MapEditor::Draw()
{
	//�w�i
	DrawBox(0, 0, 1280, 720, GetColor(50, 50, 50), true);

	//�i�s�x�ŕω�
	switch (progress)
	{
	case 0://�I��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "1�F�V�K�쐬�@2�F�ǂݎ��");
		break;

	case 1://�V�K
		//�������
		DrawFormatString(0, 720 - 160, GetColor(255, 0, 0), 
			"�E�N���b�N �@�@�@�@�@�@�@ �F�I�𒆂̃A�C�e����z�u ");
		DrawFormatString(0, 720 - 140, GetColor(255, 0, 0), 
			"+���V�t�g�@�@�@�@�@�@�@ �@�F���q�ς݃A�C�e�����ړ� ");
		DrawFormatString(0, 720 - 120, GetColor(255, 0, 0), 
			"���R���g���[��+���N���b�N �F�Ώۂ����ɉ�] ");
		DrawFormatString(0, 720 - 100, GetColor(255, 0, 0), 
			"���R���g���[��+�E�N���b�N �F�Ώۂ��E�ɉ�] ");
		DrawFormatString(0, 720 - 80, GetColor(255, 0, 0), 
			"���N���b�N �@�@�@�@�@�@�@ �F�A�C�e�����폜 ");
		DrawFormatString(0, 720 - 60, GetColor(255, 0, 0), 
			"�G���^�[   �@�@�@�@ �@�@�@�F�ݒu�A�C�e���ؑւ� ");
		DrawFormatString(0, 720 - 40, GetColor(255, 0, 0),
			"���E or AD �@�@�@�@�@�@ �@�F�}�b�v�̈ړ� ");
		DrawFormatString(0, 720 - 20, GetColor(255, 0, 0),
			"Ctrl+s�@ �@�@�@�@�@�@ �@�@�F�ۑ�");

		//�ݒu�\�A�C�e���̐���
		if (sel == TRAMPOLINE)
		{
			DrawFormatString(0, 0, GetColor(255, 0, 0), "�I�𒆂̃A�C�e���F�g�����|����");
		}
		else
		{
			DrawFormatString(0, 0, GetColor(255, 0, 0), "�I�𒆂̃A�C�e���F�����X�^�[�{�[��");
		}

		//�A�C�e���ړ����̍��W
		if(moveItem!=-1)
		{
			DrawFormatString(0, 20, GetColor(255, 0, 0), "�g�����|�����@x�F%.2f, y�F%.2f", setData.tra[moveItem].x, setData.tra[moveItem].y);
			DrawFormatString(0, 40, GetColor(255, 0, 0), "�{�[���@�@�@�@x�F%.2f, y�F%.2f", setData.ball[moveItem - BALL_MAX_NUM].x, setData.ball[moveItem - BALL_MAX_NUM].y);
		}
		TurnItem();

		//�g�����|�����\��
		for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
		{
			if (setData.tra[i].isUse)
			{
				DrawRotaGraph(setData.tra[i].x - screenNum, setData.tra[i].y, 1.0f, setData.tra[i].radian, setData.tra[i].handle, true);
			}
		}
		//�{�[���\��
		for (int i = 0; i < BALL_MAX_NUM; i++)
		{
			if (setData.ball[i].isUse)
			{
				DrawRotaGraph(setData.ball[i].x - screenNum, setData.ball[i].y, 1.0f, setData.ball[i].radian, setData.ball[i].handle, true);
			}
		}

		break;
	default:
		break;
	}
}

//========================================================================================

void MapEditor::SetItem()
{
	switch (sel)
	{
	case TRAMPOLINE:
		for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
		{
			if (!setData.tra[i].isUse)
			{
				if (Input::Mouse::Push(MOUSE_INPUT_LEFT) && !Input::Key::Keep(KEY_INPUT_LCONTROL))
				{
					setData.tra[i].x = moX + screenNum;
					setData.tra[i].y = moY;
					setData.tra[i].isUse = true;

					break;
				}
			}
		}
		break;

	case BALL:
		for (int i = 0; i < BALL_MAX_NUM; i++)
		{
			if (!setData.ball[i].isUse)
			{
				if (Input::Mouse::Push(MOUSE_INPUT_LEFT) && !Input::Key::Keep(KEY_INPUT_LCONTROL))
				{
					setData.ball[i].x = moX + screenNum;
					setData.ball[i].y = moY;
					setData.ball[i].isUse = true;

					break;
				}
			}
		}
		break;

	default:
		break;
	}
}

void MapEditor::MoveItem()
{
	for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
	{
		if (setData.tra[i].isUse)
		{
			if (Input::Mouse::Keep(MOUSE_INPUT_LEFT))
			{
				if (moveItem == -1 || moveItem == i)
				{
					if (Collision::Rect(moX, moY, 5, 5, (int)setData.tra[i].x - 96 / 2 - screenNum, (int)setData.tra[i].y - 32 / 2, 96, 32))
					{
						setData.tra[i].x = moX + screenNum;
						setData.tra[i].y = moY;
						moveItem = i;
					}
				}
			}
		}
	}
	for (int i = 0; i < BALL_MAX_NUM; i++)
	{
		if (setData.ball[i].isUse)
		{
			if (Input::Mouse::Keep(MOUSE_INPUT_LEFT))
			{
				if (moveItem == -1 || moveItem == BALL_MAX_NUM + i)
				{
					if (GetDistance(moX, moY, setData.ball[i].x - screenNum, setData.ball[i].y) < 32)
					{
						setData.ball[i].x = moX + screenNum;
						setData.ball[i].y = moY;
						moveItem = BALL_MAX_NUM + i;
					}
				}
			}
		}
	}

	if (Input::Mouse::Release(MOUSE_INPUT_LEFT))
	{
		moveItem = -1;
	}
}

//----------------------------------------------

void MapEditor::DeleteItem()
{
	//�폜
	if (Input::Mouse::Push(MOUSE_INPUT_RIGHT) && !Input::Key::Keep(KEY_INPUT_LCONTROL))
	{
		for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
		{
			if (setData.tra[i].isUse)
			{

				if (Collision::Rect(moX + screenNum, moY, 5, 5, (int)setData.tra[i].x - 96 / 2 + screenNum, (int)setData.tra[i].y - 32 / 2, 96, 32))
				{
					setData.tra[i].x = -1;
					setData.tra[i].y = -1;
					setData.tra[i].isUse = false;
					setData.tra[i].radian = 0.0f;
				}

			}
		}
		for (int i = 0; i < BALL_MAX_NUM; i++)
		{
			if (setData.ball[i].isUse)
			{
				if (GetDistance(moX + screenNum, moY, setData.ball[i].x + screenNum, setData.ball[i].y) < 32)
				{
					setData.ball[i].x = -1;
					setData.ball[i].y = -1;
					setData.ball[i].isUse = false;
					setData.ball[i].radian = 0.0f;

				}
			}
		}
	}
}

void MapEditor::SelectItem()
{
	if (Input::Key::Push(KEY_INPUT_RETURN)|| Input::Key::Push(KEY_INPUT_TAB))
	{
		moveItem = -1;
		if (sel == TRAMPOLINE)
		{
			sel = BALL;
		}
		else
		{
			sel = TRAMPOLINE;
		}
	}
}

void MapEditor::MapMove()
{
	if (Input::Key::Push(KEY_INPUT_RIGHT) || Input::Key::Push(KEY_INPUT_D))
	{
		screenNum += SCREEN_SIZE_X;
	}
	else if (Input::Key::Push(KEY_INPUT_LEFT) || Input::Key::Push(KEY_INPUT_A))
	{
		screenNum -= SCREEN_SIZE_X;
		if (screenNum <= 0)
		{
			screenNum = 0;
		}
	}
}

void MapEditor::TurnItem()
{
	if (Input::Key::Keep(KEY_INPUT_LCONTROL))
	{
		for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
		{
			if (setData.tra[i].isUse)
			{
				if (Input::Mouse::Push(MOUSE_INPUT_LEFT))
				{
					if (Collision::Rect(moX, moY, 5, 5, (int)setData.tra[i].x - 96 / 2 - screenNum, (int)setData.tra[i].y - 32 / 2, 96, 32))
					{
						setData.tra[i].radian -= ChangeDegToRad(45);
					}
				}
				if (Input::Mouse::Push(MOUSE_INPUT_RIGHT))
				{
					if (Collision::Rect(moX, moY, 5, 5, (int)setData.tra[i].x - 96 / 2 - screenNum, (int)setData.tra[i].y - 32 / 2, 96, 32))
					{
						setData.tra[i].radian += ChangeDegToRad(45);
					}
				}
			}
		}
	}
}

//----------------------------------------------

void MapEditor::Save()
{
	//Ctrl + S�@�ۑ�
	if (Input::Key::Keep(KEY_INPUT_LCONTROL) && Input::Key::Keep(KEY_INPUT_S))
	{
		FILE* fp;
		fopen_s(&fp, FILE_PATH, "wb");
		if (fp != NULL)
		{
			fwrite(&setData, sizeof(setData), 1, fp);
			fclose(fp);
		}
	}
}

void MapEditor::Load()
{
	FILE* fp;
	fopen_s(&fp, FILE_PATH, "rb");
	if (fp != NULL)
	{
		fread(&setData, sizeof(setData), 1, fp);
		fclose(fp);
	}
}
