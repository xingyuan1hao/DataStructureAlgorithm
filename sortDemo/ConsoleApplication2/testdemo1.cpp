
//ֱ�Ӳ������� ϣ������ ð�����򣨼򵥽������� �������� ��ѡ������ ������
//2·-�鲢���� �������� �������� 

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
	cout << "ԭʼ��������" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;


	//����ֱ�Ӳ�������
	test_InsertSort_Straight(a, N);
	//����ϣ������
	test_InsertSort_Shell(a, N);
}


void test_SelectionSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "ԭʼ��������" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;


	//���Լ�ѡ������
	test_SelectionSort_Simple(a, N);
	//���Զ�����
	test_SelectionSort_Heap(a, N);
}


void test_SwapSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "ԭʼ��������" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	////����ð������
	test_SwapSort_Bubble(a, N);
	//���Կ�������
	test_SwapSort_Quick(a, N);
}


void test_MergeSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "ԭʼ��������" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	//2·-�鲢����
	test_MergeSort_2(a, N);
}


void test_RadixSort()
{
	int a[N] = { 21, 26, 5, 96, 45, 12, 26, 14, 15, 12 };
	cout << "ԭʼ��������" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << left << setw(4) << a[i];
	}
	cout << endl;
	//��������
	test_RadixSort_Count(a, N);
	//��������
	test_RadixSort_Radix(a, N);
}


int testdemo1()
{
	//���е�����Ŀ�Ķ����ų���С�����˳��
	//test_InsertSort();
	//test_SwapSort();
	//test_SelectionSort();
	//test_MergeSort();
	test_RadixSort();
	return 0;
}