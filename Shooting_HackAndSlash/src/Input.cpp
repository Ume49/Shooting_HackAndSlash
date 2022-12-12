#include "Input.h"

#include<DxLib.h>

// �f�[�^�擾�֐��Ăяo���p�}�N��
// �������Ə����̂��߂�ǂ������̂�

// �}�N��������ɏȗ����ď������߂̂��
#define GET_INSTANCE	Input::getInstance()	

// �� �}�N����(����)�Ŏg�p
// �L�[���͎擾
#define GET_KEY			GET_INSTANCE.key.GetKey
#define GET_KEY_DOWN	GET_INSTANCE.key.GetKeyDown
#define GET_KEY_UP		GET_INSTANCE.key.GetKeyUp
// �}�E�X�̃{�^�����͎擾
#define GET_MOUSE		GET_INSTANCE.mouse.GetInput
#define GET_MOUSE_DOWN	GET_INSTANCE.mouse.GetDown
#define GET_MOUSE_UP	GET_INSTANCE.mouse.GetUp

namespace Shooting_HackAndSlash{
	void Input::update() {
		Input::getInstance().key	.udpate();
		Input::getInstance().mouse	.update();
		Input::getInstance().pointer.update();
	}

	// �n���ꂽ�L�[��������Ă��邩
	bool Input::Get(const Inputcode& code) {
		// ���ʂ�����ϐ�
		bool result = false;

		// code ���ƕ��򂵂ĂɃ`�F�b�N
		switch (code) {
		case Inputcode::Up:
			result = GET_KEY(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			result = GET_KEY(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			result = GET_KEY(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			result = GET_KEY(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			result = GET_MOUSE(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			result = GET_MOUSE(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			result = GET_KEY(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			result = GET_KEY(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			result = GET_KEY(KEY_INPUT_I);
			break;
		}

		return result;
	}

	// �n���ꂽ�L�[�����݂̃t���[���ŉ����ꂽ���`�F�b�N����
	// ������Ă���: true ������Ă��Ȃ�: false
	bool Input::GetDown(const Inputcode& code) {
		// ���ʂ��󂯎��ϐ�
		bool result = false;
		
		// �L�[���ƂɑΉ������������Ăяo��
		switch (code) {
		case Inputcode::Up:
			result = GET_KEY_DOWN(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			result = GET_KEY_DOWN(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			result = GET_KEY_DOWN(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			result = GET_KEY_DOWN(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			result = GET_MOUSE_DOWN(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			result = GET_MOUSE_DOWN(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			result = GET_KEY_DOWN(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			result = GET_KEY_DOWN(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			result = GET_KEY_DOWN(KEY_INPUT_I);
			break;
		}

		return result;
	}

	// ���݃t���[���ŁA�w�肵���L�[�����ꂽ���`�F�b�N
	// 
	bool Input::GetUp(const Inputcode& code) {
		bool result = false;
		switch (code) {
		case Inputcode::Up:
			result = GET_KEY_UP(KEY_INPUT_W);
			break;
		case Inputcode::Down:
			result = GET_KEY_UP(KEY_INPUT_S);
			break;
		case Inputcode::Right:
			result = GET_KEY_UP(KEY_INPUT_D);
			break;
		case Inputcode::Left:
			result = GET_KEY_UP(KEY_INPUT_A);
			break;
		case Inputcode::Fire1:
			result = GET_MOUSE_UP(MOUSE_INPUT_LEFT);
			break;
		case Inputcode::Fire2:
			result = GET_MOUSE_UP(MOUSE_INPUT_RIGHT);
			break;
		case Inputcode::Esc:
			result = GET_KEY_UP(KEY_INPUT_ESCAPE);
			break;
		case Inputcode::Tab:
			result = GET_KEY_UP(KEY_INPUT_TAB);
			break;
		case Inputcode::Debug_Exit:
			result = GET_KEY_UP(KEY_INPUT_I);
			break;
		}

		return result;
	}

	Vec2 Input::GetStick() {
		Vec2 stick{};

		stick.x = (GET_KEY(KEY_INPUT_A) ? -1.f : 0.f) + (GET_KEY(KEY_INPUT_D) ? 1.f : 0.f);
		stick.y = (GET_KEY(KEY_INPUT_W) ? -1.f : 0.f) + (GET_KEY(KEY_INPUT_S) ? 1.f : 0.f);

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

// ��Ő錾�����}�N����S�ď���
// �����ł����g��Ȃ��̂�
#undef GET_INSTANCE
#undef GET_KEY
#undef GET_KEY_DOWN
#undef GET_KEY_UP
#undef GET_MOUSE
#undef GET_MOUSE_DOWN
#undef GET_MOUSE_UP		