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
	//ERROR：对于b[]复制存在错误，不是每次从a[0]开始复制，而是从st开始复制
	/*for(int i = 0; i <= mid; ++i)
	{
	b[i] = a[i];
	}*/
	for (int i = 0; i < mid - st + 1; ++i)
	{
		b[i] = a[i + st];
	}
	//ERROR:这里int k = st;注意不是k = 0
	int k = st;
	for (int i = st, j = mid + 1; i <= mid || j <= ed;)
	{
		//注意b[i - st] <= a[j]此处，必须与下面的a[j] < b[i - st]，构成封闭的集合
		//ERROR：未能考虑等于号
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
	cout << "归并排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}
