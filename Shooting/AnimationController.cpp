#include "AnimationController.h"

namespace Animation
{
	AnimationController::AnimationController():
		nextAnimationDiray(0),nextAnimationTime(0),
		spriteSize(Vector2()),spriteChengeTime(0),
		spriteIndex(0),timeCount(0)
	{
	}

	AnimationController::AnimationController(Vector2 size):
		nextAnimationDiray(0), nextAnimationTime(0),
		spriteSize(size), spriteChengeTime(0),
		spriteIndex(0), timeCount(0)
	{
	}

	AnimationController::~AnimationController() {}

	void AnimationController::AnimationSubscrive(const char* animationName, AnimationClip newClip)
	{
		animationContainer[animationName] = newClip;
	}

	void AnimationController::AnimationPlay(const char* playAnimationName)
	{
		playClip = animationContainer[playAnimationName];									// 再生クリップを保存
		spriteChengeTime = playClip.sliceCountMax / playClip.animationTime;					// 画像変更時間を設定
		timeCount = GetNowCount();															// 時間計測用変数に経過時間を設定
		nextAnimationDiray = (playClip.animationTime / playClip.sliceCountMax) * 1000.0f;	// 画像変更時間を変数に保存(1000.0fをかけると秒数になるらしい)
		nextAnimationTime = timeCount + nextAnimationDiray;									// 画像変更を行う時間を保存
		spriteIndex = 0;																	// 画像を読み込むindexを初期化する
	}

	void AnimationController::AnimaitonUpdate(Vector2 position, bool flip)
	{
		if (playClip.animationTime == FLT_EPSILON) return;		// 再生アニメーション時間が0秒であれば処理しない(アニメーションしない or クリップ未設定のため)

		timeCount = GetNowCount();								// 経過時間更新

		if (timeCount >= nextAnimationTime)						// 画像更新時間を超えれば
		{
 			nextAnimationTime += nextAnimationDiray;			// 画像更新時間に経過時間を足して更新

			spriteIndex++;										// 画像表示indexを追加
			
			if (spriteIndex >= playClip.sliceCountMax)			// 画像数が設定された数を上回れば
			{
				if (playClip.isLoop)							// ループ再生するのであれば
				{
					spriteIndex = 0;							// 画像表示indexを再度0に変更
				}
				else
				{
					spriteIndex = playClip.sliceCountMax - 1;	// 要素数限界にindexを調整
				}
			}
		}

		// どちらかにでもサイズ設定がされていれば
		if (spriteSize.x != FLT_EPSILON || spriteSize.y != FLT_EPSILON)	
		{
			Vector2 sizeCalPos = position;						// サイズ反映座標保存用変数
			if (flip)											// 反転するのであれば
			{
				sizeCalPos.x -= spriteSize.x;					// x値のみ減算
				sizeCalPos.y += spriteSize.y;					// y方向は正しく生成してほしいため加算
			}
			else
			{
				sizeCalPos += spriteSize;						// 設定されたサイズを反映した座標値を作成
			}

			// 描画
			DrawExtendGraph(position.x, position.y, sizeCalPos.x, sizeCalPos.y, playClip.handleArray[spriteIndex], true);
		}
		else													// サイズ設定がされていない場合(する必要がない画像)
		{
			if (flip)											// 反転するのであれば
			{
				// 反転描画する
				DrawTurnGraph(position.x, position.y, playClip.handleArray[spriteIndex], true);
			}
			else
			{
				// 通常の描画処理を行う
				DrawGraph(position.x, position.y, playClip.handleArray[spriteIndex], true);
			}
		}
	}
}