#include "PhotoDisplayer.h"
#include<DxLib.h>
#include<numbers>
#include<cmath>

namespace {
	// 拡大率 いじらないので1.0で固定
	constexpr double Ex_Rate = 1.0;
}

namespace Shooting_HackAndSlash {
	PhotoDisplayer::PhotoDisplayer(const std::string& path) :
		gr_handle(path),
		gr_half_size() {
		GetGraphSizeF(gr_handle, &gr_half_size.x, &gr_half_size.y);
		gr_half_size = gr_half_size / 2.f;
	}

	void PhotoDisplayer::display(const Vec2& pos_center, const Vec2& direction) const {
		// 与えられた方向から角度を計算する
		// 基準はy軸
		auto get_angle = [](const Vec2& dir) {
			return static_cast<float>(std::atan2f(dir.y, dir.x)) + std::numbers::pi / 2;		// 反時計回りに90°与えて補正
		};

		Vec2 draw_pos = pos_center + Vec2{ 1.f,1.f };

		double angle = get_angle(direction);

		DrawRotaGraphF(draw_pos.x, draw_pos.y, Ex_Rate, angle, gr_handle, TRUE);
	}
}