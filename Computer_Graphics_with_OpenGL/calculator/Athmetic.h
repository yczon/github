#pragma once
#include<cmath>
#include<cstdlib>
#include<vector>
#include<iostream>

class Athmetic {
private:
	int num1, num2;
public:
	Athmetic() = default;
	Athmetic(int a, int b) {
		num1 = a;
		num2 = b;
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
	std::cout << "num1:" << num1 << std::endl;
	std::cout << "num2:" << num2 << std::endl;
	return num1 / num2;
}