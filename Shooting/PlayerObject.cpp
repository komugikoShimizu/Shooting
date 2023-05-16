#include "PlayerObject.h"

namespace Object
{
	PlayerObject::PlayerObject(Vector2 createPos, BulletManager* ptr) :
		hitPoint(defaultPlayerHitPoint), countForHitJudgment(0), timeCount(0.0f), targetTime(0.0f),
		bulletHittable(true), state(PlayerState::IDLE), spriteSize(Vector2(128, 128)),
		animationController(AnimationController(spriteSize)), bulletManager(ptr)
	{
		radius = playerRadius;					// �v���C���[�̔��a��ݒ�
		position = createPos;					// ���W�𐶐����W�ɐݒ�
		type = CollisionType::PLAYER;			// �ڐG�^�C�v��ݒ�
		ClipInstance();							// �A�j���[�V�������쐬����

		bulletManager->playerPos = &position;	// �e�Ǘ��N���X�̃v���C���[���W��ݒ肷��
	}

	PlayerObject::~PlayerObject() {}

	void PlayerObject::PlayerUpdate()
	{
		// �L�[���͂ňړ�����
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
		case PlayerState::IDLE:										// �ҋ@��Ԃł����
			if (CheckHitKey(KEY_INPUT_SPACE))						// �X�y�[�X�L�[�����͂��ꂽ��
			{
				// �ʏ�e�𐶐�
				bulletManager->NormalBulletCreate(0, GetPos() + Vector2(64, 64),CollisionType::PLAYER_BULLET);
				animationController.AnimationPlay("Player_Shot");	// �e���˃A�j���[�V�������Đ�
				state = PlayerState::SHOT;							// ��Ԃ�e���˂ɕύX
				timeCount = GetNowCount();							// ���Ԍv��
				targetTime = timeCount + (stateMoveTime * 1000.0f);	// �ڕW���Ԃ�ݒ�
			}
			break;
		case PlayerState::SHOT:										// �ˌ���Ԃł����
			timeCount = GetNowCount();								// ���Ԍv��

			if (timeCount >= targetTime)							// �v�����Ԃ��ڕW���Ԃ𒴂�����
			{
				state = PlayerState::IDLE;							// �ҋ@��ԂɕύX
				animationController.AnimationPlay("Player_Stay");	// ��~�A�j���[�V�������Đ�
			}
			break;
		}

		if (!bulletHittable)							// �e�ɓ�����󋵂ɂȂ����
		{
			countForHitJudgment++;						// �J�E���g�����Z
				
			if (countForHitJudgment > 100)				// �J�E���g���w�肳�ꂽ���l�ȏ�ɂȂ�����
			{
				bulletHittable = true;					// �e��������󋵂ɕύX
				countForHitJudgment = 0;				// �J�E���g��������
			}

			if (countForHitJudgment % 5 < 2) return;	// �A�j���[�V������_�ł����邽�߁A5�Ŋ������]�肪2�����ł���Α������^�[������
		}

		animationController.AnimaitonUpdate(GetPos(),false); // �A�j���[�V�����X�V����
	}

	void PlayerObject::CollisionAction()
	{
		if (bulletHittable)				// �e�ɓ������Ԃł����
		{
			bulletHittable = false;		// ������Ȃ���ԂɕύX
			hitPoint--;					// �̗͂����Z
		}
	}

	void PlayerObject::ClipInstance()
	{
		stayAnimation = AnimationClip(
			"Sprites/Player_Stay.png", 4, 2, 2, 400, 400, 0.5f, true);			// ��~�A�j���[�V�����N���b�v���쐬

		animationController.AnimationSubscrive("Player_Stay", stayAnimation);	// ��~�A�j���[�V������o�^
		animationController.AnimationPlay("Player_Stay");						// ��~�A�j���[�V�������Đ�

		shotAnimation = AnimationClip(
			"Sprites/Player_Shot.png", 4, 2, 2, 400, 400, 0.5f, true);			// �e���˃A�j���[�V�����N���b�v���쐬

		animationController.AnimationSubscrive("Player_Shot", shotAnimation);	// �e���˃A�j���[�V������o�^	
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