#include "TitleScene.h"

namespace Scene
{
	TitleScene::TitleScene(SceneType* ptr)
	{
		nextScene = ptr;	// �V�[���X�V�|�C���^��ݒ�
	}

	TitleScene::~TitleScene() {}

	void TitleScene::SceneUpdate()
	{
		DrawString(0, 0, "Shooting Game", GetColor(255, 255, 255));	// �������o��
		if (CheckHitKey(KEY_INPUT_SPACE))							// �X�y�[�X�L�[���͂��m�F������
		{
			*nextScene = SceneType::GAME;							// �V�[���X�V�|�C���^���Q�[���V�[���ɐݒ�
		}
	}
}