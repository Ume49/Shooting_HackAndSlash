#include "System.h"

#include"Define.h"
#include"Looper.h"
#include<DxLib.h>

namespace Shooting_HackAndSlash {
	bool System::initialize() {
		// 前処理
		// 処理に失敗した時はゲームを終了する

		// 処理が成功した
		static constexpr int SUCCESS = 0;

		// ウインドウサイズ等の設定
		if (SetGraphMode(Define::Window::WITDH, Define::Window::HEIGHT, Define::Window::COLOR_BIT_NUM) != DX_CHANGESCREEN_OK) {
			return false;
		}

		// ウインドウモードに設定
		if (ChangeWindowMode(Define::Window::IS_WINDOW_MODE) != DX_CHANGESCREEN_OK) { return false; }
		// ウインドウサイズを自由に変更できるかどうか設定
		if (SetWindowSizeChangeEnableFlag(Define::Window::IS_WINDOWSIZE_FLEXIBLE) != SUCCESS) { return false; }
		// ウインドウの見出しを設定
		if (SetWindowText(Define::GAME_TITLE) != SUCCESS) { return false; }

		// 背景の色を設定
		if (SetBackgroundColor(0, 0, 0) != SUCCESS) { return false; }

		// DXライブラリ初期化処理、エラーを吐いたら直ちに終了
		if (DxLib_Init() == -1) { return false; }

		// ダブルバッファリングするための裏画面を設定
		if (SetDrawScreen(DX_SCREEN_BACK) != SUCCESS) { return false; }

		// カーソルがウインドウの領域から出ないようにする
		if (SetValidMousePointerWindowOutClientAreaMoveFlag(FALSE) != SUCCESS) { return false; }

		// 無事辿り付いた場合はtrueを返す
		return true;
	}

	void System::main() {
		// ループ機を作ってメインループ
		Looper looper;
		while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
			if (!looper.loop()) {
				break;
			}
		}
	}

	void System::finalize() {
		// カーソルを領域から出るようにする
		SetValidMousePointerWindowOutClientAreaMoveFlag(TRUE);

		// DXライブラリ終了処理
		DxLib_End();
	}
}