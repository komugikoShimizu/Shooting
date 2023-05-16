#include "DxLib.h"
#include "SceneManager.h"
#include "WindowCreate.h"
#include <Memory>

using namespace Scene;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)							// ＤＸライブラリ初期化処理
	{
		return -1;									// エラーが起きたら直ちに終了
	}

	auto draw = std::make_unique<WindowCreate>();	// ウィンドウ生成クラスのユニークポインタを生成
	SceneManager sceneManager = SceneManager();		// シーン管理クラス生成

	while (ProcessMessage() == 0)					// 正常な処理がされている間ゲーム続行
	{
		ClearDrawScreen();							// スクリーン初期化

		sceneManager.SceneUpdate();					// シーン更新処理

		ScreenFlip();								// スクリーン入れ替え

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;									// エスケープ入力時処理終了
		}
	}

	DxLib_End();									// ＤＸライブラリ使用の終了処理

	return 0;										// ソフトの終了 
}