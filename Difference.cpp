#include<iostream>
using namespace std;
const int N = 100010;
int a[N], d[N];

void insert(int l, int r, int t)
{
    a[l] += t;
    a[r + 1] -= t;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        insert(i, i, t);
    }
    while (m--)
    {
        int l, r, t;
        cin >> l >> r >> t;
        insert(l, r, t);
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1] + a[i];
        cout << d[i] << " ";
    }
}