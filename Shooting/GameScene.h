#pragma once
#include "SceneBase.h"
#include "SceneType.h"
#include "PlayerObject.h"
#include "EnemyObject.h"
#include "BulletManager.h"
#include "CollisionManager.h"

using namespace Object;
using namespace Manager;
using namespace Collision;

namespace Scene
{
	/// <summary>
	/// ゲームシーンのクラス
	/// </summary>
	class GameScene : public SceneBase
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		GameScene();		

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ptr">シーン更新ポインタ</param>
		GameScene(SceneType* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~GameScene() override;

		/// <summary>
		/// シーン更新処理
		/// </summary>
		void SceneUpdate() override;

		/// <summary>
		/// シーンタイプ取得用関数
		/// </summary>
		/// <returns>このシーンのタイプ</returns>
		SceneType GetSceneType() override;
	private:
		PlayerObject player;				// プレイヤーのインスタンス
		EnemyObject enemy;					// エネミーのインスタンス
		BulletManager bulletManager;		// 弾管理クラスのインスタンス	
		CollisionManager collisionManager;	// 当たり判定クラスのインスタンス
	};

	inline GameScene::GameScene() : player(), enemy(), bulletManager(), collisionManager() {}

	inline SceneType GameScene::GetSceneType() { return SceneType::GAME; }
}