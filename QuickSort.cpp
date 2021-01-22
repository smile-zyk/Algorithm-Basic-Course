#include<iostream>
using namespace std;

const int N = 100010;
int n, a[N];

void quick_sort(int a[], int l, int r)
{
	if (l >= r)return;
	int i = l - 1, j = r + 1;
	int x = a[l + r >> 1];
	while (i < j)
	{
		while (a[++i] < x);
		while (a[--j] > x);
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	quick_sort(a, l, j);
	quick_sort(a, j + 1, r);
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
}