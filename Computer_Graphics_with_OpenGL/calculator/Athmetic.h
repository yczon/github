#pragma once
#include<cmath>
#include<cstdlib>
#include<vector>

class Athmetic {
private:
	int num1, num2;
	int vtoi(std::vector<char>);
	std::vector<char> itov(int);
public:
	Athmetic() = default;
	Athmetic(std::vector<char> a, std::vector<char> b) {
		num1 = vtoi(a);
		num2 = vtoi(b);
	}
	int a_add();
	int a_minus();
	int a_mul();
	int a_div();
};

int Athmetic::a_add() {
	return num1 + num2;
}
int Athmetic::a_minus() {
	return num1 - num2;
}
int Athmetic::a_mul() {
	return num1 * num2;
}
int Athmetic::a_div() {
	return num1 / num2;
}
// vector 数组转 数字
int Athmetic::vtoi(std::vector<char> v) {

	int result = 0;
	size_t n = 0;

	for (auto i : v)
	{
		result += pow(10, n) * i;
		++n;
	}

	return result;
}
//数字转 vector 数组
std::vector<char> Athmetic::itov(int i) {
	std::vector<char> result;
	char str[20];
	int tmp = i;
	int aa = 0;
	do
	{
		aa = tmp % 10;
		tmp = tmp / 10;
		_itoa_s(aa, str, 2, 10);
		result.push_back(*str);
	} while (tmp != 0);

	return result;
}