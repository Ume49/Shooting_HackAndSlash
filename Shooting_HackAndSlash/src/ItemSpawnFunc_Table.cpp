#include "ItemSpawnFunc_Table.h"

#include<cassert>
#include<algorithm>

namespace {
	// ����̍Œ�l
	constexpr int index_min = 0;

	// ����̍ő�l
	constexpr int index_max = 99;
}

namespace Shooting_HackAndSlash {
	ItemSpawnFunc_Table::ItemSpawnFunc_Table() :
		container()
	{
	}

	void ItemSpawnFunc_Table::reserve(size_t t) {
		container.reserve(t);
	}

	ItemSpawnFunc_Table::Func& ItemSpawnFunc_Table::at(int num) {
		// �͈͊O�̐����e��
		assert(num >= index_min && num <= ::index_max && "�m���e�[�u���ɗ^����ꂽ���l���͈͊O�ł�");

		// ���E�l��num�ɗאڂ��Ă���num���傫���v�f������
		auto itr = std::find_if(container.begin(), container.end(), [&](Set& s) {return num < s.border; });

		// �ǂ̋��E�l����num���傫���ꍇ�͖���+1��f���Ă��܂��̂ŁA�f�N�������g���Ė����ɂ��Ă���
		if (itr == container.end()) itr--;

		// �������v�f�̊֐��I�u�W�F�N�g�����J���ďI��
		return itr->func;
	}

	void ItemSpawnFunc_Table::add_unsort(Func f, int border) {
		container.push_back(Set{ f, border });
	}

	// �����Ƀ\�[�g
	void ItemSpawnFunc_Table::sort() {
		std::sort(container.begin(), container.end(), [](Set& a, Set& b) {return a.border < b.border; });
	}
}