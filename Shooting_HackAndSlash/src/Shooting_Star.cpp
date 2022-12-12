#include "Shooting_Star.h"

#include<vector>
#include<DxLib.h>
#include"Define.h"

#include"Random.h"
#include"Time.h"

namespace {	// 星自体の設定
	// 星が流れる速度
	const Vec2 velocity{ 0.f, 1000.f };

	constexpr float			radius	= 1.f;		// 星の半径
	constexpr int			poly	= 4;		// 星を正何角形で表現するか
	constexpr unsigned int	color = 0xffffff;	// 星の色

	// ステージ外と判定されるy座標
	constexpr float stage_out_border = Shooting_HackAndSlash::Define::Window::PlayArea::End::Yf + radius;
}

namespace {	// スポナーの設定
	
	constexpr float interval		= 0.2f;					// 星が出現する頻度
	constexpr float spawn_y			= ::radius * (-1.f);	// 初期y座標
	constexpr float counter_init	= 0.f;					// カウンター初期値

	// 星が出現する範囲
	constexpr int
		x_range_start = 0,
		x_range_end = Shooting_HackAndSlash::Define::Window::PlayArea::End::X;
}

namespace Shooting_HackAndSlash::BackGround_Object {
	//=星単品のメンバ実装=========================================================

	// コンストラクタ
	Shooting_Stars::Star::Star(const Vec2& p) :
		pos(p) {
	}

	// 1フレームにつき1回呼び出される更新処理
	void Shooting_Stars::Star::update() {
		// 移動
		pos += ::velocity * Time::DeltaTime();
	}

	// 星を描画
	void Shooting_Stars::Star::draw() const {
		DrawCircleAA(pos.x, pos.y, ::radius, ::poly, ::color);
	}

	// 自分がステージ外にいるのかどうか
	bool Shooting_Stars::Star::is_stage_out() const {
		return pos.y >= ::stage_out_border;
	}

	//=星の管理クラスのメンバ実装===================================================

	Shooting_Stars::Shooting_Stars() :
		container{},
		counter{ ::counter_init }
	{
		// 一画面分の星を生成する

		// 星が画面の端から端まで到達するのに要する時間
		float length = Define::Window::PlayArea::End::Yf / ::velocity.y;

		// 1画面を埋める星の数
		int star_amount = static_cast<int>(length / ::interval);

		// 星同士の間隔のy成分
		float star_distance = Define::Window::PlayArea::End::Yf / static_cast<float>(star_amount);

		// 決定した星の数だけループして生成
		for (auto i = 0; i < star_amount; i++) {
			// y座標決定
			float y = star_distance * static_cast<float>(i);

			// x座標決定
			float x = static_cast<float>(Random::Range(::x_range_start, ::x_range_end));

			// 生成
			container.push_back(Star(Vec2{ x,y }));
		}
	}

	void Shooting_Stars::update() {
		// 更新
		for (auto& w : container) { w.update(); }

		// 見えなくなった星は消去
		container.remove_if([](Star& s) {return s.is_stage_out(); });

		// 星の追加処理
		// 一定時間ごとに処理
		if ((counter += Time::DeltaTime()) >= ::interval) {
			//カウンターリセット
			counter = ::counter_init;

			// *ランダムな位置に星を生成する

			// ランダムなx座標を決定
			float x = static_cast<float>(Random::Range(::x_range_start, ::x_range_end));

			// 末尾に追加
			container.push_back(Star(Vec2{ x, ::spawn_y }));
		}
	}

	void Shooting_Stars::draw() const {
		// 管理している星のdraw関数を呼び出すだけ
		for (auto& w : container) { w.draw(); }
	}
}