#pragma once

#include "CollisionObject.h"
#include "AnimationController.h"
#include "AnimationClip.h"

using namespace Collision;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// �e�I�u�W�F�N�g�̒��ۃN���X
	/// </summary>
	class Bullet:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		Bullet();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Bullet() override;

		/// <summary>
		/// �X�V����
		/// </summary>
		/// <returns>�p���\��</returns>
		virtual bool BulletUpdate();

		/// <summary>
		/// �ڐG���֐�
		/// </summary>
		void CollisionAction() override;

		/// <summary>
		/// ���W�擾�p
		/// </summary>
		/// <returns>���W</returns>
		Vector2 GetPos() override;
	protected:
		bool active;								// �L�����ǂ���
		Vector2 spriteSize;							// �摜�T�C�Y
		AnimationController animationController;	// �A�j���[�V�����Ǘ��N���X
		AnimationClip defaultAnimation;				// �A�j���[�V�����N���b�v

		/// <summary>
		/// �A�j���[�V�����ݒ�֐�
		/// </summary>
		void AnimationSet();
	};
}