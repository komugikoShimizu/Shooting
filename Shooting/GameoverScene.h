#pragma once
#include <windows.h>
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// ゲームオーバーシーンのクラス
	/// </summary>
	class GameoverScene : public SceneBase
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		GameoverScene();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ptr">シーン更新ポインタ</param>
		GameoverScene(SceneType* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~GameoverScene();

		/// <summary>
		/// シーン更新処理
		/// </summary>
		void SceneUpdate() override;

		/// <summary>
		/// シーンタイプ取得用関数
		/// </summary>
		/// <returns>このシーンのタイプ</returns>
		SceneType GetSceneType() override;
	};

	inline GameoverScene::GameoverScene() {}

	inline GameoverScene::~GameoverScene() {}

	inline SceneType GameoverScene::GetSceneType() { return SceneType::GAMEOVER; }
}