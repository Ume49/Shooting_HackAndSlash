#include "Icon_Table.h"

namespace {

}

namespace Shooting_HackAndSlash::Gun_Custamize {
	Icon_Table::Icon_Table() :
		table() {
		
	}

	const Photo_SharedHandle& Icon_Table::at(const eBullet& b) {
		return Icon_Table::getInstance().table.at(b);
	}
}