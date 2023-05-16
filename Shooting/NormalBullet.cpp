#include "NormalBullet.h"

namespace Object
{
	NormalBullet::NormalBullet(int angle, Vector2 createPos, CollisionType type)
	{
		spriteSize = Vector2(64, 64);							// 画像サイズを設定
		animationController = AnimationController(spriteSize);	// アニメーション管理クラスを初期化

		active = true;			// 有効にする
		radius = 16.0f;			// 半径を設定
		position = createPos;	// 座標を生成座標に設定
		this->type = type;		// 接触タイプを設定

		this->angle = angle;	// 角度を設定

		AnimationSet();			// アニメーションを作成
	}

	bool NormalBullet::BulletUpdate()
	{
		// 移動座標を作成する
		float rx = NORMAL_BULLET_SPPED * cos(angle) + position.x;
		float ry = NORMAL_BULLET_SPPED * sin(angle) + position.y;

		position = Vector2(rx, ry);								// 移動座標に座標を移動する

		animationController.AnimaitonUpdate(GetPos(), false);	// アニメーションを更新する

		return active;
	}
}