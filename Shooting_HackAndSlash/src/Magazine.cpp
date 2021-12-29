#include"Magazine.h"
#include<DxLib.h>

#include"Define.h"
#include"Input.h"
#include"Gun_Info.h"
#include"Icon_Table.h"

namespace {
	// スロット間の距離
	constexpr int slot_space = 10;

	// 基準となる座標
	constexpr int pos_x = 100, pos_y = 300;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	// スロットを銃に合わせる
	void resize(std::unique_ptr<std::reference_wrapper<Gun>>& gun, std::vector<Slot>& slot, const Point& center, const Photo_SharedHandle& p) {
		auto length = gun->get().magazine.size();

		for (auto i = 0U; i < length; i++) {
			Point temp_size = p.size();

			Point temp_center = center + Point{ 0, temp_size.y + slot_space }*static_cast<int>(i);

			slot.push_back(Slot(temp_center, temp_size));
		}
	}

	Magazine::Magazine(ISetIcon& s) :
		setter(s),
		gun_ref(),
		slots(),
		null_slot_photo(Define::Path::Photo::Slot)
	{
		gun_ref = std::make_unique<ref_Gun>(Gun_Info::Now_Gun());

		resize(gun_ref, slots, Point{ ::pos_x, ::pos_y }, null_slot_photo);
	}

	void Magazine::update() {
		if (Input::GetDown(Inputcode::Fire1)) {
			for (auto i = 0U; i < slots.size(); i++) {
				if (gun_ref->get().magazine.at(i) == eBullet::Null) continue;	// Nullのところは考慮しない

				if (slots.at(i).is_on_mouse()) {	// どれかのスロットがクリックされた時
					setter.SetIcon(gun_ref->get().magazine.at(i), *this, i);

					gun_ref->get().magazine.at(i) = eBullet::Null;
					break;
				}
			}
		}
	}

	void Magazine::draw() const {
		auto iter = gun_ref->get().magazine.begin();

		for (const auto& w : slots) {
			Point temp_center = w.Center();

			int handle = -1;

			// ハンドルを決定
			if (*iter == eBullet::Null) {
				handle = null_slot_photo;
			}
			else {
				handle = Icon_Table::at(*iter);
			}

			iter++;

			using namespace Define::RotaGraph_Default;

			// 描画
			DrawRotaGraph(temp_center.x, temp_center.y, ExRate, Angle, handle, TRUE);
		}
	}

	bool Magazine::CheckDrop(const eBullet& e) {
		bool result = false;

		auto itr = gun_ref->get().magazine.begin();

		// スロットをチェック
		for (auto& w : slots) {
			if (*itr == eBullet::Null) {
				// 空のときだけ続行

				if (w.is_on_mouse()) {
					*itr = e;

					result = true;
					break;
				}
			}
			else {
				// スロットに中身があるとき
				
			}

			itr++;
		}

		return result;
	}

	void Magazine::Back(size_t index, const eBullet& bullet) {
		gun_ref->get().magazine.at(index) = bullet;
	}
}