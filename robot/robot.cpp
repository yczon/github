// robot.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <WinSock.h>  //һ��Ҫ�������������winsock2.h
#include "include/mysql.h"    //����mysqlͷ�ļ�(һ�ַ�ʽ����vcĿ¼�������ã�һ�����ļ��п�������Ŀ¼��Ȼ����������)
#include <Windows.h>

using namespace std;

//�������������Ҳ�����ڹ���--������������
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")
MYSQL mysql; //mysql����
MYSQL_FIELD *fd;  //�ֶ�������
char field[32][32];  //���ֶ�����ά����
MYSQL_RES *res; //����ṹ�������е�һ����ѯ�����
MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
string query;	//��ѯ���

bool ConnectDatabase();     //��������
void FreeConnect();
bool QueryDatabase1();  //��ѯ1
bool QueryDatabase2();  //��ѯ2
bool InsertData();
bool ModifyData();
bool DeleteData();
int main(int argc, char **argv)
{
	ConnectDatabase();
	QueryDatabase1();
	/*
	InsertData();
	QueryDatabase2();
	ModifyData();
	QueryDatabase2();
	DeleteData();
	QueryDatabase2();
	*/
	FreeConnect();

	system("pause");

	return 0;
}
//�������ݿ�
bool ConnectDatabase()
{
	//��ʼ��mysql
	mysql_init(&mysql);  //����mysql�����ݿ�

						 //����false������ʧ�ܣ�����true�����ӳɹ�
	if (!(mysql_real_connect(&mysql, "localhost", "root", "", "robot", 0, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Connected...\n");
		return true;
	}
}
//�ͷ���Դ
void FreeConnect()
{
	//�ͷ���Դ
	mysql_free_result(res);
	mysql_close(&mysql);
}

/***************************���ݿ����***********************************/
//��ʵ���е����ݿ����������д��sql��䣬Ȼ����mysql_query(&mysql,query)����ɣ������������ݿ�����ɾ�Ĳ�
//��ѯ����
bool QueryDatabase1()
{
	char *query = "select * from answer";		 //ִ�в�ѯ��䣬�����ǲ�ѯ���У�answer�����ü�����
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
										  //����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, query))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	//��ȡ�����
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
	{
		printf("Couldn't get result from %s\n", mysql_error(&mysql));
		return false;
	}

	//��ӡ��������
	cout << "number of dataline returned: " << mysql_affected_rows(&mysql) << endl;

	//��ȡ�ֶε���Ϣ
	for (int i = 0;i < 3;i++) {		//����֪�ֶ�����(i)������»�ȡ�ֶ���
		cout << mysql_fetch_field(res)->name << endl;
	}
	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res)) {  //����֪�ֶ���������£���ȡ����ӡ��һ��
		cout << column[0] << "   ";		     //column[0]�ǵ�һ���ֶ�(id)
		cout << column[1] << "   ";		     //column[1]�ǵڶ����ֶ�(say)
		cout << column[2] << endl;		     //column[2]�ǵ������ֶ�(answer)

	}
	return true;
}

/*
bool QueryDatabase2()
{
	mysql_query(&mysql, "set names gbk");
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	if (mysql_query(&mysql, "select * from user"))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("query success\n");
	}
	res = mysql_store_result(&mysql);
	//��ӡ��������
	printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
	for (int i = 0;fd = mysql_fetch_field(res);i++)  //��ȡ�ֶ���
		strcpy_s(field[i], fd->name);
	int j = mysql_num_fields(res);  // ��ȡ����
	for (int i = 0;i<j;i++)  //��ӡ�ֶ�
		printf("%10s\t", field[i]);
	printf("\n");
	while (column = mysql_fetch_row(res))
	{
		for (int i = 0;i<j;i++)
			printf("%10s\t", column[i]);
		printf("\n");
	}
	return true;
}
//��������
bool InsertData()
{
	sprintf(query, "insert into user values (NULL, 'Lilei', 'wyt2588zs','lilei23@sina.cn');");  //������취ʵ���ֶ��ڿ���̨�ֶ�����ָ��
	if (mysql_query(&mysql, query))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
//�޸�����
bool ModifyData()
{
	sprintf(query, "update user set email='lilei325@163.com' where name='Lilei'");
	if (mysql_query(&mysql, query))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
//ɾ������
bool DeleteData()
{
	sprintf(query, "delete from user where id=6");
	char query[100];
	printf("please input the sql:\n");
	//gets(query);  //�����ֶ�����sql���
	if (mysql_query(&mysql, query))        //ִ��SQL���
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
*/
