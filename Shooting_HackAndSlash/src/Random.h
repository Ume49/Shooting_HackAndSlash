#pragma once

#include"Singleton.h"

#include<random>

namespace Shooting_HackAndSlash {
	class Random : public Singleton<Random> {
	public:
		// 指定した確率に基いた結果を返す
		// numerator:   分子
		// denominator: 分母
		// 返り値: 分子/分母の確率を返す。例：20/100=>20%の確率でtrue</returns>
		static bool Question(int numerator, int denominator);
		// 指定した確率に基いた結果を返す
		// true_rate: trueが返ってくる確率
		static bool Question(float true_rate);
		// min~maxまでの数をランダムに返す
		static int Range(int min, int max);
		
	private:
		//乱数生成器
		std::mt19937 random_machine;
	private:
		friend Singleton;
		Random() : random_machine(std::random_device()()) {
		}
	};
}