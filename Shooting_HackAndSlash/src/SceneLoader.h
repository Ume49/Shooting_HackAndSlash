#pragma once

#include<stack>
#include<memory>

#include"ISceneChangListener.h"
#include"AbstructScene.h"
#include"Color.h"
#include"CursorDrawer.h"
#include"Fade.h"

namespace Shooting_HackAndSlash {
	// シーン読み込み機
	// シーンの外側で動くようなものも動かす
	class SceneLoader :public ISceneChangeListener {
		std::stack<std::unique_ptr<AbstructScene>> scene_stack;

		struct SceneChange_Info {
			eScene scene;
			bool is_clear;
		};

		SceneChange_Info next;
		bool isSceneChange, isScenePop, isFade;

		CursorDrawer cursor;

		Color background_color;

		Fade fade;
	public:
		bool load();
		// SceneChangeはScenePopの後に処理される
		void SceneChange(eScene next_scene, bool stack_clear = false, bool is_fade = false) override;
		// ScenePopはSceneChangeの前に処理される
		void ScenePop() override;
	private:

		void scene_change();
		void scene_pop();
	public:
		SceneLoader();
	};
}