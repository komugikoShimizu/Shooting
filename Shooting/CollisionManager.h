#pragma once
#include "CollisionObject.h"
#include "Math.h"
#include <map>

#define InstaceMax 256

using namespace std;

namespace Collision
{
	/// <summary>
	/// 当たり判定管理クラス
	/// </summary>
	class CollisionManager
	{
	public:
		/// <summary>
		/// コンストラクタ
		/// </summary>
		CollisionManager();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~CollisionManager();

		/// <summary>
		/// 登録関数
		/// </summary>
		/// <param name="ptr">登録する対象</param>
		void CollisionSubscrive(CollisionObject* ptr);

		/// <summary>
		/// 当たり判定処理更新
		/// </summary>
		void CollisionUpdate();

		/// <summary>
		/// 判定実行処理
		/// </summary>
		/// <param name="a">対象1</param>
		/// <param name="b">対象2</param>
		/// <returns></returns>
		bool CollisionJudge(CollisionObject* a, CollisionObject* b);
	private:
		map<int, CollisionObject*> objectMap;	// 生成したオブジェクトリスト
	};
}