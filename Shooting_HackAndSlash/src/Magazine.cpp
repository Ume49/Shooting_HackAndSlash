#include"Magazine.h"
#include<DxLib.h>

#include"Define.h"
#include"Input.h"

namespace {
	// ÉXÉçÉbÉgä‘ÇÃãóó£
	constexpr int slot_space = 10;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	Magazine::Magazine(ISetIcon& s) :
		setter(s)
	{
	}

	void Magazine::update() {
		if (Input::GetDown(Inputcode::Fire1)) {
			for (auto& w : slots) {
				if (w.is_on_mouse()) {

				}
			}
		}
	}

	void Magazine::draw() const {
		for (auto& w : slots) {
			auto pos = w.Center();


		}
	}

	bool Magazine::CheckDrop(const eBullet& e) {
		return false;
	}

	void Magazine::Back(size_t index, const eBullet& bullet) {
	}
}