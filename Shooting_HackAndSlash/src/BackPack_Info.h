#pragma once
#include"Singleton.h"
#include<vector>
#include<unordered_map>
#include"eBullet.h"
#include"Photo_SharedHandle.h"

namespace Shooting_HackAndSlash {
	class BackPack_Info : public Singleton<BackPack_Info>{
		friend Singleton;
		BackPack_Info();
		~BackPack_Info() = default;

		std::vector<eBullet> bullets;
		// 弾とアイコン画像の対応表
		std::unordered_map<eBullet, Photo_SharedHandle> icon_table;
	public:

		static std::vector<eBullet>& getContainer();

		static int getIcon(const eBullet& kind);
	};
}
