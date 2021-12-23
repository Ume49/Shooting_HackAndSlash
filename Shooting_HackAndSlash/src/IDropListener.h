namespace Shooting_HackAndSlash {
	class IDropListener {
	public:
		IDropListener() = default;
		virtual ~IDropListener() = default;

		// ドロップできた	 : true
		// ドロップできなかった	: false
		virtual bool CheckDrop() = 0;
	};
}