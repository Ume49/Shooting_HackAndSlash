#include "EnemySpawner.h"

#include"Player.h"
#include"Time.h"
#include"Random.h"

#include"Enemy_Kusozako.h"
#include<array>
#include<vector>
#include<algorithm>

#include"Define.h"
#include"Stage_Info.h"

namespace {
	// �N�o�Ԋu
	constexpr float SPAWN_INTERVAL = 5.f;
	constexpr float Interval_Decrease=0.1f;
	constexpr float Interval_Bottom=3.f;

	// -----------------
	// *�G�l�~�[�̗N�o�p�^�[��
	// -----------------
	using namespace Shooting_HackAndSlash;

	using Enemy_Set = EnemySpawner::Enemy_Info;
	using Party_List = std::vector<Enemy_Set>;

	const std::array<Party_List, 2> list{
		Party_List{
			Enemy_Set{eEnemy::Kusozako, Vec2{10, -10}},
			Enemy_Set{eEnemy::Kusozako, Vec2{600, -10}}
		},
		Party_List{
			Enemy_Set{eEnemy::Kusozako, Vec2{-10, 100}},
			Enemy_Set{eEnemy::Kusozako, Vec2{Define::Window::Center::X, -10}},
			Enemy_Set{eEnemy::Kusozako, Vec2{Define::Window::PlayArea::End::X + 10, -10}}
		}
	};
	// ------------------
}

namespace Shooting_HackAndSlash {
	EnemySpawner::EnemySpawner(const Player& p, EnemyController& e) :
		player(p),
		controller(e),
		party_list(),
		spawn_interval(SPAWN_INTERVAL),
		spawn_count(0.f)
	{
		// �G�l�~�[���X�g�o�^
		for (auto& w : ::list) {
			party_list.push_back(Party_List());

			for (auto& q : w) {
				// �������擾
				auto i = --party_list.end();

				// �ǉ�
				i->push_back(q);
			}
		}
		
		// �X�e�[�W�i�s�x�ɉ����ėN�o�Ԋu���k�߂�
		float stage_num = static_cast<float>(Stage_Info::Show_Stage_Num());
		spawn_interval = std::clamp(spawn_interval - stage_num * ::Interval_Decrease, ::Interval_Bottom, ::SPAWN_INTERVAL);
	}

	void EnemySpawner::update() {
		using Party_List = std::vector<Enemy_Info>;

		if ((spawn_count -= Time::DeltaTime()) <= 0.f) {
			// �J�E���^�X�V
			spawn_count = spawn_interval;

			int party_size = static_cast<int> (party_list.size())-1;
			// ��������p�[�e�B������
			const Party_List& party = party_list.at(Random::Range(0, party_size));

			// ���肵���p�[�e�B�̍\�����̐�����v��
			for (const auto& w : party) {
				controller.Make(w.pos, w.kind);
			}
		}
	}
}