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
#ifdef  _DEBUG

	// 初期化処理
	void init() {
	}
#endif
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s)

		//以下自由に初期化
		, volume_controller(Point{ 100,100 })
	{
#ifdef  _DEBUG
		// デバッグ専用にボタンを追加
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });
		::init();

#endif //  _DEBUG
	}

	bool Debug_Scene::update() {
#ifdef  _DEBUG
		bool is_continue = true;

		buttons.update();

		{	// 自由に書く場所
			volume_controller.update();
		}
		return is_continue;
#else
		return true;
#endif
	}

	void Debug_Scene::draw() const {
#ifdef  _DEBUG
		buttons.draw();

		{	// 自由に書く場所
			volume_controller.draw();
		}
#endif
	}
}