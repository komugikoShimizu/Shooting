#pragma once
#include <windows.h>
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// �N���A�V�[���N���X
	/// </summary>
	class ClearScene : public SceneBase
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		ClearScene();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ptr">�V�[���X�V�|�C���^</param>
		ClearScene(SceneType* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ClearScene();

		/// <summary>
		/// �V�[���X�V����
		/// </summary>
		void SceneUpdate() override;

		/// <summary>
		/// �V�[���^�C�v�擾�p�֐�
		/// </summary>
		/// <returns>���̃V�[���̃^�C�v</returns>
		SceneType GetSceneType() override;
	};

	inline ClearScene::ClearScene() {}

	inline ClearScene::~ClearScene() {}

	inline SceneType ClearScene::GetSceneType() { return SceneType::CLEAR; }
}