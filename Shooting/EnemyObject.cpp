#include "EnemyObject.h"

namespace Object
{
	EnemyObject::EnemyObject(Vector2 createPos, BulletManager* ptr):
		timeCount(GetNowCount()), countForHitJudgment(0), stateTime(stateChengeTime),
		targetTime(timeCount + (stateTime * 1000.0f)), bulletHittable(true),
		spriteSize(Vector2(128, 128)), state(EnemyState::STAY),
		animationController(AnimationController(spriteSize)), hitPoint(defaultEnemyHitPoint),
		bulletManager(ptr)
	{
		radius = enemyRadius;			// 半径を設定
		position = createPos;			// 座標に生成座標を設定
		type = CollisionType::ENEMY;	// 接触タイプを敵に設定
		ClipInstance();					// アニメーションクリップを作成
	}

	EnemyObject::~EnemyObject() {}

	void EnemyObject::EnemyUpdate()
	{
		timeCount = GetNowCount();			// 時間計測

		// 状態に応じて処理を変更する
		switch (state)
		{
		case EnemyState::STAY:											// 停止状態であるなら
			if (timeCount >= targetTime)								// 計測している時間が目標時間を上回ったら
			{
				targetTime = timeCount + (stateTime * 1000);			// 目標時間を再設定	
				animationController.AnimationPlay("Laetitia_Shot");		// 弾発射アニメーションを再生
				int rand = (GetNowCount() % 2);							// 計測した時間変数が2で割り切れるか
				if (rand > 0)											// 割り切れないのであれば
				{
					state = EnemyState::NORMAL_BULLET;					// 通常弾発射状態にする

					// 弾を生成
					bulletManager->NormalBulletCreate(135, position, CollisionType::ENEMY_BULLET);
					bulletManager->NormalBulletCreate(135, position + Vector2(-64,132), CollisionType::ENEMY_BULLET);
					bulletManager->NormalBulletCreate(135, position + Vector2(-64,-132), CollisionType::ENEMY_BULLET);
				}
				else													// 割り切れるのであれば
				{
					state = EnemyState::CHASABLE_BULLET;				// 追従弾発射状態にする

					// 弾を生成
					bulletManager->ChasableBulletCreate(position, CollisionType::ENEMY_BULLET);
					bulletManager->ChasableBulletCreate(position + Vector2(-64, 132), CollisionType::ENEMY_BULLET);
					bulletManager->ChasableBulletCreate(position + Vector2(-64, -132), CollisionType::ENEMY_BULLET);
				}
			}
			break;
		case EnemyState::NORMAL_BULLET:									// 通常弾発射状態であれば
			if (timeCount >= targetTime)								// 計測時間が目標時間を上回ったら
			{
				state = EnemyState::STAY;								// 停止状態に変更
				targetTime = timeCount + (stateTime * 1000);			// 目標時間を再設定
				animationController.AnimationPlay("Laetitia_Stay");		// 停止アニメーションを再生
			}
			break;
		case EnemyState::CHASABLE_BULLET:								// 追従弾発射状態であれば
			if (timeCount >= targetTime)								// 計測時間が目標時間を上回ったら
			{
				state = EnemyState::STAY;								// 停止状態に変更
				targetTime = timeCount + (stateTime * 1000);			// 目標時間を再設定
				animationController.AnimationPlay("Laetitia_Stay");		// 停止アニメーションを再生
			}
			break;
		default:
			break;
		}

		if (!bulletHittable)							// 弾に当たらない状態であるなら
		{
			countForHitJudgment++;						// カウントを加算

			if (countForHitJudgment > 100)				// カウントが指定された数値以上になったら
			{
				bulletHittable = true;					// 弾に当たる状態に変更
				countForHitJudgment = 0;				// カウントを初期化
			}	

			if (countForHitJudgment % 5 < 2) return;	// アニメーションを点滅させるため、5で割った余りが2未満であれば早期リターンする
		}

		animationController.AnimaitonUpdate(GetPos(),true);	// アニメーション更新処理
	}

	void EnemyObject::CollisionAction()
	{
		if (bulletHittable)				// 弾に当たる状態であれば
		{
			bulletHittable = false;		// 当たらない状態に変更
			hitPoint--;					// 体力を減算
		}
	}

	void EnemyObject::ClipInstance()
	{
		// 停止アニメーションクリップを作成し登録
		stayAnimation = AnimationClip("Sprites/Laetitia_Stay.png", 4, 2, 2, 400, 400, 0.5f, true);
		animationController.AnimationSubscrive("Laetitia_Stay", stayAnimation);
		animationController.AnimationPlay("Laetitia_Stay");

		// 弾発射アニメーションクリップを作成し登録
		shotAnimation = AnimationClip("Sprites/Laetitia_Shot.png", 4, 2, 2, 400, 400, 0.5f, true);
		animationController.AnimationSubscrive("Laetitia_Shot", shotAnimation);
	}

	Vector2 EnemyObject::GetPos()
	{
		return Vector2(position.x + (spriteSize.x / 2), position.y - (spriteSize.y / 2));
	}
}