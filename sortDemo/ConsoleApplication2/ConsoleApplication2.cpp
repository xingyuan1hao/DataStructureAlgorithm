// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <stdlib.h>
#include <vector>
using namespace std;

class CA
{
public:
	void f()
	{
		cout << "CA f()" << endl;
	}
	virtual void ff()
	{
		cout << "CA ff()" << endl;
		f();
	}
};

class CB : public CA
{
public:
	virtual void f()
	{
		cout << "CB f()" << endl;
	}
	void ff()
	{
		cout << "CB ff()" << endl;
		f();
		CA::ff();
	}
};
class CC : public CB
{
public:
	virtual void f()
	{
		cout << "C f()" << endl;
	}
};

//冒泡排序
//平均时间复杂度:O(N^2)
//最坏情况复杂度:O(N^2)
//空间复杂度:O(1)
//稳定排序
void bubblesort(vector<int>& a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
//冒泡排序升级版1
//设置一个标记来标志一趟比较是否发生交换
//如果没有发生交换，则数组已经有序
void bubblesort2(vector<int>& a)
{
	int n = a.size();
	bool flag;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}
//冒泡排序优化二
//用一个变量记录下最后一个发生交换的位置，后面没有发生交换的已经有序
//所以可以用这个值来作为下一次比较结束的位置
void bubblesort3(vector<int>& a)
{
	int n = a.size();
	int flag = n;
	int stop_pos;
	for (int i = 0; i < n; i++)
	{
		stop_pos = flag - 1;
		flag = 0;
		for (int j = 0; j < stop_pos; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = j + 1;
			}
		}
	}
}
//插入排序
//平均时间复杂度:O(N^2)
//最坏情况复杂度:O(N^2)
//最好情况复杂度:O(N)
//空间复杂度:O(1)
//最多需要n(n?1)/2次比较
//最少需要n?1次比较
//稳定排序
void insertsort(vector<int>& a)
{
	int n = a.size();
	for (int i = 1; i < n; i++)
	{
		int insert_num = a[i], j;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] > insert_num)
				a[j + 1] = a[j];
			else
				break;
		}
		a[j + 1] = insert_num;
	}
}
//选择排序
//平均时间复杂度 O(n^2)
//最坏时间复杂度 O(n^2)
//最好时间复杂度 O(n^2)
//空间复杂度 O(1)
//我这个写法 是稳定排序
void select_sort(vector<int>& vt)
{
	for (unsigned int i = 0; i < vt.size() - 1; i++)
	{
		int swap_pos = i;
		for (unsigned int j = i + 1; j < vt.size(); j++)
		{
			if (vt[swap_pos] > vt[j])
			{
				swap_pos = j;
			}
		}

		if (swap_pos != i)
		{
			swap(vt[swap_pos], vt[i]);
		}
	}
}

//希尔排序
//最坏情况复杂度:O(N^2)
//不稳定排序
void shellsort(vector<int>& a)
{
	int n = a.size();
	for (int increment = n / 2; increment > 0; increment /= 2)
	{
		for (int i = increment; i < n; i++)
		{
			int insert_num = a[i], j;
			for (j = i - increment; j >= 0; j -= increment)
			{
				if (a[j] > insert_num)
					a[j + increment] = a[j];
				else
					break;
			}
			a[j + increment] = insert_num;
		}
	}
}
//堆排序
//建堆的平均时间是：O(N)
//建堆的最坏情况是：O(NlogN)
//删除元素的时间是：O(logN)
//整个排序平均时间复杂度：O(N+NlogN)=O(NlogN)
//最坏情况复杂度：O(NlogN)
//不稳定排序

//建立一个大顶堆O(n),要求就是 把最大的元素 移动到堆顶 也就是a[0]
void make_heap(vector<int>& a, int size) //size的当前堆的大小，也就是数组的前size个数
{
	for (int i = size - 1; i > 0; i--)
	{
		if (i % 2 && a[i] > a[(i - 1) / 2])//奇数
			swap(a[i], a[(i - 1) / 2]);
		else if (i % 2 == 0 && a[i] > a[(i - 2) / 2])//偶数
			swap(a[i], a[(i - 2) / 2]);
	}
}
void heapsort(vector<int>& a)
{
	int n = a.size();
	while (n)
	{
		make_heap(a, n); //每次把新的最大元素移到堆顶，也就是a[0]
		n--;
		swap(a[0], a[n]); //然后把当前最大移动到后面来作为排好序的元素
	}
}
//归并排序
//平均时间复杂度：O(NlogN)
//稳定排序
vector<int> mergeHelper(vector<int> &a, int left, int right)
{
	if (left == right) return vector<int>(1, a[left]);
	int mid = (right - left) / 2 + left;
	vector<int> l = mergeHelper(a, left, mid);
	vector<int> r = mergeHelper(a, mid + 1, right);
	//merge
	vector<int> ret;
	unsigned int ll = 0, rr = 0;
	while (ll < l.size() && rr < r.size())
	{
		if (l[ll] <= r[rr])     ret.push_back(l[ll++]);
		else                    ret.push_back(r[rr++]);
	}
	while (ll < l.size()) ret.push_back(l[ll++]);
	while (rr < r.size()) ret.push_back(r[rr++]);
	return ret;
}

void mergesort(vector<int>& a)
{
	a = mergeHelper(a, 0, a.size() - 1);
}
//快速排序
//平均时间复杂度：O(NlogN)
//最坏情况复杂度：O(N^2)
//不稳定排序
void quicksortHelper1(vector<int>& a, int start, int end)
{
	if (start >= end) return;
	int l = start, r = end;
	int pivot = a[(end - start) / 2 + start];
	while (l <= r)
	{
		while (l <= r && a[r] > pivot)  r--;
		while (l <= r && a[l] < pivot)  l++;
		if (l <= r) swap(a[l++], a[r--]);
	}
	quicksortHelper1(a, start, r);
	quicksortHelper1(a, l, end);
}

//快排的最差时间复杂度为O(n?)
//通常出现在选择的轴值(pivot)不能将数组划分为两个长度相等的子数组的时候
//一个较好的办法是“三数取中”，查看当前数组的第一个、中间一个和最后一个位置的数组，取其中位数，以此来降低轴值选择得不好的可能性。
int findmiddle(int a, int b, int c)
{
	if (a >= b && a <= c)
		return a;
	else if (b >= a && b <= c)
		return b;
	else
		return c;
}
void quicksortHelper2(vector<int>& a, int start, int end)
{
	if (start >= end) return;
	int l = start, r = end;
	int pivot = findmiddle(a[start], a[end], a[(end - start) / 2 + start]);
	while (l <= r)
	{
		while (l <= r && a[r] > pivot)  r--;
		while (l <= r && a[l] < pivot)  l++;
		if (l <= r) swap(a[l++], a[r--]);
	}
	quicksortHelper2(a, start, r);
	quicksortHelper2(a, l, end);
}
void quicksort(vector<int>& a)
{
	//quicksortHelper1(a, 0, a.size() - 1);
	quicksortHelper2(a, 0, a.size() - 1);
}


int main()
{
	CB b;
	CA *ap = &b;
	CC c;
	CB &br = c;
	CB *bp = &c;

	//ap->f();
	//cout << endl;

	//b.f();
	//cout << endl;

	//br.f();
	//cout << endl;

	//bp->f();
	//cout << endl;

	//ap->ff();
	//cout << endl;

	bp->ff();
	cout << endl;

	getchar();
	return 0;
}