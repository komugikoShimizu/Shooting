#pragma once

#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"
#include "GameoverScene.h"
#include "SceneType.h"

namespace Scene
{
	/// <summary>
	/// �V�[�����Ǘ�����N���X
	/// </summary>
	class SceneManager
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		SceneManager();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~SceneManager();

		/// <summary>
		/// �V�[���X�V����
		/// </summary>
		void SceneUpdate();
	private:
		SceneBase* activeScene;	// ���ݓ������Ă���V�[���̃|�C���^

		SceneType scene;		// �������V�[���̃^�C�v
	};
}