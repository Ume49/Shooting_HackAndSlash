#pragma once
#include"Abstruct_UI.h"
#include"Font_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		class Kill_Count_Displayer : public Abstruct_UI {
			Font_SharedHandle font_handle;
		public:
			void draw() const override;
			Kill_Count_Displayer();
			Kill_Count_Displayer(const std::string& path);
		};
	}
}
