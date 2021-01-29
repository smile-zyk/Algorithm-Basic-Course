#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> Add(vector<int>& a, vector<int>& b)
{
	vector<int> c;
	int t = 0;
	for (int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++)
	{
		if (i < a.size())t += a[i];
		if (j < b.size())t += b[j];
		c.push_back(t % 10);
		t /= 10;
	}
	if (t)c.push_back(t % 10);
	return c;
}

vector<int> Sub(vector<int>& a, vector<int>& b)
{
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		t = a[i] - t;
		if (i < b.size())t -= b[i];
		c.push_back((t + 10) % 10);
		if (t < 0)t = 1;
		else t = 0;
	}
	while (c.size() > 1 && c.back() == 0)c.pop_back();
	return c;
}

vector<int> Mul(vector<int>& a, int b)
{
	vector<int> c;
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		t = a[i] * b + t;
		c.push_back(t % 10);
		t /= 10;
	}
	if (t)c.push_back(t);
	return c;
}

vector<int> Div(vector<int>& a, int b, int& r)
{
	vector<int> c;
	r = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		r = r * 10 + a[i];
		c.push_back(r / b);
		r %= b;
	}
	reverse(c.begin(), c.end());
	while (c.size() > 1 && c.back() == 0)c.pop_back();
	return c;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i]-'0');
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i]-'0');
	auto C = Add(A, B);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	cout << endl;
	if (a.size() > b.size() || (a.size() == b.size() && a >= b))
		C = Sub(A, B);
	else
	{
		C = Sub(B, A);
		cout << "-";
	}
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	cout << endl;
	C = Mul(A, 11);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	cout << endl;
	int r = 0;
	C = Div(A, 10, r);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	cout << endl << r;
}