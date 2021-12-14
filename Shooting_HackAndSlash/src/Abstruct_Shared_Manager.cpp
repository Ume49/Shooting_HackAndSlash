#include"Abstruct_Shared_Manager.h"

namespace Shooting_HackAndSlash {
	Abstruct_Shared_Manager::Abstruct_Shared_Manager() :
		container()
	{}

	int Abstruct_Shared_Manager::Load(const std::string& path) {

		if (container.contains(path)) {
			// 既にキーが登録されている時

			// 参照カウントを増加
			container.at(path).reference_count++;

			// ハンドルを返す
			return container.at(path).value;
		}
		else {
			// キーが存在しない時

			// 新規キーを登録、これを見てるオブジェクトがいるはずなので参照キーは1からスタート
			container.emplace(path, Handle{ 0,1 });
			
			// 登録されたロード関数を使ってハンドルを作成
			container.at(path).value = load_func(path);

			// ハンドルを返す
			return container.at(path).value;
		}
	}

	void Abstruct_Shared_Manager::Count_Add(const std::string& key) {
		container.at(key).reference_count++;
	}

	void Abstruct_Shared_Manager::Release(const std::string& path) {

		// 参照しているオブジェクトを１つ減らし、誰もいないようであれば追加処理
		if ((container.at(path).reference_count - 1) <= 0) {

			// リソースを解放
			release_func(container.at(path).value);

			// コンテナから該当オブジェクトを削除
			container.erase(path);
		}
	}
}