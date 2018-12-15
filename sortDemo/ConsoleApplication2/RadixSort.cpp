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


//��������Ԫ����0~99֮�䣬����ȡֵ
//��������
void test_RadixSort_Count(int* a, int n)
{
	//��������
	int* cnt = new int[100];
	memset(cnt, 0, sizeof(int) * 100);

	//��ʱ��cnt[a[i]]��ʾֵΪa[i]��Ԫ��������a���г��ֵĴ���
	//WARNING: ע������i < n,����i < 100
	for (int i = 0; i < n; ++i)
	{
		++cnt[a[i]];
	}
	//��ʱ��cnt[i] - 1��ʾֵΪi��Ԫ��������a������֮���������λ��
	//ERROR: ע������i < 100,����i < n
	for (int i = 1; i < 100; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	//tmp[]��ʱ���飬������a���Ƶ�����tmp��ȥ
	int* tmp = new int[n];
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = a[i];
	}
	////ERROR:��������,������ȻҲ�ܵõ���ȷ��������ǲ��ܱ�֤������ȶ���
	//for(int i = 0; i < n; ++i)
	//{
	//	a[--cnt[tmp[i]]] = tmp[i];
	//}


	//�ȶ��棺��������
	for (int i = n - 1; 0 <= i; --i)
	{
		a[--cnt[tmp[i]]] = tmp[i];
	}


	cout << "��������֮��Ľ�����£�" << endl;
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
		cout << i + 1 << "�λ�������֮��Ľ�����£�" << endl;
		print(a, n);
		cout << endl;
	}
	cout << "��������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
	delete[] cnt;
	delete[] tmp;
}
