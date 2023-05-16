#pragma once
#include "SceneType.h"

namespace Scene
{
	/// <summary>
	/// 各シーンの基底クラス
	/// </summary>
	class SceneBase
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		SceneBase();

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~SceneBase();

		/// <summary>
		/// シーン更新処理
		/// </summary>
		virtual void SceneUpdate();

		/// <summary>
		/// シーンタイプ取得用関数
		/// </summary>
		/// <returns>このシーンのタイプ</returns>
		virtual SceneType GetSceneType();
	protected:
		SceneType* nextScene;
	};

	inline SceneBase::SceneBase() : nextScene() {};

	inline SceneBase::~SceneBase() {}; 

	inline void SceneBase::SceneUpdate() {};

	inline SceneType SceneBase::GetSceneType() { return SceneType::EXCEPTION; }
}