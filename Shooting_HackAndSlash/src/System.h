#pragma once
#include"DxLib.h"

namespace Shooting_HackAndSlash {
	// �������Ăяo��������
	class System {
	public:
		/// <summary>
		/// �Q�[���̏���������
		/// </summary>
		/// <returns>������������������true, ���s��������false</returns>
		bool initialize();
		// ���C������
		void main();
		// �I������
		void finalize();
	private:
	public:
		System() {}
	};
}
