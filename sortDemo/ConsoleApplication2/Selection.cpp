// 03SelectionSort.cpp
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


void test_SelectionSort_Simple(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[minIdx])
			{
				minIdx = j;
			}
		}
		if (i != minIdx)
		{
			swap(a[i], a[minIdx]);
		}
	}
	cout << "��ѡ������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}


//n��ʾ����ĳ��ȣ� adjPos��ʾ��Ҫ�����Ķѵ�λ�ã�
//�ѵĵ�������Ĭ�϶���������������Ѿ��Ǵ����
static void HeapAdjust(int* a, int n, int adjPos)
{
	int adjVal = a[adjPos];
	//ERROR:i = 2*i +1�������˼����iָ��������   ע�ⲻ��i= 2*i
	for (int i = 2 * adjPos + 1; i < n; i = 2 * i + 1)
	{
		//��������Һ��ӵĻ����Ƚ϶��ߣ�ȡ���нϴ��ߵ�λ��
		if (i < n - 1 && a[i] < a[i + 1])
		{
			++i;
		}
		//������ӽ������ֵ��С��adjVal���������ǰ����
		if (a[i] < adjVal)
		{
			break;
		}
		//���ν�Ԫ��������
		a[adjPos] = a[i];
		adjPos = i;
	}
	a[adjPos] = adjVal;
}


//��������ѣ��Ա��С�����������
static void createMaxHeap(int* a, int n)
{
	for (int i = (n - 2) / 2; 0 <= i; --i)
	{
		HeapAdjust(a, n, i);
	}
}


void test_SelectionSort_Heap(int* a, int n)
{
	//���������
	createMaxHeap(a, n);
	//���ν���Ԫ�غ����һ��Ԫ�ؽ��н�����������
	for (int i = n - 1; 0 <= i; --i)
	{
		swap(a[0], a[i]);
		HeapAdjust(a, i, 0);
	}


	cout << "������֮��Ľ�����£�" << endl;
	print(a, n);
	cout << endl;
}

