#include"DxLib.h"
#include"System.h"

/**
 * @brief エントリポイント
 *
 * @sa System
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	Shooting_HackAndSlash::System system;

	if (system.initialize()) {
		system.main();
	}

	system.finalize();
	return 0;
}