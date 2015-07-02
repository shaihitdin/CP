#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;

double s[N], d[N];

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	for (int i = 1; i <= n; ++i)
		cin >> d[i];

	double t = 1000000;

	for (int i = 1; i <= n; ++i)
		t = min (t, d[i] / s[i]);

	for (int i = 1; i <= n; ++i)
		if (t == d[i] / s[i])
			cout << i << "\n";

	return 0;
}