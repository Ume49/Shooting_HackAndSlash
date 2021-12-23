#pragma once
#include<vector>

#include"IDragAndDropListener.h"
#include"ISetIcon.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 銃の中身を表示するクラス
	// 
	class Magazine : public IDragAndDropListener{
		ISetIcon& setter;
	public:
		void update();
		void draw() const;

		bool CheckDrop(const eBullet& e) override;
		void Back(size_t index, const eBullet& bullet) override;

		Magazine(ISetIcon& set);
		~Magazine() = default;
	};
}
