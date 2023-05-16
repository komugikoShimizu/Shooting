#pragma once
#include <math.h>
#include "Bullet.h"

#define NORMAL_BULLET_SPPED 2

namespace Object
{
	/// <summary>
	/// �ʏ�e�̃N���X
	/// </summary>
	class NormalBullet : public Bullet
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		NormalBullet();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="angle">���ˊp�x</param>
		/// <param name="createPos">�������W</param>
		/// <param name="collisionPos">�ڐG�^�C�v</param>
		NormalBullet(int angle, Vector2 createPos, CollisionType collisionType);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~NormalBullet();

		/// <summary>
		/// �e�X�V����
		/// </summary>
		/// <returns>�L���ł��邩</returns>
		bool BulletUpdate() override;
	private:
		int angle;	// ���ˊp�x
	};

	inline NormalBullet::NormalBullet() : angle() {}

	inline NormalBullet::~NormalBullet() {}
}