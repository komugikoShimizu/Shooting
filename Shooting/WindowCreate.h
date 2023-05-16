#pragma once
#include "DxLib.h"

namespace Manager
{
	/// <summary>
	/// ウィンドウ生成クラス
	/// </summary>
	class WindowCreate
	{
	public:
		WindowCreate();
		~WindowCreate();
	};

	inline WindowCreate::WindowCreate()
	{
		SetMainWindowText("Shooting");					// ウィンドウ名
		ChangeWindowMode(TRUE);							// ウィンドウモードで起動
		SetGraphMode(640, 480, 32);						// ウィンドウサイズ
		SetWindowSizeChangeEnableFlag(TRUE, TRUE);		// ウィンドウサイズを変更化にする
		DxLib_Init();									// ウィンドウ作成、DXLib起動
		SetDrawScreen(DX_SCREEN_BACK);					// 書き込む画面を生成
	}

	inline WindowCreate::~WindowCreate() {}
}