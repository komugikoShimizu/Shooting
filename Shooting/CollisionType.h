#pragma once

namespace Collision
{
	/// <summary>
	/// 当たり判定用の接触タイプ
	/// </summary>
	enum class CollisionType
	{
		TYPE_NONE,
		PLAYER,
		ENEMY,
		PLAYER_BULLET,
		ENEMY_BULLET
	};
}