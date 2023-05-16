#pragma once
#include "CollisionType.h"
#include "Vector2.h"

namespace Collision
{
	// 当たり判定を行うオブジェクトの基底クラス
	class CollisionObject
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		CollisionObject();

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~CollisionObject();
		
		/// <summary>
		/// 接触時関数
		/// </summary>
		virtual void CollisionAction();

		/// <summary>
		/// オブジェクトの当たり判定用の半径を返す
		/// </summary>
		/// <returns>オブジェクトの当たり判定用の半径</returns>
		virtual float GetRadius();

		/// <summary>
		/// オブジェクトの座標を返す
		/// </summary>
		/// <returns>座標</returns>
		virtual Vector2 GetPos();

		/// <summary>
		/// 当たり判定を行う中心座標を返す
		/// </summary>
		/// <returns>中心座標</returns>
		virtual Vector2 GetCollisionPos();

		/// <summary>
		/// 接触タイプを返す
		/// </summary>
		/// <returns>接触タイプ</returns>
		virtual CollisionType GetType();
	protected:
		float radius;									// 当たり判定用の半径
		Vector2 position;								// オブジェクトの座標
		Vector2 spriteSize;								// 画像サイズ
		CollisionType type = CollisionType::TYPE_NONE;	// 接触タイプ
	};

	inline CollisionObject::CollisionObject() : radius(), position(), spriteSize(), type() {}

	inline CollisionObject::~CollisionObject() {}

	inline void CollisionObject::CollisionAction() {}

	inline float CollisionObject::GetRadius() { return radius; }

	inline Vector2 CollisionObject::GetPos() { return position; }

	inline Vector2 CollisionObject::GetCollisionPos() { return position + Vector2(spriteSize.x * 0.5f,spriteSize.y * 0.5f); }

	inline CollisionType CollisionObject::GetType() { return type; }
}