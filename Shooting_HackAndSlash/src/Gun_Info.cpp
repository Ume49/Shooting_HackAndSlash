#include "Gun_Info.h"

namespace {
	// �C���f�b�N�X�̏����l
	constexpr int init_index = 0;

	// �J�n���e�����������Ă��邩
	constexpr int init_gun_num = 1;
}

namespace Shooting_HackAndSlash {
	using namespace Gun_Custamize;

	Gun_Info::Gun_Info() :
		guns(),
		now_select(::init_index)
	{
		// �����e�̐ݒ�
#ifdef _DEBUG
		guns.push_back(Gun(3U));

		auto& m = guns.begin()->magazine;

		m.at(0) = eBullet::ST;
		m.at(1) = eBullet::Star;
		m.at(2) = eBullet::ST;

#else

#endif // _DEBUG
	}

	void Gun_Info::initialize() {
		Gun_Info::getInstance().guns.resize(::init_gun_num);
		Gun_Info::getInstance().now_select = ::init_index;
	}

	Gun& Gun_Info::at(size_t i) {
		return Gun_Info::getInstance().guns.at(i);
	}

	void Gun_Info::Add(size_t l) {
		Gun_Info::getInstance().guns.push_back(Gun(l));
	}

	Gun& Gun_Info::Now_Gun() {
		auto& ref = Gun_Info::getInstance();

		return ref.guns.at(ref.now_select);
	}

	Gun& Gun_Info::Plus() {
		auto& ref = Gun_Info::getInstance();

		(++ref.now_select) %= ref.guns.size();

		return ref.guns.at(ref.now_select);
	}

	Gun& Gun_Info::Minus() {
		auto& ref = Gun_Info::getInstance();

		auto i = ref.guns.size();

		((--ref.now_select) += i) &= i;

		return ref.guns.at(ref.now_select);
	}
}