#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include"Button.h"
#include"Gauge_Horizontal.h"
#include<memory>
#include<functional>

namespace Shooting_HackAndSlash {
	// UI�Ƃ��Ẳ��ʒ����Ɏg����A�{�����[���o�[�N���X
	// �I�[�f�B�I�~�L�T�[�̂܂݂݂����ȋ@�\��񋟂���
	// 
	// �E�ǂꂾ���̗ʂ����邩�������Q�[�W�N���X�ƁA
	// �E�}�E�X�Ńh���b�O���ăQ�[�W�𑀍�ł���悤�ɂ���܂݃N���X
	// 
	// �ō\�������
	class Volume {
		// �{�����[����value %��������Ă���A�Ƃ����l�B0.f~1.0f�͈̔�
		float value;

		// �h���b�O����Ă��邩
		bool is_dragged;

		// �܂ݕ�������������{�^���N���X
		// �@�\�����Ă���̂Ŋ����̂��̂𗬗p
		std::unique_ptr<UI::Button> touch_pannel;
		
		// �ǂꂾ���̗ʂ����邩��\������Q�[�W�N���X
		Gauge_Horizontal gauge;
		// �[�̓_
		int start_x, end_x;
		// �Q�[�W�̒���
		float width;

		// �܂݂�\�����邽�߂̍\����
		struct Clip {
			Photo_SharedHandle handle;
			Point pos;
			int half_width;
		} clip;

		// clip�𓮂������Ƃ��ɌĂяo����鏈��
		std::function<void(float)> func_slided;
	public:
		// �X�V�����B���t���[��1�񂾂��Ăяo��
		// ��Ƀ}�E�X�ł܂ޏ����̎����ɕK�v
		void update();
		
		// �`�揈��
		void draw() const;

		// �����ڂ̍�����Ԃ�
		int height() const;

		// pos		: ����̍��W
		// func_slided	: �܂݂𓮂����x�ɌĂ΂��֐�
		// value : �����l
		Volume(const Point& pos, std::function<void(float)> func_slided, float value = 1.f);
		~Volume() = default;
	};
}
