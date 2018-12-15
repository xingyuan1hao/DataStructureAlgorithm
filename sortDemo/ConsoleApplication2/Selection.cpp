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
	cout << "简单选择排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}


//n表示数组的长度， adjPos表示需要调整的堆的位置；
//堆的调整都是默认顶点下面的子树都已经是大根堆
static void HeapAdjust(int* a, int n, int adjPos)
{
	int adjVal = a[adjPos];
	//ERROR:i = 2*i +1代表的意思就是i指向其左孩子   注意不是i= 2*i
	for (int i = 2 * adjPos + 1; i < n; i = 2 * i + 1)
	{
		//如果存在右孩子的话，比较二者，取其中较大者的位序
		if (i < n - 1 && a[i] < a[i + 1])
		{
			++i;
		}
		//如果孩子结点的最大值都小于adjVal，则调整提前结束
		if (a[i] < adjVal)
		{
			break;
		}
		//依次将元素往上移
		a[adjPos] = a[i];
		adjPos = i;
	}
	a[adjPos] = adjVal;
}


//建立大根堆，以便从小到大进行排序
static void createMaxHeap(int* a, int n)
{
	for (int i = (n - 2) / 2; 0 <= i; --i)
	{
		HeapAdjust(a, n, i);
	}
}


void test_SelectionSort_Heap(int* a, int n)
{
	//建立大根堆
	createMaxHeap(a, n);
	//依次将顶元素和最后一个元素进行交换，逐渐排序
	for (int i = n - 1; 0 <= i; --i)
	{
		swap(a[0], a[i]);
		HeapAdjust(a, i, 0);
	}


	cout << "堆排序之后的结果如下：" << endl;
	print(a, n);
	cout << endl;
}

