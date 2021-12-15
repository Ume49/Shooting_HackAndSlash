#pragma once
#include"Singleton.h"

namespace Shooting_HackAndSlash {
	class Bullet_Info : public Singleton<Bullet_Info>{
		friend Singleton;
		Bullet_Info();
		~Bullet_Info() = default;


	public:

		
	};
}
