#include "CollisionManager.h"
#include "DxLib.h"

namespace Collision
{
	CollisionManager::CollisionManager() {}

	CollisionManager::~CollisionManager() {}

	void CollisionManager::CollisionSubscrive(CollisionObject* newObj)
	{
		for (int i = 0; i < InstaceMax; i++)	// インスタンス上限まで実行
		{
			if (objectMap[i] == nullptr)		// 見た位置がヌルポインタであれば
			{
				objectMap[i] = newObj;			// 対象をその位置に格納する
				break;							// for文終了
			}
		}
	}

	void CollisionManager::CollisionUpdate()
	{
		for (int i = 0; i < InstaceMax; i++)				// インスタンス上限まで実行 
		{
			if (objectMap[i] == nullptr) continue;			// 見た位置がヌルポインタであれば次へ
			// プレイヤーかエネミーでないなら次へ
			if (objectMap[i]->GetType() != CollisionType::PLAYER && objectMap[i]->GetType() != CollisionType::ENEMY) continue;
			for (int j = 0; j < InstaceMax; j++)			// インスタンス上限まで実行
			{
				if (i == j) continue;
				if (objectMap[j] == nullptr) continue;		// 見た位置がヌルポインタであれば次へ
				// 見た位置の接触タイプが未設定なら
				if (objectMap[j]->GetType() == CollisionType::TYPE_NONE)
				{
					objectMap[j] = nullptr;					// 対象の位置にヌルポインタを設定
					continue;								// 次へ
				}
				// 敵対する弾であれば
				if ((objectMap[i]->GetType() == CollisionType::ENEMY && objectMap[j]->GetType() == CollisionType::PLAYER_BULLET) ||
					(objectMap[i]->GetType() == CollisionType::PLAYER && objectMap[j]->GetType() == CollisionType::ENEMY_BULLET))
				{
					// 判定関数を実行し、当たっているのなら
					if (CollisionJudge(objectMap[i], objectMap[j]))
					{
						// 判定を行った双方に接触時関数を実行する
						objectMap[i]->CollisionAction();
						objectMap[j]->CollisionAction();

						objectMap[j] = nullptr;				// 弾のポインタをヌルポインタに設定
					}
				}
			}
		}
	}

	bool CollisionManager::CollisionJudge(CollisionObject* base, CollisionObject* opponent)
	{
		// 2つの座標の距離を計算
		double distance =
			sqrt(pow((double)base->GetCollisionPos().x - (double)opponent->GetCollisionPos().x, 2) +
				pow((double)base->GetCollisionPos().y - (double)opponent->GetCollisionPos().y, 2));

		// 0未満なら整数化するために-1をかける
		if (distance < 0) distance *= -1;

		// 半径をの合計が計算した距離以上であるならtrueを返す
		bool ret = (double)base->GetRadius() + (double)opponent->GetRadius() >= distance;

		return ret;
	}
}