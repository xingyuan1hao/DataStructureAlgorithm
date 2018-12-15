// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ð������
//ƽ��ʱ�临�Ӷ�:O(N^2)
//�������Ӷ�:O(N^2)
//�ռ临�Ӷ�:O(1)
//�ȶ�����
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
//ð������������1
//����һ���������־һ�˱Ƚ��Ƿ�������
//���û�з����������������Ѿ�����
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
//ð�������Ż���
//��һ��������¼�����һ������������λ�ã�����û�з����������Ѿ�����
//���Կ��������ֵ����Ϊ��һ�αȽϽ�����λ��
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
//��������
//ƽ��ʱ�临�Ӷ�:O(N^2)
//�������Ӷ�:O(N^2)
//���������Ӷ�:O(N)
//�ռ临�Ӷ�:O(1)
//�����Ҫn(n?1)/2�αȽ�
//������Ҫn?1�αȽ�
//�ȶ�����
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
//ѡ������
//ƽ��ʱ�临�Ӷ� O(n^2)
//�ʱ�临�Ӷ� O(n^2)
//���ʱ�临�Ӷ� O(n^2)
//�ռ临�Ӷ� O(1)
//�����д�� ���ȶ�����
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

//ϣ������
//�������Ӷ�:O(N^2)
//���ȶ�����
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
//������
//���ѵ�ƽ��ʱ���ǣ�O(N)
//���ѵ������ǣ�O(NlogN)
//ɾ��Ԫ�ص�ʱ���ǣ�O(logN)
//��������ƽ��ʱ�临�Ӷȣ�O(N+NlogN)=O(NlogN)
//�������Ӷȣ�O(NlogN)
//���ȶ�����

//����һ���󶥶�O(n),Ҫ����� ������Ԫ�� �ƶ����Ѷ� Ҳ����a[0]
void make_heap(vector<int>& a, int size) //size�ĵ�ǰ�ѵĴ�С��Ҳ���������ǰsize����
{
	for (int i = size - 1; i > 0; i--)
	{
		if (i % 2 && a[i] > a[(i - 1) / 2])//����
			swap(a[i], a[(i - 1) / 2]);
		else if (i % 2 == 0 && a[i] > a[(i - 2) / 2])//ż��
			swap(a[i], a[(i - 2) / 2]);
	}
}
void heapsort(vector<int>& a)
{
	int n = a.size();
	while (n)
	{
		make_heap(a, n); //ÿ�ΰ��µ����Ԫ���Ƶ��Ѷ���Ҳ����a[0]
		n--;
		swap(a[0], a[n]); //Ȼ��ѵ�ǰ����ƶ�����������Ϊ�ź����Ԫ��
	}
}
//�鲢����
//ƽ��ʱ�临�Ӷȣ�O(NlogN)
//�ȶ�����
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
//��������
//ƽ��ʱ�临�Ӷȣ�O(NlogN)
//�������Ӷȣ�O(N^2)
//���ȶ�����
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

//���ŵ����ʱ�临�Ӷ�ΪO(n?)
//ͨ��������ѡ�����ֵ(pivot)���ܽ����黮��Ϊ����������ȵ��������ʱ��
//һ���Ϻõİ취�ǡ�����ȡ�С����鿴��ǰ����ĵ�һ�����м�һ�������һ��λ�õ����飬ȡ����λ�����Դ���������ֵѡ��ò��õĿ����ԡ�
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