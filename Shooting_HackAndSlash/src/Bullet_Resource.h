#pragma once

#include<queue>

#include"eBullet.h"

namespace Shooting_HackAndSlash {
	// 何の弾に派生するか、という情報を持つコンテナ
	// 中身はキュー
	class Bullet_Resource {
		std::queue<eBullet> resource;
	public:

		// 取得関数
		// これを使用すると「次の弾」という情報も一緒に更新される
		// 空の場合は一度だけNullが排出される
		const eBullet& get();

		Bullet_Resource(const Bullet_Resource& r);
		Bullet_Resource();
		~Bullet_Resource() = default;
	};
}
