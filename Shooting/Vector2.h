#pragma once

/// <summary>
/// ���W�Ǘ����Ŏg�p����\����
/// </summary>
struct Vector2
{
public:
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Vector2();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">�v�f1</param>
	/// <param name="y">�v�f2</param>
	Vector2(float x,float y);

	float x;	// �v�f1
	float y;	// �v�f2

	/// <summary>
	/// �E�ӂ̒l�Ƃ̘a��Ԃ��܂�
	/// </summary>
	/// <param name="plus">�E��</param>
	/// <returns>�v�Z����</returns>
	Vector2 operator + (Vector2 plus);

 	/// <summary>
 	/// ���ӂɉE�ӂ̗v�f�����Z���܂�
 	/// </summary>
 	/// <param name="plus">�E��</param>
 	void operator += (Vector2 plus);

	/// <summary>
	/// �E�ӂ̒l�Ƃ̍���Ԃ��܂�
	/// </summary>
	/// <param name="minus">�E��</param>
	/// <returns>�v�Z����</returns>
	Vector2 operator - (Vector2 minus);

	/// <summary>
	/// ���ӂɉE�ӂ̗v�f�����Z���܂�
	/// </summary>
	/// <param name="minus">�E��</param>
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