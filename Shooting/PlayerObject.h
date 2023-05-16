#pragma once

#include "CollisionObject.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "AnimationController.h"
#include "AnimationClip.h"
#include "PlayerState.h"

#define defaultPlayerHitPoint 10
#define playerRadius 32.0f

using namespace Collision;
using namespace Manager;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// �v���C���[�̃I�u�W�F�N�g�N���X
	/// </summary>
	class PlayerObject:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		PlayerObject();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="createPos">�������W</param>
		/// <param name="ptr">�e�Ǘ��N���X�̃|�C���^</param>
		PlayerObject(Vector2 createPos, BulletManager* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~PlayerObject();

		/// <summary>
		/// �̗͎擾�p�֐�
		/// </summary>
		/// <returns>�c��̗�</returns>
		int GetHitPoint();

		/// <summary>
		/// �v���C���[�X�V����
		/// </summary>
		void PlayerUpdate();

		/// <summary>
		/// �ڐG���֐�
		/// </summary>
		void CollisionAction() override;

		/// <summary>
		/// �I�u�W�F�N�g�̍��W��Ԃ�
		/// </summary>
		/// <returns>���W</returns>
		Vector2 GetPos() override;
	private:
		float stateMoveTime = 2.0f;

		int hitPoint;								// �c�̗�
		int countForHitJudgment;					// �����蔻��p�̃J�E���g
		float timeCount;							// ���Ԍv���p�ϐ�
		float targetTime;							// �ڕW����
		bool bulletHittable;						// �e��������󋵂ɂ��邩
		BulletManager* bulletManager;				// �e�Ǘ��N���X�̃|�C���^
		Vector2 spriteSize;							// �摜�T�C�Y
		PlayerState state;							// �v���C���[�̍s����
		AnimationController animationController;	// �A�j���[�V�����Ǘ��N���X
		AnimationClip stayAnimation;				// ��~��Ԃ̃A�j���[�V�����N���b�v
		AnimationClip shotAnimation;				// �e���ˏ�Ԃ̃A�j���[�V�����N���b�v

		/// <summary>
		/// �N���b�v�����p�֐�
		/// </summary>
		void ClipInstance();						
	};

	inline PlayerObject::PlayerObject() :
		hitPoint(), countForHitJudgment(), timeCount(), targetTime(), spriteSize(), bulletHittable(),
		bulletManager(), state(), animationController(), stayAnimation(), shotAnimation() {}
}