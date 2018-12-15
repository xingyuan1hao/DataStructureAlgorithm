// 04MergeSort.cpp
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


static void merge(int* a, int st, int mid, int ed)
{
	int* b = new int[mid - st + 1];
	//ERROR������b[]���ƴ��ڴ��󣬲���ÿ�δ�a[0]��ʼ���ƣ����Ǵ�st��ʼ����
	/*for(int i = 0; i <= mid; ++i)
	{
	b[i] = a[i];
	}*/
	for (int i = 0; i < mid - st + 1; ++i)
	{
		b[i] = a[i + st];
	}
	//ERROR:����int k = st;ע�ⲻ��k = 0
	int k = st;
	for (int i = st, j = mid + 1; i <= mid || j <= ed;)
	{
		//ע��b[i - st] <= a[j]�˴��������������a[j] < b[i - st]�����ɷ�յļ���
		//ERROR��δ�ܿ��ǵ��ں�
		if ((i <= mid&&j <= ed&&b[i - st] <= a[j]) || ed < j)
		{
			a[k++] = b[i - st];
			++i;
		}
		else if (i <= mid&&j <= ed && a[j] < b[i - st])
		{
			a[k++] = a[j];
			++j;
		}
		else
		{
			break;
		}
	}
	delete[] b;
}


static void  mergeSort(int* a, int st, int ed)
{
	if (st < ed)
	{
		int mid = st + (ed - st) / 2;
		mergeSort(a, st, mid);
		mergeSort(a, mid + 1, ed);
		merge(a, st, mid, ed);
	}
}


void test_MergeSort_2(int* a, int n)
{
	mergeSort(a, 0, n - 1);
	cout << "�鲢����֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}
