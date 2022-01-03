#include "Bullet_Resource.h"

#include"Gun_Info.h"

#include<cassert>

namespace Shooting_HackAndSlash {
	const eBullet& Bullet_Resource::get() {
		assert(resource.size() > 0 && "中身がないリソースにアクセスしようとしています");

		// 次の要素を取得し、更新
		auto& e = resource.front();
		resource.pop();

		return e;
	}

	Bullet_Resource::Bullet_Resource() :
		resource() {
		auto& info = Gun_Info::Now_Gun().magazine;

		// 現在の銃から弾の情報を取得
		for (auto& w : info) {
			resource.push(w);
		}

		// 末尾を込める
		resource.push(eBullet::Null);
	}

	Bullet_Resource::Bullet_Resource(const Bullet_Resource& r) :
		resource(r.resource) {
	}
}