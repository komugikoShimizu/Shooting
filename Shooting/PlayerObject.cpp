#include "PlayerObject.h"

namespace Object
{
	PlayerObject::PlayerObject(Vector2 createPos, BulletManager* ptr) :
		hitPoint(defaultPlayerHitPoint), countForHitJudgment(0), timeCount(0.0f), targetTime(0.0f),
		bulletHittable(true), state(PlayerState::IDLE), spriteSize(Vector2(128, 128)),
		animationController(AnimationController(spriteSize)), bulletManager(ptr)
	{
		radius = playerRadius;					// プレイヤーの半径を設定
		position = createPos;					// 座標を生成座標に設定
		type = CollisionType::PLAYER;			// 接触タイプを設定
		ClipInstance();							// アニメーションを作成する

		bulletManager->playerPos = &position;	// 弾管理クラスのプレイヤー座標を設定する
	}

	PlayerObject::~PlayerObject() {}

	void PlayerObject::PlayerUpdate()
	{
		// キー入力で移動する
		if (CheckHitKey(KEY_INPUT_A))
		{
			position.x -= 1;
		}
		if (CheckHitKey(KEY_INPUT_D))
		{
			position.x += 1;
		}
		if (CheckHitKey(KEY_INPUT_W))
		{
			position.y -= 1;
		}
		if (CheckHitKey(KEY_INPUT_S))
		{
			position.y += 1;
		}

		switch (state)		
		{
		case PlayerState::IDLE:										// 待機状態であれば
			if (CheckHitKey(KEY_INPUT_SPACE))						// スペースキーが入力されたら
			{
				// 通常弾を生成
				bulletManager->NormalBulletCreate(0, GetPos() + Vector2(64, 64),CollisionType::PLAYER_BULLET);
				animationController.AnimationPlay("Player_Shot");	// 弾発射アニメーションを再生
				state = PlayerState::SHOT;							// 状態を弾発射に変更
				timeCount = GetNowCount();							// 時間計測
				targetTime = timeCount + (stateMoveTime * 1000.0f);	// 目標時間を設定
			}
			break;
		case PlayerState::SHOT:										// 射撃状態であれば
			timeCount = GetNowCount();								// 時間計測

			if (timeCount >= targetTime)							// 計測時間が目標時間を超えたら
			{
				state = PlayerState::IDLE;							// 待機状態に変更
				animationController.AnimationPlay("Player_Stay");	// 停止アニメーションを再生
			}
			break;
		}

		if (!bulletHittable)							// 弾に当たる状況になければ
		{
			countForHitJudgment++;						// カウントを加算
				
			if (countForHitJudgment > 100)				// カウントが指定された数値以上になったら
			{
				bulletHittable = true;					// 弾が当たる状況に変更
				countForHitJudgment = 0;				// カウントを初期化
			}

			if (countForHitJudgment % 5 < 2) return;	// アニメーションを点滅させるため、5で割った余りが2未満であれば早期リターンする
		}

		animationController.AnimaitonUpdate(GetPos(),false); // アニメーション更新処理
	}

	void PlayerObject::CollisionAction()
	{
		if (bulletHittable)				// 弾に当たる状態であれば
		{
			bulletHittable = false;		// 当たらない状態に変更
			hitPoint--;					// 体力を減算
		}
	}

	void PlayerObject::ClipInstance()
	{
		stayAnimation = AnimationClip(
			"Sprites/Player_Stay.png", 4, 2, 2, 400, 400, 0.5f, true);			// 停止アニメーションクリップを作成

		animationController.AnimationSubscrive("Player_Stay", stayAnimation);	// 停止アニメーションを登録
		animationController.AnimationPlay("Player_Stay");						// 停止アニメーションを再生

		shotAnimation = AnimationClip(
			"Sprites/Player_Shot.png", 4, 2, 2, 400, 400, 0.5f, true);			// 弾発射アニメーションクリップを作成

		animationController.AnimationSubscrive("Player_Shot", shotAnimation);	// 弾発射アニメーションを登録	
	}

	int PlayerObject::GetHitPoint()
	{
		return hitPoint;
	}

	Vector2 PlayerObject::GetPos()
	{
		return Vector2(position.x - (spriteSize.x / 2),position.y - (spriteSize.y / 2));
	}
}