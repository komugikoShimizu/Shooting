#include "BulletManager.h"

namespace Manager
{
	BulletManager::BulletManager(CollisionManager* ptr) : collisionManager(ptr) {}

	BulletManager::~BulletManager() {}

	void BulletManager::BulletUpdate()
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)	// インスタンス上限まで実行
		{
			if (instanceBullets[i] != nullptr)				// その配列要素番号に値があれば
			{
				if (!instanceBullets[i]->BulletUpdate())	// 弾更新処理を実行
				{
					BulletUnregister(i);					// 有効でなければ弾設定を解除
				}
			}
		}
	}

	int BulletManager::NormalBulletCreate(int angle, Vector2 createPos, CollisionType collisionType)
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)					// インスタンス上限まで実行
		{
			if (instanceBullets[i] == nullptr)								// その配列要素番号にインスタンスが存在しなければ
			{
				instanceBullets[i] =
					new NormalBullet(angle, createPos, collisionType);		// インスタンスを配列に登録
				collisionManager->CollisionSubscrive(instanceBullets[i]);	// 当たり判定クラスにインスタンスした弾を登録する
				return i;													// 要素番号を渡す
			}
		}

		return -1;
	}

	int BulletManager::ChasableBulletCreate(Vector2 createPos, CollisionType collisionType)
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)						// インスタンス上限まで実行
		{
			if (instanceBullets[i] == nullptr)									// その配列要素番号にインスタンスが存在しなければ
			{
				instanceBullets[i] =
					new ChasableBullet(playerPos, createPos, collisionType);	// インスタンスを配列に登録
				collisionManager->CollisionSubscrive(instanceBullets[i]);		// 当たり判定クラスにインスタンスした弾を登録する
				return i;														// 要素番号を渡す
			}
		}

		return -1;
	}

	void BulletManager::BulletUnregister(int index)
	{
		instanceBullets[index] = nullptr;	// 指定の要素番号をnullptrで初期化
	}
}