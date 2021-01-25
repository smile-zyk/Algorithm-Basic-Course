#include<iostream>
using namespace std;

const int N = 100010;
int a[N], q, n;

int binary_search1(int l,int r,int x)//—∞’“”“±ﬂΩÁ
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (a[mid] <= x)l = mid;
		else r = mid - 1;
	}
	return l;
}

int binary_search2(int l, int r, int x)//—∞’“◊Û±ﬂΩÁ
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (a[mid] >= x)r = mid;
		else  l = mid + 1;
	}
	return l;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++)cin >> a[i];
	while (q--)
	{
		int k;
		cin >> k;
		int f = binary_search2(0, n - 1, k);
		if (a[f] != k)cout << "-1 -1" << endl;
		else
			cout << f << " " << binary_search1(0, n - 1, k) << endl;
	}
}