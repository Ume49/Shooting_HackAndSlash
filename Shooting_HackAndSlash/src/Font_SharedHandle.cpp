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
		// CreateFont用
		int Load(const std::string& FontName, int Size, int Thick, int FontType) {
			// 元々Loadはファイルパスを指定するものなので、不格好ではあるものの手書きでオーバーロード

			if (container.contains(FontName)) {
				// 既にキーが登録されている時

				// 参照カウントを増加
				container.at(FontName).reference_count++;

				// ハンドルを返す
				return container.at(FontName).value;
			}
			else {
				// キーが存在しない時

				// 新規キーを登録、これを見てるオブジェクトがいるはずなので参照キーは1からスタート
				container.emplace(FontName, Handle{ 0,1 });

				// 登録されたロード関数を使ってハンドルを作成
				container.at(FontName).value = CreateFontToHandle(FontName.c_str(), Size, Thick, FontType);

				// ハンドルを返す
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