#pragma once
#include<vector>
#include<memory>
#include<functional>

#include"Slot.h"
#include"Photo_SharedHandle.h"
#include"Gun.h"

#include"IDragAndDropListener.h"
#include"ISetIcon.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	// 銃の中身を表示するクラス
	class Magazine : public IDragAndDropListener {
		ISetIcon& setter;

		using ref_Gun = std::reference_wrapper<Gun>;
		// 銃の参照
		std::unique_ptr<ref_Gun> gun_ref;

		std::vector<Slot> slots;
		Photo_SharedHandle null_slot_photo;
	public:
		void update();
		void draw() const;

		bool CheckDrop(IPackagedIcon& i) override;
		void Back(size_t index, const eBullet& bullet) override;

		Magazine(ISetIcon& set);
		~Magazine() = default;
	};
}
