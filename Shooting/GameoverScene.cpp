#include "GameoverScene.h"

namespace Scene
{
	GameoverScene::GameoverScene(SceneType* ptr)
	{
		nextScene = ptr;	// シーン更新ポインタを設定
	}

	void GameoverScene::SceneUpdate()
	{
		DrawString(0,0,"Game Over...",GetColor(255,255,255));	// 文字出力

		if (CheckHitKey(KEY_INPUT_SPACE))						// スペースキー入力を確認したら
		{
			*nextScene = SceneType::TITLE;						// シーン更新ポインタにタイトルシーンを設定
		}
	}
}