// 01InsertSort.cpp
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


static void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
}


void test_InsertSort_Straight(int* a, int n)
{
	//�Ա�shell��������st=0; step=1;
	for (int i = 0 + 1; i < n; ++i)
	{
		//�洢��ǰ���Ƚϵı���
		int tem = a[i];
		int j = i;
		for (; 1 <= j&&tem < a[j - 1]; --j)
		{
			//Ԫ�غ���
			a[j] = a[j - 1];
		}
		a[j] = tem;
	}
	cout << "ֱ�Ӳ�������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}


//������a��һ��ϣ���������򡣱��㷨��һ��ֱ�Ӳ���������ȣ����������޸ģ�
//	1.ǰ���¼λ�õ�����Ϊstep,������1
static void ShellInsert(int* a, int n, int step)
{
	for (int st = 0; st < step; ++st)
	{
		//��߾���ֱ�Ӳ�������
		for (int i = st + step; i < n; i += step)
		{
			int tem = a[i];
			int j = i;
			for (; step <= j&&tem < a[j - step]; j -= step)
			{
				//Ԫ�غ���
				a[j] = a[j - step];
			}
			a[j] = tem;
		}
	}
	/*cout << "����Ϊ" << step << ", ϣ������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;*/
}


void test_InsertSort_Shell(int* a, int n)
{
	//stepIncλ�õ�����
	for (int stepInc = n >> 1; 1 <= stepInc; stepInc >>= 1)
	{
		ShellInsert(a, n, stepInc);
	}
	cout << "ϣ������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}


//WARNING:  �������Լ�д�ļ򵥲��������õ���swap����ʵ��ȥ�������������������ֻ���롣
void Mytest_InsertSort_Straight(int* a, int n)
{


	for (int i = 1; i < n; ++i)
	{
		for (int j = i; 0 < j; --j)
		{
			if (a[j] < a[j - 1])
			{
				//���a[j-1]����a[j]��ʱ�򣬶Ի�����
				swap(a[j], a[j - 1]);
			}
			else
			{
				//˵������a[0,..,j]�����Ѿ�����ɹ���ֱ������ѭ��
				break;
			}
		}
	}
	cout << "ֱ�Ӳ�������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}
