#include"stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

//¼Ó
int c_add(int i, int j)
{
	return i + j;
}

//¼õ
int c_minus(int i, int j)
{
	return i - j;
}

//³Ë
int c_mul(int i, int j)
{
	return i * j;
}

//³ı
int c_div(int i, int j)
{
	return i / j;
}

int main(int argc, char **argv)
{
	int a = 0, b = 0;
	string op;
	map<string, int(*)(int, int)> binops;
	binops.insert({"+",c_add});
	binops.insert({"-",c_minus});
	binops.insert({"*",c_mul});
	binops.insert({"/",c_div});

	string str = "12 3 4 / +";
	istringstream record(str);

	string test;
	record >> test;
	cout << test << endl;
	/*
	while (cin >> a >> b >> op)
	{
		cout << binops[op](a, b) << endl;
	}
	*/

	cin.get();
	return 0;
}

