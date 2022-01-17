#pragma once
#include"Define_Debug.h"

namespace Shooting_HackAndSlash {
	namespace Palette {
		constexpr unsigned int Black = 0x000000;
		constexpr unsigned int White = 0xffffff;
	}

	namespace Define {
		// �E�C���h�E�̍���ɕ\������郁�b�Z�[�W
		constexpr char GAME_TITLE[] = "This text is written Define.h file.";

		// �w�i�̐F
		namespace Background {
			constexpr int R = 10;
			constexpr int G = 10;
			constexpr int B = 10;
		}

		namespace Window {
			// �J���[�r�b�g��
			constexpr int COLOR_BIT_NUM = 32;

			constexpr int WITDH = 768;
			constexpr int HEIGHT = 1024;

			// �E�C���h�E�T�C�Y���ςɂ��邩�ǂ���
			constexpr int IS_WINDOWSIZE_FLEXIBLE = static_cast<int>(false);
			// �E�C���h�E���[�h�ŋN�����邩�ǂ���
			constexpr int IS_WINDOW_MODE = static_cast<int>(true);

			namespace Center {
				constexpr float Xf = static_cast<float>(Window::WITDH) / 2.f;
				constexpr float Yf = static_cast<float>(Window::HEIGHT) / 2.f;
				constexpr int X = static_cast<int>(Xf);
				constexpr int Y = static_cast<int>(Yf);
			}

			namespace UI {
				constexpr int WIDTH = 120;

				// UI�G���A�̊�_�A����
				namespace Standerd {
					constexpr int X = Window::WITDH - UI::WIDTH;
					constexpr int Y = 0;
					constexpr float Xf = static_cast<float>(X);
					constexpr float Yf = static_cast<float>(Y);
				}
				namespace Center {
					constexpr int X = (Window::WITDH + Standerd::X) / 2;
					constexpr int Y = (Window::HEIGHT + Standerd::Y) / 2;
					constexpr float Xf = static_cast<float>(X);
					constexpr float Yf = static_cast<float>(Y);
				}
				namespace End {
					constexpr int X = Window::WITDH;
					constexpr int Y = Window::HEIGHT;
					constexpr float Xf = static_cast<float>(X);
					constexpr float Yf = static_cast<float>(Y);
				}
			}

			// �v���C���[���ړ��ł���͈�
			namespace PlayArea {
				// �v���C�G���A���ǂꂾ�����߂邩
				constexpr int SPACE = 5;

				namespace Start {
					constexpr int X = SPACE;
					constexpr int Y = SPACE;
					constexpr float Xf = static_cast<float>(X);
					constexpr float Yf = static_cast<float>(Y);
				}
				namespace End {
					constexpr int X = UI::Standerd::X - 1 - SPACE;	// UI�G���A�̍��ׂȂ̂�-1���Ă���
					constexpr int Y = Window::HEIGHT - SPACE;
					constexpr float Xf = static_cast<float>(X);
					constexpr float Yf = static_cast<float>(Y);
				}
				namespace Center {
					constexpr float Xf = static_cast<float>(Start::X + End::X) / 2.f;
					constexpr float Yf = static_cast<float>(Start::Y + End::Y) / 2.f;
					constexpr int X = static_cast<int>(Xf);
					constexpr int Y = static_cast<int>(Yf);
				}
			}
		}

		// DrawRotaGraph���g�����Ƃ��́A�f�t�H���g�̒l
		namespace RotaGraph_Default {
			constexpr double ExRate = 1.;
			constexpr double Angle = 0.;
		}

		// �t�@�C���p�X
		namespace Path {
			namespace Photo {
				constexpr char Bullet[] = "Resource/bullet.png";
				constexpr char Player[] = "Resource/player.png";
				constexpr char BackScreen[] = "Resource/back_screen.png";
				constexpr char Cursor[] = "Resource/cursor.png";
				constexpr char UI_Window[] = "Resource/ui_window.png";
				constexpr char Cristal[] = "Resource/cristal.png";
				constexpr char Slot[]{ "Resource/null_slot.png" };

				namespace Enemy {
					constexpr char Kusozako[] = "Resource/kusozako.png";
				}
				namespace Bullet_Gauge {
					constexpr char Gauge[] = "Resource/BulletGauge.png";
					constexpr char Frame[] = "Resource/BulletGauge_Frame.png";
					constexpr char Back[] = "Resource/BulletGauge_Back.png";
				}
				namespace HP_Bar {
					constexpr char Gauge[] = "Resource/HP_Bar.png";
					constexpr char Frame[] = "Resource/HP_Frame.png";
					constexpr char Back[] = "Resource/HP_Back.png";
				}
				namespace Button {
					constexpr char Normal[] = "Resource/button.png";
					constexpr char Selected[] = "Resource/button_selected.png";
				}
				namespace Volume {
					constexpr char Clip[] = "Resource/clip.png";
					constexpr char Clip_selected[] = "Resource/clip_selected.png";
					constexpr char Back[] = "Resource/volume_back.png";
					constexpr char Gauge[] = "Resource/volume_gauge.png";
					constexpr char Window[] = "Resource/volume_window.png";
				}
				namespace Icon {
					constexpr char ST[] = "Resource/Bullet_ST.png";
					constexpr char V[] = "Resource/Bullet_V.png";
					constexpr char Star[] = "Resource/Bullet_Star.png";
					constexpr char RightCurve[] = "Resource/Bullet_RightCurve.png";
					constexpr char LeftCurve[] = "Resource/Bullet_LeftCurve.png";
					constexpr char Refrect[] = "Resource/Bullet_Refrect.png";
				}
			}
		}
	}
}
