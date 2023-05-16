#pragma once
#include <windows.h>
#include "SceneBase.h"
#include "DxLib.h"

namespace Scene
{
	/// <summary>
	/// �Q�[���I�[�o�[�V�[���̃N���X
	/// </summary>
	class GameoverScene : public SceneBase
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		GameoverScene();

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ptr">�V�[���X�V�|�C���^</param>
		GameoverScene(SceneType* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~GameoverScene();

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

	inline GameoverScene::GameoverScene() {}

	inline GameoverScene::~GameoverScene() {}

	inline SceneType GameoverScene::GetSceneType() { return SceneType::GAMEOVER; }
}