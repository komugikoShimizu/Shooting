#pragma once

#include "DxLib.h" 

namespace Animation
{
	/// <summary>
	/// アニメーションの内容が詰められた構造体
	/// </summary>
	struct AnimationClip
	{
		/// <summary>
		/// コンストラクタ(値設定ができないので使用禁止)
		/// </summary>
		AnimationClip();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="const char*">画像パス</param>
		/// <param name="int 1">切り分ける最大数</param>
		/// <param name="int 2">x方向に切り分ける回数</param>
		/// <param name="int 3">y方向に切り分ける回数</param>
		/// <param name="int 4">画像のサイズX</param>
		/// <param name="int 5">画像のサイズY</param>
		/// <param name="float">アニメーションにかける時間</param>
		/// <param name="bool">ループ再生を行うかどうか</param>
		AnimationClip(const char*,int,int,int,int,int,float,bool);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~AnimationClip();

		const char* spritePass;	// 画像のパス
		int sliceCountMax;		// 切り分ける画像数
		int sliceCountX;		// x方向に切り分ける回数
		int sliceCountY;		// y方向に切り分ける回数
		int sliceSizeX;			// 画像サイズ(x)
		int sliceSizeY;			// 画像サイズ(y)
		float animationTime;	// アニメーションにかける時間
		bool isLoop;			// ループ再生を行うかどうか

		int handleArray[10];	// 画像のハンドル配列
	};

	inline AnimationClip::AnimationClip() : 
		spritePass(), sliceCountMax(), sliceCountX(), sliceCountY(), sliceSizeX(), sliceSizeY(),
		animationTime(), isLoop(), handleArray() {};

	inline AnimationClip::AnimationClip(const char* spritePass, int sliceCountMax,
		int sliceCountX, int sliceCountY, int sliceSizeX, int sliceSizeY, float animationTime, bool isLoop)
	{
		this->spritePass = spritePass;
		this->sliceCountMax = sliceCountMax;
		this->sliceCountX = sliceCountX;
		this->sliceCountY = sliceCountY;
		this->sliceSizeX = sliceSizeX;
		this->sliceSizeY = sliceSizeY;
		this->animationTime = animationTime;
		this->isLoop = isLoop;

		LoadDivGraph(spritePass, sliceCountMax, sliceCountX, sliceCountY, sliceSizeX, sliceSizeY, handleArray);
	}

	inline AnimationClip::~AnimationClip() {};
}