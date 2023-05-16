#pragma once
#include "DxLib.h"

namespace Manager
{
	/// <summary>
	/// �E�B���h�E�����N���X
	/// </summary>
	class WindowCreate
	{
	public:
		WindowCreate();
		~WindowCreate();
	};

	inline WindowCreate::WindowCreate()
	{
		SetMainWindowText("Shooting");					// �E�B���h�E��
		ChangeWindowMode(TRUE);							// �E�B���h�E���[�h�ŋN��
		SetGraphMode(640, 480, 32);						// �E�B���h�E�T�C�Y
		SetWindowSizeChangeEnableFlag(TRUE, TRUE);		// �E�B���h�E�T�C�Y��ύX���ɂ���
		DxLib_Init();									// �E�B���h�E�쐬�ADXLib�N��
		SetDrawScreen(DX_SCREEN_BACK);					// �������މ�ʂ𐶐�
	}

	inline WindowCreate::~WindowCreate() {}
}