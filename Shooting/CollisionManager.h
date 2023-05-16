#pragma once
#include "CollisionObject.h"
#include "Math.h"
#include <map>

#define InstaceMax 256

using namespace std;

namespace Collision
{
	/// <summary>
	/// �����蔻��Ǘ��N���X
	/// </summary>
	class CollisionManager
	{
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		CollisionManager();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~CollisionManager();

		/// <summary>
		/// �o�^�֐�
		/// </summary>
		/// <param name="ptr">�o�^����Ώ�</param>
		void CollisionSubscrive(CollisionObject* ptr);

		/// <summary>
		/// �����蔻�菈���X�V
		/// </summary>
		void CollisionUpdate();

		/// <summary>
		/// ������s����
		/// </summary>
		/// <param name="a">�Ώ�1</param>
		/// <param name="b">�Ώ�2</param>
		/// <returns></returns>
		bool CollisionJudge(CollisionObject* a, CollisionObject* b);
	private:
		map<int, CollisionObject*> objectMap;	// ���������I�u�W�F�N�g���X�g
	};
}