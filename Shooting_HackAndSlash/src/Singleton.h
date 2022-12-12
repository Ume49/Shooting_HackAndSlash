#pragma once

namespace Shooting_HackAndSlash {
	template<class T>
	class Singleton {
	public:
		// 呼び出し用関数＆単一性担保
		static T& getInstance() {
			static T instance;	// 唯一のインスタンスを生成
			return instance;
		}
	protected:
		Singleton() = default;
		virtual ~Singleton() = default;
	private:
		// コピーコンストラクタと代入演算子を禁止
		void operator=(const Singleton& s) = delete;
		Singleton(const Singleton& s) = delete;
	};

#ifdef _DEBUG
	// 上記 Singleton クラスの使用例
	// アクセス方式は クラス名::getInstance().メンバ で
	class Singleton_Test : public Singleton<Singleton_Test> {	// Singleton<自分> を継承させる
	public:
		// 適当なメンバ変数
		int  member_int;
		bool member_bool;

		// メンバ関数も適当に作っていい
		int get_member() { return member_int; }

	private:
		// 必読=====================================================================================

		// 必須
		// privateに設定したコンストラクタへのアクセスを許さないとSingleton<T>::getInstance()が動作しないため
		friend Singleton;

		// コンストラクタは必ずprivateにすること
		Singleton_Test() :
			member_int{}, member_bool{} {
			// コンストラクタの内容自体は好きに書いていい
		}

		// 呼び出されることがないので引数付きコンストラクタは作っても意味ない
		Singleton_Test(int para):
			member_int{para}, member_bool{true}
		{}

		// =========================================================================================
	};
#endif // __DEBUG
}