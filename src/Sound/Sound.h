#pragma once

enum BGM_TYPE
{	
	//音楽
	BGM_TITLE,	//タイトル画面
	BGM_PLAY,	//プレイ画面
	BGM_RESULT,	//リザルト画面

	BGM_MAX_NUM
};

enum SE_TYPE
{
	SE_SYSTEM,		//システム
	SE_GOAL,		//ゴール

	SE_MAX_NUM
};

class Sound
{
public:
	//サウンドまとめ初期化
	static void Init();

	class Bgm
	{
	private:
		//音ハンドル
		static int handle[BGM_MAX_NUM];

	public:
		//BGMの初期化
		static void Init();

		//BGMの通常処理：種類
		static void Play(int type);
		//BGMの音量調節：種類,音量(ﾊﾟｰｾﾝﾃｰｼﾞ)
		static void SetVolume(int type,int volume);
		//BGMの停止：種類
		static void StopSound(int type);
	};

	class Se
	{
	private:
		//音ハンドル
		static int handle[SE_MAX_NUM];

	public:
		//SEの初期化
		static void Init();

		//SEの通常処理：種類
		static void Play(int type);
		//SEの音量調節：種類,音量(ﾊﾟｰｾﾝﾃｰｼﾞ)
		static void SetVolume(int type,int volume);
	};
};


/*使い方指南
	//Finで使う
	DeleteSoundMem(〇〇〇);
	//全削除
	InitSoundMem();

	//BGMの停止
	StopSoundMem(Hundle);

	//音量の設定（0〜255）（↓は80％の音量で出力）
	ChangeVolumeSoundMem( 255 * 80 / 100, Handle );

	//効果音の再生
	PlaySoundMem(Hundle, DX_PLAYTYPE_BACK, true);
	//BGMの再生
	PlaySoundMem(Hundle, DX_PLAYTYPE_LOOP, true);
*/