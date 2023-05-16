#include "ChasableBullet.h"

namespace Object
{
	ChasableBullet::ChasableBullet(Vector2* targetPosPtr, Vector2 createPos, CollisionType collisionType)
	{
		spriteSize = Vector2(64, 64);							// 画像サイズ設定
		animationController = AnimationController(spriteSize);	// アニメーション管理クラス生成

		active = true;											// 有効化する
		radius = 16.0f;											// 当たり判定用半径設定
		position = createPos;									// 座標を生成座標に設定
		this->targetPosPtr = targetPosPtr;						// 追従座標ポインタを設定
		type = collisionType;									// 接触タイプ設定

		targetTime = GetNowCount() + 10000;						// 目標時間設定

		AnimationSet();											// アニメーション設定
	}

	bool ChasableBullet::BulletUpdate()
	{
		Vector2 distance = *targetPosPtr - position;						// 対象座標との距離を作成 

		float hypotenuse = sqrt(pow(distance.x, 2) + pow(distance.y, 2));		// 斜辺を計算

		// 移動ベクトルを作成
		float mx = (distance.x / hypotenuse) * ChasableBulletSpped;
		float my = (distance.y / hypotenuse) * ChasableBulletSpped;

		position += Vector2(mx, my);											// 座標に移動ベクトルを加算

		animationController.AnimaitonUpdate(GetPos(), false);				// アニメーション更新

		if (targetTime < GetNowCount())										// 目標時間を超えたら
		{
			active = false;													// 無効化する
			type = CollisionType::TYPE_NONE;								// 接触タイプを未設定にする
		}

		return active;
	}
}