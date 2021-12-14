#pragma once

namespace Shooting_HackAndSlash {
	// �F���Ƃ��Ďg�p����unsigned int�^�̃��b�p�[�\����
	// RGB�œ���
	struct Color{
	private:
		unsigned int code;
	public:
		// �Ԑ��������Ԃ�
		int Red() const;
		// �ΐ��������Ԃ�
		int Green() const;
		// ���������Ԃ�
		int Blue() const;

		// �Ԑ����ɑ΂��Ęa�Z
		// �l��0~255���͂ݏo���Ȃ��悤�ɏ��������
		void AddRed(int r);
		// �ΐ����ɑ΂��Ęa�Z
		// �l��0~255���͂ݏo���Ȃ��悤�ɏ��������
		void AddGreen(int g);
		// �����ɑ΂��Ęa�Z
		// �l��0~255���͂ݏo���Ȃ��悤�ɏ��������
		void AddBlue(int b);

		operator unsigned int() const noexcept;
		Color& operator=(unsigned int r);
		Color(unsigned int color_code);
		Color(int r, int g, int b);
		Color();
		~Color() = default;
	};
}
