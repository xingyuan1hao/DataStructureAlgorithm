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
	//对比shell排序，这里st=0; step=1;
	for (int i = 0 + 1; i < n; ++i)
	{
		//存储当前待比较的变量
		int tem = a[i];
		int j = i;
		for (; 1 <= j&&tem < a[j - 1]; --j)
		{
			//元素后移
			a[j] = a[j - 1];
		}
		a[j] = tem;
	}
	cout << "直接插入排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}


//对数组a作一趟希尔插入排序。本算法和一趟直接插入排序相比，作了以下修改：
//	1.前后记录位置的增量为step,而不是1
static void ShellInsert(int* a, int n, int step)
{
	for (int st = 0; st < step; ++st)
	{
		//这边就是直接插入排序，
		for (int i = st + step; i < n; i += step)
		{
			int tem = a[i];
			int j = i;
			for (; step <= j&&tem < a[j - step]; j -= step)
			{
				//元素后移
				a[j] = a[j - step];
			}
			a[j] = tem;
		}
	}
	/*cout << "步长为" << step << ", 希尔排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;*/
}


void test_InsertSort_Shell(int* a, int n)
{
	//stepInc位置的增量
	for (int stepInc = n >> 1; 1 <= stepInc; stepInc >>= 1)
	{
		ShellInsert(a, n, stepInc);
	}
	cout << "希尔排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}


//WARNING:  点评：自己写的简单插入排序，用到了swap。其实免去这个操作。做到真正的只插入。
void Mytest_InsertSort_Straight(int* a, int n)
{


	for (int i = 1; i < n; ++i)
	{
		for (int j = i; 0 < j; --j)
		{
			if (a[j] < a[j - 1])
			{
				//如果a[j-1]大于a[j]的时候，对换二者
				swap(a[j], a[j - 1]);
			}
			else
			{
				//说明数组a[0,..,j]部分已经排序成功，直接跳出循环
				break;
			}
		}
	}
	cout << "直接插入排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}
