#include "Icon_Table.h"

#include"eBullet.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	namespace Path = Define::Path::Photo::Icon;

	Icon_Table::Icon_Table() :
		table() {
		// ëŒâûï\ÇçÏê¨
		table.emplace(eBullet::ST, Path::ST);
		table.emplace(eBullet::V, Path::V);
		table.emplace(eBullet::Star, Path::Star);
		table.emplace(eBullet::Refrect, Path::Refrect);
		table.emplace(eBullet::RightCurve, Path::RightCurve);
		table.emplace(eBullet::LeftCurve, Path::LeftCurve);
	}

	const Photo_SharedHandle& Icon_Table::at(const eBullet& b) {
		return Icon_Table::getInstance().table.at(b);
	}
}