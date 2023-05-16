#pragma once
#include "SceneBase.h"
#include "SceneType.h"
#include "PlayerObject.h"
#include "EnemyObject.h"
#include "BulletManager.h"
#include "CollisionManager.h"

using namespace Object;
using namespace Manager;
using namespace Collision;

namespace Scene
{
	/// <summary>
	/// �Q�[���V�[���̃N���X
	/// </summary>
	class GameScene : public SceneBase
	{
	public:
		/// <summary>
		/// �f�t�H���g�R���X�g���N�^
		/// </summary>
		GameScene();		

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="ptr">�V�[���X�V�|�C���^</param>
		GameScene(SceneType* ptr);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~GameScene() override;

		/// <summary>
		/// �V�[���X�V����
		/// </summary>
		void SceneUpdate() override;

		/// <summary>
		/// �V�[���^�C�v�擾�p�֐�
		/// </summary>
		/// <returns>���̃V�[���̃^�C�v</returns>
		SceneType GetSceneType() override;
	private:
		PlayerObject player;				// �v���C���[�̃C���X�^���X
		EnemyObject enemy;					// �G�l�~�[�̃C���X�^���X
		BulletManager bulletManager;		// �e�Ǘ��N���X�̃C���X�^���X	
		CollisionManager collisionManager;	// �����蔻��N���X�̃C���X�^���X
	};

	inline GameScene::GameScene() : player(), enemy(), bulletManager(), collisionManager() {}

	inline SceneType GameScene::GetSceneType() { return SceneType::GAME; }
}