// 05RadixSort.cpp
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;


static void print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
}


//假设数组元素在0~99之间，进行取值
//计数排序
void test_RadixSort_Count(int* a, int n)
{
	//计数数组
	int* cnt = new int[100];
	memset(cnt, 0, sizeof(int) * 100);

	//此时，cnt[a[i]]表示值为a[i]的元素在数组a当中出现的次数
	//WARNING: 注意这里i < n,不是i < 100
	for (int i = 0; i < n; ++i)
	{
		++cnt[a[i]];
	}
	//此时，cnt[i] - 1表示值为i的元素在数组a中排序之后的最大可能位置
	//ERROR: 注意这里i < 100,不是i < n
	for (int i = 1; i < 100; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	//tmp[]临时数组，将数组a复制到数组tmp中去
	int* tmp = new int[n];
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = a[i];
	}
	////ERROR:计数排序,这样虽然也能得到正确结果，但是不能保证排序的稳定性
	//for(int i = 0; i < n; ++i)
	//{
	//	a[--cnt[tmp[i]]] = tmp[i];
	//}


	//稳定版：计数排序
	for (int i = n - 1; 0 <= i; --i)
	{
		a[--cnt[tmp[i]]] = tmp[i];
	}


	cout << "计数排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
	delete[] cnt;
	delete[] tmp;
}


static int getRadix(int num, int sq, int RADIX)
{
	return (num / (int)pow(RADIX, sq)) % RADIX;
}


static void Distribute(int* a, int n, int sq, int* cnt, int* tmp, int RADIX)
{
	memset(cnt, 0, sizeof(int)*RADIX);
	for (int i = 0; i < n; ++i)
	{
		int ord = getRadix(a[i], sq, RADIX);
		++cnt[ord];
	}
}


static void Collect(int* a, int n, int sq, int* cnt, int* tmp, int RADIX)
{
	for (int i = 1; i < RADIX; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = a[i];
	}
	for (int i = n - 1; 0 <= i; --i)
	{
		int ord = getRadix(tmp[i], sq, RADIX);
		a[--cnt[ord]] = tmp[i];
	}
}


void test_RadixSort_Radix(int* a, int n)
{
	int keyNum = 2;
	int RADIX = 10;
	int* cnt = new int[RADIX];
	int* tmp = new int[n];


	for (int i = 0; i < keyNum; ++i)
	{
		Distribute(a, n, i, cnt, tmp, RADIX);
		Collect(a, n, i, cnt, tmp, RADIX);
		cout << i + 1 << "次基数排序之后的结果如下：" << endl;
		print(a, n);
		cout << endl;
	}
	cout << "基数排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
	delete[] cnt;
	delete[] tmp;
}
