#pragma once
#include"Abstruct_UI.h"
#include"Font_SharedHandle.h"

namespace Shooting_HackAndSlash::UI {
	class Stage_Num_Displayer : public Abstruct_UI{
		Font_SharedHandle font_handle;
	public:
		void draw() const override;

		Stage_Num_Displayer();
		~Stage_Num_Displayer() = default;
	};
}
