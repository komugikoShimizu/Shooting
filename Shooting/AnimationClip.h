#pragma once

#include "DxLib.h" 

namespace Animation
{
	/// <summary>
	/// �A�j���[�V�����̓��e���l�߂�ꂽ�\����
	/// </summary>
	struct AnimationClip
	{
		/// <summary>
		/// �R���X�g���N�^(�l�ݒ肪�ł��Ȃ��̂Ŏg�p�֎~)
		/// </summary>
		AnimationClip();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="const char*">�摜�p�X</param>
		/// <param name="int 1">�؂蕪����ő吔</param>
		/// <param name="int 2">x�����ɐ؂蕪�����</param>
		/// <param name="int 3">y�����ɐ؂蕪�����</param>
		/// <param name="int 4">�摜�̃T�C�YX</param>
		/// <param name="int 5">�摜�̃T�C�YY</param>
		/// <param name="float">�A�j���[�V�����ɂ����鎞��</param>
		/// <param name="bool">���[�v�Đ����s�����ǂ���</param>
		AnimationClip(const char*,int,int,int,int,int,float,bool);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~AnimationClip();

		const char* spritePass;	// �摜�̃p�X
		int sliceCountMax;		// �؂蕪����摜��
		int sliceCountX;		// x�����ɐ؂蕪�����
		int sliceCountY;		// y�����ɐ؂蕪�����
		int sliceSizeX;			// �摜�T�C�Y(x)
		int sliceSizeY;			// �摜�T�C�Y(y)
		float animationTime;	// �A�j���[�V�����ɂ����鎞��
		bool isLoop;			// ���[�v�Đ����s�����ǂ���

		int handleArray[10];	// �摜�̃n���h���z��
	};

	inline AnimationClip::AnimationClip() : 
		spritePass(), sliceCountMax(), sliceCountX(), sliceCountY(), sliceSizeX(), sliceSizeY(),
		animationTime(), isLoop(), handleArray() {};

	inline AnimationClip::AnimationClip(const char* spritePass, int sliceCountMax,
		int sliceCountX, int sliceCountY, int sliceSizeX, int sliceSizeY, float animationTime, bool isLoop)
	{
		this->spritePass = spritePass;
		this->sliceCountMax = sliceCountMax;
		this->sliceCountX = sliceCountX;
		this->sliceCountY = sliceCountY;
		this->sliceSizeX = sliceSizeX;
		this->sliceSizeY = sliceSizeY;
		this->animationTime = animationTime;
		this->isLoop = isLoop;

		LoadDivGraph(spritePass, sliceCountMax, sliceCountX, sliceCountY, sliceSizeX, sliceSizeY, handleArray);
	}

	inline AnimationClip::~AnimationClip() {};
}