#include "ClearScene.h"

namespace Scene
{
	ClearScene::ClearScene(SceneType* ptr)
	{
		nextScene = ptr;	// �V�[���X�V�|�C���^��ݒ�
	}

	void ClearScene::SceneUpdate()
	{
		DrawString(0, 0, "Game Clear", GetColor(255, 255, 255));	// �����o��

		if (CheckHitKey(KEY_INPUT_SPACE))							// �X�y�[�X�L�[���͂��m�F������
		{
			*nextScene = SceneType::TITLE;							// �V�[���X�V�|�C���^�Ƀ^�C�g���V�[����ݒ�
		}
	}
}