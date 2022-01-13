#pragma once

#include<vector>
#include<functional>
#include<list>
#include<memory>

#include"AbstructItem.h"

namespace Shooting_HackAndSlash {
	// 0~99�܂ł̐�����^����ƑΉ������֐��I�u�W�F�N�g��Ԃ��Ă����N���X
	// �m���Ή��\�݂����Ɏg����
	class ItemSpawnFunc_Table {
		using Func = std::function<void(const Vec2& pos)>;

		struct Set {
			Func func;
			int border;
		};

		std::vector<Set> container;

	public:
		ItemSpawnFunc_Table();
		~ItemSpawnFunc_Table() = default;

		// 0~99�܂ł̒l��^����ƑΉ������֐���Ԃ�
		Func& at(int num);

		// ���ڂ�ǉ�
		// �\�[�g���Ȃ��̂ŁA�S�Ă̒ǉ����I���������sort()���Ăяo������
		void add_unsort(Func, int border);

		// �����R���e�i���\�[�g
		// add_unsort��S�čs������ɍs���ׂ�
		void sort();

		// �����R���e�i�̑傫���𖾎��I�ɗ\�񂷂�
		void reserve(size_t size);
	};
}
