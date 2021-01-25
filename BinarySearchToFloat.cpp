#include<iostream>
using namespace std;

double x;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> x;
	bool is_min = false;
	double l = 0;
	if (x < 0)x = -x, is_min = true;
	double r = x >= 1 ? x : 1;
	while (fabs(l - r) > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid <= x)l = mid;
		else r = mid;
	}
	printf("%.6f", l);
}