namespace Shooting_HackAndSlash {
	class IBackListener {
	public:
		IBackListener() = default;
		virtual ~IBackListener() = default;

		// 戻る
		virtual void Back() = 0;
	};
}