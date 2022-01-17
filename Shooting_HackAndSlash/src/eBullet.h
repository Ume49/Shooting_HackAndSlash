#pragma once

namespace Shooting_HackAndSlash {
	// ’e‚Ìí—Ş
	// ST : ’¼i‚·‚é
	// Single , Double , Triple : Á–Å‚µ‚½ŒãA‰½ŒÂ‚Ì’eŠÛ‚ğ¶¬‚·‚é‚Ì‚©
	enum class eBullet : int {
		Null,
		ST,
		V,
		Star,
		Refrect,
		RightCurve,
		LeftCurve
	};

	// ’e‚ğƒ‰ƒ“ƒ_ƒ€‚Éæ“¾‚·‚é
	eBullet Random_Bullet();
}