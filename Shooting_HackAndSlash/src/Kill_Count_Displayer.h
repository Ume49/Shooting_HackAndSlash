#pragma once
#include"Abstruct_UI.h"
#include"Font_SharedHandle.h"

namespace Shooting_HackAndSlash {
	namespace UI {
		class Kill_Count_Displayer : public Abstruct_UI {
			Font_SharedHandle font_handle;
		public:
			void draw() const override;
#ifdef _DEBUG
			Kill_Count_Displayer();
#endif // _DEBUG
			Kill_Count_Displayer(const std::string& path);
		};
	}
}
