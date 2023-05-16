#include "Bullet.h"
#include "DxLib.h"

namespace Object
{
	Bullet::Bullet() : active(), spriteSize(), animationController(), defaultAnimation() {}

	Bullet::~Bullet() {}

	bool Bullet::BulletUpdate() { return false; }

	void Bullet::CollisionAction() 
	{
		active = false;						// 無効化する
		type = CollisionType::TYPE_NONE;	// 接触タイプを未設定にする
	}

	Vector2 Bullet::GetPos()
	{
		return Vector2(position.x - spriteSize.x / 2, position.y - spriteSize.y / 2);	// 中心座標を返す
	} 

	void Bullet::AnimationSet()
	{
		// 必要なアニメーションクリップを作成し、登録する
		if (type == CollisionType::PLAYER_BULLET)
		{
			defaultAnimation = AnimationClip("Sprites/Player_Bullet.png", 6, 3, 2, 400, 400, 1, false);
			animationController.AnimationSubscrive("Bullet_Default", defaultAnimation);
			animationController.AnimationPlay("Bullet_Default");
		}
		else if (type == CollisionType::ENEMY_BULLET)
		{
			defaultAnimation = AnimationClip("Sprites/Laetitia_Bullet.png", 6, 3, 2, 400, 400, 0.3f, true);
			animationController.AnimationSubscrive("Bullet_Default", defaultAnimation);
			animationController.AnimationPlay("Bullet_Default");
		}
	}
}