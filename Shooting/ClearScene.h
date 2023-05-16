#pragma once
#include <windows.h>
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// クリアシーンクラス
	/// </summary>
	class ClearScene : public SceneBase
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		ClearScene();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ptr">シーン更新ポインタ</param>
		ClearScene(SceneType* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ClearScene();

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

	inline ClearScene::ClearScene() {}

	inline ClearScene::~ClearScene() {}

	inline SceneType ClearScene::GetSceneType() { return SceneType::CLEAR; }
}