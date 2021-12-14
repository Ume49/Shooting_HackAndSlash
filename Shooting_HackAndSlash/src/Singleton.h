#pragma once

namespace Shooting_HackAndSlash {
	template<class T>
	class Singleton {
	public:
		static T& getInstance() {
			static T instance;
			return instance;
		}
	protected:
		Singleton() = default;
		virtual ~Singleton() = default;
	private:
		void operator=(const Singleton& s) = delete;
		Singleton(const Singleton& s) = delete;
	};
}