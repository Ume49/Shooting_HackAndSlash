#pragma once

#include<queue>

#include"eBullet.h"

namespace Shooting_HackAndSlash {
	// ���̒e�ɔh�����邩�A�Ƃ����������R���e�i
	// ���g�̓L���[
	class Bullet_Resource {
		std::queue<eBullet> resource;
	public:

		// �擾�֐�
		// ������g�p����Ɓu���̒e�v�Ƃ��������ꏏ�ɍX�V�����
		// ��̏ꍇ�͈�x����Null���r�o�����
		const eBullet& get();

		Bullet_Resource(const Bullet_Resource& r);
		Bullet_Resource();
		~Bullet_Resource() = default;
	};
}
