#pragma once

#include"Singleton.h"

#include<random>

namespace Shooting_HackAndSlash {
	class Random : public Singleton<Random> {
	public:
		/// <summary>
		/// �w�肵���m���Ɋ�����ʂ�Ԃ�
		/// </summary>
		/// <param name="numerator">���q</param>
		/// <param name="denominator">����</param>
		/// <returns>���q/����̊m����Ԃ��B��F20/100=>20%�̊m����true</returns>
		static bool Question(int numerator, int denominator);
		/// <summary>
		/// �w�肵���m���Ɋ�����ʂ�Ԃ�
		/// </summary>
		/// <param name="true_rate"> true���Ԃ��Ă���m�� </param>
		static bool Question(float true_rate);
		// min~max�܂ł̐��������_���ɕԂ�
		static int Range(int min, int max);

		
	private:
		//����������
		std::mt19937 random_machine;
	private:
		friend Singleton;
		Random() : random_machine(std::random_device()()) {
		}
	};
}