#pragma once

#include "Bullet.h"
#include "NormalBullet.h"
#include "ChasableBullet.h"
#include "CollisionType.h"
#include "CollisionManager.h"

using namespace Object;
using namespace Collision;

namespace Manager
{
	/// <summary>
	/// �e�Ǘ��N���X
	/// </summary>
	class BulletManager
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		BulletManager();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ptr">�����蔻��N���X�̃|�C���^</param>
		BulletManager(CollisionManager*);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~BulletManager();

		Vector2* playerPos;	// �v���C���[���W�̃|�C���^(�Ǐ]�e�p)

		/// <summary>
		/// �e�X�V����
		/// </summary>
		void BulletUpdate();

		/// <summary>
		/// �ʏ�e�쐬�֐�
		/// </summary>
		/// <param name="angle">���ˊp�x</param>
		/// <param name="createPos">�������W</param>
		/// <param name="collisionPos">�ڐG�^�C�v</param>
		/// <returns>���������e�̃C���f�b�N�X</returns>
		int NormalBulletCreate(int angle, Vector2 createPos, CollisionType collisionPos);

		/// <summary>
		/// �Ǐ]�e�쐬�֐�
		/// </summary>
		/// <param name="createPos">�������W</param>
		/// <param name="collisionPos">�ڐG�^�C�v</param>
		/// <returns>���������e�̃C���f�b�N�X</returns>
		int ChasableBulletCreate(Vector2 createPos,CollisionType collisionPos);

		/// <summary>
		/// �e�o�^�����֐�
		/// </summary>
		/// <param name="index">�o�^��������e�̃C���f�b�N�X</param>
		void BulletUnregister(int index);
	private:
		static const int BULLET_MAXINSTANCE_COUNT = 100;	// �������
		Bullet* instanceBullets[BULLET_MAXINSTANCE_COUNT];	// ���������e�̃C���X�^���X�̔z��
		CollisionManager* collisionManager;					// �����蔻��N���X
	};

	inline BulletManager::BulletManager() : collisionManager(nullptr), instanceBullets(), playerPos() {}
}