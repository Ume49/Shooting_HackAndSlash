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

	// ‰Šú‰»ˆ—
	void init() {
		color = 0x11110f;
	}
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s),

		//ˆÈ‰º©—R‚É‰Šú‰»
		
		//v(Point{ 100, 100 }, [](float f) {})
		v(Point{ 70,100 }),
		fade()
	{
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });

		buttons.Add([&]() { fade.Set();  }, "ˆÃ‚­‚·‚é", Point{ 200,10 });

		::init();
	}

	bool Debug_Scene::update() {
		bool is_continue = true;

		buttons.update();

		{	// ©—R‚É‘‚­êŠ
			v.update();

			fade.update();
		}
		return is_continue;
	}

	void Debug_Scene::draw() const {
		buttons.draw();

		{	// ©—R‚É‘‚­êŠ
			v.draw();

			BulletIcon icon{ Define::Path::Photo::Cristal };
			icon.draw();
		}
	}
}