#pragma once

#include "CollisionObject.h"
#include "AnimationController.h"
#include "AnimationClip.h"

using namespace Collision;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// 弾オブジェクトの抽象クラス
	/// </summary>
	class Bullet:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		Bullet();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Bullet() override;

		/// <summary>
		/// 更新処理
		/// </summary>
		/// <returns>継続可能か</returns>
		virtual bool BulletUpdate();

		/// <summary>
		/// 接触時関数
		/// </summary>
		void CollisionAction() override;

		/// <summary>
		/// 座標取得用
		/// </summary>
		/// <returns>座標</returns>
		Vector2 GetPos() override;
	protected:
		bool active;								// 有効かどうか
		Vector2 spriteSize;							// 画像サイズ
		AnimationController animationController;	// アニメーション管理クラス
		AnimationClip defaultAnimation;				// アニメーションクリップ

		/// <summary>
		/// アニメーション設定関数
		/// </summary>
		void AnimationSet();
	};
}