#include "VolumeController.h"

#include"Define.h"
#include<DxLib.h>

#include"Volume_Info.h"

namespace {
	// �{�����[���o�[��x���W
	// *����
	constexpr int x = 250;

	// �{�����[���o�[�̊J�ny���W
	// *����
	constexpr int y = 82;

	// �{�����[���o�[���m�̋󔒂̑傫��
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
		// ���{�����[���o�[��o�^����̂�
		constexpr int bar_amount = 3;

		// �R���e�i�̗e�ʂ�ݒ�
		container.reserve(bar_amount);

		// x���W�v�Z
		auto x_pos = p.x + ::x;

		// �傫���𒲂ׂ邽�߂ɁA�Q�[�W�̉摜��ǂݍ���
		// �ǂ����Ȃ̂ŃR���X�g���N�^�̊Ԃ͕ێ����Ă���
		Photo_SharedHandle volume_photo(Define::Path::Photo::Volume::Gauge);
		// �Q�[�W�̍������擾
		int height = volume_photo.size().y;

		// y���W�v�Z num�͉��Ԗڂ��Ƃ����l
		auto y_pos = [&](int num) { return p.y + ::y + (num - 1) * (space + height); };

		// �{�����[���o�[��o�^
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(1) }, [](float value) { Volume_Info::SetMaster(value); }, Volume_Info::getInstance().master_volume));
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(2) }, [](float value) { Volume_Info::SetBGM(value); },	  Volume_Info::getInstance().bgm_volume));
		container.push_back(std::make_unique<Volume>(Point{ x_pos,y_pos(3) }, [](float value) { Volume_Info::SetSE(value); },	  Volume_Info::getInstance().se_volume));

		// �e�L�X�g��o�^
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
		// �w�i�`��
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