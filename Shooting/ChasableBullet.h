#pragma once
#include <math.h>
#include "Bullet.h"

#define ChasableBulletSpped 1

namespace Object
{
	/// <summary>
	/// 追従弾クラス
	/// </summary>
	class ChasableBullet : public Bullet
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		ChasableBullet();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="targetPosPtr">追従する座標ポインタ</param>
		/// <param name="createPos">生成座標</param>
		/// <param name="collisionPos">接触タイプ</param>
		ChasableBullet(Vector2* targetPosPtr, Vector2 createPos, CollisionType collisionPos);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ChasableBullet();

		/// <summary>
		/// 弾更新処理
		/// </summary>
		/// <returns>有効であるか</returns>
		bool BulletUpdate() override;
	private:
		int targetTime;			// 目標時間変数 
		Vector2* targetPosPtr;	// 追従する座標ポインタ
	};

	inline ChasableBullet::ChasableBullet() : targetTime(), targetPosPtr() {}

	inline ChasableBullet::~ChasableBullet() {}
}
