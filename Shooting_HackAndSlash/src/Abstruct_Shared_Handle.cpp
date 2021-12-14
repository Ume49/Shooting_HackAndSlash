#include "Abstruct_Shared_Handle.h"

namespace Shooting_HackAndSlash {
	Abstruct_SharedHandle::Abstruct_SharedHandle(const std::string& s, Abstruct_Shared_Manager& m) :
		handle(),
		release_key(s),
		manager(m) {
		handle = m.Load(s);
	}

	Abstruct_SharedHandle::Abstruct_SharedHandle(Abstruct_Shared_Manager& m) :
		handle(),
		release_key(),
		manager(m) {}

	Abstruct_SharedHandle::Abstruct_SharedHandle(const Abstruct_SharedHandle& s) :
		handle(s.handle),
		release_key(s.release_key),
		manager(s.manager) {
		// コピーコンストラクタでインスタンスを生成したときは参照カウンタの増加が呼ばれないため、それを明示する
		manager.Count_Add(release_key);
	}

	Abstruct_SharedHandle::~Abstruct_SharedHandle() {
		manager.Release(release_key);
	}

	Abstruct_SharedHandle::operator int() const noexcept {
		return handle;
	}
}