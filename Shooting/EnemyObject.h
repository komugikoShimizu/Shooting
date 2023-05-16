#pragma once

#include "CollisionObject.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "AnimationController.h"
#include "AnimationClip.h"
#include "EnemyState.h"

#define defaultEnemyHitPoint 10
#define stateChengeTime 3
#define enemyRadius 32.0f

using namespace Collision;
using namespace Manager;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// 敵のオブジェクトクラス
	/// </summary>
	class EnemyObject:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		EnemyObject();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="createPos">生成座標</param>
		/// <param name="ptr">弾管理クラスのポインタ</param>
		EnemyObject(Vector2 createPos, BulletManager* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~EnemyObject();

		/// <summary>
		/// 体力取得用関数
		/// </summary>
		/// <returns>残り体力</returns>
		int GetHitPoint();

		/// <summary>
		/// 敵更新処理
		/// </summary>
		void EnemyUpdate();

		/// <summary>
		/// 接触時関数
		/// </summary>
		void CollisionAction() override;

		/// <summary>
		/// オブジェクトの座標を返す
		/// </summary>
		/// <returns>座標</returns>
		Vector2 GetPos() override;
	private:
		int hitPoint;								// 残体力
		int countForHitJudgment;					// 当たり判定用のカウント
		float stateTime;							// ステート変更を行う時間
		float timeCount;							// 時間計測用変数
		float targetTime;							// 目標時間
		bool bulletHittable;						// 弾が当たることができるか
		BulletManager* bulletManager;				// 弾管理クラスのポインタ
		EnemyState state;							// 敵の行動状態
		Vector2 spriteSize;							// 画像サイズ
		AnimationController animationController;	// アニメーション管理クラス
		AnimationClip stayAnimation;				// 停止状態のアニメーションクリップ
		AnimationClip shotAnimation;				// 弾発射状態のアニメーションクリップ

		/// <summary>
		/// クリップ生成用関数
		/// </summary>
		void ClipInstance();
	};

	inline EnemyObject::EnemyObject() :
		hitPoint(), countForHitJudgment(), stateTime(), timeCount(), targetTime(), bulletHittable(),
		bulletManager(), state(), spriteSize(), animationController(), stayAnimation(), shotAnimation() {}

	inline int EnemyObject::GetHitPoint() { return hitPoint; }
}