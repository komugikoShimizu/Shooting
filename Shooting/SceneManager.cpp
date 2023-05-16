#include "SceneManager.h"

namespace Scene
{
	SceneManager::SceneManager()
	{
		scene = SceneType::TITLE;
		activeScene = new TitleScene(&scene);
	}

	SceneManager::~SceneManager()
	{
		activeScene->~SceneBase();
	}

	void SceneManager::SceneUpdate()
	{
		if (activeScene->GetSceneType() != scene)
		{
			activeScene->~SceneBase();

			switch (scene)
			{
			case SceneType::TITLE:
				activeScene = new TitleScene(&scene);
				return;
			case SceneType::GAME:
				activeScene = new GameScene(&scene);
				return;
			case SceneType::CLEAR:
				activeScene = new ClearScene(&scene);
				return;
			case SceneType::GAMEOVER:
				activeScene = new GameoverScene(&scene);
				return;
			default:
				break;
			}
		}

		activeScene->SceneUpdate();
	}
}