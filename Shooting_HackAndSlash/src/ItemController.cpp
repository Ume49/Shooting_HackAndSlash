#include "ItemController.h"
#include"Random.h"
#include<cassert>
#include<algorithm>
#include"Player.h"

#include"Item_Cure.h"
#include"eBullet.h"
#include"Item_Bullet.h"

namespace {
	constexpr float Spanw_Rate = 0.7f;

	// �����̏���l
	constexpr int random_max = 99;

	// �����̉����l
	constexpr int random_min = 0;

	// �񕜃A�C�e���̏o����
	constexpr float cure_spawn_rate = 0.30f;

	// �e�A�C�e���̏o����
	constexpr float bullet_spawn_rate = 0.3f;

	// �e�A�C�e���̏o����
	constexpr float gun_spawn_rate = 0.05f;
}

namespace Shooting_HackAndSlash {
	ItemController::ItemController(Player& p) :
		item_list(),
		player_ref(p),
		func_table()
	{
		func_table.reserve(4U);

		{	// �e�틫�E�l���v�Z����
			// �������O��Ԃ̊m�������E�l������int�^�ɕϊ�����
			auto convert = [](float rate) {return static_cast<int>(rate * 100.f); };

			// �����������Ȃ��ꍇ
			int void_rate = 100 - convert(::cure_spawn_rate + ::bullet_spawn_rate + ::gun_spawn_rate) - 1;

			// �񕜃A�C�e���𐶐�����ꍇ
			int cure_rate = void_rate + convert(::cure_spawn_rate);

			// �e�A�C�e���𐶐�����ꍇ
			int bullet_rate = cure_rate + convert(::bullet_spawn_rate);

			// �e�A�C�e���𐶐�����ꍇ
			int gun_rate = bullet_rate + convert(::gun_spawn_rate);

			{	// �o�^
#define Arg const Vec2& pos
				// �������������Ȃ�
				func_table.add_unsort([&](Arg) {/* �������Ȃ� */}, void_rate);
				// �񕜃A�C�e��
				func_table.add_unsort([&](Arg) { item_list.push_back(std::make_unique<Item::Cure>(pos, player_ref)); }, cure_rate);
				// �e�A�C�e��
				func_table.add_unsort([&](Arg) { item_list.push_back(std::make_unique<Item::Bullet>(Random_Bullet(), pos, player_ref)); }, bullet_rate);
				// �e�A�C�e��
				func_table.add_unsort([&](Arg) {/* �e��ǉ����鏈�� */}, gun_rate);

				// �Ō�Ƀ\�[�g�v��
				func_table.sort();
#undef Arg
			}
		}
	}

	void ItemController::update() {
		for (auto& w : item_list) {
			w->update();
		}

		// ���S���Ă���A�C�e���͏���
		item_list.remove_if([](std::unique_ptr<AbstructItem>& w) { return w->is_dead; });
	}

	void ItemController::draw() const {
		for (auto& w : item_list) {
			w->draw();
		}
	}

	void ItemController::call_spawn(const Vec2& p) {
		// �����_���Ȍ��ʂ��o��

		// �������擾
		int rand = Random::Range(::random_min, ::random_max);

		// �A�C�e�������֐������s
		auto& func = func_table.at(rand);

		func(p);
	}
}