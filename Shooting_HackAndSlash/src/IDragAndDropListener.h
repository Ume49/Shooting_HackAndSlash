#pragma once
#include"IDropListener.h"
#include"IBackListener.h"

namespace Shooting_HackAndSlash {
	// ドラッグ&ドロップに対応していることを示すインターフェース
	class IDragAndDropListener : public IDropListener, public IBackListener{
	public:
		IDragAndDropListener() = default;
		virtual ~IDragAndDropListener() = default;
	};
}