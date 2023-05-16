#include "AnimationController.h"

namespace Animation
{
	AnimationController::AnimationController():
		nextAnimationDiray(0),nextAnimationTime(0),
		spriteSize(Vector2()),spriteChengeTime(0),
		spriteIndex(0),timeCount(0)
	{
	}

	AnimationController::AnimationController(Vector2 size):
		nextAnimationDiray(0), nextAnimationTime(0),
		spriteSize(size), spriteChengeTime(0),
		spriteIndex(0), timeCount(0)
	{
	}

	AnimationController::~AnimationController() {}

	void AnimationController::AnimationSubscrive(const char* animationName, AnimationClip newClip)
	{
		animationContainer[animationName] = newClip;
	}

	void AnimationController::AnimationPlay(const char* playAnimationName)
	{
		playClip = animationContainer[playAnimationName];									// �Đ��N���b�v��ۑ�
		spriteChengeTime = playClip.sliceCountMax / playClip.animationTime;					// �摜�ύX���Ԃ�ݒ�
		timeCount = GetNowCount();															// ���Ԍv���p�ϐ��Ɍo�ߎ��Ԃ�ݒ�
		nextAnimationDiray = (playClip.animationTime / playClip.sliceCountMax) * 1000.0f;	// �摜�ύX���Ԃ�ϐ��ɕۑ�(1000.0f��������ƕb���ɂȂ�炵��)
		nextAnimationTime = timeCount + nextAnimationDiray;									// �摜�ύX���s�����Ԃ�ۑ�
		spriteIndex = 0;																	// �摜��ǂݍ���index������������
	}

	void AnimationController::AnimaitonUpdate(Vector2 position, bool flip)
	{
		if (playClip.animationTime == FLT_EPSILON) return;		// �Đ��A�j���[�V�������Ԃ�0�b�ł���Ώ������Ȃ�(�A�j���[�V�������Ȃ� or �N���b�v���ݒ�̂���)

		timeCount = GetNowCount();								// �o�ߎ��ԍX�V

		if (timeCount >= nextAnimationTime)						// �摜�X�V���Ԃ𒴂����
		{
 			nextAnimationTime += nextAnimationDiray;			// �摜�X�V���ԂɌo�ߎ��Ԃ𑫂��čX�V

			spriteIndex++;										// �摜�\��index��ǉ�
			
			if (spriteIndex >= playClip.sliceCountMax)			// �摜�����ݒ肳�ꂽ���������
			{
				if (playClip.isLoop)							// ���[�v�Đ�����̂ł����
				{
					spriteIndex = 0;							// �摜�\��index���ēx0�ɕύX
				}
				else
				{
					spriteIndex = playClip.sliceCountMax - 1;	// �v�f�����E��index�𒲐�
				}
			}
		}

		// �ǂ��炩�ɂł��T�C�Y�ݒ肪����Ă����
		if (spriteSize.x != FLT_EPSILON || spriteSize.y != FLT_EPSILON)	
		{
			Vector2 sizeCalPos = position;						// �T�C�Y���f���W�ۑ��p�ϐ�
			if (flip)											// ���]����̂ł����
			{
				sizeCalPos.x -= spriteSize.x;					// x�l�̂݌��Z
				sizeCalPos.y += spriteSize.y;					// y�����͐������������Ăق������߉��Z
			}
			else
			{
				sizeCalPos += spriteSize;						// �ݒ肳�ꂽ�T�C�Y�𔽉f�������W�l���쐬
			}

			// �`��
			DrawExtendGraph(position.x, position.y, sizeCalPos.x, sizeCalPos.y, playClip.handleArray[spriteIndex], true);
		}
		else													// �T�C�Y�ݒ肪����Ă��Ȃ��ꍇ(����K�v���Ȃ��摜)
		{
			if (flip)											// ���]����̂ł����
			{
				// ���]�`�悷��
				DrawTurnGraph(position.x, position.y, playClip.handleArray[spriteIndex], true);
			}
			else
			{
				// �ʏ�̕`�揈�����s��
				DrawGraph(position.x, position.y, playClip.handleArray[spriteIndex], true);
			}
		}
	}
}