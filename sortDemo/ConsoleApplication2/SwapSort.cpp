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
	cout << "冒泡排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}


//点评：没有考虑提前退出的情况
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
	cout << "冒泡排序之后的结果如下：" << endl;
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


//获取轴点的位置，此时轴点之前的记录均不大于轴点的值，轴点之后的记录均小于轴点的值
static int Partition(int* a, int st, int ed)
{
	/*int stPos = getMiddleID(a, st, (ed - st) / 2, ed);
	swap(a[st], a[stPos]);*/
	int tem = a[st];
	while (st < ed)
	{
		//ERROR:这两次while当中，至少要出现一次等于<=,否则对于相等元素，会陷入无限循环中；
		//轴点之后的记录均小于轴点的值
		while (st < ed&&tem < a[ed])
		{
			--ed;
		}
		a[st] = a[ed];
		//轴点之前的记录均不大于轴点的值
		while (st < ed&&a[st] <= tem)
		{
			++st;
		}
		a[ed] = a[st];
	}
	a[st] = tem;
	return st;
}


//快速排序算法
static void QuickSort(int* a, int st, int ed)
{
	if (st < ed)
	{
		//pivot 轴点
		int pivotLoc = Partition(a, st, ed);
		QuickSort(a, st, pivotLoc - 1);
		QuickSort(a, pivotLoc + 1, ed);
	}
}


void test_SwapSort_Quick(int* a, int n)
{
	//对于初始点的选择，从数组元素的起点，中点和终点三者当中，选择中间大的数作为起点。
	//int stPos = getMiddleID(a, n, 0, (n - 1) / 2, n - 1);
	QuickSort(a, 0, n - 1);
	cout << "快速排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}
