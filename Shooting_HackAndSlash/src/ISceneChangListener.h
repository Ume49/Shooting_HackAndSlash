#pragma once
#include"eScene.h"

namespace Shooting_HackAndSlash {
	class ISceneChangeListener {
	public:
		ISceneChangeListener() = default;
		virtual ~ISceneChangeListener() = default;

		// �V�[���ύX�֐�
		// escene		: �ǉ����Ăق����V�[��
		// stack_clear	: �V�[���X�^�b�N���N���A���邩�ǂ���
		// is_fade		: �V�[����ύX����ہA�t�F�[�h���������邩�ǂ���
		virtual void SceneChange(eScene nextScene, bool stack_clear = false, bool is_fade=false) = 0;
		virtual void ScenePop() = 0;
	};
}