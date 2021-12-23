#include "Debug_Scene.h"
#include"Define.h"
#include<DxLib.h>
#include"Input.h"
#include<format>
#include"Color.h"

#include"Inventory_Info.h"

namespace {
	int bright = 255;

	Shooting_HackAndSlash::Color color;

	// ����������
	void init() {
		color = 0x11110f;
	}
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s),

		//�ȉ����R�ɏ�����
		custamize()
	{
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });


		
		buttons.Add([&]() { *(Gun_Custamize::Inventory_Info::container_space()) = eBullet::ST_Single;}, "�A�C�e���ǉ�", Point{ 10, 110 });
		buttons.Add([&]() { *(Gun_Custamize::Inventory_Info::container_space()) = eBullet::ST_Double;}, "�A�C�e���ǉ�2", Point{ 10, 180 });

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
		}
	}
}