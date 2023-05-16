#include "ClearScene.h"

namespace Scene
{
	ClearScene::ClearScene(SceneType* ptr)
	{
		nextScene = ptr;	// シーン更新ポインタを設定
	}

	void ClearScene::SceneUpdate()
	{
		DrawString(0, 0, "Game Clear", GetColor(255, 255, 255));	// 文字出力

		if (CheckHitKey(KEY_INPUT_SPACE))							// スペースキー入力を確認したら
		{
			*nextScene = SceneType::TITLE;							// シーン更新ポインタにタイトルシーンを設定
		}
	}
}