#include "stdafx.h"
#include"OpenglDraw.h"

#include<fstream>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;

//------main------
void main(int argc, char **argv)
{
	// 选择应用ID
	cout << "请选择应用ID:" << endl;
	cout << "01：美柚经期" << endl;
	cout << "02：美柚孕期" << endl;
	cout << "03：O2O商家段" << endl;
	cout << "05：美柚育儿" << endl;
	cout << "06：美柚经期PRO" << endl;
	cout << "07：柚子街" << endl;
	cout << "08：美柚孕期PRO" << endl;
	cout << "请输入: ";

	int app_id;
	cin >> app_id;

	// 选择平台
	cout << "请选择平台:" << endl;
	cout << "2:IOS"<< endl;
	cout << "3:ANDROID"<< endl;
	cout << "4:IPAD"<< endl;
	cout << "5:WINDOWS PHONE"<< endl;
	cout << "6:ANDROID PAD"<< endl;
	cout << "请输入：";

	int platform;
	cin >> platform;

	//版本号
	cout << "请输入版本号:";
	int version;
	cin >> version;

	// 渠道号
	cout << "请输入渠道号文件：";
	string filename;
	cin >> filename;

	fstream fin(filename, ios::in);
	fstream fcout("channel.txt", ios::out);

	string line;

	while (getline(fin, line)) //从文件中读取字符串到输入输出流中。不可以换成get（）。
	{
		fcout << setw(2) << setfill('0') <<app_id 
			<< setw(1)<<platform  
			<<setw(4)<<setfill('0')<<version  
			<<setw(4) << setfill('0') << line << "00000" << "\n"; //写入数据
	}
	fin.close();
	fcout.close();

	//for (int i = 1;i < 425;++i)
	//	fcout << app_id << platform << version << setw(4) << setfill('0') << i << "00000" << "\n"; //写入数据
	//	//fcout << app_id << platform << version << setw(4) << setfill('0') << i << "\n"; //写入数据

	//fcout.close();
}