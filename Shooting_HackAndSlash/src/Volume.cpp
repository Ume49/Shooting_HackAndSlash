#include "Volume.h"

#include"Define.h"
#include"Input.h"
#include<DxLib.h>
#include<algorithm>

namespace Shooting_HackAndSlash {
	namespace PATH = Define::Path::Photo::Volume;

	Volume::Volume(const Point& p, std::function<void(float)> f, float v) :
		value(v),
		is_dragged(false),
		gauge(PATH::Gauge, PATH::Back, p),
		touch_pannel(),
		clip{ Photo_SharedHandle(PATH::Clip), p },
		start_x(p.x),
		end_x(),
		width(),
		func_slided(f)
	{
		touch_pannel = std::make_unique<UI::Button>(gauge.size(), [&]() { is_dragged = true; }, p);

		clip.half_width = clip.handle.size().x / 2;

		width = static_cast<float>(gauge.size().x);
		end_x = start_x + gauge.size().x;

		// clip�̍��W��value�ɓK�p
		value = static_cast<float>(clip.pos.x - start_x) / width;
	}

	void Volume::update() {
		touch_pannel->update();

		if (is_dragged) {
			if (Input::GetUp(Inputcode::Fire1)) {
				is_dragged = false;
			}

			// �}�E�X��x���W���擾
			int mouse_x = Input::GetMousePos().x;
			// �n�_�ƏI�_�̊ԂɎ��߂�
			mouse_x = std::clamp(mouse_x, start_x, end_x);

			{	// value���v�Z
				int now_width = mouse_x - start_x;

				value = static_cast<float>(now_width) / width;
			}

			// clip�̍��W��ύX
			clip.pos.x = mouse_x;

			// �ύX����value�ŋK�肳�ꂽ�����Ăяo��
			func_slided(value);
		}
	}

	void Volume::draw() const {
		// �Q�[�W��`��
		gauge.draw(value);

		// �N���b�v��`��
		DrawGraph(clip.pos.x - clip.half_width, clip.pos.y, clip.handle, TRUE);

#ifdef _DEBUG
		// �{�^���̓����蔻���`��
		touch_pannel->draw();
#endif // _DEBUG
	}

	int Volume::height() const {
		return gauge.size().y;
	}
}