#include"BackPack.h"
#include<DxLib.h>
#include"Inventory_Info.h"
#include"Icon_Table.h"
#include"Define.h"

namespace {
	// スロット同士の間隔
	constexpr int Button_distance = 74;

	// スロットを横に何個並べるか
	constexpr int x = 2;

	// スロットの初期位置
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash::Gun_Custamize {
	BackPack::BackPack(const Point& p, ISetIcon& i) :
		null_slot_photo(Define::Path::Photo::Slot),
		slots(),
		pos(p),
		iseticon(i)
	{
		// スロットの初期位置を求める
		Point init = p + Point{ ::init_x, ::init_y };

		// スロットの領域を予約
		slots.reserve(static_cast<size_t>(Inventory_Info::getInstance().owned_item.size()));

		// スロットを縦に何個並べるか
		int height = Inventory_Length / ::x;

		// スロットを登録
		for (auto y = 0; y < height; y++) {
			for (auto x = 0; x < ::x; x++) {
				// 座標を計算
				Point temp = init + Point{ Button_distance * x, Button_distance * y };

				// 登録
				slots.push_back(BackPack_Slot(temp));
			}
		}
	}

	void BackPack::update() {
		// アイテムドラッグ関数
		auto generate = [&](const eBullet& b) {
			iseticon.SetIcon(b);
		};

		for (auto i = 0U; i < slots.size(); i++) {
			if (slots.at(i).is_click()) {
				auto bullet = Inventory_Info::getInstance().owned_item.at(i);

				
				if (bullet != eBullet::Null) { 
					generate(bullet);
					Inventory_Info::SetNull(i);
				}
				break;
			}
		}
	}

	void BackPack::draw() const {
		// 背景描画
		DrawGraph(pos.x, pos.y, back_photo, TRUE);

		// スロットの戦闘イテレータを取得
		auto iter = slots.cbegin();

		// インベントリを参照
		for (auto& w : Inventory_Info::getInstance().owned_item) {
			// 座標を取得
			auto pos = iter->get_center();

			// 描画命令
			auto draw = [&](int h) {DrawRotaGraph(pos.x, pos.y, Define::RotaGraph_Default::ExRate, Define::RotaGraph_Default::Angle, h, TRUE); };

			if (w == eBullet::Null) {	// 中身が空の場合
				iter->draw();
				draw(null_slot_photo);
			}
			else {						// 中身がある場合
				// 画像ハンドルを取得
				int handle = Icon_Table::at(w);

				draw(handle);
			}

			iter++;
		}
	}

	bool BackPack::CheckDrop() {
		for (auto& w : slots) {

		}
	}
}