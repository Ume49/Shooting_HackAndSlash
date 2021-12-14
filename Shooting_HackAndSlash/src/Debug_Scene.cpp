#include "Debug_Scene.h"
#include"Define.h"

#include<DxLib.h>
#include"Input.h"

#include"Color.h"

#include<format>

#include"BulletIcon.h"

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
		
		//v(Point{ 100, 100 }, [](float f) {})
		v(Point{ 70,100 }),
		fade()
	{
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });

		buttons.Add([&]() { fade.Set();  }, "暗くする", Point{ 200,10 });

		::init();
	}

	bool Debug_Scene::update() {
		bool is_continue = true;

		buttons.update();

		{	// 自由に書く場所
			v.update();

			fade.update();
		}
		return is_continue;
	}

	void Debug_Scene::draw() const {
		buttons.draw();

		{	// 自由に書く場所
			v.draw();

			BulletIcon icon{ Define::Path::Photo::Cristal };
			icon.draw();
		}
	}
}