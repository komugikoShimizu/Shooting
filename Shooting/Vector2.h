#pragma once

/// <summary>
/// 座標管理等で使用する構造体
/// </summary>
struct Vector2
{
public:
	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Vector2();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">要素1</param>
	/// <param name="y">要素2</param>
	Vector2(float x,float y);

	float x;	// 要素1
	float y;	// 要素2

	/// <summary>
	/// 右辺の値との和を返します
	/// </summary>
	/// <param name="plus">右辺</param>
	/// <returns>計算結果</returns>
	Vector2 operator + (Vector2 plus);

 	/// <summary>
 	/// 左辺に右辺の要素を加算します
 	/// </summary>
 	/// <param name="plus">右辺</param>
 	void operator += (Vector2 plus);

	/// <summary>
	/// 右辺の値との差を返します
	/// </summary>
	/// <param name="minus">右辺</param>
	/// <returns>計算結果</returns>
	Vector2 operator - (Vector2 minus);

	/// <summary>
	/// 左辺に右辺の要素を減算します
	/// </summary>
	/// <param name="minus">右辺</param>
	void operator -= (Vector2 minus);
};

inline Vector2::Vector2()
{
	x = 0;
	y = 0;
}

inline Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

inline Vector2 Vector2::operator+ (Vector2 plus)
{
	return Vector2(x + plus.x, y + plus.y);
}

inline void Vector2::operator+= (Vector2 plus)
{
	this->x += plus.x;
	this->y += plus.y;
}

inline Vector2 Vector2::operator- (Vector2 minus)
{
	return Vector2(x - minus.x, y - minus.y);
}

inline void Vector2::operator-= (Vector2 minus)
{
	this->x -= minus.x;
	this->y -= minus.y;
}