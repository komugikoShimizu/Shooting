#include "CollisionManager.h"
#include "DxLib.h"

namespace Collision
{
	CollisionManager::CollisionManager() {}

	CollisionManager::~CollisionManager() {}

	void CollisionManager::CollisionSubscrive(CollisionObject* newObj)
	{
		for (int i = 0; i < InstaceMax; i++)	// �C���X�^���X����܂Ŏ��s
		{
			if (objectMap[i] == nullptr)		// �����ʒu���k���|�C���^�ł����
			{
				objectMap[i] = newObj;			// �Ώۂ����̈ʒu�Ɋi�[����
				break;							// for���I��
			}
		}
	}

	void CollisionManager::CollisionUpdate()
	{
		for (int i = 0; i < InstaceMax; i++)				// �C���X�^���X����܂Ŏ��s 
		{
			if (objectMap[i] == nullptr) continue;			// �����ʒu���k���|�C���^�ł���Ύ���
			// �v���C���[���G�l�~�[�łȂ��Ȃ玟��
			if (objectMap[i]->GetType() != CollisionType::PLAYER && objectMap[i]->GetType() != CollisionType::ENEMY) continue;
			for (int j = 0; j < InstaceMax; j++)			// �C���X�^���X����܂Ŏ��s
			{
				if (i == j) continue;
				if (objectMap[j] == nullptr) continue;		// �����ʒu���k���|�C���^�ł���Ύ���
				// �����ʒu�̐ڐG�^�C�v�����ݒ�Ȃ�
				if (objectMap[j]->GetType() == CollisionType::TYPE_NONE)
				{
					objectMap[j] = nullptr;					// �Ώۂ̈ʒu�Ƀk���|�C���^��ݒ�
					continue;								// ����
				}
				// �G�΂���e�ł����
				if ((objectMap[i]->GetType() == CollisionType::ENEMY && objectMap[j]->GetType() == CollisionType::PLAYER_BULLET) ||
					(objectMap[i]->GetType() == CollisionType::PLAYER && objectMap[j]->GetType() == CollisionType::ENEMY_BULLET))
				{
					// ����֐������s���A�������Ă���̂Ȃ�
					if (CollisionJudge(objectMap[i], objectMap[j]))
					{
						// ������s�����o���ɐڐG���֐������s����
						objectMap[i]->CollisionAction();
						objectMap[j]->CollisionAction();

						objectMap[j] = nullptr;				// �e�̃|�C���^���k���|�C���^�ɐݒ�
					}
				}
			}
		}
	}

	bool CollisionManager::CollisionJudge(CollisionObject* base, CollisionObject* opponent)
	{
		// 2�̍��W�̋������v�Z
		double distance =
			sqrt(pow((double)base->GetCollisionPos().x - (double)opponent->GetCollisionPos().x, 2) +
				pow((double)base->GetCollisionPos().y - (double)opponent->GetCollisionPos().y, 2));

		// 0�����Ȃ琮�������邽�߂�-1��������
		if (distance < 0) distance *= -1;

		// ���a���̍��v���v�Z���������ȏ�ł���Ȃ�true��Ԃ�
		bool ret = (double)base->GetRadius() + (double)opponent->GetRadius() >= distance;

		return ret;
	}
}