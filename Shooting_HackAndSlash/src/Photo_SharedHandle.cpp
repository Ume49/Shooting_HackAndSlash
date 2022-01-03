#include "Photo_SharedHandle.h"
#include<DxLib.h>
#include"Abstruct_Shared_Manager.h"

namespace {
	constexpr char Null[] = "";
}

namespace {
	class Manager : public Shooting_HackAndSlash::Abstruct_Shared_Manager {
	public:
		Manager() { Load(::Null); }
		~Manager() { InitGraph(); }
	protected:
		int load_func(const std::string& path) override { return LoadGraph(path.c_str()); }
		void release_func(int handle) override { DeleteGraph(handle); }
	};

	static Manager manager;
}
namespace Shooting_HackAndSlash {
	Photo_SharedHandle::Photo_SharedHandle() :
		Abstruct_SharedHandle(::Null, ::manager) {
	}

	Photo_SharedHandle::Photo_SharedHandle(const std::string& path) :
		Abstruct_SharedHandle(path, ::manager) {}

	Point Photo_SharedHandle::size() const {
		Point s;

		GetGraphSize(handle, &s.x, &s.y);

		return s;
	}

	const std::string& Photo_SharedHandle::getkey() const {
		return this->release_key;
	}
}