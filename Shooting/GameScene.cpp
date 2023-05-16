#include "GameScene.h"
#include "DxLib.h"
#include <string>
#include <iostream>

using namespace std;

namespace Scene
{
	GameScene::GameScene(SceneType* ptr) :
		collisionManager(CollisionManager()), bulletManager(BulletManager(&collisionManager)),
		player(PlayerObject(Vector2(100, 150), &bulletManager)), enemy(EnemyObject(Vector2(550, 150), &bulletManager))
	{
		collisionManager.CollisionSubscrive(&player);	// �����蔻��N���X�Ƀv���C���[��o�^����	
		collisionManager.CollisionSubscrive(&enemy);	// �����蔻��N���X�ɃG�l�~�[��o�^����

		nextScene = ptr;								// �V�[���X�V�|�C���^��ݒ�
	}

	GameScene::~GameScene() {}

	void GameScene::SceneUpdate()
	{
		player.PlayerUpdate();				// �v���C���[�X�V�������s��
		enemy.EnemyUpdate();				// �G�l�~�[�X�V�������s��
		bulletManager.BulletUpdate();		// �e�Ǘ��N���X�̍X�V�������s��
		collisionManager.CollisionUpdate();	// �����蔻��N���X�̍X�V�������s��

		// �v���C���[�̗̑͂��o��
		DrawString(0,0,"Player:",GetColor(255,255,255));
		for (int i = 0; i < player.GetHitPoint(); i++)
		{
			DrawString((i + 3) * 20,0,"��",GetColor(255,255,255));
		}

		// �G�l�~�[�̗̑͂��o��
		DrawString(0, 30, "Enemy :", GetColor(255, 255, 255));
		for (int i = 0; i < enemy.GetHitPoint(); i++)
		{
			DrawString((i + 3) * 20,30,"��",GetColor(255,255,255));
		}

		if (player.GetHitPoint() <= 0)			// �v���C���[�̗̑͂��Ȃ��Ȃ�����
		{
			*nextScene = SceneType::GAMEOVER;	// �V�[���X�V�|�C���^�ɃQ�[���I�[�o�[��ݒ�
		}

		if (enemy.GetHitPoint() <= 0)			// �G�l�~�[�̗̑͂��Ȃ��Ȃ�����
		{
			*nextScene = SceneType::CLEAR;		// �V�[���X�V�|�C���^�ɃN���A��ݒ�
		}
	}
}