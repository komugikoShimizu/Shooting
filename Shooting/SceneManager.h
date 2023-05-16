#pragma once

#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"
#include "GameoverScene.h"
#include "SceneType.h"

namespace Scene
{
	/// <summary>
	/// シーンを管理するクラス
	/// </summary>
	class SceneManager
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		SceneManager();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~SceneManager();

		/// <summary>
		/// シーン更新処理
		/// </summary>
		void SceneUpdate();
	private:
		SceneBase* activeScene;	// 現在動かしているシーンのポインタ

		SceneType scene;		// 動かすシーンのタイプ
	};
}