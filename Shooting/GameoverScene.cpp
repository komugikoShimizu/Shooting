#include "GameoverScene.h"

namespace Scene
{
	GameoverScene::GameoverScene(SceneType* ptr)
	{
		nextScene = ptr;	// �V�[���X�V�|�C���^��ݒ�
	}

	void GameoverScene::SceneUpdate()
	{
		DrawString(0,0,"Game Over...",GetColor(255,255,255));	// �����o��

		if (CheckHitKey(KEY_INPUT_SPACE))						// �X�y�[�X�L�[���͂��m�F������
		{
			*nextScene = SceneType::TITLE;						// �V�[���X�V�|�C���^�Ƀ^�C�g���V�[����ݒ�
		}
	}
}