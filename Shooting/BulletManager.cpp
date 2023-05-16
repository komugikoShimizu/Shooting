#include "BulletManager.h"

namespace Manager
{
	BulletManager::BulletManager(CollisionManager* ptr) : collisionManager(ptr) {}

	BulletManager::~BulletManager() {}

	void BulletManager::BulletUpdate()
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)	// �C���X�^���X����܂Ŏ��s
		{
			if (instanceBullets[i] != nullptr)				// ���̔z��v�f�ԍ��ɒl�������
			{
				if (!instanceBullets[i]->BulletUpdate())	// �e�X�V���������s
				{
					BulletUnregister(i);					// �L���łȂ���Βe�ݒ������
				}
			}
		}
	}

	int BulletManager::NormalBulletCreate(int angle, Vector2 createPos, CollisionType collisionType)
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)					// �C���X�^���X����܂Ŏ��s
		{
			if (instanceBullets[i] == nullptr)								// ���̔z��v�f�ԍ��ɃC���X�^���X�����݂��Ȃ����
			{
				instanceBullets[i] =
					new NormalBullet(angle, createPos, collisionType);		// �C���X�^���X��z��ɓo�^
				collisionManager->CollisionSubscrive(instanceBullets[i]);	// �����蔻��N���X�ɃC���X�^���X�����e��o�^����
				return i;													// �v�f�ԍ���n��
			}
		}

		return -1;
	}

	int BulletManager::ChasableBulletCreate(Vector2 createPos, CollisionType collisionType)
	{
		for (int i = 0; i < BULLET_MAXINSTANCE_COUNT; i++)						// �C���X�^���X����܂Ŏ��s
		{
			if (instanceBullets[i] == nullptr)									// ���̔z��v�f�ԍ��ɃC���X�^���X�����݂��Ȃ����
			{
				instanceBullets[i] =
					new ChasableBullet(playerPos, createPos, collisionType);	// �C���X�^���X��z��ɓo�^
				collisionManager->CollisionSubscrive(instanceBullets[i]);		// �����蔻��N���X�ɃC���X�^���X�����e��o�^����
				return i;														// �v�f�ԍ���n��
			}
		}

		return -1;
	}

	void BulletManager::BulletUnregister(int index)
	{
		instanceBullets[index] = nullptr;	// �w��̗v�f�ԍ���nullptr�ŏ�����
	}
}