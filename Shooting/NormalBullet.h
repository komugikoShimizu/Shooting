#pragma once
#include <math.h>
#include "Bullet.h"

#define NORMAL_BULLET_SPPED 2

namespace Object
{
	/// <summary>
	/// 通常弾のクラス
	/// </summary>
	class NormalBullet : public Bullet
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		NormalBullet();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="angle">発射角度</param>
		/// <param name="createPos">生成座標</param>
		/// <param name="collisionPos">接触タイプ</param>
		NormalBullet(int angle, Vector2 createPos, CollisionType collisionType);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~NormalBullet();

		/// <summary>
		/// 弾更新処理
		/// </summary>
		/// <returns>有効であるか</returns>
		bool BulletUpdate() override;
	private:
		int angle;	// 発射角度
	};

	inline NormalBullet::NormalBullet() : angle() {}

	inline NormalBullet::~NormalBullet() {}
}