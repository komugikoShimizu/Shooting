#pragma once
#include "SceneType.h"

namespace Scene
{
	/// <summary>
	/// �e�V�[���̊��N���X
	/// </summary>
	class SceneBase
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		SceneBase();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~SceneBase();

		/// <summary>
		/// �V�[���X�V����
		/// </summary>
		virtual void SceneUpdate();

		/// <summary>
		/// �V�[���^�C�v�擾�p�֐�
		/// </summary>
		/// <returns>���̃V�[���̃^�C�v</returns>
		virtual SceneType GetSceneType();
	protected:
		SceneType* nextScene;
	};

	inline SceneBase::SceneBase() : nextScene() {};

	inline SceneBase::~SceneBase() {}; 

	inline void SceneBase::SceneUpdate() {};

	inline SceneType SceneBase::GetSceneType() { return SceneType::EXCEPTION; }
}