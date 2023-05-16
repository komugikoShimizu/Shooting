#pragma once

#include "CollisionObject.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "AnimationController.h"
#include "AnimationClip.h"
#include "EnemyState.h"

#define defaultEnemyHitPoint 10
#define stateChengeTime 3
#define enemyRadius 32.0f

using namespace Collision;
using namespace Manager;
using namespace Animation;

namespace Object
{
	/// <summary>
	/// �G�̃I�u�W�F�N�g�N���X
	/// </summary>
	class EnemyObject:public virtual CollisionObject
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		EnemyObject();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="createPos">�������W</param>
		/// <param name="ptr">�e�Ǘ��N���X�̃|�C���^</param>
		EnemyObject(Vector2 createPos, BulletManager* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~EnemyObject();

		/// <summary>
		/// �̗͎擾�p�֐�
		/// </summary>
		/// <returns>�c��̗�</returns>
		int GetHitPoint();

		/// <summary>
		/// �G�X�V����
		/// </summary>
		void EnemyUpdate();

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
		int hitPoint;								// �c�̗�
		int countForHitJudgment;					// �����蔻��p�̃J�E���g
		float stateTime;							// �X�e�[�g�ύX���s������
		float timeCount;							// ���Ԍv���p�ϐ�
		float targetTime;							// �ڕW����
		bool bulletHittable;						// �e�������邱�Ƃ��ł��邩
		BulletManager* bulletManager;				// �e�Ǘ��N���X�̃|�C���^
		EnemyState state;							// �G�̍s�����
		Vector2 spriteSize;							// �摜�T�C�Y
		AnimationController animationController;	// �A�j���[�V�����Ǘ��N���X
		AnimationClip stayAnimation;				// ��~��Ԃ̃A�j���[�V�����N���b�v
		AnimationClip shotAnimation;				// �e���ˏ�Ԃ̃A�j���[�V�����N���b�v

		/// <summary>
		/// �N���b�v�����p�֐�
		/// </summary>
		void ClipInstance();
	};

	inline EnemyObject::EnemyObject() :
		hitPoint(), countForHitJudgment(), stateTime(), timeCount(), targetTime(), bulletHittable(),
		bulletManager(), state(), spriteSize(), animationController(), stayAnimation(), shotAnimation() {}

	inline int EnemyObject::GetHitPoint() { return hitPoint; }
}