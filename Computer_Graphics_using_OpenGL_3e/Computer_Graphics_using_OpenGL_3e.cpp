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
	// ѡ��Ӧ��ID
	cout << "��ѡ��Ӧ��ID:" << endl;
	cout << "01�����־���" << endl;
	cout << "02����������" << endl;
	cout << "03��O2O�̼Ҷ�" << endl;
	cout << "05����������" << endl;
	cout << "06�����־���PRO" << endl;
	cout << "07�����ӽ�" << endl;
	cout << "08����������PRO" << endl;
	cout << "������: ";

	int app_id;
	cin >> app_id;

	// ѡ��ƽ̨
	cout << "��ѡ��ƽ̨:" << endl;
	cout << "2:IOS"<< endl;
	cout << "3:ANDROID"<< endl;
	cout << "4:IPAD"<< endl;
	cout << "5:WINDOWS PHONE"<< endl;
	cout << "6:ANDROID PAD"<< endl;
	cout << "�����룺";

	int platform;
	cin >> platform;

	//�汾��
	cout << "������汾��:";
	int version;
	cin >> version;

	// ������
	cout << "�������������ļ���";
	string filename;
	cin >> filename;

	fstream fin(filename, ios::in);
	fstream fcout("channel.txt", ios::out);

	string line;

	while (getline(fin, line)) //���ļ��ж�ȡ�ַ���������������С������Ի���get������
	{
		fcout << setw(2) << setfill('0') <<app_id 
			<< setw(1)<<platform  
			<<setw(4)<<setfill('0')<<version  
			<<setw(4) << setfill('0') << line << "00000" << "\n"; //д������
	}
	fin.close();
	fcout.close();

	//for (int i = 1;i < 425;++i)
	//	fcout << app_id << platform << version << setw(4) << setfill('0') << i << "00000" << "\n"; //д������
	//	//fcout << app_id << platform << version << setw(4) << setfill('0') << i << "\n"; //д������

	//fcout.close();
}