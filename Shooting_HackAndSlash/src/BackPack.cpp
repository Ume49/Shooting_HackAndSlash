#include"BackPack.h"
#include<DxLib.h>
#include"BackPack_Info.h"
#include"BackPack_Info.h"

namespace {
	// スロット同士の間隔
	constexpr int Button_distance = 74;

	// スロットの個数
	constexpr int x = 3, y = 3;

	// スロットの位置 *相対座標
	constexpr int init_x = 10, init_y = 10;
}

namespace Shooting_HackAndSlash {
	BackPack::BackPack(const Point& p) :
		slots(),
		pos(p)
	{
		// スロットの初期位置を求める
		Point init = p + Point{ ::init_x, ::init_y };

		// スロットの領域を予約
		slots.reserve(static_cast<size_t>(::x * ::y));

		// スロットを登録
		for (auto x = 0; x < ::x; x++) {
			for (auto y = 0; y < ::y; y++) {
				// 座標を計算
				Point temp = init + Point{ Button_distance * x, Button_distance * y };

				// 登録
				slots.push_back(BackPack_Slot(temp));
			}
		}
	}

	void BackPack::update() {
		// アイテムドラッグ関数
		auto generate = []() {};

		for (auto& w : slots) {
			if (w.is_click()) {
				generate();
				break;
			}
		}
	}

	void BackPack::draw() const {
		// 背景描画
		DrawGraph(pos.x, pos.y, back_photo, TRUE);
		// 空枠描画
		for (auto& w : slots) { w.draw(); }
		// アイテムアイコン描画
		auto& data = BackPack_Info::getContainer();
		for (auto i = 0U; i < data.size(); i++) {
			const auto& c = slots.at(i).get_center();

			// スロットの中央を基準にアイコンを描画
			DrawRotaGraph(c.x, c.y, 1., 0., BackPack_Info::getIcon(data.at(i)), TRUE);
		}
	}
}