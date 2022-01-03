#include "Bullet_Resource.h"

#include"Gun_Info.h"

#include<cassert>

namespace Shooting_HackAndSlash {
	const eBullet& Bullet_Resource::get() {
		assert(resource.size() > 0 && "���g���Ȃ����\�[�X�ɃA�N�Z�X���悤�Ƃ��Ă��܂�");

		// ���̗v�f���擾���A�X�V
		auto& e = resource.front();
		resource.pop();

		return e;
	}

	Bullet_Resource::Bullet_Resource() :
		resource() {
		auto& info = Gun_Info::Now_Gun().magazine;

		// ���݂̏e����e�̏����擾
		for (auto& w : info) {
			resource.push(w);
		}

		// ���������߂�
		resource.push(eBullet::Null);
	}

	Bullet_Resource::Bullet_Resource(const Bullet_Resource& r) :
		resource(r.resource) {
	}
}