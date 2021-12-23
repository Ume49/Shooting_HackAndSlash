#include"BackPack.h"
#include<DxLib.h>
#include"Inventory_Info.h"
#include"Icon_Table.h"
#include"Define.h"
#include"Input.h"

namespace {
	// スロット同士の間隔
	constexpr int Button_distance = 10;

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
		setter(i)
	{
		// スロットの初期位置を求める
		Point init = p + Point{ ::init_x, ::init_y };

		// スロットの領域を予約
		slots.reserve(static_cast<size_t>(Inventory_Info::getInstance().owned_item.size()));

		// スロットを縦に何個並べるか
		int height = Inventory_Length / ::x;

		// スロットのサイズを取得
		auto size = null_slot_photo.size();

		// スロットを登録
		for (auto y = 0; y < height; y++) {
			for (auto x = 0; x < ::x; x++) {
				Point temp = pos + Point{ ::init_x, ::init_y } + (Point{ Button_distance, Button_distance } + size) * Point { x, y };

				// 登録
				slots.push_back(Slot(temp, size));
			}
		}
	}

	void BackPack::update() {
		// アイテムドラッグ関数
		auto generate = [&](const eBullet& b, size_t index) {
			setter.SetIcon(b, *this, index);
		};

		if (Input::GetDown(Inputcode::Fire1)) {	// 左クリックが押された時
			for (auto i = 0U; i < slots.size(); i++) {	// 全ての当たり判定をチェック
				if (slots.at(i).is_on_mouse()) {	// マウスが重なっているスロットがあるかどうか
					//インベントリから、対応する弾を取得
					auto bullet = Inventory_Info::getInstance().owned_item.at(i);

					if (bullet != eBullet::Null) {
						generate(bullet, i);
						Inventory_Info::SetNull(i);
					}
					break;
				}
			}
		}
	}

	void BackPack::draw() const {
		// 背景描画
		DrawGraph(pos.x, pos.y, back_photo, TRUE);

		// スロットの戦闘イテレータを取得
		auto iter = slots.cbegin();

#ifdef _DEBUG
		int count = 0;
#endif // _DEBUG

		// インベントリを参照
		for (auto& w : Inventory_Info::getInstance().owned_item) {
			// 座標を取得
			auto pos = iter->Center();

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

			// デバッグ用に番号描画
#ifdef _DEBUG
			DrawFormatString(pos.x, pos.y, Palette::White, "%d", count);
			count++;
#endif // _DEBUG

			iter++;
		}
	}

	bool BackPack::CheckDrop(const eBullet& b) {
		bool result = false;

		// コンテナの先頭イテレータを取得
		auto iter = Inventory_Info::getInstance().owned_item.begin();

		// マウスが重なっているスロットがあるか探索
		// ついでにそれと合うようにイテレータも移動
		for (auto& w : slots) {
			if (w.is_on_mouse()) {
				result = true;

				// 代入
				*iter = b;

				break;
			}

			iter++;
		}

		return result;
	}

	void BackPack::Back(size_t index, const eBullet& bullet) {
		Inventory_Info::Set(index, bullet);
	}
}