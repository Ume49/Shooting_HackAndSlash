#include "Font_SharedHandle.h"
#include<DxLib.h>
#include<format>

namespace {
	class Manager : public Shooting_HackAndSlash::Abstruct_Shared_Manager {
	public:
		Manager() = default;
		~Manager() { InitFontToHandle(); }
	protected:
		int load_func(const std::string& path) override { return LoadFontDataToHandle(path.c_str()); }
		void release_func(int handle) override { DeleteFontToHandle(handle); }
	public:
		// CreateFont�p
		int Load(const std::string& FontName, int Size, int Thick, int FontType) {
			// ���XLoad�̓t�@�C���p�X���w�肷����̂Ȃ̂ŁA�s�i�D�ł͂�����̂̎菑���ŃI�[�o�[���[�h

			if (container.contains(FontName)) {
				// ���ɃL�[���o�^����Ă��鎞

				// �Q�ƃJ�E���g�𑝉�
				container.at(FontName).reference_count++;

				// �n���h����Ԃ�
				return container.at(FontName).value;
			}
			else {
				// �L�[�����݂��Ȃ���

				// �V�K�L�[��o�^�A��������Ă�I�u�W�F�N�g������͂��Ȃ̂ŎQ�ƃL�[��1����X�^�[�g
				container.emplace(FontName, Handle{ 0,1 });

				// �o�^���ꂽ���[�h�֐����g���ăn���h�����쐬
				container.at(FontName).value = CreateFontToHandle(FontName.c_str(), Size, Thick, FontType);

				// �n���h����Ԃ�
				return container.at(FontName).value;
			}
		}
	};

	static Manager manager;
}

namespace Shooting_HackAndSlash {
	Font_SharedHandle::Font_SharedHandle(const std::string& DX_fontfile_path) :
		Abstruct_SharedHandle(DX_fontfile_path, ::manager) {}

	Font_SharedHandle::Font_SharedHandle(const std::string& FontName, int Size, int Thick, int FontType) :
		Abstruct_SharedHandle(::manager) {
		handle = ::manager.Load(FontName, Size, Thick, FontType);
		release_key = FontName;
	}

	int Font_SharedHandle::fontsize() const {
		return GetFontSizeToHandle(handle);
	}
}