#include"Abstruct_Shared_Manager.h"

namespace Shooting_HackAndSlash {
	Abstruct_Shared_Manager::Abstruct_Shared_Manager() :
		container()
	{}

	int Abstruct_Shared_Manager::Load(const std::string& path) {

		if (container.contains(path)) {
			// ���ɃL�[���o�^����Ă��鎞

			// �Q�ƃJ�E���g�𑝉�
			container.at(path).reference_count++;

			// �n���h����Ԃ�
			return container.at(path).value;
		}
		else {
			// �L�[�����݂��Ȃ���

			// �V�K�L�[��o�^�A��������Ă�I�u�W�F�N�g������͂��Ȃ̂ŎQ�ƃL�[��1����X�^�[�g
			container.emplace(path, Handle{ 0,1 });
			
			// �o�^���ꂽ���[�h�֐����g���ăn���h�����쐬
			container.at(path).value = load_func(path);

			// �n���h����Ԃ�
			return container.at(path).value;
		}
	}

	void Abstruct_Shared_Manager::Count_Add(const std::string& key) {
		container.at(key).reference_count++;
	}

	void Abstruct_Shared_Manager::Release(const std::string& path) {

		// �Q�Ƃ��Ă���I�u�W�F�N�g���P���炵�A�N�����Ȃ��悤�ł���Βǉ�����
		if ((container.at(path).reference_count - 1) <= 0) {

			// ���\�[�X�����
			release_func(container.at(path).value);

			// �R���e�i����Y���I�u�W�F�N�g���폜
			container.erase(path);
		}
	}
}