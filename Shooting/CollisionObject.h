#pragma once
#include "CollisionType.h"
#include "Vector2.h"

namespace Collision
{
	// �����蔻����s���I�u�W�F�N�g�̊��N���X
	class CollisionObject
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		CollisionObject();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~CollisionObject();
		
		/// <summary>
		/// �ڐG���֐�
		/// </summary>
		virtual void CollisionAction();

		/// <summary>
		/// �I�u�W�F�N�g�̓����蔻��p�̔��a��Ԃ�
		/// </summary>
		/// <returns>�I�u�W�F�N�g�̓����蔻��p�̔��a</returns>
		virtual float GetRadius();

		/// <summary>
		/// �I�u�W�F�N�g�̍��W��Ԃ�
		/// </summary>
		/// <returns>���W</returns>
		virtual Vector2 GetPos();

		/// <summary>
		/// �����蔻����s�����S���W��Ԃ�
		/// </summary>
		/// <returns>���S���W</returns>
		virtual Vector2 GetCollisionPos();

		/// <summary>
		/// �ڐG�^�C�v��Ԃ�
		/// </summary>
		/// <returns>�ڐG�^�C�v</returns>
		virtual CollisionType GetType();
	protected:
		float radius;									// �����蔻��p�̔��a
		Vector2 position;								// �I�u�W�F�N�g�̍��W
		Vector2 spriteSize;								// �摜�T�C�Y
		CollisionType type = CollisionType::TYPE_NONE;	// �ڐG�^�C�v
	};

	inline CollisionObject::CollisionObject() : radius(), position(), spriteSize(), type() {}

	inline CollisionObject::~CollisionObject() {}

	inline void CollisionObject::CollisionAction() {}

	inline float CollisionObject::GetRadius() { return radius; }

	inline Vector2 CollisionObject::GetPos() { return position; }

	inline Vector2 CollisionObject::GetCollisionPos() { return position + Vector2(spriteSize.x * 0.5f,spriteSize.y * 0.5f); }

	inline CollisionType CollisionObject::GetType() { return type; }
}