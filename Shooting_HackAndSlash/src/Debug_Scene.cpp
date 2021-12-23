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

	// 初期化処理
	void init() {
		color = 0x11110f;
	}
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s),

		//以下自由に初期化
		custamize()
	{
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });

		buttons.Add([&]() { *(Inventory_Info::container_space()) = eBullet::ST_Single;}, "アイテム追加", Point{ 10, 110 });

		::init();
	}

	bool Debug_Scene::update() {
		bool is_continue = true;

		buttons.update();

		{	// 自由に書く場所
			custamize.update();
		}
		return is_continue;
	}

	void Debug_Scene::draw() const {
		buttons.draw();

		{	// 自由に書く場所
			custamize.draw();
		}
	}
}