#include"Magazine.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash::Gun_Custamize {
	Magazine::Magazine(ISetIcon& s) : 
		setter(s)
	{

	}

	void Magazine::update() {

	}

	void Magazine::draw() const {
		/*for (auto& w : slots) {
			w.draw();
		}*/
	}

	bool Magazine::CheckDrop(const eBullet& e) {


		return false;
	}

	void Magazine::Back(size_t index, const eBullet& bullet) {

	}
}
