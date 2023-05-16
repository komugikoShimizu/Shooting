#include "ChasableBullet.h"

namespace Object
{
	ChasableBullet::ChasableBullet(Vector2* targetPosPtr, Vector2 createPos, CollisionType collisionType)
	{
		spriteSize = Vector2(64, 64);							// �摜�T�C�Y�ݒ�
		animationController = AnimationController(spriteSize);	// �A�j���[�V�����Ǘ��N���X����

		active = true;											// �L��������
		radius = 16.0f;											// �����蔻��p���a�ݒ�
		position = createPos;									// ���W�𐶐����W�ɐݒ�
		this->targetPosPtr = targetPosPtr;						// �Ǐ]���W�|�C���^��ݒ�
		type = collisionType;									// �ڐG�^�C�v�ݒ�

		targetTime = GetNowCount() + 10000;						// �ڕW���Ԑݒ�

		AnimationSet();											// �A�j���[�V�����ݒ�
	}

	bool ChasableBullet::BulletUpdate()
	{
		Vector2 distance = *targetPosPtr - position;						// �Ώۍ��W�Ƃ̋������쐬 

		float hypotenuse = sqrt(pow(distance.x, 2) + pow(distance.y, 2));		// �Εӂ��v�Z

		// �ړ��x�N�g�����쐬
		float mx = (distance.x / hypotenuse) * ChasableBulletSpped;
		float my = (distance.y / hypotenuse) * ChasableBulletSpped;

		position += Vector2(mx, my);											// ���W�Ɉړ��x�N�g�������Z

		animationController.AnimaitonUpdate(GetPos(), false);				// �A�j���[�V�����X�V

		if (targetTime < GetNowCount())										// �ڕW���Ԃ𒴂�����
		{
			active = false;													// ����������
			type = CollisionType::TYPE_NONE;								// �ڐG�^�C�v�𖢐ݒ�ɂ���
		}

		return active;
	}
}