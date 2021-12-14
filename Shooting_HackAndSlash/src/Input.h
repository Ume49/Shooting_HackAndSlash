#pragma once
#include"Singleton.h"

#include"KeyChecker.h"
#include"MouseChecker.h"
#include"MousePointer.h"

#include"Vector.h"
#include"Inputcode.h"

namespace Shooting_HackAndSlash {
	class Input :public Singleton<Input> {
	private:
		Input_Component::KeyChecker key;
		Input_Component::MouseChecker mouse;
		Input_Component::MousePointer pointer;
	public:
		static void update();

		// 入力しているか
		static bool Get(const Inputcode& code);
		// 押された瞬間か
		static bool GetDown(const Inputcode& code);
		// 離された瞬間か
		static bool GetUp(const Inputcode& code);
		// 仮想スティックの入力
		static Vec2 GetStick();
		// マウス座標
		static Point GetMousePos();
		// マウス座標
		static Vec2 GetMousePosf();
		// マウスの前フレームと比較した移動量を渡す
		static Point GetMouseDelta();
	private:
		friend Singleton;
		Input() : key(), mouse() {}
	};
}
