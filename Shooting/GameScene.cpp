#include "GameScene.h"
#include "DxLib.h"
#include <string>
#include <iostream>

using namespace std;

namespace Scene
{
	GameScene::GameScene(SceneType* ptr) :
		collisionManager(CollisionManager()), bulletManager(BulletManager(&collisionManager)),
		player(PlayerObject(Vector2(100, 150), &bulletManager)), enemy(EnemyObject(Vector2(550, 150), &bulletManager))
	{
		collisionManager.CollisionSubscrive(&player);	// 当たり判定クラスにプレイヤーを登録する	
		collisionManager.CollisionSubscrive(&enemy);	// 当たり判定クラスにエネミーを登録する

		nextScene = ptr;								// シーン更新ポインタを設定
	}

	GameScene::~GameScene() {}

	void GameScene::SceneUpdate()
	{
		player.PlayerUpdate();				// プレイヤー更新処理を行う
		enemy.EnemyUpdate();				// エネミー更新処理を行う
		bulletManager.BulletUpdate();		// 弾管理クラスの更新処理を行う
		collisionManager.CollisionUpdate();	// 当たり判定クラスの更新処理を行う

		// プレイヤーの体力を出力
		DrawString(0,0,"Player:",GetColor(255,255,255));
		for (int i = 0; i < player.GetHitPoint(); i++)
		{
			DrawString((i + 3) * 20,0,"■",GetColor(255,255,255));
		}

		// エネミーの体力を出力
		DrawString(0, 30, "Enemy :", GetColor(255, 255, 255));
		for (int i = 0; i < enemy.GetHitPoint(); i++)
		{
			DrawString((i + 3) * 20,30,"■",GetColor(255,255,255));
		}

		if (player.GetHitPoint() <= 0)			// プレイヤーの体力がなくなったら
		{
			*nextScene = SceneType::GAMEOVER;	// シーン更新ポインタにゲームオーバーを設定
		}

		if (enemy.GetHitPoint() <= 0)			// エネミーの体力がなくなったら
		{
			*nextScene = SceneType::CLEAR;		// シーン更新ポインタにクリアを設定
		}
	}
}