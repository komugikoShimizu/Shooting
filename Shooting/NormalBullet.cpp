#include "NormalBullet.h"

namespace Object
{
	NormalBullet::NormalBullet(int angle, Vector2 createPos, CollisionType type)
	{
		spriteSize = Vector2(64, 64);							// �摜�T�C�Y��ݒ�
		animationController = AnimationController(spriteSize);	// �A�j���[�V�����Ǘ��N���X��������

		active = true;			// �L���ɂ���
		radius = 16.0f;			// ���a��ݒ�
		position = createPos;	// ���W�𐶐����W�ɐݒ�
		this->type = type;		// �ڐG�^�C�v��ݒ�

		this->angle = angle;	// �p�x��ݒ�

		AnimationSet();			// �A�j���[�V�������쐬
	}

	bool NormalBullet::BulletUpdate()
	{
		// �ړ����W���쐬����
		float rx = NORMAL_BULLET_SPPED * cos(angle) + position.x;
		float ry = NORMAL_BULLET_SPPED * sin(angle) + position.y;

		position = Vector2(rx, ry);								// �ړ����W�ɍ��W���ړ�����

		animationController.AnimaitonUpdate(GetPos(), false);	// �A�j���[�V�������X�V����

		return active;
	}
}