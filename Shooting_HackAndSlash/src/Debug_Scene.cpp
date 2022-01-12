#include "Debug_Scene.h"
#include"Define.h"
#include<DxLib.h>
#include"Input.h"
#include<format>
#include"Color.h"

#include"Inventory_Info.h"

#include"Vector.h"
#include"Vec2_Rotate.h"

namespace {
	int bright = 255;

	Shooting_HackAndSlash::Color color;

	Vec2 center{ 100,600 };
	Vec2 point{ 50,50 };
	Vec2 point2;
	float angle = 90.f;

	// ����������
	void init() {
		color = 0x11110f;

		point2 = Shooting_HackAndSlash::Vec2_Rotate(point, Shooting_HackAndSlash::Degree_to_Radian(angle));
	}
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s),

		//�ȉ����R�ɏ�����
		custamize()
	{
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });

		buttons.Add([&]() { *(Inventory_Info::container_space()) = eBullet::ST; }, "�A�C�e���ǉ�", Point{ 10, 110 });
		buttons.Add([&]() { *(Inventory_Info::container_space()) = eBullet::V; }, "�A�C�e���ǉ�2", Point{ 10, 180 });

		::init();
	}

	bool Debug_Scene::update() {
		bool is_continue = true;

		buttons.update();

		{	// ���R�ɏ����ꏊ
			custamize.update();
		}
		return is_continue;
	}

	void Debug_Scene::draw() const {
		buttons.draw();

		{	// ���R�ɏ����ꏊ
			custamize.draw();

			auto drawpixel = [](const Vec2& p, UINT color = Palette::Collider) {DrawCircleAA(p.x, p.y, 3.f, 12, color); };

			drawpixel(::center, 0x4169e1);
			drawpixel(::center + ::point, Palette::White);
			drawpixel(::center + ::point2);
		}
	}
}