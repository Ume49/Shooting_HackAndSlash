#pragma once

namespace Shooting_HackAndSlash {
	template<class T>
	class Singleton {
	public:
		// �Ăяo���p�֐����P�ꐫ�S��
		static T& getInstance() {
			static T instance;	// �B��̃C���X�^���X�𐶐�
			return instance;
		}
	protected:
		Singleton() = default;
		virtual ~Singleton() = default;
	private:
		// �R�s�[�R���X�g���N�^�Ƒ�����Z�q���֎~
		void operator=(const Singleton& s) = delete;
		Singleton(const Singleton& s) = delete;
	};

#ifdef _DEBUG
	// ��L Singleton �N���X�̎g�p��
	// �A�N�Z�X������ �N���X��::getInstance().�����o ��
	class Singleton_Test : public Singleton<Singleton_Test> {	// Singleton<����> ���p��������
	public:
		// �K���ȃ����o�ϐ�
		int  member_int;
		bool member_bool;

		// �����o�֐����K���ɍ���Ă���
		int get_member() { return member_int; }

	private:
		// �K��=====================================================================================

		// �K�{
		// private�ɐݒ肵���R���X�g���N�^�ւ̃A�N�Z�X�������Ȃ���Singleton<T>::getInstance()�����삵�Ȃ�����
		friend Singleton;

		// �R���X�g���N�^�͕K��private�ɂ��邱��
		Singleton_Test() :
			member_int{}, member_bool{} {
			// �R���X�g���N�^�̓��e���͍̂D���ɏ����Ă���
		}

		// �Ăяo����邱�Ƃ��Ȃ��̂ň����t���R���X�g���N�^�͍���Ă��Ӗ��Ȃ�
		Singleton_Test(int para):
			member_int{para}, member_bool{true}
		{}

		// =========================================================================================
	};
#endif // __DEBUG
}