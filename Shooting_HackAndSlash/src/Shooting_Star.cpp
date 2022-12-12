#include "Shooting_Star.h"

#include<vector>
#include<DxLib.h>
#include"Define.h"

#include"Random.h"
#include"Time.h"

namespace {	// �����̂̐ݒ�
	// ��������鑬�x
	const Vec2 velocity{ 0.f, 1000.f };

	constexpr float			radius	= 1.f;		// ���̔��a
	constexpr int			poly	= 4;		// ���𐳉��p�`�ŕ\�����邩
	constexpr unsigned int	color = 0xffffff;	// ���̐F

	// �X�e�[�W�O�Ɣ��肳���y���W
	constexpr float stage_out_border = Shooting_HackAndSlash::Define::Window::PlayArea::End::Yf + radius;
}

namespace {	// �X�|�i�[�̐ݒ�
	
	constexpr float interval		= 0.2f;					// �����o������p�x
	constexpr float spawn_y			= ::radius * (-1.f);	// ����y���W
	constexpr float counter_init	= 0.f;					// �J�E���^�[�����l

	// �����o������͈�
	constexpr int
		x_range_start = 0,
		x_range_end = Shooting_HackAndSlash::Define::Window::PlayArea::End::X;
}

namespace Shooting_HackAndSlash::BackGround_Object {
	//=���P�i�̃����o����=========================================================

	// �R���X�g���N�^
	Shooting_Stars::Star::Star(const Vec2& p) :
		pos(p) {
	}

	// 1�t���[���ɂ�1��Ăяo�����X�V����
	void Shooting_Stars::Star::update() {
		// �ړ�
		pos += ::velocity * Time::DeltaTime();
	}

	// ����`��
	void Shooting_Stars::Star::draw() const {
		DrawCircleAA(pos.x, pos.y, ::radius, ::poly, ::color);
	}

	// �������X�e�[�W�O�ɂ���̂��ǂ���
	bool Shooting_Stars::Star::is_stage_out() const {
		return pos.y >= ::stage_out_border;
	}

	//=���̊Ǘ��N���X�̃����o����===================================================

	Shooting_Stars::Shooting_Stars() :
		container{},
		counter{ ::counter_init }
	{
		// ���ʕ��̐��𐶐�����

		// ������ʂ̒[����[�܂œ��B����̂ɗv���鎞��
		float length = Define::Window::PlayArea::End::Yf / ::velocity.y;

		// 1��ʂ𖄂߂鐯�̐�
		int star_amount = static_cast<int>(length / ::interval);

		// �����m�̊Ԋu��y����
		float star_distance = Define::Window::PlayArea::End::Yf / static_cast<float>(star_amount);

		// ���肵�����̐��������[�v���Đ���
		for (auto i = 0; i < star_amount; i++) {
			// y���W����
			float y = star_distance * static_cast<float>(i);

			// x���W����
			float x = static_cast<float>(Random::Range(::x_range_start, ::x_range_end));

			// ����
			container.push_back(Star(Vec2{ x,y }));
		}
	}

	void Shooting_Stars::update() {
		// �X�V
		for (auto& w : container) { w.update(); }

		// �����Ȃ��Ȃ������͏���
		container.remove_if([](Star& s) {return s.is_stage_out(); });

		// ���̒ǉ�����
		// ��莞�Ԃ��Ƃɏ���
		if ((counter += Time::DeltaTime()) >= ::interval) {
			//�J�E���^�[���Z�b�g
			counter = ::counter_init;

			// *�����_���Ȉʒu�ɐ��𐶐�����

			// �����_����x���W������
			float x = static_cast<float>(Random::Range(::x_range_start, ::x_range_end));

			// �����ɒǉ�
			container.push_back(Star(Vec2{ x, ::spawn_y }));
		}
	}

	void Shooting_Stars::draw() const {
		// �Ǘ����Ă��鐯��draw�֐����Ăяo������
		for (auto& w : container) { w.draw(); }
	}
}