#pragma once
#include <math.h>
#include "Bullet.h"

#define ChasableBulletSpped 1

namespace Object
{
	/// <summary>
	/// �Ǐ]�e�N���X
	/// </summary>
	class ChasableBullet : public Bullet
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		ChasableBullet();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="targetPosPtr">�Ǐ]������W�|�C���^</param>
		/// <param name="createPos">�������W</param>
		/// <param name="collisionPos">�ڐG�^�C�v</param>
		ChasableBullet(Vector2* targetPosPtr, Vector2 createPos, CollisionType collisionPos);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ChasableBullet();

		/// <summary>
		/// �e�X�V����
		/// </summary>
		/// <returns>�L���ł��邩</returns>
		bool BulletUpdate() override;
	private:
		int targetTime;			// �ڕW���ԕϐ� 
		Vector2* targetPosPtr;	// �Ǐ]������W�|�C���^
	};

	inline ChasableBullet::ChasableBullet() : targetTime(), targetPosPtr() {}

	inline ChasableBullet::~ChasableBullet() {}
}
