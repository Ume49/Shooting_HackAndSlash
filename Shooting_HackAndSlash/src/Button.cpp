#include "Button.h"

#include"Input.h"
#include<DxLib.h>

#include"Define.h"

namespace {
	const std::string SE_Path = "Resource/button06.mp3";
}

namespace Shooting_HackAndSlash::UI {
#define _FONT Font_SharedHandle("Resource/Dot_24.dft")
#define _SOUND sound(::SE_Path)

	Button::Button(std::function<void(void)> onclick, const std::string& text, const Point& leftup) :
		leftup(leftup),
		rightdown(),
		on_click(onclick),
		isselect(false),
		center(),
		photo(Define::Path::Photo::Button::Normal),
		photo_selected(Define::Path::Photo::Button::Selected),
		text(text, _FONT, Color(Palette::Black)) ,
		_SOUND
	{
		// rightdown���v�Z
		rightdown = leftup + photo.size();

		// �������W���v�Z
		Point p = leftup + rightdown;
		center = Vec2(static_cast<float>(p.x), static_cast<float>(p.y)) / 2.f;
	}

	// �^����ꂽ�p�X�ŉ摜��o�^����ȊO�͏�̃R���X�g���N�^�Ɠ�������������
	Button::Button(const std::string& photo_path, const std::string& photo_selected_path, std::function<void(void)> onclick, const std::string& text, const Point& leftup) :
		leftup(leftup),
		rightdown(),
		on_click(onclick),
		isselect(false),
		center(),
		photo(photo_path),
		photo_selected(photo_selected_path),
		text(text, _FONT, Color(Palette::Black)),
		_SOUND
	{
		// rightdown���v�Z
		rightdown = leftup + photo.size();

		// �������W���v�Z
		Point p = leftup + rightdown;
		center = Vec2(static_cast<float>(p.x), static_cast<float>(p.y)) / 2.f;
	}

	Button::Button(const Point& size, std::function<void(void)> onclick, const Point& leftup) :
		leftup(leftup),
		rightdown(),
		on_click(onclick),
		isselect(false),
		center(),
		photo(),
		photo_selected(),	/*�摜�͎g�p���Ȃ��̂ŗ����Ƃ�Null�œo�^*/
		text("", _FONT, Color(Palette::Black)),
		_SOUND
	{
		// rightdown���v�Z
		rightdown = leftup + size;

		// �������W���v�Z
		Point p = leftup + rightdown;
		center = Vec2(static_cast<float>(p.x), static_cast<float>(p.y)) / 2.f;
	}

#undef _FONT
#undef _SOUND

	void Button::draw() const {
		DrawGraph(leftup.x, leftup.y, (isselect ? photo_selected : photo), TRUE);
		text.draw(center);

#ifdef _DEBUG
		// �����蔻���\��
		DrawBox(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider, FALSE);
		DrawLine(leftup.x, leftup.y, rightdown.x, rightdown.y, Palette::Collider);
#endif // _DEBUG

	}

	void Button::update() {
		// �}�E�X�Əd�Ȃ��Ă��邩�`�F�b�N
		Point mouse_pos = Input::GetMousePos();

		isselect = (mouse_pos.x >= leftup.x && mouse_pos.x <= rightdown.x
			&&
			mouse_pos.y >= leftup.y && mouse_pos.y <= rightdown.y);

		if (isselect && Input::GetDown(Inputcode::Fire1)) {
			on_click();
			sound.play();
		}
	}

	void Button::Slide_horizontal(int x) {
		leftup.x += x;
		rightdown.x += x;

		center.x += static_cast<float>(x);
	}
}