#include<iostream>
using namespace std;
const int N = 1010;

int a[N][N], b[N][N];
int n, m, q;

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
        }
    while (q--)
    {
        int n1, m1, n2, m2;
        cin >> n1 >> m1 >> n2 >> m2;
        cout << b[n2][m2] - b[n1 - 1][m2] - b[n2][m1 - 1] + b[n1 - 1][m1 - 1] << endl;
    }

}