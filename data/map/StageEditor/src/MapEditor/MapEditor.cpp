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
	case 0:	//新規or継続
		if (Input::Key::Push(KEY_INPUT_1))
		{
			progress = 1;	//新規
		}
		else if (Input::Key::Push(KEY_INPUT_2))
		{
			progress = 2;	//継続
		}

		break;

	case 1://新規（エディット）

		//マウスの座標取得
		GetMousePoint(&moX, &moY);

		//シフトが押されていたら
		if (Input::Key::Keep(KEY_INPUT_LSHIFT))
		{
			//アイテムの移動
			MoveItem();
		}
		//押されていなかったら
		else
		{
			//アイテム設置
			SetItem();
		}

		//アイテム削除
		DeleteItem();
		//設置アイテムの切り替え
		SelectItem();
		//マップの移動
		MapMove();

		//保存
		Save();

		break;

	case 2://継続

		//読み込み
		Load();
		//エディットへ
		progress = 1;

		break;
	default:
		break;
	}

}

void MapEditor::Draw()
{
	//背景
	DrawBox(0, 0, 1280, 720, GetColor(50, 50, 50), true);

	//進行度で変化
	switch (progress)
	{
	case 0://選ぶ
		DrawFormatString(0, 0, GetColor(255, 255, 255), "1：新規作成　2：読み取り");
		break;

	case 1://新規
		//操作説明
		DrawFormatString(0, 720 - 160, GetColor(255, 0, 0), 
			"右クリック 　　　　　　　 ：選択中のアイテムを配置 ");
		DrawFormatString(0, 720 - 140, GetColor(255, 0, 0), 
			"+左シフト　　　　　　　 　：瀬智済みアイテムを移動 ");
		DrawFormatString(0, 720 - 120, GetColor(255, 0, 0), 
			"左コントロール+左クリック ：対象を左に回転 ");
		DrawFormatString(0, 720 - 100, GetColor(255, 0, 0), 
			"左コントロール+右クリック ：対象を右に回転 ");
		DrawFormatString(0, 720 - 80, GetColor(255, 0, 0), 
			"左クリック 　　　　　　　 ：アイテムを削除 ");
		DrawFormatString(0, 720 - 60, GetColor(255, 0, 0), 
			"エンター   　　　　 　　　：設置アイテム切替え ");
		DrawFormatString(0, 720 - 40, GetColor(255, 0, 0),
			"左右 or AD 　　　　　　 　：マップの移動 ");
		DrawFormatString(0, 720 - 20, GetColor(255, 0, 0),
			"Ctrl+s　 　　　　　　 　　：保存");

		//設置可能アイテムの説明
		if (sel == TRAMPOLINE)
		{
			DrawFormatString(0, 0, GetColor(255, 0, 0), "選択中のアイテム：トランポリン");
		}
		else
		{
			DrawFormatString(0, 0, GetColor(255, 0, 0), "選択中のアイテム：モンスターボール");
		}

		//アイテム移動中の座標
		if(moveItem!=-1)
		{
			DrawFormatString(0, 20, GetColor(255, 0, 0), "トランポリン　x：%.2f, y：%.2f", setData.tra[moveItem].x, setData.tra[moveItem].y);
			DrawFormatString(0, 40, GetColor(255, 0, 0), "ボール　　　　x：%.2f, y：%.2f", setData.ball[moveItem - BALL_MAX_NUM].x, setData.ball[moveItem - BALL_MAX_NUM].y);
		}
		TurnItem();

		//トランポリン表示
		for (int i = 0; i < TRAMPOLINE_MAX_NUM; i++)
		{
			if (setData.tra[i].isUse)
			{
				DrawRotaGraph(setData.tra[i].x - screenNum, setData.tra[i].y, 1.0f, setData.tra[i].radian, setData.tra[i].handle, true);
			}
		}
		//ボール表示
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
	//削除
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
	//Ctrl + S　保存
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
