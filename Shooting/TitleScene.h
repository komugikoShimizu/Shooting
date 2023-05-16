#pragma once
#include "SceneBase.h"
#include "SceneType.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// �^�C�g���V�[���̃N���X
	/// </summary>
	class TitleScene : public SceneBase
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		TitleScene();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ptr">�V�[���X�V�|�C���^</param>
		TitleScene(SceneType* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~TitleScene();

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

	inline TitleScene::TitleScene() {}

	inline SceneType TitleScene::GetSceneType() { return SceneType::TITLE; }
}