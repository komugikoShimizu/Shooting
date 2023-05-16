#pragma once

#include "CollisionObject.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "AnimationController.h"
#include "AnimationClip.h"
#include "PlayerState.h"

#define defaultPlayerHitPoint 10
#define playerRadius 32.0f

using namespace Collision;
using namespace Manager;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// プレイヤーのオブジェクトクラス
	/// </summary>
	class PlayerObject:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		PlayerObject();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="createPos">生成座標</param>
		/// <param name="ptr">弾管理クラスのポインタ</param>
		PlayerObject(Vector2 createPos, BulletManager* ptr);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~PlayerObject();

		/// <summary>
		/// 体力取得用関数
		/// </summary>
		/// <returns>残り体力</returns>
		int GetHitPoint();

		/// <summary>
		/// プレイヤー更新処理
		/// </summary>
		void PlayerUpdate();

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
		float stateMoveTime = 2.0f;

		int hitPoint;								// 残体力
		int countForHitJudgment;					// 当たり判定用のカウント
		float timeCount;							// 時間計測用変数
		float targetTime;							// 目標時間
		bool bulletHittable;						// 弾が当たる状況にあるか
		BulletManager* bulletManager;				// 弾管理クラスのポインタ
		Vector2 spriteSize;							// 画像サイズ
		PlayerState state;							// プレイヤーの行動状況
		AnimationController animationController;	// アニメーション管理クラス
		AnimationClip stayAnimation;				// 停止状態のアニメーションクリップ
		AnimationClip shotAnimation;				// 弾発射状態のアニメーションクリップ

		/// <summary>
		/// クリップ生成用関数
		/// </summary>
		void ClipInstance();						
	};

	inline PlayerObject::PlayerObject() :
		hitPoint(), countForHitJudgment(), timeCount(), targetTime(), spriteSize(), bulletHittable(),
		bulletManager(), state(), animationController(), stayAnimation(), shotAnimation() {}
}