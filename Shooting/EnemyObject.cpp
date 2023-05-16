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
		radius = enemyRadius;			// ���a��ݒ�
		position = createPos;			// ���W�ɐ������W��ݒ�
		type = CollisionType::ENEMY;	// �ڐG�^�C�v��G�ɐݒ�
		ClipInstance();					// �A�j���[�V�����N���b�v���쐬
	}

	EnemyObject::~EnemyObject() {}

	void EnemyObject::EnemyUpdate()
	{
		timeCount = GetNowCount();			// ���Ԍv��

		// ��Ԃɉ����ď�����ύX����
		switch (state)
		{
		case EnemyState::STAY:											// ��~��Ԃł���Ȃ�
			if (timeCount >= targetTime)								// �v�����Ă��鎞�Ԃ��ڕW���Ԃ���������
			{
				targetTime = timeCount + (stateTime * 1000);			// �ڕW���Ԃ��Đݒ�	
				animationController.AnimationPlay("Laetitia_Shot");		// �e���˃A�j���[�V�������Đ�
				int rand = (GetNowCount() % 2);							// �v���������ԕϐ���2�Ŋ���؂�邩
				if (rand > 0)											// ����؂�Ȃ��̂ł����
				{
					state = EnemyState::NORMAL_BULLET;					// �ʏ�e���ˏ�Ԃɂ���

					// �e�𐶐�
					bulletManager->NormalBulletCreate(135, position, CollisionType::ENEMY_BULLET);
					bulletManager->NormalBulletCreate(135, position + Vector2(-64,132), CollisionType::ENEMY_BULLET);
					bulletManager->NormalBulletCreate(135, position + Vector2(-64,-132), CollisionType::ENEMY_BULLET);
				}
				else													// ����؂��̂ł����
				{
					state = EnemyState::CHASABLE_BULLET;				// �Ǐ]�e���ˏ�Ԃɂ���

					// �e�𐶐�
					bulletManager->ChasableBulletCreate(position, CollisionType::ENEMY_BULLET);
					bulletManager->ChasableBulletCreate(position + Vector2(-64, 132), CollisionType::ENEMY_BULLET);
					bulletManager->ChasableBulletCreate(position + Vector2(-64, -132), CollisionType::ENEMY_BULLET);
				}
			}
			break;
		case EnemyState::NORMAL_BULLET:									// �ʏ�e���ˏ�Ԃł����
			if (timeCount >= targetTime)								// �v�����Ԃ��ڕW���Ԃ���������
			{
				state = EnemyState::STAY;								// ��~��ԂɕύX
				targetTime = timeCount + (stateTime * 1000);			// �ڕW���Ԃ��Đݒ�
				animationController.AnimationPlay("Laetitia_Stay");		// ��~�A�j���[�V�������Đ�
			}
			break;
		case EnemyState::CHASABLE_BULLET:								// �Ǐ]�e���ˏ�Ԃł����
			if (timeCount >= targetTime)								// �v�����Ԃ��ڕW���Ԃ���������
			{
				state = EnemyState::STAY;								// ��~��ԂɕύX
				targetTime = timeCount + (stateTime * 1000);			// �ڕW���Ԃ��Đݒ�
				animationController.AnimationPlay("Laetitia_Stay");		// ��~�A�j���[�V�������Đ�
			}
			break;
		default:
			break;
		}

		if (!bulletHittable)							// �e�ɓ�����Ȃ���Ԃł���Ȃ�
		{
			countForHitJudgment++;						// �J�E���g�����Z

			if (countForHitJudgment > 100)				// �J�E���g���w�肳�ꂽ���l�ȏ�ɂȂ�����
			{
				bulletHittable = true;					// �e�ɓ������ԂɕύX
				countForHitJudgment = 0;				// �J�E���g��������
			}	

			if (countForHitJudgment % 5 < 2) return;	// �A�j���[�V������_�ł����邽�߁A5�Ŋ������]�肪2�����ł���Α������^�[������
		}

		animationController.AnimaitonUpdate(GetPos(),true);	// �A�j���[�V�����X�V����
	}

	void EnemyObject::CollisionAction()
	{
		if (bulletHittable)				// �e�ɓ������Ԃł����
		{
			bulletHittable = false;		// ������Ȃ���ԂɕύX
			hitPoint--;					// �̗͂����Z
		}
	}

	void EnemyObject::ClipInstance()
	{
		// ��~�A�j���[�V�����N���b�v���쐬���o�^
		stayAnimation = AnimationClip("Sprites/Laetitia_Stay.png", 4, 2, 2, 400, 400, 0.5f, true);
		animationController.AnimationSubscrive("Laetitia_Stay", stayAnimation);
		animationController.AnimationPlay("Laetitia_Stay");

		// �e���˃A�j���[�V�����N���b�v���쐬���o�^
		shotAnimation = AnimationClip("Sprites/Laetitia_Shot.png", 4, 2, 2, 400, 400, 0.5f, true);
		animationController.AnimationSubscrive("Laetitia_Shot", shotAnimation);
	}

	Vector2 EnemyObject::GetPos()
	{
		return Vector2(position.x + (spriteSize.x / 2), position.y - (spriteSize.y / 2));
	}
}