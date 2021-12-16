#pragma once
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// ドラッグ＆ドロップ可能な、弾丸のアイコン
	class BulletIcon{
		Photo_SharedHandle photo;
		Vec2 pos;
	public:
		void update();
		void draw() const;

		BulletIcon(const std::string& path);
		~BulletIcon() = default;
	};
}
