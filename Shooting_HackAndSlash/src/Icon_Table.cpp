#include "Icon_Table.h"

#include"eBullet.h"
#include"Define.h"

namespace Shooting_HackAndSlash::Gun_Custamize {
	namespace Path = Define::Path::Photo::Icon;

	Icon_Table::Icon_Table() :
		table() {
		// ‘Î‰•\‚ğì¬
		table.emplace(eBullet::ST, Path::ST_1);
		table.emplace(eBullet::V, Path::ST_2);
		table.emplace(eBullet::Star, Path::ST_3);
	}

	const Photo_SharedHandle& Icon_Table::at(const eBullet& b) {
		return Icon_Table::getInstance().table.at(b);
	}
}