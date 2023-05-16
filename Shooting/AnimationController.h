#pragma once

#include "AnimationClip.h"
#include "Vector2.h"
#include "DxLib.h"
#include <map>
using namespace std;

namespace Animation
{
	/// <summary>
	/// �A�j���[�V�����𐧌䂷��N���X
	/// </summary>
	class AnimationController
	{
	public:

		/// <summary>
		/// �R���X�g���N�^(���W0,0����)
		/// </summary>
		AnimationController();

		/// <summary>
		/// �R���X�g���N�^(���W�Œ萶��)
		/// </summary>
		/// <param name="size">�������W</param>
		AnimationController(Vector2);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~AnimationController();

		/// <summary>
		/// �A�j���[�V�����o�^�֐�
		/// </summary>
		/// <param name="animationName">�A�j���[�V������</param>
		/// <param name="newClip">�o�^����N���b�v</param>
		void AnimationSubscrive(const char*, AnimationClip);

		/// <summary>
		/// �A�j���[�V�����ύX�֐�
		/// </summary>
		/// <param name="playAnimationName">���s�A�j���[�V������</param>
		void AnimationPlay(const char*);

		/// <summary>
		/// �A�j���[�V�����X�V�֐�(�펞���s����.��������ĂԂ��Ƃ�񐄏�)
		/// </summary>
		/// <param name="position">�摜�������W</param>
		/// <param name="flip">���]�������邩�ǂ���</param>
		void AnimaitonUpdate(Vector2, bool);
	private:
		int spriteIndex;									// ���Ԗڂ̉摜��ǂݍ��ނ�
		float spriteChengeTime;								// �摜�ύX���ԕۑ��p�ϐ�
		float timeCount;									// ���Ԍv���p�ϐ�
		float nextAnimationTime;							// ���̉摜�ɕύX����܂ł̎���
		float nextAnimationDiray;							// ���̉摜�ɕύX����̂ɂ����鎞��
		Vector2 spriteSize;									// �摜�T�C�Y
		AnimationClip playClip;								// ���s���̃N���b�v
		map<const char*, AnimationClip> animationContainer;	// �A�j���[�V�������ŃN���b�v��ۑ�����map�ϐ�
	};
}