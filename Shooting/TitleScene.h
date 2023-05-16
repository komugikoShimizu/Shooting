#pragma once
#include "SceneBase.h"
#include "SceneType.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// タイトルシーンのクラス
	/// </summary>
	class TitleScene : public SceneBase
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		TitleScene();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ptr">シーン更新ポインタ</param>
		TitleScene(SceneType* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~TitleScene();

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

	inline TitleScene::TitleScene() {}

	inline SceneType TitleScene::GetSceneType() { return SceneType::TITLE; }
}