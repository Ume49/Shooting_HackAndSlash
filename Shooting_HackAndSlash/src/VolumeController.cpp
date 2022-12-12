#include "VolumeController.h"

#include"Define.h"
#include<DxLib.h>

#include"Volume_Info.h"

namespace {
	// ボリュームバーのx座標
	// *相対
	constexpr int x = 250;

	// ボリュームバーの開始y座標
	// *相対
	constexpr int y = 82;

	// ボリュームバー同士の空白の大きさ
	constexpr int space = 30;

	const std::vector<std::string> text{
		"Master",
		"BGM",
		"SE"
	};

	constexpr int text_space = 80;
}

namespace Shooting_HackAndSlash {
	VolumeController::VolumeController(const Point& p) :
		container(),
		back{ Photo_SharedHandle(Define::Path::Photo::Volume::Window), p },
		font("Resource/Dot_16.dft")
	{
		// 何個ボリュームバーを登録するのか
		constexpr int bar_amount = 3;

		// コンテナの容量を設定
		container.reserve(bar_amount);

		// x座標計算
		auto x_pos = p.x + ::x;

		// 大きさを調べるために、ゲージの画像を読み込む
		// どうせなのでコンストラクタの間は保持しておく
		Photo_SharedHandle volume_photo(Define::Path::Photo::Volume::Gauge);
		// ゲージの高さを取得
		int height = volume_photo.size().y;

		// y座標計算 numは何番目かという値
		auto y_pos = [&](int num) { return p.y + ::y + (num - 1) * (space + height); };

		// ボリュームバーを登録
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(1) }, [](float value) { Volume_Info::SetMaster(value); }, Volume_Info::getInstance().master_volume));
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(2) }, [](float value) { Volume_Info::SetBGM(value); },	  Volume_Info::getInstance().bgm_volume));
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(3) }, [](float value) { Volume_Info::SetSE(value); },	  Volume_Info::getInstance().se_volume));

		// テキストを登録
		texts.reserve(bar_amount);
		for (auto i = 0; i < bar_amount; i++) {
			texts.push_back(std::make_pair(::text.at(i), Point{ x_pos - ::text_space, y_pos(i + 1) }));
		}
	}

	void VolumeController::update() {
		for (auto& w : container) {
			w->update();
		}
	}

	void VolumeController::draw() const {
		// 背景描画
		DrawGraph(back.pos.x, back.pos.y, back.handle, TRUE);

		for (auto& w : container) {
			w->draw();
		}

		for (auto& w : texts) {
			auto [t, p] = w;

			DrawStringToHandle(p.x, p.y, t.c_str(), Palette::Black, font);
		}
	}
}