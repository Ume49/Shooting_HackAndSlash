#pragma once
#include"eScene.h"

namespace Shooting_HackAndSlash {
	class ISceneChangeListener {
	public:
		ISceneChangeListener() = default;
		virtual ~ISceneChangeListener() = default;

		// シーン変更関数
		// escene		: 追加してほしいシーン
		// stack_clear	: シーンスタックをクリアするかどうか
		// is_fade		: シーンを変更する際、フェード処理をするかどうか
		virtual void SceneChange(eScene nextScene, bool stack_clear = false, bool is_fade=false) = 0;
		virtual void ScenePop() = 0;
	};
}