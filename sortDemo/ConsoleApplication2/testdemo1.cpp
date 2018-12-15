
//直接插入排序 希尔排序 冒泡排序（简单交换排序） 快速排序 简单选择排序 堆排序
//2路-归并排序 计数排序 基数排序 

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
#define N 10


void test_InsertSort_Straight(int* a, int n);
void test_InsertSort_Shell(int* a, int n);
void test_SwapSort_Bubble(int* a, int n);
void test_SwapSort_Quick(int* a, int n);
void test_SelectionSort_Simple(int* a, int n);
void test_SelectionSort_Heap(int* a, int n);
void test_MergeSort_2(int* a, int n);
void test_RadixSort_Count(int* a, int n);
void test_RadixSort_Radix(int* a, int n);




void test_InsertSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "原始数据如下" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;


	//测试直接插入排序
	test_InsertSort_Straight(a, N);
	//测试希尔排序
	test_InsertSort_Shell(a, N);
}


void test_SelectionSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "原始数据如下" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;


	//测试简单选择排序
	test_SelectionSort_Simple(a, N);
	//测试堆排序
	test_SelectionSort_Heap(a, N);
}


void test_SwapSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "原始数据如下" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	////测试冒泡排序
	test_SwapSort_Bubble(a, N);
	//测试快速排序
	test_SwapSort_Quick(a, N);
}


void test_MergeSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "原始数据如下" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	//2路-归并排序
	test_MergeSort_2(a, N);
}


void test_RadixSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "原始数据如下" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	//计数排序
	test_RadixSort_Count(a, N);
	//基数排序
	test_RadixSort_Radix(a, N);
}


int testdemo1()
{
	//所有的排序目的都是排出由小到大的顺序
	//test_InsertSort();
	//test_SwapSort();
	//test_SelectionSort();
	//test_MergeSort();
	test_RadixSort();
	return 0;
}