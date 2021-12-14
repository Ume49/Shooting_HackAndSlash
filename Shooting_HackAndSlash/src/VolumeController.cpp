#include "VolumeController.h"
#include"Define.h"
#include<DxLib.h>

namespace {
	// ボリュームバーのx座標
	// *相対
	constexpr int x = 100;

	// ボリュームバーの開始y座標
	// *相対
	constexpr int y = 10;

	// ボリュームバー同士の空白の大きさ
	constexpr int space = 10;
}

namespace Shooting_HackAndSlash {
	VolumeController::VolumeController(const Point& p) :
		container(),
		back{ Photo_SharedHandle(Define::Path::Photo::Volume::Window), p }{
		// コンテナの容量を設定
		container.reserve(3);

		// x座標計算
		auto x_pos = [&]() { return p.x + ::x; };

		// 大きさを調べるために、ゲージの画像を読み込む
		// どうせなのでコンストラクタの間は保持しておく
		Photo_SharedHandle volume_photo(Define::Path::Photo::Volume::Gauge);
		// ゲージの高さを取得
		int height = volume_photo.size().y;

		// y座標計算 numは何番目かという値
		auto y_pos = [&](int num) { return p.y + ::y + (num - 1) * (space+height); };

		// ボリュームバーを登録
		container.push_back(std::make_unique<Volume>(Point{ x_pos(),y_pos(1) }, [](float value) {}));
		container.push_back(std::make_unique<Volume>(Point{ x_pos(),y_pos(2) }, [](float value) {}));
		container.push_back(std::make_unique<Volume>(Point{ x_pos(),y_pos(3) }, [](float value) {}));
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
	}
}