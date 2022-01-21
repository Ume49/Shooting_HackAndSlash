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

	// ����������
	void init() {
	}
#endif
}

namespace Shooting_HackAndSlash::Scene {
	Debug_Scene::Debug_Scene(ISceneChangeListener& s) :
		AbstructScene(s)

		//�ȉ����R�ɏ�����
		, volume_controller(Point{ 100,100 })
	{
#ifdef  _DEBUG
		buttons.Add([&]() { listener.ScenePop(); }, "Return", Point{ 10, 10 });
		::init();

#endif //  _DEBUG
	}

	bool Debug_Scene::update() {
#ifdef  _DEBUG
		bool is_continue = true;

		buttons.update();

		{	// ���R�ɏ����ꏊ
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

		{	// ���R�ɏ����ꏊ
			volume_controller.draw();
		}
#endif
	}
}