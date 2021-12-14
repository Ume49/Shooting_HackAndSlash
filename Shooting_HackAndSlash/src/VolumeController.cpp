#include "VolumeController.h"
#include"Define.h"
#include<DxLib.h>

namespace {
	// �{�����[���o�[��x���W
	// *����
	constexpr int x = 100;

	// �{�����[���o�[�̊J�ny���W
	// *����
	constexpr int y = 10;

	// �{�����[���o�[���m�̋󔒂̑傫��
	constexpr int space = 10;
}

namespace Shooting_HackAndSlash {
	VolumeController::VolumeController(const Point& p) :
		container(),
		back{ Photo_SharedHandle(Define::Path::Photo::Volume::Window), p }{
		// �R���e�i�̗e�ʂ�ݒ�
		container.reserve(3);

		// x���W�v�Z
		auto x_pos = [&]() { return p.x + ::x; };

		// �傫���𒲂ׂ邽�߂ɁA�Q�[�W�̉摜��ǂݍ���
		// �ǂ����Ȃ̂ŃR���X�g���N�^�̊Ԃ͕ێ����Ă���
		Photo_SharedHandle volume_photo(Define::Path::Photo::Volume::Gauge);
		// �Q�[�W�̍������擾
		int height = volume_photo.size().y;

		// y���W�v�Z num�͉��Ԗڂ��Ƃ����l
		auto y_pos = [&](int num) { return p.y + ::y + (num - 1) * (space+height); };

		// �{�����[���o�[��o�^
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
		// �w�i�`��
		DrawGraph(back.pos.x, back.pos.y, back.handle, TRUE);

		for (auto& w : container) {
			w->draw();
		}
	}
}