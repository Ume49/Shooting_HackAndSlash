#include "Input.h"

#include<DxLib.h>

namespace Shooting_HackAndSlash{
	void Input::update() {
		Input::getInstance().key.udpate();
		Input::getInstance().mouse.update();
		Input::getInstance().pointer.update();
	}

	bool Input::Get(const Inputcode& code) {
		bool temp = false;
		switch (code) {
		case Inputcode::Up:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			temp = Input::getInstance().mouse.GetInput(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			temp = Input::getInstance().mouse.GetInput(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			temp = Input::getInstance().key.GetKey(KEY_INPUT_I);
			break;
		}

		return temp;
	}

	bool Input::GetDown(const Inputcode& code) {
		bool temp = false;
		switch (code) {
		case Inputcode::Up:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			temp = Input::getInstance().mouse.GetDown(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			temp = Input::getInstance().mouse.GetDown(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			temp = Input::getInstance().key.GetKeyDown(KEY_INPUT_I);
			break;
		}

		return temp;
	}

	bool Input::GetUp(const Inputcode& code) {
		bool temp = false;
		switch (code) {
		case Inputcode::Up:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			temp = Input::getInstance().mouse.GetUp(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			temp = Input::getInstance().mouse.GetUp(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			temp = Input::getInstance().key.GetKeyUp(KEY_INPUT_I);
			break;
		}

		return temp;
	}

	Vec2 Input::GetStick() {
		Vec2 stick{};

		stick.x = (Input::getInstance().key.GetKey(KEY_INPUT_A) ? -1.f : 0.f) + (Input::getInstance().key.GetKey(KEY_INPUT_D) ? 1.f : 0.f);
		stick.y = (Input::getInstance().key.GetKey(KEY_INPUT_W) ? -1.f : 0.f) + (Input::getInstance().key.GetKey(KEY_INPUT_S) ? 1.f : 0.f);

		return stick.nomalize();
	}

	Point Input::GetMousePos() {
		return Input::getInstance().pointer.MousePos();
	}

	Vec2 Input::GetMousePosf() {
		return Input::getInstance().pointer.MousePosF();
	}

	Point Input::GetMouseDelta() {
		return Input::getInstance().pointer.MouseDelta();
	}
}