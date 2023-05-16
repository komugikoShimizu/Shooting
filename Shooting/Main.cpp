#include "DxLib.h"
#include "SceneManager.h"
#include "WindowCreate.h"
#include <Memory>

using namespace Scene;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)							// �c�w���C�u��������������
	{
		return -1;									// �G���[���N�����璼���ɏI��
	}

	auto draw = std::make_unique<WindowCreate>();	// �E�B���h�E�����N���X�̃��j�[�N�|�C���^�𐶐�
	SceneManager sceneManager = SceneManager();		// �V�[���Ǘ��N���X����

	while (ProcessMessage() == 0)					// ����ȏ���������Ă���ԃQ�[�����s
	{
		ClearDrawScreen();							// �X�N���[��������

		sceneManager.SceneUpdate();					// �V�[���X�V����

		ScreenFlip();								// �X�N���[������ւ�

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;									// �G�X�P�[�v���͎������I��
		}
	}

	DxLib_End();									// �c�w���C�u�����g�p�̏I������

	return 0;										// �\�t�g�̏I�� 
}