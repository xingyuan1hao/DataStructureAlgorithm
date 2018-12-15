// 02SwapSort.cpp
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


static void swap(int& a, int& b)
{
	int tem = a;
	a = b;
	b = tem;
}


static void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
}


void test_SwapSort_Bubble(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		bool isSorted = true;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j], a[j + 1]);
				isSorted = false;
			}
		}
		if (true == isSorted)
		{
			break;
		}
	}
	cout << "ð������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}


//������û�п�����ǰ�˳������
void Mytest_SwapSort_Bubble(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << "ð������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}


static int getMiddleID(int* a, int st, int mid, int ed)
{
	int res;
	if (a[st] < a[mid])
	{
		if (a[mid] < a[ed])
		{
			res = mid;
		}
		else
		{
			res = a[st] < a[ed] ? ed : st;
		}
	}
	else
	{
		if (a[ed] < a[mid])
		{
			res = mid;
		}
		else
		{
			res = a[st] > a[ed] ? ed : st;
		}
	}
	return res;
}


//��ȡ����λ�ã���ʱ���֮ǰ�ļ�¼������������ֵ�����֮��ļ�¼��С������ֵ
static int Partition(int* a, int st, int ed)
{
	/*int stPos = getMiddleID(a, st, (ed - st) / 2, ed);
	swap(a[st], a[stPos]);*/
	int tem = a[st];
	while (st < ed)
	{
		//ERROR:������while���У�����Ҫ����һ�ε���<=,����������Ԫ�أ�����������ѭ���У�
		//���֮��ļ�¼��С������ֵ
		while (st < ed&&tem < a[ed])
		{
			--ed;
		}
		a[st] = a[ed];
		//���֮ǰ�ļ�¼������������ֵ
		while (st < ed&&a[st] <= tem)
		{
			++st;
		}
		a[ed] = a[st];
	}
	a[st] = tem;
	return st;
}


//���������㷨
static void QuickSort(int* a, int st, int ed)
{
	if (st < ed)
	{
		//pivot ���
		int pivotLoc = Partition(a, st, ed);
		QuickSort(a, st, pivotLoc - 1);
		QuickSort(a, pivotLoc + 1, ed);
	}
}


void test_SwapSort_Quick(int* a, int n)
{
	//���ڳ�ʼ���ѡ�񣬴�����Ԫ�ص���㣬�е���յ����ߵ��У�ѡ���м�������Ϊ��㡣
	//int stPos = getMiddleID(a, n, 0, (n - 1) / 2, n - 1);
	QuickSort(a, 0, n - 1);
	cout << "��������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}
