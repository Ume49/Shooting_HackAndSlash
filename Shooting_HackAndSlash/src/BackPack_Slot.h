#pragma once
#include"Vector.h"
#include"Photo_SharedHandle.h"
#include<memory>

namespace Shooting_HackAndSlash {
	// �o�b�N�p�b�N�����ɓ����蔻���񋟂���
	class BackPack_Slot{
		Point leftup, rightdown;
		// ������
		Photo_SharedHandle photo;
	public:
		// �N���b�N���ꂽ��
		bool is_click() const;
		
		void draw() const;

		BackPack_Slot(const Point& leftup);
		~BackPack_Slot() = default;
	};
}
