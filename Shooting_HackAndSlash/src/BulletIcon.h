#pragma once
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// �h���b�O���h���b�v�\�ȁA�e�ۂ̃A�C�R��
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
