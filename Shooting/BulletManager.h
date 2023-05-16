#pragma once

#include "Bullet.h"
#include "NormalBullet.h"
#include "ChasableBullet.h"
#include "CollisionType.h"
#include "CollisionManager.h"

using namespace Object;
using namespace Collision;

namespace Manager
{
	/// <summary>
	/// 弾管理クラス
	/// </summary>
	class BulletManager
	{
	public:
		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		BulletManager();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="ptr">当たり判定クラスのポインタ</param>
		BulletManager(CollisionManager*);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~BulletManager();

		Vector2* playerPos;	// プレイヤー座標のポインタ(追従弾用)

		/// <summary>
		/// 弾更新処理
		/// </summary>
		void BulletUpdate();

		/// <summary>
		/// 通常弾作成関数
		/// </summary>
		/// <param name="angle">発射角度</param>
		/// <param name="createPos">生成座標</param>
		/// <param name="collisionPos">接触タイプ</param>
		/// <returns>生成した弾のインデックス</returns>
		int NormalBulletCreate(int angle, Vector2 createPos, CollisionType collisionPos);

		/// <summary>
		/// 追従弾作成関数
		/// </summary>
		/// <param name="createPos">生成座標</param>
		/// <param name="collisionPos">接触タイプ</param>
		/// <returns>生成した弾のインデックス</returns>
		int ChasableBulletCreate(Vector2 createPos,CollisionType collisionPos);

		/// <summary>
		/// 弾登録解除関数
		/// </summary>
		/// <param name="index">登録解除する弾のインデックス</param>
		void BulletUnregister(int index);
	private:
		static const int BULLET_MAXINSTANCE_COUNT = 100;	// 生成上限
		Bullet* instanceBullets[BULLET_MAXINSTANCE_COUNT];	// 生成した弾のインスタンスの配列
		CollisionManager* collisionManager;					// 当たり判定クラス
	};

	inline BulletManager::BulletManager() : collisionManager(nullptr), instanceBullets(), playerPos() {}
}