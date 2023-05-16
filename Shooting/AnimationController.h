#pragma once

#include "AnimationClip.h"
#include "Vector2.h"
#include "DxLib.h"
#include <map>
using namespace std;

namespace Animation
{
	/// <summary>
	/// アニメーションを制御するクラス
	/// </summary>
	class AnimationController
	{
	public:

		/// <summary>
		/// コンストラクタ(座標0,0生成)
		/// </summary>
		AnimationController();

		/// <summary>
		/// コンストラクタ(座標固定生成)
		/// </summary>
		/// <param name="size">生成座標</param>
		AnimationController(Vector2);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~AnimationController();

		/// <summary>
		/// アニメーション登録関数
		/// </summary>
		/// <param name="animationName">アニメーション名</param>
		/// <param name="newClip">登録するクリップ</param>
		void AnimationSubscrive(const char*, AnimationClip);

		/// <summary>
		/// アニメーション変更関数
		/// </summary>
		/// <param name="playAnimationName">実行アニメーション名</param>
		void AnimationPlay(const char*);

		/// <summary>
		/// アニメーション更新関数(常時実行推奨.複数から呼ぶことを非推奨)
		/// </summary>
		/// <param name="position">画像生成座標</param>
		/// <param name="flip">反転生成するかどうか</param>
		void AnimaitonUpdate(Vector2, bool);
	private:
		int spriteIndex;									// 何番目の画像を読み込むか
		float spriteChengeTime;								// 画像変更時間保存用変数
		float timeCount;									// 時間計測用変数
		float nextAnimationTime;							// 次の画像に変更するまでの時間
		float nextAnimationDiray;							// 次の画像に変更するのにかける時間
		Vector2 spriteSize;									// 画像サイズ
		AnimationClip playClip;								// 実行中のクリップ
		map<const char*, AnimationClip> animationContainer;	// アニメーション名でクリップを保存するmap変数
	};
}