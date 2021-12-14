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

		// ���͂��Ă��邩
		static bool Get(const Inputcode& code);
		// �����ꂽ�u�Ԃ�
		static bool GetDown(const Inputcode& code);
		// �����ꂽ�u�Ԃ�
		static bool GetUp(const Inputcode& code);
		// ���z�X�e�B�b�N�̓���
		static Vec2 GetStick();
		// �}�E�X���W
		static Point GetMousePos();
		// �}�E�X���W
		static Vec2 GetMousePosf();
		// �}�E�X�̑O�t���[���Ɣ�r�����ړ��ʂ�n��
		static Point GetMouseDelta();
	private:
		friend Singleton;
		Input() : key(), mouse() {}
	};
}
