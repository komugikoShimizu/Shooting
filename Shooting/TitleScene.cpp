#include "TitleScene.h"

namespace Scene
{
	TitleScene::TitleScene(SceneType* ptr)
	{
		nextScene = ptr;	// シーン更新ポインタを設定
	}

	TitleScene::~TitleScene() {}

	void TitleScene::SceneUpdate()
	{
		DrawString(0, 0, "Shooting Game", GetColor(255, 255, 255));	// 文字を出力
		if (CheckHitKey(KEY_INPUT_SPACE))							// スペースキー入力を確認したら
		{
			*nextScene = SceneType::GAME;							// シーン更新ポインタをゲームシーンに設定
		}
	}
}