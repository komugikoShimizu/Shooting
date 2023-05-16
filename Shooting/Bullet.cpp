#include "Bullet.h"
#include "DxLib.h"

namespace Object
{
	Bullet::Bullet() : active(), spriteSize(), animationController(), defaultAnimation() {}

	Bullet::~Bullet() {}

	bool Bullet::BulletUpdate() { return false; }

	void Bullet::CollisionAction() 
	{
		active = false;						// ����������
		type = CollisionType::TYPE_NONE;	// �ڐG�^�C�v�𖢐ݒ�ɂ���
	}

	Vector2 Bullet::GetPos()
	{
		return Vector2(position.x - spriteSize.x / 2, position.y - spriteSize.y / 2);	// ���S���W��Ԃ�
	} 

	void Bullet::AnimationSet()
	{
		// �K�v�ȃA�j���[�V�����N���b�v���쐬���A�o�^����
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